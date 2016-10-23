/*
In this Implementation we are using Stack to revert a String.
*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
	char data;
	struct Node* next;
};

//Create a new Node
struct Node* getNewNode(char element){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = element;
	(*newNode).next = NULL;
	return newNode;
}

//Push an element to the Stack
struct Node* Push(struct Node* topOfStack,char element){

	struct Node* newNode = getNewNode(element);

	if(topOfStack==NULL){
		topOfStack = newNode;
		return topOfStack;
	}else{
		(*newNode).next = topOfStack;
		topOfStack = newNode;
	}
	return topOfStack;
}

//Pop an element from the Stack
struct Node* Pop(struct Node* topOfStack){

	if(topOfStack==NULL){
		printf("Stack Underflow...\n");
		return topOfStack;
	}else{
		struct Node* nodeTobeDeleted = topOfStack;
		topOfStack = (*nodeTobeDeleted).next;
		free (nodeTobeDeleted);
	}
	return topOfStack;
}

//Return the Top of Stack
char Top(struct Node* topOfStack){

	struct Node* tempNode = topOfStack;

	if(topOfStack==NULL){
		printf("Stack Underflow...\n");
		return 0;
	}else{
		return (*tempNode).data;
	}
}

//Checks if the Stack is empty.
int isEmpty(struct Node* topOfStack){
	if(topOfStack==NULL){
		return 0;
	}else{
		return 1;
	}
}

void getReversedArray(struct Node* topOfStack,char* myArray,int arrayLength){

	for(int j=0;j<arrayLength;j++){
		topOfStack = Push(topOfStack,*(myArray+j));
	}

	while(isEmpty(topOfStack)==1){
		printf("%c",Top(topOfStack));
		topOfStack = Pop(topOfStack);
	}
}

int main(){

	struct Node* topOfStack = NULL; // Empty Stack.
	
	
	char myArray[]="hello world";
	char element;
	int numberOfChar;
	
	//printf("Enter the expression: \n");
	//scanf("%s",myArray);
	numberOfChar = sizeof(myArray)/sizeof(char);

	printf("Following is the string: \n");
	for(int j=0;j<numberOfChar;j++){
		printf("%c ", *(myArray+j));
		topOfStack = Push(topOfStack,*(myArray+j));
	}
	printf("\n");

	printf("Following is the string reversed: \n");

	while(topOfStack!=NULL){
		printf("%c ", Top(topOfStack));
		topOfStack = Pop(topOfStack);
	}
	printf("\n");
	
}