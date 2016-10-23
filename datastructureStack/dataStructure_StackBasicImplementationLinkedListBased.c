/*
This is a Linked List based implementation of Stack.
*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

//Create a new Node
struct Node* getNewNode(int element){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = element;
	(*newNode).next = NULL;
	return newNode;
}

//Push an element to the Stack
struct Node* Push(struct Node* topOfStack,int element){

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
int Top(struct Node* topOfStack){

	struct Node* tempNode = topOfStack;

	if(topOfStack==NULL){
		printf("Stack Underflow...\n");
		return 0;
	}else{
		return (*tempNode).data;
	}
}

//Print the Stack
void printStack(struct Node* topOfStack){

	struct Node* tempNode = topOfStack;

	while(tempNode!=NULL){
		printf("%d ",(*tempNode).data);
		tempNode = (*tempNode).next;
	}
	printf("\n");
}


int main(){

	struct Node* topOfStack = NULL; // Empty Stack.

	printf("*****Welcome to the Implementation of Stack*****\n");
	printf("Choice 1: Push an element to Stack.\n");
	printf("Choice 2: Pop an element from Stack.\n");
	printf("Choice 3: Get the top element of the Stack.\n");
	printf("Choice 4: Print the current Stack.\n");
	printf("Choice 0: Exit.\n");
	
	int choice,element;

	do{

	printf("Enter your Choice: \n");
	scanf("%d",&choice);

		switch(choice){
			case 1:
				printf("Enter the element that you want to push to stack: \n");
				scanf("%d",&element);
				topOfStack = Push(topOfStack,element);
				printStack(topOfStack);
				break;
			case 2:
				printf("Here you go...\n");
				topOfStack = Pop(topOfStack);
				printStack(topOfStack);
				break;
			case 3:
				printf("Top element of our Stack is: \n");
				int data = Top(topOfStack);
				printf("%d\n",data);
				break;
			case 4:
				printf("Here you go: Our current Stack: \n");
				printStack(topOfStack);
				break;
			default:
				printf("Have a nice day.\n");
			}

			if(choice < 1 || choice > 4 || choice ==0){
				break;
			}

	}while(choice >= 1 || choice <= 4);



}