#include <iostream>
using namespace std;

//Search an element in the Circularly Sorted Array
int searchCircularlySortedArray(int myArray[],int size,int element){
	int start = 0;
	int end = size - 1;
	while (start <= end){
		int mid = start + (end-start)/2;
		if(element == myArray[mid]){
			return mid;
		//Dividing the array into halfs
		}else if(myArray[start] <= myArray[mid]){
			//Dividing the search space into halfs
			if(element >= myArray[start] && element <= myArray[mid]){
				end = mid - 1;
			}else{
				start = mid + 1;
			}
		}else if(myArray[mid] <= myArray[end]){
			//Dividing the search space into halfs
			if(element >= myArray[mid] && element <= myArray[end]){
				start = mid + 1;
			}else{
				end = mid - 1;
			}
		}
	}
	return -1;
}



int main(int argc, char const *argv[])
{
	int element;
	int myArray[] = {11,12,15,18,2,5,6,8};
	int size = sizeof(myArray) / sizeof(int);

	cout << "Enter the element you want to search: " << endl;
	cin >> element;

	int searchResult = searchCircularlySortedArray(myArray,size,element);
	if(searchResult != -1){
		cout << "The no is found and located at the index: " << searchResult << endl;
	}else{
		cout << "Better luck next time !!!" << endl;
	}
	return 0;
}