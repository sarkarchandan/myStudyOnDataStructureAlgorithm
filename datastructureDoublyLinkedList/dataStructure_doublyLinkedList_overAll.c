/*
Basic implementation of a doubly linked list.
*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* previous;
	struct Node* next;	
};

//Create a new node
struct Node* getNewNode(int element){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = element;
	(*newNode).previous = NULL;
	(*newNode).next = NULL;
	return newNode;
}

//Insert a new Node at head
struct Node* insertNodeAtHead(struct Node* listHead,int element){

	struct Node* newNode = getNewNode(element);

	if(listHead==NULL){
		listHead = newNode;
		return listHead;
	}else{
		(*newNode).next = listHead;
		(*listHead).previous = newNode;
		listHead = newNode;
	}
	return listHead;
}

//Insert a new Node at tail
struct Node* insertNodeAtTail(struct Node* listHead,int element){

	struct Node* newNode = getNewNode(element);

	if(listHead==NULL){
		listHead=newNode;
		return listHead;
	}else{
		struct Node* tempNode = listHead;
		while((*tempNode).next!=NULL){
			tempNode = (*tempNode).next;
		}
		(*tempNode).next = newNode;
		(*newNode).previous = tempNode;
	}
	return listHead;
}

//Insert a new Node at an arbitrary position
struct Node* insertNodeAtArbitraryPosition(struct Node* listHead,int element,int position){

	struct Node* newNode = getNewNode(element);

	if(listHead==NULL){
		printf("List is empty. Adding the Node at the head of the list.\n");
		listHead = newNode;
	}else{
		struct Node* tempNode = listHead;
		for(int i =0;i<position-2;i++){
			tempNode = (*tempNode).next;
		}
		struct Node* anotherNode = (*tempNode).next;

		(*newNode).next = (*tempNode).next;
		(*anotherNode).previous = newNode;
		(*tempNode).next = newNode;
		(*newNode).previous = tempNode;
	}
	return listHead;
}

//Delete a Node from the head
struct Node* deleteNodeFromHead(struct Node* listHead){

	struct Node* tempNode = listHead;

	if(listHead==NULL){
		return listHead;
	}else{
		struct Node* secondNode = (*tempNode).next;
		listHead = secondNode;
		(*secondNode).previous=NULL;
		free(tempNode);
	}
	return listHead;
}

//Delete a Node from the tail 
struct Node* deleteNodeFromTail(struct Node* listHead){

	struct Node* tempNode = listHead;
	if(listHead==NULL){
		return listHead;
	}else{
		while((*tempNode).next!=NULL){
			tempNode = (*tempNode).next;
		}
		struct Node* secondLastNode = (*tempNode).previous;
		(*secondLastNode).next = NULL;
		free(tempNode);
	}	
	return listHead;
}


//Delete a Node from given position
struct Node* deleteNodeFromPosition(struct Node* listHead,int position){

	struct Node* tempNode = listHead;

	if(listHead==NULL){
		return listHead;
	}else{
		for(int i =0;i<position-2;i++){
		tempNode = (*tempNode).next;
		}
		struct Node* nodeTobeDeleted = (*tempNode).next;
		struct Node* nextNodeTotheposition = (*nodeTobeDeleted).next;
		(*tempNode).next = nextNodeTotheposition;
		(*nextNodeTotheposition).previous = tempNode;
		free(nodeTobeDeleted);
	}
	return listHead;	
}

//Print list forward
void printListForward(struct Node* listHead){

	struct Node* tempNode = listHead;
	while(tempNode!=NULL){
		printf("%d ",(*tempNode).data);
		tempNode = (*tempNode).next;
	}
	printf("\n");
}

//Print list reverse
void printListReverse(struct Node* listHead){

	struct Node* tempNode = listHead;
	while((*tempNode).next!=NULL){
		tempNode=(*tempNode).next;
	}
	while(tempNode!=NULL){
		printf("%d ",(*tempNode).data);
		tempNode = (*tempNode).previous;
	}
	printf("\n");
}

//Print reverse recursively
void printReverseRecusrive(struct Node* listHead){

	struct Node* tempNode = listHead;

	if(listHead==NULL || tempNode==NULL){
		return;
	}
	printReverseRecusrive((*tempNode).next);
	printf("%d ", (*tempNode).data);
}



int main(){

	struct Node* listHead = NULL; // Pointer to head node of an empty doubly liked list.

	int choice,numberToBeAdded,position;

	printf("*****Welcome to the Implementation of the Doubly Linked list*****\n");
	printf("Choice 1: Insert a node at the beginning.\n");
	printf("Choice 2: Insert a node at the end.\n");
	printf("Choice 3: Insert a node at a given position.\n");

	printf("Choice 4: Delete a node from head.\n");
	printf("Choice 5: Delete a node from tail.\n");
	printf("Choice 6: Delete a node from a given position.\n");

	printf("Choice 7: Print the entire Linked List forward.\n");
	printf("Choice 8: Print the entire Linked List reverse.\n");
	printf("Choice 9: Print the entire Linked List reverse recursively.\n");
	printf("Choice 0: To Exit.\n");



do{
	printf("Enter your choice: \n");
	scanf("%d",&choice);

	switch(choice){
		case 1:
			printf("Enter the element: ");
			scanf("%d",&numberToBeAdded);
			listHead =  insertNodeAtHead(listHead,numberToBeAdded);
			printListForward(listHead);
			printf("\n");
			break;
		
		case 2:
			printf("Enter the element: ");
			scanf("%d",&numberToBeAdded);
			listHead = insertNodeAtTail(listHead,numberToBeAdded);
			printListForward(listHead);
			printf("\n");
			break;

		case 3:
			printf("Enter the element: ");
			scanf("%d",&numberToBeAdded);
			printf("Enter the position: \n");
			scanf("%d",&position);
			listHead = insertNodeAtArbitraryPosition(listHead,numberToBeAdded,position);
			printListForward(listHead);
			printf("\n");
			break;

		case 4:
			printf("Deleting the node from the head: \n");
			listHead = deleteNodeFromHead(listHead);
			printListForward(listHead);
			printf("\n");
			break;

		case 5:
			printf("Dleting the node from the tail: \n");
			listHead = deleteNodeFromTail(listHead);
			printListForward(listHead);
			printf("\n");
			break;

		case 6:
			printf("Enter the position: \n");
			scanf("%d",&position);
			printf("Deleting the node from the %d position: \n",position);
			listHead = deleteNodeFromPosition(listHead,position);
			printListForward(listHead);
			printf("\n");
			break;

		case 7:
			printf("Following is the list so far: \n");
			printListForward(listHead);
			printf("\n");
			break;

		case 8:
			printf("Following is the list so far in reverse order: \n");
			printListReverse(listHead);
			printf("\n");
			break;

		case 9:
			printf("Printing the list reverse in recursive method: \n");
			printReverseRecusrive(listHead);
			printf("\n");
			break;

		default:
			printf("Have a nice day.\n");
		}

		if(choice < 1 || choice > 9 || choice==0){
			break;
		}

	}while(choice >= 1 || choice<= 9);

}