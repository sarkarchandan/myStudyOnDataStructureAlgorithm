//Naive Binary Search Array Implementation with a predefined Array.
#include<iostream>

using namespace std;

//Binary Search Array Implementation.
int binarySearchIterative(int myArray[],int number,int noOfElements){

	int start = 0;
	int end = (noOfElements-1);

	while(start <= end){
		int mid = start+(end-start)/2;
		//int mid = (start+end)/2;
		/*We could have used the commented out statement for determining the mid as well but the used statement is better
		then the statement we have commented out.
		Sometimes, when we are dealing with a very large input size, start+end may exceed the limit that a 32 bit integer
		can store i.e. it may exceed 2^31.
		Having this statement instead, start+(end-start)/2 safegurds us from that possibility.
		*/
		if(number == myArray[mid]){
			return mid;
		}else if(number < myArray[mid]){
			end = mid-1;
		}else{
			start = mid+1;
		}
	}
	return -1;
}


int main(){

	int myArray[] = {34,56,67,79,101,597,678,1004};
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

	int searchResult = binarySearchIterative(myArray,number,sizeOfArray);
	if(searchResult !=-1){
		cout << "We have found " << number << " at the index: " << searchResult+1 << endl;
	}else{
		cout << "We have not found " << number << "in the entered array." << endl;
	}
}
