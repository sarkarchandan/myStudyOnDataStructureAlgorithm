/*
This implementation performs a binary search in circularly sorted array.
*/

#include<iostream>

using namespace std;

//Find a number and return its index in a circularly sorted array
int binarySearchInCircularlySortedArray(int myArray[],int size,int element){

        int start = 0;
        int end = size-1;

        while(start<=end){

                int mid = start+(end-start)/2;

                if(element==myArray[mid]){
                        return mid;
                }else if(myArray[mid]<=myArray[end]){
                        if(element<=myArray[end] && element>=myArray[mid]){
                                start = mid+1;
                        }else{
                                end = mid-1;
                        }
                }else if(myArray[start]<=myArray[mid]){
                        if(element>=myArray[start] && element<=myArray[mid]){
                                end = mid-1;
                        }else{
                                start = mid+1;
                        }
                }
        }
        return -1;
}


int main(){

        int myArray[] = {12,14,18,21,3,6,8,9};
        int number;
        cout << "Hello, This is a Binary Search Array Implementation of the Circularly Sorted Array below: " << endl;
        int sizeOfArray = sizeof(myArray)/sizeof(int);
        for(int j=0;j<sizeOfArray;j++){
                cout << myArray[j] << " ";
        }
        cout << endl;
        cout << endl;

        cout  << "Please eneter the number you want to search: " << endl;
        cin >> number;

        int searchResult = binarySearchInCircularlySortedArray(myArray,sizeOfArray,number);
        if(searchResult !=-1){
                cout << "We have found " << number << " at the index: " << searchResult+1 << endl;
        }else{
                cout << "We have not found " << number << " in the entered array." << endl;
        }
}