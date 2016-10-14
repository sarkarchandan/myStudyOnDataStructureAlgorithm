#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

//Insert a node at the end of the list.
struct Node* insertNodeAtTail(struct Node* listHead, int element){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = element;
	(*newNode).next = NULL;

	if(listHead==NULL){
		listHead=newNode;
	}else{
		struct Node* tempNode = listHead;
		while((*tempNode).next!=NULL){
			tempNode = (*tempNode).next;
		}
		(*tempNode).next = newNode;
	}
	return listHead;
}

//Revert the Linked list using recursion.

struct Node* revertUsingRecursion(struct Node* listHead){

	if(listHead == NULL || (*listHead).next == NULL){
		return listHead;
	}
	struct Node* restOfTheList = revertUsingRecursion((*listHead).next);
	struct Node* pointer = (*listHead).next;
	(*pointer).next = listHead;
	(*listHead).next = NULL;
	return restOfTheList;
}


// Naive forward print using Recursion.
void printList(struct Node* listHead){

	if(listHead==NULL){
		return;
	}
	printf("%d ",(*listHead).data);
	printList((*listHead).next);
}

int main(){

	struct Node* listHead = NULL;

	int numberOfElements;
	printf("Enter the no of elements that you want: \n");
	scanf("%d",&numberOfElements);

	for(int i=1;i<=numberOfElements;i++){

		listHead = insertNodeAtTail(listHead,i);
	}
	printf("\n");
	printf("Linked List: \n");
	printList(listHead);
	printf("\n");


	printf("Reverting the List using Recursive method: \n");
	listHead = revertUsingRecursion(listHead);

	printList(listHead);
	printf("\n");

}