#include <iostream>
using namespace std;

void insertionSort(int myArray[],int size){
	for(int i=1;i<=size-1;i++){
		int buffer = myArray[i];
		int space = i;
		while(space > 0 && myArray[space-1] > buffer){
			myArray[space] = myArray[space-1];
			space = space-1;
		}
		myArray[space] = buffer;
	}
}

int main(int argc, char const *argv[])
{
	int myArray[] = {2,7,4,1,5,3};
	int size = sizeof(myArray) / sizeof(int);
	insertionSort(myArray,size);
	cout << "After Sorting we get: " <<endl;
	for(int i=0;i<size;i++){
		cout << myArray[i] << " ";
	}
	cout << endl;
 	return 0;
}