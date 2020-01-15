/*
 * Line_Folower01.cpp
 *
 * Created: 20.12.2019 22:27:22
 * Author : Šimon Skládaný
 */ 

#include "3piLibPack.h"

#define Motor_ol 0,100
#define Motor_or 100,0
#define Motor_rov 100,100

#define tim 100
#define rmot 60
#define lmot 20

void run(void)
{
	buzzer.start();
	delay(100);
	buzzer.stop();
	display.printToXY("press", 1, 0);
	display.printToXY("Button_B", 0, 1);
	cal_round();
	delay (1000);
	display.clear
	display.printNumToXY(getBatteryVoltage(), 2,0);
	display.printToXY("mV", 6,0);
	
	bool white_line = true;
	
	int senzor0 = 0;
	int senzor1 = 0;
	int senzor2 = 0;
	int senzor3 = 0;
	int senzor4 = 0;
	int bila = 0;
	
	waitForButton(BUTTON_B);
	display.clear();
	
	
	
	
	while (1) 
    {
		
		while(1)
		{
			
			senzor0 = getSensorValue(0);
			senzor1 = getSensorValue(1);
			senzor2 = getSensorValue(2);
			senzor3 = getSensorValue(3);
			senzor4 = getSensorValue(4);
			
			bila = senzor0 + senzor1 + senzor2 + senzor3 + senzor4;
			
			int position = getLinePos(white_line = false);
			rs232.sendNumber(bila);
			rs232.send("\n");
			
			if(bila < 100) // vyjel si z èáry
			{
				setMotorPower(50,50);
				delay (400);
				for(int i;i!=4 ;i++)
				{
					setMotorPower(-50,-50);
					delay(100);
					setMotorPower(rmot,lmot);
					delay(tim);
					setMotorPower(-rmot,-lmot);
					delay(tim);
					setMotorPower(lmot,rmot);
					delay(tim);
					setMotorPower(-lmot,-rmot);
					delay(tim);
					tim+100;
				
				}	
			}
			else if(position < 1024)//zatoè vlevo (nefunguje s0 proto 2000 jinak 1000)
			{
				setMotorPower(Motor_ol);
				
				
				
			}
			else if(position < 3072) //èára pod tebou
			{
				setMotorPower(Motor_rov);	
			}
			
			else if(position <= 4096) // zatoè vpravo pokud je position < 4000
			{
				setMotorPower(Motor_or);
				
			}	
			
		}
    }
}

