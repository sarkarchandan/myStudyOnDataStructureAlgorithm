/*
	We have studied that Using Recursive Methods is not always the bright idea. We want to understand why. 
	In this program we are comparing the Iterative method  and Recursive method for finding out the nth Fibonacci no for some considerably
	large input n e.g. n = 40

	We have observed that in our system Iterative method indeed produced the result almost instantaneously whereas Recursive method took
	considerable time to produce the result for some large n.

	What essentially happening here is with respect to a given large numberOfElements value, Iterative method is computing each step sequentially
	and exactly ones. But with respect to the same large input Recursive method is computing each step a number of times which is an overhead
	or redundancy in terms of in terms of running time.

	We will analyze the time complexity of the Recusrive methods and how to get rid of the redundant steps going forward.
*/

#include<stdio.h>

/*
Getting nth Fibonacci no using Iterative method:
*/
int getFactorialWithIteration(int numberOfElements){
	int result;
	if(numberOfElements<=1){
		printf("%d ",numberOfElements);
	}
	int factOne = 1;
	int factTwo = 2;
	printf("%d ",factOne);
	printf("%d ",factTwo);
	for(int i=2;i<=numberOfElements-1;i++){
		result = factOne+factTwo;
		printf("%d ",result);
		factOne = factTwo;
		factTwo = result;		
	}
	printf("\n");
	return result;
}

/*
Getting nth Fibonacci no using Recursive method:
*/
int getFectorialWithRecursion(int numberOfElements){

	if(numberOfElements<=1){
		return 1;
	}
	return getFectorialWithRecursion(numberOfElements-1)+getFectorialWithRecursion(numberOfElements-2);

}

int main(){
	int numberOfElements,resultIterative,resultRecursive;

	printf("Enter the number of elements: ");
	scanf("%d",&numberOfElements);

	printf("Using Iterative Method: \n");
	resultIterative = getFactorialWithIteration(numberOfElements);
	printf("The element with index %d is:  %d\n",numberOfElements,resultIterative);

	printf("Using Recursive Method: \n");
	for (int i=1;i<=numberOfElements;i++){
		printf("%d ",getFectorialWithRecursion(i));
	}
	printf("\n");
	resultRecursive= getFectorialWithRecursion(numberOfElements);
	printf("The element with index %d is:  %d\n",numberOfElements,resultRecursive);
}