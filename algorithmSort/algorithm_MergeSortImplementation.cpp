/*
This is the Merge Sort Implementation.
*/

#include <iostream>

using namespace std;

//Sort and Merge the left and right half of the divided array.
void merge(int* left,int* right,int* final,int lengthLeft, int lengthRight){

	int i=0;
	int j=0;
	int k=0;

	while(i < lengthLeft && j < lengthRight){
		if(left[i]<right[j]){
			final[k] = left[i];
			i=i+1;
		}else{
			final[k] = right[j];
			j=j+1;
		}
		k=k+1;
	}
	while(i < lengthLeft){
		final[k]=left[i];
		i=i+1;
		k=k+1;
	}
	while(j < lengthRight){
		final[k]=right[j];
		j=j+1;
		k=k+1;
	}
}


//Implements Merge Sort using recursion.
void mergeSort(int* myArray,int length){

	if(length<2){
		return;
	}

	int mid = (length/2);

	int lengthLeft = mid;
	int lengthRight = length-mid;

	int* left = new int[lengthLeft];
	int* right = new int[lengthRight];

	for(int i=0;i<mid;i++){
		left[i]=myArray[i];
	}
	for(int j=mid;j<length;j++){
		right[j-mid]=myArray[j];
	}

	mergeSort(left,lengthLeft);
	mergeSort(right,lengthRight);
	merge(left,right,myArray,lengthLeft,lengthRight);
	delete(left);
	delete(right);
}


int main(){

	int myArray[] = {28,4,104,3,54,9};
	int size = sizeof(myArray)/sizeof(int);

	cout << "Unsorted Array: " << endl;
	for(int i=0;i<size;i++){
		cout << myArray[i] <<" ";
	}
	mergeSort(myArray,size);
	cout << endl;
	cout << "Array sorted with Merge Sort: " << endl;
		for(int j=0;j<size;j++){
		cout << myArray[j] <<" ";
	}
	cout << endl;
}