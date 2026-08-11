 //C function to get the most repeated element in an array.
#include<stdio.h>
#include"../std_types.h"
int main(void ){
	S8 arr[100],max=0, ind=0;
	S8 freq[100]={0};
	for (int i=0;i<10;i++){
		scanf(" %c",&arr[i]);
		freq[arr[i]]++;
	}
	max=freq[0];
for (int i=0;i<100;i++){
	
	if(freq[i]>max){
		max=freq[i];
		ind=i;
	}
}

printf("%c ",ind);
}
