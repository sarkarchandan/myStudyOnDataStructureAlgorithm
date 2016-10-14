#include<stdio.h>

int main(){
	int myVariable = 1025;
	int* pointerTomyVariable;
	pointerTomyVariable = &myVariable;

	printf("Size of the integer in C: %d\n", sizeof(int));
	printf("Address of myVariable: %d, Value of myVariable: %d\n", pointerTomyVariable, *pointerTomyVariable);

	/*
	Print statement for the Integer pointer gives us the expected result i.e. the memory address of myVariable and the value which is 1025
	*/
	printf("Address of the next integer: %d, Value of the next integer: %d\n",pointerTomyVariable+1,*(pointerTomyVariable+1));
	/*
	Print statement now shows address of the next integer 4 blocks away and a garbage value for the same.
	*/

	char* pointerToChar;
	pointerToChar = pointerTomyVariable; // Assign Integer pointer to the character pointer

	printf("Size of the char in C: %d\n", sizeof(char));
	printf("Address stored in char pointer: %d, Value at the address stored in char pointer %d\n",pointerToChar, *pointerToChar);

	/*
	Print statement for the character pointer gives us the same address as of the address of myVariable since we have assigned the Integer
	pointer to the character pointer.
	But the Value of the character pointer has been printed to be 1. Here's why:

	Following is how the value of myVariable is stored in the memory in consecutive bytes. 

	 byte 3   byte2    byte 1   byte 0
	00000000|00000000|00000100|00000001

	When we printed the Integer pointer all the 4 consecutive bytes are read from the memory. But we have assigned the 
	integer pointer to the character pointer now. Charater takes only 1 byte in memory. Hence while reading the value of the
	character pointer program reads only the first block of the four blocks and the decimal representation of the first block
	produces the value 1.

	*/
	printf("Next Address stored in char pointer: %d, Value at the next address stored in char pointer: %d\n",pointerToChar+1, *(pointerToChar+1));
	/*
	Print statements now shows the address of the next character 1 blocks away and it has found the value 4 which is decimal 
	representation of the binary 0000 0100 .
	*/

}