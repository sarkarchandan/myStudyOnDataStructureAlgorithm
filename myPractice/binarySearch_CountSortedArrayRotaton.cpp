#include <iostream>
using namespace std;

int countSortedArrayRotation(int myArray[],int size){
	int start = 0;
	int end = size - 1;
	int mid,previous,next;

	while(start <= end){
		if(myArray[start] <= myArray[end]){
			//This means array is not rotated at all.
			return start;
		}
		mid = start + (end-start)/2;
		previous = (mid-1+size)%size;
		next = (mid+1)%size;
		//Assuming that the array is rotated
		if(myArray[mid] <= myArray[previous] && myArray[mid] <= myArray[next]){//Unique property of he pivot element
			return mid;
			//Divding the array to short the search space.
		}else if(myArray[mid] >= myArray[start]){
			start = mid + 1;
		}else if(myArray[mid] <= myArray[end]){
			end = mid-1;
		}
	}
	//Invalid case
	return -1;
}

int main(int argc, char const *argv[])
{
	int myArray[] = {10,15,18,2,5,6,8};
	int size = sizeof(myArray)/sizeof(int);
	int result = countSortedArrayRotation(myArray,size);
	if(result != -1){
		cout << "The given array is rotated " << result << " times." << endl;
	}else{
		cout << "This is an invalid case." << endl;
	}
	return 0;
}