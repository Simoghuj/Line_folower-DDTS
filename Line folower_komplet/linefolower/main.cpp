/*
 * Line_Folower01.cpp
 * Created: 20.12.2019 22:27:22
 * Author : Šimon Skládaný, David Skrob
 */ 

#include "3piLibPack.h"

#define Motor_ol motor_l,motor_r
#define Motor_or motor_l,motor_r
#define Motor_rov motor_l,motor_r

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

int tick = 1000;

bool white_line = true;
bool black = false;

int white_ ();
int white ();


int white_()
{
	senzor0 = getSensorValue(0);
	senzor1 = getSensorValue(1);
	senzor2 = getSensorValue(2);
	senzor3 = getSensorValue(3);
	senzor4 = getSensorValue(4);
	
	return senzor0 + senzor1 + senzor2 + senzor3 + senzor4;
};


int white()
{
	setMotorPower(40,40);
	for(int i = 0; i < 800; i++)
	{
			
		position = getLinePos(white_line = false);
		
		if(white_ () > 15)
		{
			black = true;
			break;
		}
	}
}
	
	/*setMotorPower(40,20);
	for(int i = 0; i < 800; i++)

int folow()
{
	for(int i = 0; i < tick; i++)

	{
		if(black)
		{
			break;
		}
		
		position = getLinePos(white_line = false);

		if(white_ > 15)
		{	
			black = true;
			break;
		}
	}
	setMotorPower(20,40);
	for(int i = 0; i < 800; i++)
	{
		if(black)
		{
			break;
		}
		position = getLinePos(white_line = false);
		if(white_ > 15)
		{
		}
		if(white_ > 15)
		{
			black = true;
			break;
		}
	}
}

int white()
{
	setMotorPower(50,50);
	folow();
	
	for(int i = 0;i < 4 ;i++)
	{	
		setMotorPower(-50,-50);
		folow();
		setMotorPower(40,10);
		folow();
		setMotorPower(-40,-10);
		folow();
		setMotorPower(10,40);
		folow();
		setMotorPower(-10,-40);
		folow();
		tick = tick + 500; 
	}
}
*/
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
			tick = 1000;
			black = false;
			//white_ = 0;
			
			position = getLinePos(white_line = false);
			
			//rs232.sendNumber(white_);
			//rs232.send("\n");
			
			if(white_ () < 500) // vyjel si z èáry
			{
				white();
			}
			
			else
			{
				int proportional = ((int)position) - 2000;
				int derivative = proportional - last_proportional;
			
				integral += proportional;
				last_proportional = proportional;
			
				int power_difference = proportional/20 + integral/10000 + derivative*3/2;
			
				const int max = 60;
			
				if(power_difference > max)
				{
					power_difference = max;
				}
				if(power_difference < -max)
				{
					power_difference = -max;
				}
				if(power_difference < 0)
				{
					motor_l = max+power_difference;
					motor_r = max;
				}
				else
				{
					motor_l = max;
					motor_r = max-power_difference;
				}
			
				/*if(position < 1024)//zatoè vlevo (nefunguje s0 proto 2000 jinak 1000)
				{
					setMotorPower(Motor_ol);
				
				}
				else if(position < 3072) //èára pod tebou
				{
					setMotorPower(Motor_rov);	
				}
			
				else  // zatoè vpravo pokud je position < 4000
				{
					setMotorPower(Motor_or);
				}*/
					
			}
				
			
		}
    }
}