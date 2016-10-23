/*
In this Implementation we are using Stack to revert a String.
*/
#include<stdlib.h>
#include<iostream>

using namespace std;

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
bool isEmpty(struct Node* topOfStack){
	if(topOfStack==NULL){
		return true;
	}else{
		return false;
	}
}

void getReversedString(struct Node* topOfStack,string myString){

	for(int i=0;j<myString.length();j++){
		topOfStack = Push(topOfStack,*(myArray+i));
	}

	while(isEmpty(topOfStack)==false){
		cout << Top(topOfStack);
		topOfStack = Pop(topOfStack);
	}
}

int main(){

	struct Node* topOfStack = NULL; // Empty Stack.
	
	/* This is one way but we have tried to implement in a better way.
	char *myArray;
	char element;
	int numberOfChar;
	printf("Enter the no of characters in your string: \n");
	scanf("%d",&numberOfChar);
	printf("\n");
	for (int i=0;i<numberOfChar;i++){
		printf("Enter te character: \n");
		scanf(" %c",&element);
		*(myArray+i)=element;
	}
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
	*/
	/* This is another way but we have something else in mind
	printf("\n");
	printf("Enter your String by individual characters and enter 0 when you are done...\n");
	printf("\n");
	char *myArray;
	int i=0;
	char element;
	while(element!='#'){
		printf("Enter te character: \n");
		scanf(" %c",&element);
		if(element!='#'){
			*(myArray+i) = element;	
		}
		i++;
	}
	printf("\n");
	printf("Following is the string: \n");
	for(int j=0;j<i;j++){
		printf("%c", *(myArray+j));
	}
	printf("\n");
	printf("\n");
	printf("We are using the stack to revert the string here...\n");
	printf("Following is the String reverted: \n");
	getReversedArray(topOfStack,myArray,i);
	printf("\n");
	printf("\n");
	*/

	string expression;
	cout << "Enter the string: " << endl;
	cin >> expression;

	cout << "We are using the stack to revert the string here..." << endl;
	cout << "Following is the String reverted:" << endl;
	getReversedString(topOfStack,expression);
	cout << endl;

}