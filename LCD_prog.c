#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_int.h"
#include "LCD_config.h"
#include "LCD_int.h"
#include <util/delay.h>



void LCD_vid_SendData(u8 Copy_u8Data){

	DIO_Vid_SetPinValue(CONTROL_PORT, RS_PIN,PinHigh);
	DIO_Vid_SetPinValue(CONTROL_PORT, RW_PIN,PinLow);
	DIO_Vid_SetPortValue(DATA_PORT, Copy_u8Data);
	DIO_Vid_SetPinValue(CONTROL_PORT, E_PIN,PinHigh);
	_delay_ms(3);
	DIO_Vid_SetPinValue(CONTROL_PORT, E_PIN,PinLow);

}

void LCD_vid_SendCmd(u8 Copy_u8Cmd){

	DIO_Vid_SetPinValue(CONTROL_PORT, RS_PIN,PinLow);
	DIO_Vid_SetPinValue(CONTROL_PORT, RW_PIN,PinLow);
	DIO_Vid_SetPortValue(DATA_PORT, Copy_u8Cmd);
	DIO_Vid_SetPinValue(CONTROL_PORT, E_PIN,PinHigh);
	_delay_ms(3);
	DIO_Vid_SetPinValue(CONTROL_PORT, E_PIN,PinLow);

}

void LCD_Vid_Init(void){

	_delay_ms(40);
	LCD_vid_SendCmd(0b00111100);
	_delay_ms(1);

	LCD_vid_SendCmd(0b00001111);

	LCD_vid_SendCmd(1);

}

void LCD_vid_DisplayClear(){
	LCD_vid_SendCmd(1);
}




void LCD_vid_SendInt(u32 Copy_U32Number){
	if(Copy_U32Number != 0){
		LCD_vid_SendInt(Copy_U32Number/10);
		LCD_vid_SendData((Copy_U32Number%10)+'0');
	}

}


void LCD_vid_SendString(u8 *str){
	 u8 i=0;
	 while(str[i] != '\0'){
		 LCD_vid_SendData(str[i]);
		 i++;
	 }
}
