#include<stdio.h>

int main(){

	int element = 34346;
	int reminder;
	int quotient = element;

	while(quotient!=0){

		quotient = (element/10);
		reminder = (element%10);
		printf("%d\n", reminder);
		element = quotient;

		
	}
}
