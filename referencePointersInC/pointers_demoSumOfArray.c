/*
#include<stdio.h>

int sumOfArrayElements(int A[],int size){

	int sum = 0;
	for(int i;i<size;i++){
		sum=sum+A[i];
	}
	return sum;
}

int main(){

	int myArray[] = {1,2,3,4,5};
	int sizeOfArray = sizeof(myArray)/sizeof(myArray[0]);
	int sumOfArray = sumOfArrayElements(myArray,sizeOfArray);
	printf("Size of the array: %d\n",sizeOfArray);
	printf("Sum of elements in the Array: %d\n", sumOfArray);
}
*/

#include<stdio.h>

int sumOfArrayElements(int A[]){

	int i, sum = 0;
	int size= sizeof(A)/sizeof(A[0]);
	printf("Size of the Array: %d\n",size);
	for(i;i<size;i++){
		sum+=A[i];
	}
	return sum;
}

int main(){

	int A[] = {1,2,3,4,5};
	int sumOfArray = sumOfArrayElements(A);
	printf("Sum of elements in the Array: %d\n", sumOfArray);
}