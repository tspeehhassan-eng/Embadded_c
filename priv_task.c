#include <stdio.h>
void Swap(int(*)[3],int(*)[3]);// pointer to all array 

int main(void)
{
	int arr1[3]={1,2,3};
	int arr2[3]={4,5,6};
	

	Swap(&arr1,&arr2);//send address of all array ex 1001->[1,2,3]
	
	
	for(int i=0;i<3;i++){
		printf("%d\n",arr1[i]);
	}
	for(int i=0;i<3;i++){
		printf("%d\n",arr2[i]);
	}
	return 0;
}

void Swap(int (*arr1) [3] , int (*arr2)[3]){
	int temp_arr[3];
	for(int i=0;i<3;i++){
	temp_arr[i]=(*arr1)[i];
	(*arr1)[i]=(*arr2)[i];
	(*arr2)[i]=temp_arr[i];}
	
	}
	
//another sol-> 
/* void Swap(int(*),int(*));// pointer to int
 
int main(void)
{
	int arr1[3]={1,2,3};
	int arr2[3]={4,5,6};
	

	Swap(arr1,arr2);//send address of frist element at array ex 1001->1
	
	
	for(int i=0;i<3;i++){
		printf("%d\n",arr1[i]);
	}
	for(int i=0;i<3;i++){
		printf("%d\n",arr2[i]);
	}
	return 0;
}
void Swap(int (*arr1) , int (*arr2)){
	int temp_arr[3];
	for(int i=0;i<3;i++){
	temp_arr[i]=(arr1)[i];
	(arr1)[i]=(arr2)[i];
	(arr2)[i]=temp_arr[i];}
	
	} */