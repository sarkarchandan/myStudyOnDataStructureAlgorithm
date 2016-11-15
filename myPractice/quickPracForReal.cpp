#include <iostream>

using namespace std;

//Paritions the input array for sorting
int quickPartition(int* myArray,int start,int end){

	int pivot = myArray[end];
	int partitionIndex = start;

	for(int i=0;i<end;i++){
		if(myArray[i]<=pivot){
			swap(myArray[i],myArray[partitionIndex]);
			partitionIndex = partitionIndex + 1;
		}
	}
	swap(myArray[partitionIndex],myArray[end]);
	return partitionIndex;
}

//Implements the Quick Sort Algorithm
void quickSort(int* myArray,int start,int end){

	while(start<end){
		int partitionIndex = quickPartition(myArray,start,end);
		quickSort(myArray,start,partitionIndex-1);
		quickSort(myArray,partitionIndex+1,end);
	}
}


int main(){

	int myArray[] = {7,2,1,6,8,5,3,4};
	/*int size = sizeof(myArray)/sizeof(int);

	cout << "Unsorted Array: " << endl;

	for(int i=0;i<size;i++){
		cout << myArray[i] <<" ";

	}*/
	
	quickSort(myArray,0,7);
	cout << endl;
	cout << "Array sorted with Quick Sort Algorithm: " << endl;
		for(int j=0;j<8;j++){
		cout << myArray[j] <<" ";
	}
	
}
