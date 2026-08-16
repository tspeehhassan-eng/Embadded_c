//C function to count how many times it has been called in the system
#include<stdio.h>
#include"../std_types.h"
U16 times(void);
int main(void){
	U16 var;
	times();
	times();
	times();
	times();
	times();
	var=times();
	printf("%hu",var);
}
U16 times(void){
	static U16 counter;
	counter++;
	return counter;
}