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

// Recursively Print the list forward.
void recursivePrintFwd(struct Node* listHead){
	
	struct Node* tempNode = listHead;

	if(tempNode==NULL){
		return;
	}
	printf("%d ",(*tempNode).data);
	recursivePrintFwd((*tempNode).next);

}

// Recursively Print the list reverse.
void recursivePrintRev(struct Node* listHead){
	
	struct Node* tempNode = listHead;

	if(tempNode==NULL){
		return;
	}
	recursivePrintRev((*tempNode).next);
	printf("%d ",(*tempNode).data);

}

int main(){

	struct Node* listHead = NULL; // Empty List

	int numberOfElements;

	printf("Enter the no of elements in the list: \n");
	scanf("%d",&numberOfElements);
	for(int i=1;i<=numberOfElements;i++){

		listHead = insertElementAtEnd(&listHead,i);
	}
		printf("Printing the list Forward:\n");
		recursivePrintFwd(listHead);
		printf("\n");

		printf("Printing the list Reverse:\n");
		recursivePrintRev(listHead);
		printf("\n");
}