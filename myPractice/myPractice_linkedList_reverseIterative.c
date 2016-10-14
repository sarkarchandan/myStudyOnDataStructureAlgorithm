#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* insertAtTail(struct Node** listHead,int number){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	(*newNode).data = number;
	(*newNode).next = NULL;

	if((*listHead) ==NULL){
		(*listHead) = newNode;
	}else
	{
		struct Node* tempNode = (*listHead);

		while((*tempNode).next != NULL){
			tempNode = (*tempNode).next;
		}
		(*tempNode).next = newNode;
	}
	return (*listHead);
}

struct Node* reverseList(struct Node** listHead){

	struct Node *previous,*next,*current;

	current = (*listHead);
	previous = NULL;

	while(current!=NULL){
		next = (*current).next;
		(*current).next = previous;
		previous = current;
		current = next;
	}
	(*listHead) = previous;
	return (*listHead);
}

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
	int numberOfElements;
	printf("Enter the no of elements in the list: \n");
	scanf("%d",&numberOfElements);
	for(int i=1;i<=numberOfElements;i++){
		listHead = insertAtTail(&listHead,i);
	}
	printList(listHead);
	printf("Following is the list reveresed:  \n");
	listHead = reverseList(&listHead);
	printList(listHead);

	printf("Following is the list reveresed:  \n");
	listHead = reverseList(&listHead);
	printList(listHead);

	printf("Following is the list reveresed:  \n");
	listHead = reverseList(&listHead);
	printList(listHead);
}	