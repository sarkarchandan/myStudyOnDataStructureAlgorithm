/*
This implementation finds out the no of times a given sorted array is rotated.
*/

#include<iostream>

using namespace std;

//This function will find out the no of times a sorted array is rotated circularly.
int getNoOfTimesRotated(int myArray[],int size){

	int start = 0;
	int end = size-1;

	while(start<=end){

		if(myArray[start]<=myArray[end]){
		return start;
		}
		int mid = start+(end-start)/2;
		int next = (mid+1)%size;
		int previous = (mid-1+size)%size;
		if(myArray[mid]<=myArray[previous] && myArray[mid]<=myArray[next]){
			return mid;
		}else if(myArray[mid]>=myArray[start]){
			start = mid+1;
		}else if(myArray[mid]<=myArray[end]){
			end = mid-1;
		}
	}
	return -1;
}



int main(){

        int myArray[] = {2,5,6,8,11,12,15,18};
        int number;
        cout << "Hello, This is a Binary Search Array Implementation" << endl;
        cout << "in order to find out how many times a given sorted array is rotated: " << endl;
        int sizeOfArray = sizeof(myArray)/sizeof(int);
        for(int j=0;j<sizeOfArray;j++){
                cout << myArray[j] << " ";
        }
        cout << endl;
        cout << endl;

        int rotation = getNoOfTimesRotated(myArray,sizeOfArray);
        if(rotation !=-1){
                cout << "The no of times given array is rotated: " << rotation << endl;
        }else{
                cout << "Given Array is not rotated !!!" << endl;
        }
}