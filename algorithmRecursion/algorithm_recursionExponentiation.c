#include<stdio.h>

// This is a demonstration of the exponentiation using Recursion.
int getExponent(int x,int n){

	if(n==0){
		return 1;
	}else{
		if(n%2==0){
			int y=getExponent(x,(n/2));
			return y*y;
		}else{
			return x*getExponent(x,n-1);
		}
	}


}

int main(){

	int number,power,exponentResult;
	printf("Enter the number: \n");
	scanf("%d",&number);
	printf("Enter the power for exponentiation: \n");
	scanf("%d",&power);

	exponentResult = getExponent(number,power);
	printf("The Result of exponentiation is: %d\n",exponentResult);
}