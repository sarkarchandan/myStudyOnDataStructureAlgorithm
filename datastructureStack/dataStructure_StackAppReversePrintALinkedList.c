/*
In this implementation, we are just printing the elements of a linked list in reverse order using a stack.
Original list is not being reverted.
*/

#include<stdio.h>
#include<stdlib.h>

//Node datatype.
struct Node{
	int data;
	struct Node* next;
};

//Stack datatype.
struct Stack{
	struct Node* node;
	struct Stack* next; 
};

//Create a new Node of the linked list.
struct Node* getNewListNode(int element){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = element;
	(*newNode).next = NULL;
	return newNode;
}

//Create a new Node for the Stack
struct Stack* getNewStackNode(struct Node* listNode){

	struct Stack* newStackNode = (struct Stack*)malloc(sizeof(struct Stack));
	(*newStackNode).node = listNode;
	(*newStackNode).next = NULL;
	return newStackNode;
}



//Insert New Node
struct Node* insertNodeAtEnd(struct Node* head,int element){

	struct Node* newNode = getNewListNode(element);

	if(head==NULL){
		head = newNode;
		return head;
	}else{
		struct Node* tempNode = head;
		while((*tempNode).next!=NULL){
			tempNode = (*tempNode).next;
		}
		(*tempNode).next = newNode;
	}
	return head;
}

//Push operation for stack
struct Stack* Push(struct Stack* topOfStack,struct Node* node){

	struct Stack* newStackNode = getNewStackNode(node);

	if(topOfStack==NULL){
		topOfStack = newStackNode;
		return topOfStack;
	}else{
		(*newStackNode).next = topOfStack;
		topOfStack = newStackNode;
	}
	return topOfStack;
}

//Pop operation for stack
struct Stack* Pop(struct Stack* topOfStack){

	struct Stack* tempStackNode = topOfStack;
	if(topOfStack==NULL){
		printf("Stack Underflow !!!! Operation not permitted....\n");
		return topOfStack;
	}else{
		topOfStack = (*tempStackNode).next;
		free(tempStackNode);
	}
	return topOfStack;
}

//Top operation for the stack
struct Node* Top(struct Stack* topOfStack){

	if(topOfStack==NULL){
		printf("Stack Underflow !!!! Operation not permitted....\n");
	}else{
		return (*topOfStack).node;
	}
}


//isEmpty check for stack
int isEmpty(struct Stack* topOfStack){
	if(topOfStack==NULL){
		return 0;
	}else{
		return 1;
	}
}

//Revert operation for linked list
struct Stack* reverseList(struct Stack* topOfStack,struct Node* head){

	struct Node* tempListNode = head;

	while(tempListNode!=NULL){
		topOfStack = Push(topOfStack,tempListNode);
		tempListNode = (*tempListNode).next;
	}

	//At this point all our linked list nodes are pushed to Stack

	while(isEmpty(topOfStack)==1){
		struct Node* node = Top(topOfStack);
		printf("%d ",(*node).data);
		topOfStack = Pop(topOfStack);
	}
	return topOfStack;
}

//Print the linked list.
void printList(struct Node* head){

	struct Node* tempNode = head;
	while(tempNode!=NULL){
		printf("%d ",(*tempNode).data);
		tempNode = (*tempNode).next;
	}
	printf("\n");
}


int main(){

	struct Node* listHead = NULL;// Empty List
	struct Stack* topOfStack = NULL;//Empty Stack

	int numberOfElements,element;

	printf("Enter the no of elements in the linked list: ");
	scanf("%d",&numberOfElements);

	for(int i=0;i<numberOfElements;i++){
		printf("Enter the number: \n");
		scanf("%d",&element);
		listHead = insertNodeAtEnd(listHead,element);
	}
	printf("\n");
	printList(listHead);

	printf("We are going to print the list element reverse using the stack....\n");
	printf("Folowing is the list printed in reverse: \n");

	topOfStack = reverseList(topOfStack,listHead);
	printf("\n");

}