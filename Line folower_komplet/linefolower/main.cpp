/*
 * Line_Folower01.cpp
 * Created: 20.12.2019 22:27:22
 * Author : Šimon Skládaný, David Skrob, Tomas Nazler
 */ 

#include "3piLibPack.h"
#include "math.h"

#define MOTOR_OL motor_l,motor_r
#define MOTOR_OR motor_l,motor_r
#define MOTOR_ROV motor_l,motor_r

int motor_r = 0;
int motor_l = 0;
int senzor0 = 0;
int senzor1 = 0;
int senzor2 = 0;
int senzor3 = 0;
int senzor4 = 0;

int last_proportional = 0;
int integral = 0;
int position = 0;

int tick = 50;

bool white_line = true;
bool black = false;

int sumPos(){
	senzor0 = getSensorValue(0);
	senzor1 = getSensorValue(1);
	senzor2 = getSensorValue(2);
	senzor3 = getSensorValue(3);
	senzor4 = getSensorValue(4);
	
	position = getLinePos(white_line = false);
	
	return senzor0 + senzor1 + senzor2 + senzor3 + senzor4;
}

void deriv(int p,int speed){
	int proportional = ((int)position) - 2000;
	int derivative = proportional - last_proportional;
	
	integral += proportional;
	last_proportional = proportional;
	
	int power_difference = proportional/20 + integral/p + derivative*3/2;
	
	const int max = speed;
	
	if(power_difference > max){
		power_difference = max;
	}
	
	if(power_difference < -max){
		power_difference = -max;
	}
	
	if(power_difference < 0){
		motor_l = max+power_difference;
		motor_r = max;
	}
	
	else{
		motor_l = max;
		motor_r = max-power_difference;
	}
}


void checkLine(int tick){
	for (int l;l!=tick ;l++){
		if (black){
			break;
		}
		sumPos();
		if(sumPos()>499){
			black=true;
			break;
		} //kdyz najdes cernou, vypadni a skipni vsechny dalsi checkLine
	}
		
}

void searchForLine(){
	for(;;){
		setMotorPower(60,50);
		checkLine(5000);//5000 promena ktera se bude pricitat
	
		setMotorPower(0,40);// musi se jeste menit , kvuli ruznemu r kruznuce //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		delay(500);
		setMotorPower(50,60);
		checkLine(10000);//10000 promena ktera se bude pricitat
		
		setMotorPower(40,0);
		delay(500);
	}
}

void run(void)
{
	buzzer.start();
	delay(100);
	buzzer.stop();
	display.printToXY("press", 1, 0);
	display.printToXY("Button_B", 0, 1);
	cal_round();
	
	waitForButton(BUTTON_B);
	display.clear();
	display.printNumToXY(getBatteryVoltage(), 2,0);
	display.printToXY("mV", 6,0);
	delay(1000);
	display.clear();
	display.printToXY("go!", 3,0);
	
	while (1) 
    {
		bool power = true;
		
		while(power)
		{
			tick = 50;
			black = false;
			
			
			sumPos();
			position = getLinePos(white_line = false);
			
			//rs232.sendNumber(white_);
			//rs232.send("\n\n");
			
			if(sumPos()< 500){ // vyjel si z èáry
				searchForLine();
			}
			
			if(sumPos()>2048){
				for (int t;t!=10;t++){
					setMotorPower(60,40);
				}
			}
			
			if(position<1024){
				deriv(1000,200);
			}
			
			if(position<4097){
				if (position>3072){
					deriv(1000,200);
				}
				
				else{
				deriv(5000,135);
				}
			}
			
			
		}
    }
}
