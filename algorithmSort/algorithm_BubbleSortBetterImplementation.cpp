/*
Implementing Bubble Sort algorithm with modification that can provided linear time complexity in best case.
*/

#include<iostream>

using namespace std;

//Implements Bubble Sort Algorithm
void bubbleSort(int myArray[],int size){

	for (int j = 1;j<=size;j++){
		int flag = 0;
		for(int i=0;i<=size-j-1;i++){
			if(myArray[i]>myArray[i+1]){
				int temp = myArray[i];
				myArray[i] = myArray[i+1];
				myArray[i+1] = temp;
				flag = 1;
			}
		}
		if(flag==0){
			break;
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