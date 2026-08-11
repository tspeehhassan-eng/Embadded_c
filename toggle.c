//3-C function to toggle a specific bit in 8-bits variable
#include<stdio.h>
#include"BitMath.h"
#include"../std_types.h"
int main(void){
	 U8 reg, no_bit;

    printf("Please enter number and number of bit: ");
	scanf("%hhu",&reg);
	scanf("%hhu",&no_bit);
	toggle(reg,no_bit);
    printf("the result:%hhu",reg);
}

