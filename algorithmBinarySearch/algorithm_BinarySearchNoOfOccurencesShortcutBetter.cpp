/*
Iterative implementation for finding out the no of occurences of a number in a sorted array using Binary Search.
*/

#include<iostream>

using namespace std;

//Finds out the first and last occurence of the number.
int binSearchOccurence(int myArray[],int sizeOfArray,int element,bool searchFirst){

	int start = 0;
	int end = sizeOfArray-1;
	int result = -1;
	while(start <= end){

		int mid = start+(end-start)/2;
		if(element==myArray[mid]){
			result=mid;
			if(searchFirst){ //Based on this check, the function will return either first or last occurence.
				end = mid-1;	
			}else{
				start=mid+1;
			}			
		}else if(element>myArray[mid]){
			start = mid+1;
		}else{
			end=mid-1;
		}
	}
	return result;
}


//Finds out the no of occurences of the number
int binarySearchNoOfOccurences(int myArray[],int sizeOfArray,int element){

	int firstIndex = binSearchOccurence(myArray,sizeOfArray,element,true);
	int lastIndex = binSearchOccurence(myArray,sizeOfArray,element,false);

	if(firstIndex==-1 || lastIndex==-1){
		return -1;
	}else{
		return (lastIndex-firstIndex+1);
	}
}


int main(){

        int myArray[] = {3,26,45,45,45,60,60,378,494,597,687,687,687,687};
        int number;
        cout << "Hello, This is a Binary Search Array Implementation of the array below: " << endl;
        int sizeOfArray = sizeof(myArray)/sizeof(int);
        for(int j=0;j<sizeOfArray;j++){
                cout << myArray[j] << " ";
        }
        cout << endl;
        cout << endl;
        cout  << "Please eneter the number for which you want to know the last occurence: " << endl;
        cin >> number;

        int searchResult = binarySearchNoOfOccurences(myArray,sizeOfArray,number);
        if(searchResult !=-1){
                cout << "The No of occurence of " << number << " in our array is: " << searchResult << endl;
        }else{
                cout << "We have not found " << number << " in the entered array." << endl;
        }
}