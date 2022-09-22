#ifndef KPD_INT_H
#define KPD_INT_H

u8 kpd_Get_PressedKey();

u32 kpd_Get_Lnum(u8 *operand2, u8 size, u8 *operator);

u32 kpd_Get_Fnum(u8 *operand1, u8 size, u8 *operator);

u32 kpd_Get_arrNum(u8 *arr, u8 size);

#endif
