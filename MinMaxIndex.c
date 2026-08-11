//C function to get the max. / min. number in array and its index
#include<stdio.h>
#include"../std_types.h"

U32 max_ind,min_ind;

void getMaxMin(S32 arr[10]);

int main(void){
	S32 arr[10]={1,2,3,5,10,9,8,7,6,0};
	getMaxMin(arr);
	printf("the max number at index %lu\n",max_ind);
	printf("the min number at index %lu\n",min_ind);
}
void getMaxMin(S32 arr[10]){
	S32 max=arr[0];
	S32 min=arr[0];
	for(S32 i=0;i<10;i++){
		if(arr[i]>max){
			max=arr[i];
			max_ind=i;
		}
	}
	for(S32 i=0;i<10;i++){
		if(arr[i]<min){
			min=arr[i];
			min_ind=i;
		}
	}
}