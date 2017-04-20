/**
This is practice implementation of th Quick Sort algorithm
*/
#include <iostream>
using namespace std;

void swapNumbers(int *firstNumber, int *secondNumber){
	int temp = *firstNumber;
	*firstNumber = *secondNumber;
	*secondNumber = temp;
}

int partitionArray(int *myArray,int start,int end){
	int pivot = myArray[end];
	int partitionIndex = start;

	for(int i=start;i < end ; i++){
		if(myArray[i] <= pivot){
			swapNumbers(&myArray[i],&myArray[partitionIndex]);
			partitionIndex++;
		}
	}
	swapNumbers(&myArray[partitionIndex],&myArray[end]);
	return partitionIndex;
}

void quickSort(int *myArray, int start,int end){
	if(start < end){
		int partitionIndex = partitionArray(myArray,start,end);
		quickSort(myArray,start,partitionIndex-1);
		quickSort(myArray,partitionIndex+1,end);
	}
}

int main(int argc, char const *argv[])
{
	int myArray[] = {8,3,1,2,13,6,5,4};
	int length = sizeof(myArray) / sizeof(int);
	cout << "Applying Quick Sort Algorithm we get..." << endl;
	
	quickSort(myArray,0,length-1);

	for(int i =0;i<length;i++){
		cout << myArray[i] << " " ;
	}
	cout << endl;
	return 0;
}