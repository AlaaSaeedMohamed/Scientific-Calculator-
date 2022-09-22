#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_int.h"
#include "KPD_config.h"
#include "KPD_int.h"
#include "KPD_private.h"
#include "LCD_config.h"
#include "LCD_int.h"



u8 kpd_Get_PressedKey(void){

	u8 bc_u8PressedKey;
	u8 x;

	u8 COL_ARR[]={row1,row2,row3,row4};
	u8 ROW_ARR[]={col1,col2,col3,col4};

	for(u8 col=0; col<4; col++){

		DIO_Vid_SetPinValue(KPD_COL_PORT, COL_ARR[col],PinLow);

		for(u8 row=0; row<4; row++){

            DIO_Vid_GetPinValue(KPD_ROW_PORT, ROW_ARR[row], &x);

            if(x == 0){

            	bc_u8PressedKey = KPD_ARR[row][col];
            	while(x == 0){
            		DIO_Vid_GetPinValue(KPD_ROW_PORT, ROW_ARR[row], &x);

            	}

            	return bc_u8PressedKey;
            }

		}
		DIO_Vid_SetPinValue(KPD_COL_PORT, COL_ARR[col],PinHigh);

	}
	return 101;

}

// to get the first number entered bu the user and the operator
u32 kpd_Get_Fnum(u8 *operand1, u8 size, u8 *operator){

	u8 z;


	while(1){
		z = kpd_Get_PressedKey();
		if((z != 101) && (z != '+') && (z != '*') && (z != '/') && (z != 'c') && (z != '-') && (z!='=')){

			LCD_vid_SendData(z);
			operand1[size] = z;
			size++;

		}
		else if(z != 101){
			LCD_vid_SendData(z);
			*operator = z;
			break;
		}



	}
	u32 n = kpd_Get_arrNum(operand1, size);


	return n;
}

// to get the second number entered by the user
u32 kpd_Get_Lnum(u8 *operand2, u8 size, u8 *operator){

	u8 z ;

while(1){
	z = kpd_Get_PressedKey();
	if((z != 101) && (z != '+') && (z != '*') && (z != '/') && (z != 'c') && (z != '-') && (z!='=')){

		LCD_vid_SendData(z);
		operand2[size] = z;
		size++;


	}
	// to break from the loop if the user typed '='
	else if(z != 101){
		LCD_vid_SendData(z);
		*operator = z;
		break;
	}



}

u32 n = kpd_Get_arrNum(operand2, size);
	return n;
}


// to convert the array elements into one number
u32 kpd_Get_arrNum(u8 *arr, u8 size){

	u32 val = 0;
	u32 number = 0;
	u32 n = 0 ;

	for(n = 0 ; n<size ; n++){

		number = arr[n] - '0';
		val = (val*10) + number;
	}

	return val;
}


