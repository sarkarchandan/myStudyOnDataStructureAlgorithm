#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

//Insert Node at Head
struct Node* insertNodeAtHead(struct Node** listHead,int element){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = element;

	if((*listHead)==NULL){
		(*newNode).next = NULL;
		(*listHead) = newNode;
	}else{
		(*newNode).next = (*listHead);
		(*listHead) = newNode;
	}
	return (*listHead);
}

//Insert Node at Tail
struct Node* insertNodeAtTail(struct Node** listHead,int element){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = element;
	(*newNode).next = NULL;

	if((*listHead)==NULL){
		(*listHead) = newNode;
	}else{
		struct Node* tempNode = (*listHead);

		while((*tempNode).next!=NULL){
			tempNode = (*tempNode).next;
		}
		(*tempNode).next = newNode;
	}
	return (*listHead);
}

//Insert Node at arbitrary position
struct Node* insertNodeAtArbitraryPosition(struct Node** listHead,int element,int position){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = element;

	if((*listHead)==NULL){
		(*newNode).next = NULL;
		(*listHead) = newNode;
	} else{
		struct Node* tempNode = (*listHead);
		for(int i = 0;i<position-2;i++){
			tempNode = (*tempNode).next;
		}
		(*newNode).next = (*tempNode).next;
		(*tempNode).next = newNode;
	}
	return (*listHead);
}

//Delete Node from Head
struct Node* deleteNodeFromHead(struct Node** listHead){

	if((*listHead)==NULL){
		printf("Invalid Action: List is Empty.\n");
		return (*listHead);
	}else{
		struct Node* tempNode = (*listHead);
		(*listHead) = (*tempNode).next;
		free(tempNode);
	}
	return (*listHead);
}

//Delete Node from Tail
struct Node* deleteNodeFromTail(struct Node** listHead){

	struct Node* tempNode = (*listHead);
	struct Node* previous;

	while((*tempNode).next!=NULL){
		previous = tempNode;
		tempNode = (*tempNode).next;
	}
	(*previous).next = NULL;
	free(tempNode);
	return (*listHead);
}

//Delete Node from Arbitrary Position
struct Node* deleteNodeFromArbitraryPosition(struct Node** listHead,int position){

	struct Node* tempNode = (*listHead);
	for(int i = 0;i<position-2;i++){
		tempNode = (*tempNode).next;
	}
	struct Node* nodeToBeDeleted = (*tempNode).next;
	(*tempNode).next = (*nodeToBeDeleted).next;
	free(nodeToBeDeleted);
	return (*listHead);
}

//Reverse linked list using Iterative method
struct Node* reverseListIterative(struct Node** listHead){

	struct Node *previous,*current,*next;

	if((*listHead)==NULL){
		printf("Invalid Operation. Empty List.\n");
		return (*listHead);
	}else{	
		current = (*listHead);
		previous = NULL;

		while(current!=NULL){
			next = (*current).next;
			(*current).next = previous;
			previous = current;
			current = next;
		}
	}
	(*listHead)=previous;
	return (*listHead);
}

//Print list forward recursive
void forwardPrintRecusrive(struct Node* listHead){

	struct Node* tempNode = listHead;

	if(tempNode==NULL){
		return;
	}
	printf("%d ",(*tempNode).data);
	forwardPrintRecusrive((*tempNode).next);
}

//Print list reverse recursive
void reversePrintRecursive(struct Node* listHead){

	struct Node* tempNode = listHead;

	if(tempNode==NULL){
		return;
	}
	reversePrintRecursive((*tempNode).next);
	printf("%d ",(*tempNode).data);
}

//Native print method
void printList(struct Node* listHead){

	struct Node* tempNode = listHead;
	while(tempNode!=NULL){
		printf("%d ",(*tempNode).data);
		tempNode = (*tempNode).next;
	}
	printf("\n");
}


int main(){
	struct Node* listHead = NULL; // Empty List
	int choice,numberToBeAdded,position;

	printf("*****Welcome to the Implementation of the linked list*****\n");
	printf("Choice 1: Insert a node at the beginning.\n");
	printf("Choice 2: Insert a node at the end.\n");
	printf("Choice 3: Insert a node at a given position.\n");
	printf("Choice 4: Delete the node at the beginning.\n");
	printf("Choice 5: Delete the node at the end.\n");
	printf("Choice 6: Delete a node at a given position.\n");
	printf("Choice 7: Reverse the entire Linked List using iterative method.\n");
	printf("Choice 8: Print the entire Linked List forward using recursive method.\n");
	printf("Choice 9: Print the entire Linked List reverse using recursive method.\n");


	do{
		printf("Enter your choice:\n");
		scanf("%d",&choice);

		switch(choice){
			case 1:
				printf("Enter the element: \n");
				scanf("%d",&numberToBeAdded);
				listHead = insertNodeAtHead(&listHead,numberToBeAdded);
				printList(listHead);
				break;
			case 2:
				printf("Enter the element: \n");
				scanf("%d",&numberToBeAdded);
				listHead = insertNodeAtTail(&listHead,numberToBeAdded);
				printList(listHead);
				break;
			case 3:
				printf("Enter the element: \n");
				scanf("%d",&numberToBeAdded);
				printf("Enter the position: \n");
				scanf("%d",&position);
				listHead = insertNodeAtArbitraryPosition(&listHead,numberToBeAdded,position);
				printList(listHead);
				break;
			case 4:
				printf("Deleting the Node at the beginning.\n");
				listHead = deleteNodeFromHead(&listHead);
				printList(listHead);
				break;
			case 5:
				printf("Deleting the Node at the end.\n");
				listHead = deleteNodeFromTail(&listHead);
				printList(listHead);
				break;
			case 6:
				printf("Enter the position: \n");
				scanf("%d",&position);
				printf("Deleting the specific Node:\n");
				listHead = deleteNodeFromArbitraryPosition(&listHead,position);
				printList(listHead);
				break;
			case 7:
				printf("Reverting the linked list:\n");
				listHead = reverseListIterative(&listHead);
				printList(listHead);
				break;
			case 8:
				printf("Printing the list forward using recursive method.\n");
				forwardPrintRecusrive(listHead);
				printf("\n");
				break;
			case 9:
				printf("Printing the list reverse using recursive method.\n");
				reversePrintRecursive(listHead);
				printf("\n");
				break;
			default:
				printf("Invalid Choice.\n");
		}

		if(choice < 1 || choice > 10){
			break;
		}

	}while(choice >=1 || choice <= 10);
	
}