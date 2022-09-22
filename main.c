/*
 * main.c
 *
 *  Created on: Sep 11, 2022
 *      Author: Omar Saeed
 */

#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_int.h"
#include "KPD_config.h"
#include "KPD_int.h"
#include "LCD_config.h"
#include "LCD_int.h"
#include <util/delay.h>


int main(){

	DIO_Vid_SetPortDirection(Port_A,output);
	DIO_Vid_SetPortDirection(Port_B,output);

	LCD_Vid_Init();

	DIO_Vid_SetPortDirection(KPD_ROW_PORT, input);
	DIO_Vid_SetPortValue(KPD_ROW_PORT, 0b11111111);

	DIO_Vid_SetPortDirection(KPD_COL_PORT, output);



	u8 size1 = 0, size2 = 0;

	u8 op1[size1], op2[size2], operator1,operator2;

	u8 number1, number2;
	u32 result;

	LCD_vid_SendString("welcome!");

	_delay_ms(3000);

	LCD_vid_DisplayClear();
	while(1){


		number1 = kpd_Get_Fnum(op1, size1, &operator1);

		/* to display the first number if the user typed '=' after entering the first number*/
		if(operator1 == '='){
			result = number1;
			LCD_vid_SendInt(result);
		}

		/*to clear the lcd if the user pushed the 'c' button*/
		else if(operator1 == 'c'){
			LCD_vid_DisplayClear();
			size1 = 0;
			size2 = 0;
			continue;
		}

		number2 = kpd_Get_Lnum(op2, size2, &operator2);

		/*to clear the lcd if the user pushed the 'c' button*/
		 if(operator2 == 'c'){
					LCD_vid_DisplayClear();
					size1 = 0;
					size2 = 0;
					continue;
				}


			switch(operator1){
					case '+':
						result=number1+number2;
						break;
					case '-':

						result=number1-number2;
						/*to display the minus before the result because the CGROM does not have negative numbers*/
						if(number1<number2){
							LCD_vid_SendData('-');
							result = number2- number1;
						}
						else{
							result = number1 - number2;
						}
						break;
					case '/':
						result=number1/number2;
						break;
					case '*':
						result=number1*number2;
						break;

				}
			if(operator2 == '='){
				LCD_vid_SendInt(result);
			}





}



}













	/*
	u8 op1[4], op2[4], operator;
	s32 number1, number2;
	s32 result;



	number1 = kpd_Get_Fnum(op1);

	while(1){
		u8 z = kpd_Get_PressedKey();

		if(z!= 101){

			LCD_vid_SendData(z);
			operator = z;

			break;
			}
	}



	number2 = kpd_Get_Lnum(op2);


	switch(operator){
			case '+':
				result=number1+number2;
				break;
			case '-':
				result=number1-number2;
				break;
			case '/':
				result=number1/number2;
				break;
			case '%':
				result=number1%number2;
				break;
			case '*':
				result=number1*number2;
				break;
			case '=':
				result=number1;
				break;
		}

*/



