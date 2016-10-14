#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

// Insert new Node at the end of the list.
struct Node* insertElementAtEnd(struct Node** listHead,int number){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = number;
	(*newNode).next = NULL;

	if((*listHead)==NULL){
		(*listHead)=newNode;
	}else{
		struct Node* tempNode = (*listHead);
		while((*tempNode).next!=NULL){
			tempNode = (*tempNode).next;
		}
		(*tempNode).next = newNode;
	}
	return (*listHead);
}

// Print the list.
void printList(struct Node** listHead){
	
	struct Node* tempNode = (*listHead);
	
	while(tempNode != NULL){
		printf("%d ",(*tempNode).data);
		tempNode = (*tempNode).next;
	}
	printf("\n");
}

// Reverese the linked list.
struct Node* reverseListIterative(struct Node** listHead){

	struct Node *previousNode,*currentNode,*nextNode;
	currentNode = (*listHead);
	previousNode = NULL;

	/*
	This is very crucial that we iterate the loop in the below mentioned fashion. Because we want the control to reach to the last node.
	If we iterate the loop e.g. (*currentNode).next != NULL , control will not reach to last node. Because we are assigning the address of
	the nextNode to currentNode. Hence previousNode will point to second last Node, (*currentNode).next will refer to NULL. Loop condition
	will fail.
	*/
	while(currentNode!=NULL){

		nextNode = (*currentNode).next;
		(*currentNode).next = previousNode;
		previousNode = currentNode;
		currentNode = nextNode;
	}
	(*listHead) = previousNode;
	return (*listHead);

}



int main(){

	struct Node* listHead = NULL; // Empty List

	int inputElement,numberOfElements;

	printf("Enter the no of elements in the list: \n");
	scanf("%d",&numberOfElements);
	for(int i=0;i<numberOfElements;i++){
		printf("Enter the element: \n");
		scanf("%d",&inputElement);

		listHead = insertElementAtEnd(&listHead,inputElement);
		printList(&listHead);
	}
		printf("\n");
		printf("\n");
		printf("Following is the list reversed: \n");
		listHead = reverseListIterative(&listHead);
		printList(&listHead);

}