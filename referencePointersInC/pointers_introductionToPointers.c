/*
This program deals with the pointer reference and memory addresses in Word Format.
While compiling we may get an warning regarding that.
*/
#include<stdio.h>

int main(){

	int myVariable;
	int *pointerTomyVariable; //We may also declare int* pointerTomyVariable; That would work in the same way.

	myVariable = 10;

	pointerTomyVariable = &myVariable; //&=addressOf
	printf("Current value of myVaribale: %d\n", myVariable);
	printf("Value stored in the pointer:  %d\n", pointerTomyVariable); //Returns the value stored in pointer pointerTomyVariable.
	printf("Current value at address stored in pointer: %d\n", *pointerTomyVariable); //Returns the valueAt(Address stored in pointer pointerTomyVariable).
	printf("Current address of myVaribale: %d\n", &myVariable); //Returns the address of myVaribale. Note that this value is same as the value stored in pointerTomyVariable.

	*pointerTomyVariable = 20; //Modifying the valueAt(address). This is called "dereferencing"
	printf("Current value of myVaribale: %d\n", myVariable);

	int secondVariable = 30;
	*pointerTomyVariable = secondVariable;
	/*
	The above statement is not changing the pointerTomyVariable to point to secondVariable.
	What it's simply doing is it's changing the value at the address stored by pointerTomyVariable to something.
	It's not changing anything to the pointerTomyVariable itself.
	However, it may change the pointer using the statement "pointerTomyVariable = &secondVariable". That would mean that we are assigning
	the addressOf secondVariable to pointerTomyVariable. That means pointerTomyVariable will now point secondVariable instead of myVaribale.
	*/
	printf("Current value of myVaribale: %d\n", myVariable);
}