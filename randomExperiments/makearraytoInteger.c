#include<stdio.h>
#include<math.h>

int main(){

	int myArray[] = {1,2,3,4,5};
	int result=0;
	int arraySize = (sizeof(myArray)/sizeof(int));
	
	int count = arraySize-1;
		for(int j=0;j<arraySize;j++){
			if(count>=0)
			result = (result+ (myArray[j]*(int)pow(10,count)));
			count--;
		}
	printf("The Number is: %d\n",result);

}