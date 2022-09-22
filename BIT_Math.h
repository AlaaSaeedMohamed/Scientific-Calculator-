#ifndef BIT_MATH_H
#define BIT_MATH_H

#define Set(Reg,BitNum) Reg|=(1<<BitNum)
#define Clr(Reg,BitNum) Reg&=~(1<<BitNum)
#define Toggle(Reg,BitNum) Reg^=(1<<BitNum)
#define GetBit(Reg,BitNum) (Reg>>BitNum)&1



#endif
