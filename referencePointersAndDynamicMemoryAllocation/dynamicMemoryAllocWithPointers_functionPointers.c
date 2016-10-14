/*
This program is a demonstration of function pointers.
*/

#include<stdio.h>

int addNumbers(int a,int b){
	return (a+b);
}

void showGreetings(char* name){
	printf("Hello %s\n",name);
}

int main(){
	int sum;
	int (*ptr)(int,int);
	/*
	If we declare the function pointer as int* p(int,int) , it would mean that we are declaring a function which would return a pointer
	to integer.
	*/
	ptr = &addNumbers;

	sum = (*ptr)(5,5);
	/*
	We could have written sum = ptr(5,5); It would work in the same way.
	*/
	printf("The Sum of the two given no is: %d\n", sum);

	/*
	We can declare function pointer for void return type as well.
	*/
	void (*greeting)(char*);
	greeting=&showGreetings;
	greeting("Dominik");

}