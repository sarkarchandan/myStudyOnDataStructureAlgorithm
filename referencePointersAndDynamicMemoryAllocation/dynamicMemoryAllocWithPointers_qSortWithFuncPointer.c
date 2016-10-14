/*
This program demonstrates function pointer using quick sort library function
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
In this compareNumber function we are passing the memory addresses of the numbers as constant pointers.
This means the addresses will not be changed.
However we are passing void pointers because qsort() function expects it's argument accordingly.
qsort can sort any array and not only integer array. We just need to provide the logic for comparision.
*/
int comparNumber(const void* a,const void* b){
	int numberA = *((int*)a);
	int numberB = *((int*)b);
	return numberA-numberB; // Sorting order depends upon this.
	/*
	return postive > ascending
	return negative > descending
	return 0 > do nothing
	*/
}

int main(){
	int myArray[]={-31,22,-1,50,-6,4};
	int size=sizeof(myArray)/sizeof(int);
	int (*ptr)(const void*,const void*);
	ptr=&comparNumber;
	qsort(myArray,size,sizeof(int),ptr);
	// We have could have directly written the function name as well. Function name also return a pointer
	//For instance qsort(myArray,size,sizeof(int),comparNumber);
	printf("Sorted Array is: \n");
	for(int i=0;i<size;i++){
		printf("%d ",myArray[i]);
	}
	printf("\n");
}