// Basic Implementation of a doubly linked list.

#include<stdio.h>
#include<stdlib.h>

//Declaration for doubly linked list.
struct Node{
	int data;
	struct Node* previous;
	struct Node* next;
};

//Cretae new Node and return the pointer to Node
struct Node* getNewNode(int element){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = element;
	(*newNode).previous = NULL;
	(*newNode).next = NULL;
	return newNode;
}

//Insert a node at the head position for a doubly linked list.
struct Node* insertAtDoublyHead(struct Node* listHead,int element){

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

//Print the doubly linked list forward Iterative method
void printDoublyForward(struct Node* listHead){

	struct Node* tempNode = listHead;

	while(tempNode!=NULL){
		printf("%d ",(*tempNode).data);
		tempNode = (*tempNode).next;
	}
	printf("\n");
}

//Print the doubly linked list reverse Iterative method
void printDoublyReverse(struct Node* listHead){

	struct Node* tempNode = listHead;
	while((*tempNode).next!=NULL){
		tempNode = (*tempNode).next;
	}
	while(tempNode!=NULL){
		printf("%d ",(*tempNode).data);
		tempNode = (*tempNode).previous;
	}
	printf("\n");
}

int main(){

	struct Node* listHead = NULL; //pointer to head to empty doubly linked list

	printf("Enter the No of elements you want in the list: \n");
	int numberOfElements,element;
	scanf("%d",&numberOfElements);

	for(int i=0;i<numberOfElements;i++){
		printf("Enter the element: \n");
		scanf("%d",&element);
		listHead = insertAtDoublyHead(listHead,element);
		printDoublyForward(listHead);
	}
	printf("\n");
	printf("Printing the List Forward: \n");
	printDoublyForward(listHead);
	printf("\n");
	printf("Printing the List Reverse: \n");
	printDoublyReverse(listHead);
	printf("\n");

}