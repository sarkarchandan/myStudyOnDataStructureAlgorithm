/*
Considering the theory that arrays as function parameters are always considered as pass by reference, we can operate on array
elements like this.
*/
#include<stdio.h>

int sumOfArrayElements(int *pointerToArray,int size){

	int sum = 0;
	for(int i;i<size;i++){
		sum+=*(pointerToArray+i);
	}
	return sum;
}

void makeDouble(int *pointerToArray,int size){

	for (int i=0;i<size;i++){
		*(pointerToArray+i) = 2 * (*(pointerToArray+i));
	}
}

int main(){

	int myArray[] = {1,2,3,4,5};
	int sizeOfArray = sizeof(myArray)/sizeof(myArray[0]);
	int sumOfArray = sumOfArrayElements(myArray,sizeOfArray);
	printf("Size of the array: %d\n",sizeOfArray);
	printf("Sum of elements in the Array: %d\n", sumOfArray);


	makeDouble(myArray,sizeOfArray);
	printf("The Array elements have been doubled. The new array is:\n");
	for (int i=0;i<sizeOfArray;i++){
		printf("%d\n",myArray[i]);
	}

}


