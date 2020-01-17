/*
 * TEST_SENZORU.cpp
 *
 * Created: 20.12.2019 1:28:46
 * Author : simon
 */ 

#include "3piLibPack.h"


void run()
{
	bool white_line = true;
	display.print("Zapnuto");
	
	cal_round();
	
    int senz0 = 0;
	int senz1 = 0;
	int senz2 = 0;	
	int senz3 = 0;	
	int senz4 = 0;
	
	int position = 0;
	int bila = 0;
	
	while (1) 
    {
					
		bila = senz0 + senz1 + senz2 + senz3 + senz4;
		rs232.send("bila: ");
		rs232.sendNumber(bila);
		rs232.send("\n\n");
		delay(500);
		
		
		position = getLinePos(white_line = false);
		rs232.send("position: ");
		rs232.sendNumber(position);
		rs232.send("\n\n");
		delay(500);
		
				
		
					
					senz0 = getSensorValue(0);
					
					rs232.send("senz0: ");
					rs232.sendNumber(senz0);
					rs232.send("    ||");
					
					
					
					senz1 = getSensorValue(1);
					
					rs232.send("senz1: ");
					rs232.sendNumber(senz1);
					rs232.send("    ||");
				    
				
					
					senz2 = getSensorValue(2);
					
					rs232.send("senz2: ");
					rs232.sendNumber(senz2);
					rs232.send("    ||");

				
				
					senz3 = getSensorValue(3);
					
					rs232.send("senz3: ");
					rs232.sendNumber(senz3);
					rs232.send("    ||");
				
					
					
				
					senz4 = getSensorValue(4);
					
					rs232.send("senz4: ");
					rs232.sendNumber(senz4);
					rs232.send("||    \n\n");
					
			
					
					

	
			
    }
}

