#include <iostream>

using namespace std;

//Quick Partition for Quick Sort
int quickParition(int* myArray,int start,int end){

	int pivot = myArray[end];
	int partitionIndex = start;

	for(int i=0;i<end;i++){
		if(myArray[i]<=pivot){
			swap(myArray[i],myArray[partitionIndex]);
			partitionIndex=partitionIndex+1;
		}
	}
	swap(myArray[end],myArray[partitionIndex]);
	return partitionIndex;
}

int main(){

	int myArray[] = {7,2,1,6,8,5,3,4};
	int size = sizeof(myArray)/sizeof(int);

	cout << "Unsorted Array: " << endl;
	for(int i=0;i<size;i++){
		cout << myArray[i] <<" ";
	}
	int partitionIndex = quickParition(myArray,0,size-1);
	cout << endl;
	cout << "Array partitioned with Quick Partition: " << endl;
		for(int j=0;j<size;j++){
		cout << myArray[j] <<" ";
	}
	cout << endl;
	cout << "The Partition Index is: " << partitionIndex << endl;
}