#include<stdio.h>
int MultiBitwise(int ,int);
int main(void){
     int a=5,b=3,m=0;
	 m=MultiBitwise(a,b);
	 printf("%d",m);
}
 int MultiBitwise(int x,int y){
	 int res=0;
	 while(y>0){
		 if (y&1==true){
		 res+=x;
		 
	 }
	 x<<=1;
	 y>>=1;
	 
	 }	
	 return res;
 }