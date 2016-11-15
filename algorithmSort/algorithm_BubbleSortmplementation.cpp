/*
Implementing Bubble Sort algorithm
*/

#include<iostream>

using namespace std;

//Implements Bubble Sort Algorithm
void bubbleSort(int myArray[],int size){

	for (int j = 0;j<size;j++){
		for(int i=0;i<size-1;i++){
			if(myArray[i]>myArray[i+1]){
				int temp = myArray[i];
				myArray[i] = myArray[i+1];
				myArray[i+1] = temp;
			}
		}	
	}
}


int main(){
	int myArray[] = {28,4,104,3,54,9};

	int size = sizeof(myArray)/sizeof(int);
	cout << "Unsorted Array: " << endl;
	for(int i=0;i<size;i++){
		cout << myArray[i] <<" ";
	}
	bubbleSort(myArray,size);
	cout << endl;
	cout << "Array sorted with Bubble Sort: " << endl;
		for(int j=0;j<size;j++){
		cout << myArray[j] <<" ";
	}
	cout << endl;

}