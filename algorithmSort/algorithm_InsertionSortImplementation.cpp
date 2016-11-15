/*
Implementing Insertion Sort algorithm.
*/

#include<iostream>

using namespace std;

//Implements Insertion Sort Algorithm
void insertionSort(int myArray[],int size){

	for (int i=1;i<=size-1;i++){

		int thirVariable = myArray[i];
		int hole = i;

		while(hole > 0 && myArray[hole-1] > thirVariable){
			myArray[hole] = myArray[hole-1];
			hole = hole-1;
		}
		myArray[hole] = thirVariable;
	}
}


int main(){
	int myArray[] = {28,4,104,3,54,9};

	int size = sizeof(myArray)/sizeof(int);
	cout << "Unsorted Array: " << endl;
	for(int i=0;i<size;i++){
		cout << myArray[i] <<" ";
	}
	insertionSort(myArray,size);
	cout << endl;
	cout << "Array sorted with Insertion Sort: " << endl;
		for(int j=0;j<size;j++){
		cout << myArray[j] <<" ";
	}
	cout << endl;

}