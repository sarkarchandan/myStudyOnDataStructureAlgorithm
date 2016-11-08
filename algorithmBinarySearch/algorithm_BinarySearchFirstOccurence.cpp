/*
This is the iterative implementation of the Birnary Search for finding out the first occurence of given no.
*/

#include<iostream>

using namespace std;

//Binary Search First Occurence of a number.
int binarySearchFirstOccurence(int myArray[],int arraySize,int element){

        int start = 0;
        int end = arraySize-1;
        int result = -1;

        while(start<=end){
                int mid = start+(end-start)/2;
                if(element==myArray[mid]){
                        result = mid;
                        end = mid-1;
                }else if(element > myArray[mid]){
                        start = mid+1;
                }else{
                        end = mid-1;
                }
        }
        return result;
}


int main(){

        int myArray[] = {3,26,45,45,45,101,297,378,494,597,687,798,898,1004};
        int number;
        cout << "Hello, This is a Binary Search Array Implementation of the array below: " << endl;
        int sizeOfArray = sizeof(myArray)/sizeof(int);
        for(int j=0;j<sizeOfArray;j++){
                cout << myArray[j] << " ";
        }
        cout << endl;
        cout << endl;

        cout  << "Please eneter the number for which you want to know the first occurence: " << endl;
        cin >> number;

        int searchResult = binarySearchFirstOccurence(myArray,sizeOfArray,number);
        if(searchResult !=-1){
                cout << "We have found the first occurence of " << number << " at the index: " << searchResult+1 << endl;
        }else{
                cout << "We have not found " << number << " in the entered array." << endl;
        }
}