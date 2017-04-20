#include <iostream>
using namespace std;

void selectionSort(int myArray[],int size){
	for(int i=0;i<size-1;i++){
		int min = i;
		for(int j=i+1;j<size;j++){
			if(myArray[j] < myArray[min]){
				min = j;
			}
		}
		int temp = myArray[min];
		myArray[min] = myArray[i];
		myArray[i] = temp;
	}
}

int main(int argc, char const *argv[])
{
	int myArray[] = {2,7,4,1,5,3};
	int size = sizeof(myArray) / sizeof(int);
	selectionSort(myArray,size);
	cout << "After Sorting we get: " <<endl;
	for(int i=0;i<size;i++){
		cout << myArray[i] << " ";
	}
	cout << endl;
 	return 0;
}