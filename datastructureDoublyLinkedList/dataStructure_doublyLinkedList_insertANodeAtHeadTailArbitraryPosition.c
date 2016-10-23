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



int main(){

	struct Node* listHead = NULL; // Pointer to head node of an empty doubly liked list.

	int choice,numberToBeAdded,position;

	printf("*****Welcome to the Implementation of the Doubly Linked list*****\n");
	printf("Choice 1: Insert a node at the beginning.\n");
	printf("Choice 2: Insert a node at the end.\n");
	printf("Choice 3: Insert a node at a given position.\n");
	printf("Choice 4: Print the entire Linked List forward.\n");
	printf("Choice 5: Print the entire Linked List reverse.\n");
	printf("Choice 6: To Exit.\n");



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
			printf("Following is the list so far: \n");
			printListForward(listHead);
			printf("\n");
			break;

		case 5:
			printf("Following is the list so far in reverse order: \n");
			printListReverse(listHead);
			printf("\n");
			break;

		default:
			printf("Have a nice day.\n");
		}

		if(choice < 1 || choice > 5 || choice==6){
			break;
		}

	}while(choice >= 1 || choice<= 5);

}