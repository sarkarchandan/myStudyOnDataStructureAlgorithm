/*
This is an example of call by reference using pointer as a parameter of the function
*/
#include<stdio.h>

void incrementNumber(int *p){
	*p = *p+5;
}

int main(){

	int a = 10;
	incrementNumber(&a);
	printf("Incremented value of the variable: %d\n",a);
}