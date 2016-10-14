#include<stdio.h>

int main(){
	int myVariable = 10;
	int *pointerTomyVariable;
	pointerTomyVariable = &myVariable;

	printf("Size of the integer in C: %d\n", sizeof(int));
	printf("Val of pointerTomyVariable: %d, Value at the address in pointerTomyVariable: %d\n", pointerTomyVariable, *pointerTomyVariable);

	int *(*pointerToPointer) = &pointerTomyVariable;
	printf("Value of pointerToPointer: %d,Value at the address in pointerToPointer%d\n", pointerToPointer, *pointerToPointer);

	int *(*(*pointerToPointerToPointer)) = &pointerToPointer;
	printf("Value of pointerToPointerToPointer: %d,Value at the address in pointerToPointerToPointer: %d\n", pointerToPointerToPointer, *pointerToPointerToPointer);

}