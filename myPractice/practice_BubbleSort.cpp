#include <iostream>
using namespace std;

void bubbleSort(int myArray[],int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size-1;j++){
			if(myArray[j] > myArray[j+1]){
				int temp = myArray[j];
				myArray[j] = myArray[j+1];
				myArray[j+1] = temp;
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	int myArray[] = {2,7,4,1,5,3};
	int size = sizeof(myArray) / sizeof(int);
	bubbleSort(myArray,size);
	cout << "After Sorting we get: " <<endl;
	for(int i=0;i<size;i++){
		cout << myArray[i] << " ";
	}
	cout << endl;
 	return 0;
}