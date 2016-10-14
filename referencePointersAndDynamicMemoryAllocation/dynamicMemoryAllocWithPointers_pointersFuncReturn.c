/*
In this program we are dynamically allocating memory from Heap and we are returning a pointer to the 
allocated memory as the return type of our function.
*/

#include<stdio.h>
#include<stdlib.h>

void printHelloWorld(){
	printf("Hellow World !!!\n");
}

int* addNumbers(int* a,int* b){
	int *c = (int *)malloc(sizeof(int));
	*c = (*a)+(*b);
	return c;
}

int main(){
	int a = 5,b=5;
	int* ptr = addNumbers(&a,&b);
	printHelloWorld();
	printf("Sum of two numbers: %d\n",*ptr);
}