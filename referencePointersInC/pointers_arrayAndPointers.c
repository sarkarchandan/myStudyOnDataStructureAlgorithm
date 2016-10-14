/*
This program snippet demonstrates the pointer operation on an integer array
*/

#include<stdio.h>

int main(){
	int myArray[] = {4,6,3,7,2,9,8};

	int* pointerToArray = myArray;

	for(int counter=0;counter<7;counter++){

		printf("%d th element of the array is: %d\n", counter,*(pointerToArray+counter));
		printf("Memory Adress of %d th element is: %d\n",counter,(pointerToArray+counter));
		printf("\n");

	}
}

