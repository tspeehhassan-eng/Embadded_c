
#ifndef COMMON_BITMATH_H_
#define COMMON_BITMATH_H_

#define set(reg,no) reg|=(1<<no)
#define clear(reg,no) reg&=~(1<<no)
#define toggle(reg,no) reg^=(1<<no)
#define read(reg,no) ((reg>>no)&1)

#endif /* COMMON_BITMATH_H_ */
