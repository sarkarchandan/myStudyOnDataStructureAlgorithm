/*
This is Recursive implementation of the Binary Search for a sorted array.
*/

#include<iostream>

using namespace std;

//Binary Search Array Implementation.
int binarySearchRecursive(int myArray[],int start,int end, int element){

	if(start > end){
		return -1;
	}
	int mid = start+(end-start)/2;

	if(element == myArray[mid]){
		return mid;
	}else if(element > myArray[mid]){
		return binarySearchRecursive(myArray,mid+1,end,element);
	}else{
		return binarySearchRecursive(myArray,start,mid-1,element);
	}
}


int main(){

        int myArray[] = {3,26,45,67,79,101,297,378,494,597,687,798,898,1004};
        int number;
        cout << "Hello, This is a Binary Search Array Implementation of the array below: " << endl;
        int sizeOfArray = sizeof(myArray)/sizeof(int);
        for(int j=0;j<sizeOfArray;j++){
                cout << myArray[j] << " ";
        }
        cout << endl;
        cout << endl;

        cout  << "Please eneter the number you want to search: " << endl;
        cin >> number;

        int searchResult = binarySearchRecursive(myArray,0,sizeOfArray-1,number);
        if(searchResult !=-1){
                cout << "We have found " << number << " at the index: " << searchResult+1 << endl;
        }else{
                cout << "We have not found " << number << " in the entered array." << endl;
        }
}