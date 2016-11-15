#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

//Paritions the input array for sorting
int quickPartition(int *myArray,int start,int end){

	int pivot = myArray[end];
	int partitionIndex = start;

	for(int i=start;i<end;i++){
		if(myArray[i] <= pivot){
			swap(myArray[i],myArray[partitionIndex]);
			partitionIndex = partitionIndex + 1;
		}
	}
	swap(myArray[partitionIndex],myArray[end]);
	return partitionIndex;
}

int randomizedQuickPartition(int *myArray,int start,int end){

	int pivotIndex = start + (rand() % (end - start + 1));
	swap(myArray[pivotIndex],myArray[end]);
	int partitionIndex = quickPartition(myArray,start,end);
	return partitionIndex;
}

//Implements the Quick Sort Algorithm
void quickSort(int *myArray,int start,int end){

	if(start<end){
		int partitionIndex = randomizedQuickPartition(myArray,start,end);
		cout << "Obtained Paritions Index" << partitionIndex << endl;
		quickSort(myArray,start,partitionIndex-1);
		quickSort(myArray,partitionIndex+1,end);
	}
}


int main(){

	int myArray[] = {7,2,1,6,8,5,3,4};
	int size = sizeof(myArray)/sizeof(int);

	cout << "Unsorted Array: " << endl;

	for(int i=0;i<size;i++){
		cout << myArray[i] <<" ";
	}
	cout << endl;
	quickSort(myArray,0,7);
	cout << endl;
	cout << "Array sorted with Quick Sort Algorithm: " << endl;
		for(int j=0;j<8;j++){
		cout << myArray[j] <<" ";
	}
	cout << endl;
}