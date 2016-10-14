/*
This program is first demonstration of the basic ideas of dynamic memory allocation.
*/

#include<stdio.h>
#include<stdlib.h>

int main(){

	int n;
	printf("Enter the desired size of an integer array: \n");
	scanf("%d",&n);

	/*
	We are dynamically allocating memory for our integer array here.
	Functions for dynamic memory allocation always returns a void pointer. Hence in order to operate on that pointer
	we have to use type casting which we have done here for integer
	*/
	int* myArray = (int *)malloc(n*sizeof(int));

	/*
	malloc does not initializes the dynamically allocated memory. Hence typically those memory
	locations contain garbage valude before te value assignment.
	*/

	printf("Demonstarting 'malloc'>>>>>\n");
	printf("This is your array created with malloc before value assignment: \n");
	printf("Values here are basically garbage values. But again it depends on the environment.\n");
	printf("In our linux environment probably the default implementation in calloc\n");
	for(int l=0;l<n;l++){
		printf("%d ",*(myArray+l));
	}
	printf("\n");

	/*
	We are assigning the values to the array
	*/
	for(int i=0;i<n;i++){
		*(myArray+i)=i+1;
	}

	printf("Following is your array created with malloc after value assignment: \n");
	for(int j=0;j<n;j++){
		printf("%d ",*(myArray+j));
	}
	printf("\n");
	printf("\n");
	printf("\n");

	/*
	As a programmer it's our best practice to free the memory after user.
	We adjust the pointer to null after freeing the memory.
	*/
	//free(myArray);
	//myArray = NULL;

	/*
	Here we are going to see how realloc works. We want to extend the myArray to double of it's present size.
	realloc may work in different ways such as:
		> If the space is available in the contiguous memory blocks with respect to the array that we want to extend, then realloc
		extends the same array to double size.
		> If the space is not available, realloc blocks required amount of memory somewhere else and copies the elemnts from the
		previous array to the newly allocated memory location and deallocates the previously allocated memory locations.

	*/
	printf("Demonstarting 'realloc'>>>>>\n");
	printf("Now we are will try to extend the array to be of double of it's previous size.\n");
	int *extendedArray = (int *)realloc(myArray,2*n*sizeof(int));
	printf("The previously allocated base address was: %d, Base address of the new extended array is: %d\n",myArray,extendedArray);

	printf("Following is the new extended array of double size: \n");
	for(int m=0;m<2*n;m++){
		printf("%d ",*(extendedArray+m));
	}
	printf("\n");
	printf("\n");
	printf("\n");
	//int *extendedArray = (int *)realloc(myArray,0); // This statement is equivalent to calling free(myArray);
	//int * myArray = (int *)realloc(myArray,2*n*sizeof(myArray));// This is also possible if we want the same array to be extended.
	//int * extendedArray = (int *)realloc(NULL,2*n*sizeof(myArray)); // This is equivalent of calling a malloc function where an inetger
	//array of the twice the size of input value will be allocated.



	/*
	We can test how calloc works in this program itself. Difference between malloc and calloc is in the arguments they take.
	calloc expects two arguments which are the number of elements of a given datatype and the size of the given datatype.
	calloc also typically initializes the dynamically allocated memory with zero.
	*/

	int* myUninitializedArray = (int *)calloc(n,sizeof(int));

	printf("Demonstarting 'calloc'>>>>>\n");
	printf("Following is the uninitialized array created with calloc\n");
	printf("As we can see calloc initializes the allocated memory with zero\n");

	for(int k=0;k<n;k++){
		printf("%d ",*(myUninitializedArray+k));
	}
	printf("\n");

	/*
	As a programmer it's our best practice to free the memory after user.
	We adjust the pointer to null after freeing the memory.
	*/
	//free(myUninitializedArray);
	//myUninitializedArray = NULL;

}