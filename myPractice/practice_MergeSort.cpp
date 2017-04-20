/**
This is a practice implementation of the Merge Sort Algorithm
*/
#include <iostream>
using namespace std;

//The function merge sorts and merges two child arrays.
void merge(int *left,int *right, int lengthLeft,int lengthRight,int *result){
	int i = 0;
	int j = 0;
	int k = 0;

	while(i < lengthLeft && j < lengthRight){
		if(left[i] <= right[j]){
			result[k] = left[i];
			i++;
		}else{
			result[k] = right[j];
			j++;
		}
		k++;		
	}
	while(i < lengthLeft){
		result[k] = left[i];
		i++;
		k++;
	}
	while(j < lengthRight){
		result[k] = right[j];
		j++;
		k++;
	}
}


//The function mergeSort divides the provided array and called merge function on them recursively
void mergeSort(int *myArray,int length){
	if(length < 2){
		return;
	}

	int mid = length / 2;

	int *left = new int(mid);
	int *right = new int(length-mid);

	for(int i = 0;i < mid;i++){
		left[i] = myArray[i];
	}
	for(int j = mid;j < length;j++){
		right[j-mid] = myArray[j];
	}

	mergeSort(left,mid);
	mergeSort(right,length-mid);
	merge(left,right,mid,length-mid,myArray);

	delete(left);
	delete(right);
}

int main(int argc, char const *argv[])
{
	int myArray[] = {2,4,1,6,8,5,3,7};
	mergeSort(myArray,(sizeof(myArray)/sizeof(int)));

	cout << "Applying the Merge Sort Algorithm..." << endl;
	for(int i = 0;i<(sizeof(myArray)/sizeof(int));i++){
		cout << myArray[i] << " ";
	}
	cout << endl;
	return 0;
}