#include<stdio.h>

// Reverse a character array.
char* reverseCharArray(char* myArray,int length){

	int i=0;
	int j = length;
	char temp;
	while(i<j){
		temp = *(myArray+i);
		*(myArray+i) = *(myArray+j);
		*(myArray+j) = temp;
		i++;
		j--;
	}
	return myArray;

}

int main(){

	char *myArray;
	char element;
	int i=0;

	while(element!='#')	{
		printf("Enter the character:--");
		scanf(" %c",&element);
		if(element!='#'){
			*(myArray+i)=element;	
		}
		i++;
	}
	for(int j=0;j<=i;j++){
		printf("%c",*(myArray+j));
	}
	printf("\n");
	myArray = reverseCharArray(myArray,i);
	printf("Following is the array reversed: \n");
	
	for(int k=0;k<=i;k++){
		printf("%c",*(myArray+k));
	}
	printf("\n");

}