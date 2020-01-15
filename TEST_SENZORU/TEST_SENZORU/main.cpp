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
    
	while (1) 
    {
					
		
				
					int senz0 = 0;
					senz0 = getSensorValue(0);
					
					rs232.send("senz0: ");
					rs232.sendNumber(senz0);
					rs232.send("\n\n\n\n");
					
					delay(1000);
					
					//display.print("0: ");
					//display.printNumber(senz0);
					//delay(1000);
					//display.clear();
					
					
					
					int senz1 = 0;
					senz1 = getSensorValue(1);
					
					rs232.send("senz1: ");
					rs232.sendNumber(senz1);
					rs232.send("\n\n\n\n");
					delay(1000);
					
					//display.print("1: ");
					//display.printNumber(senz1);
					//delay(1000);
					//display.clear();
			
				    
				
					int senz2 = 0;
					senz2 = getSensorValue(2);
					
					rs232.send("senz2: ");
					rs232.sendNumber(senz2);
					rs232.send("\n\n\n\n");
					delay(1000);
					
					//display.print("2: ");
					//display.printNumber(senz2);
					//delay(1000);
					//display.clear();
			
				
					int senz3 = 0;
					senz3 = getSensorValue(3);
					
					rs232.send("senz3: ");
					rs232.sendNumber(senz3);
					rs232.send("\n\n\n\n");
					delay(1000);
					
					//display.print("3: ");
					//display.printNumber(senz3);
					//delay(1000);
					//display.clear();
					
					int senz4 = 0;
					senz4 = getSensorValue(4);
					
					rs232.send("senz4: ");
					rs232.sendNumber(senz4);
					rs232.send("\n\n\n\n");
					delay(1000);
					
					//display.print("4: ");
					//display.printNumber(senz4);
					//delay(1000);
					//display.clear();
					
					
					
					int bila = senz0 + senz1 + senz2 + senz3 + senz4;
					senz2 = getSensorValue(2);
					
					rs232.send("senz2: ");
					rs232.sendNumber(senz2);
					rs232.send("\n\n\n\n");
					delay(1000);
					
					
					
					
					int position = getLinePos(white_line = false);
					rs232.sendNumber(position);
					delay(500);
					rs232.send("\n\n\n\n\n\n\n");
					delay(500);
		

	
			
    }
}

