/*
This is a basic demonstration of the Recursion.
*/
#include<stdio.h>

int getFactorial(int number){
	printf("Hi, I am now computing getFactorial(%d)\n",number);
	if(number==0){
		return 1;
	}
	int result = number*getFactorial(number-1);
	printf("I have got the value of getFactorial(%d) as: %d \n",number,result);
	return result;
}

int main(){
	int number;
	printf("Enter a number for which you want he factorial: \n");
	scanf("%d",&number);
	int factorNumber = getFactorial(number);
	printf("Therefore the Factorial of %d is %d: \n",number,factorNumber);
}