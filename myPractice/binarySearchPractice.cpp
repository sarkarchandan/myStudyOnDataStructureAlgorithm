#include <iostream>
using namespace std;

//Iterative implementation
bool binarySearch(int myArray[],int start,int end,int element){
	int mid;
	while(start <= end){
		mid = start+(end-start)/2;
		if(element == myArray[mid]){
			return true;
		}

		if(element > myArray[mid]){
			start = mid+1;
		}else{
			end = mid-1;
		}
	}
	return false;
}

//Recursive Implementation
bool binarySearchRecursive(int myArray[],int start,int end,int element){
	if(start > end){
		return false;
	}
	int mid = start + (end-start)/2;
	if(element == myArray[mid]){
		return true;
	}else if(element > myArray[mid]){
		return binarySearchRecursive(myArray,mid+1,end,element);
	}else{
		return binarySearchRecursive(myArray,start,mid-1,element);
	}
}

int main(int argc, char const *argv[])
{
	int mySearchArray[] = {1,5,6,7,23,45,67,78,98,102,456,875};
	int size = sizeof(mySearchArray)/sizeof(int);
	int searchElement;
	cout << "Enter the element that you want to search: " << endl;
	cin >> searchElement;
	if(binarySearchRecursive(mySearchArray,0,size-1,searchElement) == true){
		cout << "The Element is Found Recursively." << endl;
	}else{
		cout << "Better luck next time Recursively." <<endl;
	}
	if(binarySearch(mySearchArray,0,size-1,searchElement) == true){
		cout << "The Element is Found Iteratively." << endl;
	}else{
		cout << "Better luck next time Iteratively." <<endl;
	}
	return 0;
}