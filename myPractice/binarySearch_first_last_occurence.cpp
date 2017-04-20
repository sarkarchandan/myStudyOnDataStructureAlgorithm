#include <iostream>
using namespace std;

//Method that resturns first and last occurence of a number
int binarySearchFirstOrLastOcc(int myArray[],int size,int element,bool isFirstOcc){
	int mid;
	int start = 0;
	int end = size-1;
	int result = -1;

	while(start <= end){

		mid = start + (end - start)/2;
		if(element == myArray[mid]){
			result = mid;
			if(isFirstOcc == true){
				end = mid - 1;
			}else{
				start = mid + 1;
			}
		}else if(element < myArray[mid]){
			end = mid - 1;
		}else{
			start = mid + 1;
		}
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int myArray[] = {2,4,8,45,45,45,45,45,67,78,89,98,108,167,234,345,567,789};
	int size = sizeof(myArray) / sizeof(int);

	int num;
	cout << "Enter the no that you want to check:" << endl;
	cin >> num;

	int firstOccu = binarySearchFirstOrLastOcc(myArray,size,num,true);
	int lastOccu = binarySearchFirstOrLastOcc(myArray,size,num,false);
	if(firstOccu == -1 || lastOccu == -1){
		cout << "The Element is not found." << endl;
	}else{
		cout << "The First Occurence of " << num <<"  in the given array is: " << firstOccu << endl;
		cout << "The Last Occurence of " << num <<"  in the given array is: " << lastOccu << endl;
		cout << "The total no of occurences of " << num << " in the given array is: " << (lastOccu - firstOccu) + 1 << endl;
	}
	return 0;
}