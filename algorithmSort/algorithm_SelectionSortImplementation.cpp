/*
Implementing Selection Sort Algorithm.
*/

#include<iostream>

using namespace std;


//Implementing Selection Sort Algorithm
void selectionSort(int myArray[],int size){

	for(int i=0;i<size-1;i++){

		int min = i;

		for(int j=i+1;j<size;j++){
			if(myArray[j]<myArray[min]){
				min = j;
			}
		}
		/*
		myArray[i] = myArray[i]+myArray[min];
		myArray[min] = myArray[i]-myArray[min];
		myArray[i] = myArray[i]-myArray[min];
		*/

		int temp = myArray[i];
		myArray[i] = myArray[min];
		myArray[min] = temp;
	}
}

int main(){

	int myArray[] = {28,4,104,3,54,9};

	int size = sizeof(myArray)/sizeof(int);
	cout << "Unsorted Array: " << endl;
	for(int i=0;i<size;i++){
		cout << myArray[i] <<" ";
	}
	selectionSort(myArray,size);
	cout << endl;
	cout << "Array sorted with Selection Sort: " << endl;
		for(int j=0;j<size;j++){
		cout << myArray[j] <<" ";
	}
	cout << endl;
}