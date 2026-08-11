//2- C function to multiply two integer numbers. by bitwise 

#ifndef BitMath.h
#define BitMath.h

#define set(reg,no) reg |= (1 << no)
#define clear(reg,no) reg &= ~(1 << no)
#define toggle(reg,no) reg ^= (1 << no)
#define get(reg,no) ((reg >> no) & 1)


#endif