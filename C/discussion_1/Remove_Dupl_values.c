//C function to remove the duplicated numbers in an array
#include<stdio.h>
#include"../std_types.h"
int main(void ){
	S8 arr[100],var;
	S8 freq[100]={0};
	U16 counter=0;
	for (int i=0;i<10;i++){
		scanf(" %c",&var);
		if(freq[var]==0){
			arr[counter]=var;
			freq[var]=1;
			counter++;
			}
	}
for (int i=0;i<counter;i++){
	printf(" %c ",arr[i]);
}}
// it's the same problem!?