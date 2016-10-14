#include<stdio.h>

int main(){
	int myVariable = 1025;
	int* pointerTomyVariable;
	pointerTomyVariable = &myVariable;

	printf("Size of the integer in C: %d\n", sizeof(int));
	printf("Address of myVariable: %d, Value of myVariable: %d\n", pointerTomyVariable, *pointerTomyVariable);


	void* voidPointer; // Declaring void pointer
	voidPointer = pointerTomyVariable;

	printf("Address stored in void pointer: %d\n", voidPointer);
	/*
	We can not see the value of the void pointer with the *(valueAt) operator. It generally throws "error: invalid use of void expression"
	*/
}