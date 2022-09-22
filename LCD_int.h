#ifndef LCD_INT_H
#define LCD_INT_H

void LCD_vid_SendData(u8 Copy_u8Data);

void LCD_vid_SendCmd(u8 Copy_u8Cmd);

void LCD_Vid_Init(void);


void LCD_vid_SendInt(u32 Copy_U32Number);

void LCD_vid_SendString(u8 *str);

#endif
