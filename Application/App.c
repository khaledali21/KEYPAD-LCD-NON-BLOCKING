/*
 * App.c
 *
 * Created: 2/8/2022 3:23:10 PM
 *  Author: Khaled Ali
 */ 
#include "App.h"


void App_Init(void){
	KEYPAD_u8Init();
	LCD_u8Init();
}

void App_Update(void){
	
	uint8_t key = 0;
	uint8_t counter = 0;
	while(1){
		KEYPAD_u8GetKey(&key);
		if(key != NO_KEY_PRESSED){
			if(counter == 16){
				LCD_u8SetCursor(1, 0);
			}
			else if(counter == 32){
				counter = 0;
				LCD_u8SendCommand(LCD_CLEAR);
			}
			LCD_u8SendNumber(key);
			counter++;
		}
	}
}