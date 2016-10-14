#include<stdio.h>

//Basic implementation of recursion in exponentiation.

int getModExponent(int x,int n,int m){

	if(n==0){
		return 1;
	}else{
		if(n%2==0){
			int y=getModExponent(x,n/2,m);
			return (y*y)%m;
		}else
		return((x%m)*getModExponent(x,n-1,m))%m;
	}

}

int main(){
	int base,power,modulo;
	printf("Enter the base for exponentiation: \n");
	scanf("%d",&base);
	printf("Enter the power: \n");
	scanf("%d",&power);
	printf("Enter the Modulo: \n");
	scanf("%d",&modulo);

	int result = getModExponent(base,power,modulo);
	printf("The Result is: %d\n",result);

}