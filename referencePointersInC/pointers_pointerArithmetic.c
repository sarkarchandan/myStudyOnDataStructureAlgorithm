#include<stdio.h>

int main(){

	int myVariable = 10;
	int* pointerTomyVariable; 
	pointerTomyVariable = &myVariable;

	printf("Current value stored by the pointer: %d\n", pointerTomyVariable);
	printf("Current value stored by the pointer: %d\n", pointerTomyVariable+1);
	printf("Current value stored by the pointer: %d\n", pointerTomyVariable+2);
	printf("Size of an integer in C: %d\n", sizeof(int));

	/*
	All the above mentioned statements will display changed value of the integer pointer. Interestingly it'll not show the values incremented by
	1,2 or 3. Since the pointerTomyVariable is an integer pointer incrementing the integer pointer will take us to the next integer. That means
	(pointerTomyVariable+1) will show us the memory address of 4 blocks away, (pointerTomyVariable+2) will show us the memory address of 8 blocks
	away and so on. Size of integer in C is 4 bytes. It consumes 4 of the 1 byte partitions in memory.
	*/

}