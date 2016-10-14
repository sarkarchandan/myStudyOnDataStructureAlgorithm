#include<stdio.h>
#include<stdlib.h>

//creating the datatype;
struct Node{
	int data;
	struct Node* next;
};

// Insert Node at the beginning.
struct Node* insertNodeAtHead(struct Node** listHead,int element){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = element;
	(*newNode).next = (*listHead);
	(*listHead) = newNode;
	return (*listHead);
}

// Insert Node at the end.
struct Node* insertNodeAtTail(struct Node** listHead, int element){
	
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = element;
	(*newNode).next = NULL;

	struct Node* tempNode = (*listHead);
	while((*tempNode).next != NULL){
		tempNode = (*tempNode).next;
	}

	(*tempNode).next = newNode;
	return (*listHead);
}

// Insert Node at the given position.
struct Node* insertNodeAtGivenPosition(struct Node** listHead, int element,int position){
	
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = element;

	if(position==1){
		(*newNode).next = (*listHead);
		(*listHead) = newNode;
	}else{
		struct Node* tempNode = (*listHead);

		for(int i=0;i<position-2;i++){
			tempNode = (*tempNode).next;
		}

		(*newNode).next = (*tempNode).next;
		(*tempNode).next = newNode;
	}
	return (*listHead);
}

// Delete from the beginning.
struct Node* deleteNodeFromHead(struct Node** listHead){

	struct Node* tempNode = (*listHead);
	(*listHead) = (*tempNode).next;
	free(tempNode);
	return (*listHead);
}

// Delete from the end.
struct Node* deleteNodeFromTail(struct Node** listHead){

	struct Node* tempNode = (*listHead);
	struct Node* previoustoEnd;
	while((*tempNode).next != NULL){
		previoustoEnd = tempNode;
		tempNode = (*tempNode).next;
	}
	(*previoustoEnd).next = NULL;
	free(tempNode);
	return (*listHead);
}

// Delete from a given position.
struct Node* deleteNodeFromGivenPosition(struct Node** listHead,int position){

	struct Node* tempNode = (*listHead);
	if(position==1){
		(*listHead) = (*tempNode).next;
		free(tempNode);
	}else{
		for(int i=0;i<position-2;i++){
			tempNode = (*tempNode).next;
		}
		struct Node* delNode = (*tempNode).next;
		(*tempNode).next = (*delNode).next;
		free(delNode);
	}
	return (*listHead);
}

// Print the current state of the list.
void printList(struct Node** listHead){

	struct Node* tempNode = (*listHead);
	while(tempNode != NULL){
		printf("%d ",(*tempNode).data);
		tempNode = (*tempNode).next;
	}
	printf("\n");
}



int main(){

	struct Node* listHead = NULL; //Empty List

	int choice;

	printf("*****Welcome to the Implementation of the linked list*****\n");
	printf("Choice 1: Insert a node at the beginning.\n");
	printf("Choice 2: Insert a node at the end.\n");
	printf("Choice 3: Insert a node at a given position.\n");
	printf("Choice 4: Delete the node at the beginning.\n");
	printf("Choice 5: Delete the node at the end.\n");
	printf("Choice 6: Delete a node at a given position.\n");


	do{
		printf("Enter your choice: \n");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				printf("Enter the element to insert at the beginning: \n");
				int elementB;
				scanf("%d",&elementB);
				listHead = insertNodeAtHead(&listHead,elementB);
				printList(&listHead);
				break;
			case 2:
				printf("Enter the element to insert at the end: \n");
				int elementE;
				scanf("%d",&elementE);
				listHead = insertNodeAtTail(&listHead,elementE);
				printList(&listHead);
				break;
			case 3:
				printf("Enter the element to insert at the position: \n");
				int elementP,iPosition;
				scanf("%d",&elementP);
				printf("Enter the Position: \n");
				scanf("%d",&iPosition);
				listHead = insertNodeAtGivenPosition(&listHead,elementP,iPosition);
				printList(&listHead);
				break;
			case 4:
				printf("Deleteing the Node from the beginning.\n");
				listHead = 	deleteNodeFromHead(&listHead);
				printList(&listHead);
				break;
			case 5:
				printf("Deleteing the Node from the end.\n");
				listHead = deleteNodeFromTail(&listHead);
				printList(&listHead);
				break;
			case 6:
				printf("Enter the position for deleting a node: \n");
				int dPosition;
				scanf("%d",&dPosition);
				listHead = deleteNodeFromGivenPosition(&listHead,dPosition);
				printList(&listHead);
				break;
			default:
				printf("Your choice is invalid. Enter valid choice.\n");

		}
		if(choice < 1 || choice > 6 ){
			break;
		}
	}while(choice >= 1 || choice <= 6);

}