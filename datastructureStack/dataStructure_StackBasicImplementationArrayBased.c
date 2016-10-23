//Basic implementation of Stack.

#include<stdio.h>

#define MAX_SIZE 10

int Stack[MAX_SIZE];
int topOfStack = -1;


//Push element to stack
void Push(int element){

	if(topOfStack==(MAX_SIZE-1)){
		printf("Stack Overflow !!!. Current Stack is: \n");
	}else{
		topOfStack++;
		Stack[topOfStack]=element;
	}
}

//Pop element from Stack
void Pop(){

	if(isEmpty() == 0){
		printf("Stack Underflow !!!\n");
	}else{
		topOfStack--;
	}

}

//Return the top element of the stack
int Top(){

	if(isEmpty() == 0){
		printf("Stack Underflow !!!\n");
	}else{
		return Stack[topOfStack];
	}

}

//Check if stack is empty
int isEmpty(){

	if(topOfStack==-1){
		return 0;
	}else{
		return 1;
	}
}

//Print the stack
void printStack(){

	for(int i=0;i<=topOfStack;i++){
		printf("%d ", Stack[i]);
	}
	printf("\n");
}

int main(){

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
				Push(element);
				printStack();
				break;
			case 2:
				printf("Here you go...\n");
				Pop();
				printStack();
				break;
			case 3:
				printf("Top element of our Stack is: \n");
				int data = Top();
				printf("%d\n",data);
				break;
			case 4:
				printf("Here you go: Our current Stack: \n");
				printStack();
				break;
			default:
				printf("Have a nice day.\n");
			}

			if(choice < 1 || choice > 4 || choice ==0){
				break;
			}

	}while(choice >= 1 || choice <= 4);

}




