#include<stdio.h>
#include<stdlib.h>

// Creating the Node datatype
struct Node{
	int data;
	struct Node* next;
};

//Insert a Node at the end of the linked list.
struct Node* insertNodeAtEnd(struct Node** listHead,int inputElement){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = inputElement;
	(*newNode).next = NULL;

	if(*listHead==NULL){
		(*listHead)=newNode;
	}else{
		struct Node* tempPointer = (*listHead);

		while((*tempPointer).next!=NULL){
			tempPointer=(*tempPointer).next;
		}
	(*tempPointer).next = newNode;
	}
	return (*listHead);
}

// Print the current element of the linked list.
void printList(struct Node* listHead){

	while(listHead!=NULL){
		printf("%d ",(*listHead).data);
		listHead = (*listHead).next;
	}
	printf("\n");

}

// Delete a node from a given position
struct Node* deleteNodeAtGivenPosition(struct Node** listHead,int deletePosition){

	struct Node* tempHead = (*listHead);
	if(deletePosition==1){
		(*listHead)=(*tempHead).next;
		free(tempHead);
	}else{
		for(int i=0;i<deletePosition-2;i++){
			tempHead=(*tempHead).next;
		}
		struct Node* tempNodeToDelete = (*tempHead).next;
		(*tempHead).next=(*tempNodeToDelete).next;
		free(tempNodeToDelete);
	}
	return(*listHead);

}

int main(){

	// Declaring the pointer to node as list head and initializing as NULL. That means it points to an empty list. 
	struct Node* listHead = NULL;

	int noOfElements,deletePosition,inputElement;
	printf("Enter the No Of Elements in the List: \n");
	scanf("%d",&noOfElements);

	for(int i = 0;i<noOfElements;i++){
		printf("Enter the element to insert at the end of the list: \n");
		scanf("%d",&inputElement);
		listHead = insertNodeAtEnd(&listHead,inputElement);
		printList(listHead);
	}

	printf("Enter the Node index you want to delete from the List: \n");
	scanf("%d",&deletePosition);
	listHead = deleteNodeAtGivenPosition(&listHead,deletePosition);
	printList(listHead);

}
