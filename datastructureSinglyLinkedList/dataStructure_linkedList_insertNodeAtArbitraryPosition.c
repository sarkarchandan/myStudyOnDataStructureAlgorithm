#include<stdio.h>
#include<stdlib.h>

/*
Creating the Node data type
*/
struct Node{
	int data;
	struct Node* next;
};

void insertAtTheBegining(struct Node** listHead,int inputElement){

	struct Node* tempNode = (struct Node*)malloc(sizeof(struct Node));

	(*tempNode).data = inputElement;
	(*tempNode).next = *listHead;
	*listHead = tempNode;
}

void insertAtPosition(struct Node** listHead,int newNumber,int positionToInsert){
	
	struct Node* tempNode = (struct Node*)malloc(sizeof(struct Node));
	(*tempNode).data = newNumber;
	(*tempNode).next = NULL;
	if(positionToInsert==0){
		insertAtTheBegining(listHead,newNumber);
	}else{
		struct Node* tempNode2 = *listHead;

		for(int i=0;i<positionToInsert-1;i++){
			tempNode2 = (*tempNode2).next;
		}
		(*tempNode).next = (*tempNode2).next;
		(*tempNode2).next = tempNode;

	}
}

void printList(struct Node* listHead){
	while(listHead!=NULL){
		printf("%d ",(*listHead).data);
		listHead = (*listHead).next;
	}
	printf("\n");
}


int main(){
	struct Node* listHead;
	listHead = NULL;

	int numberOfElements,inputElement;
	printf("Enter the no of elements in the list: ");
	scanf("%d",&numberOfElements);

	for(int i=0;i<numberOfElements;i++){
		printf("Enter the element: ");
		scanf("%d",&inputElement);
		insertAtTheBegining(&listHead,inputElement);
		printList(listHead);
	}

	printf("Enter a number and the position where you want to insert it: ");
	int newNumber,positionToInsert;
	scanf("%d,%d",&newNumber,&positionToInsert);

	insertAtPosition(&listHead,newNumber,positionToInsert);
	printList(listHead);



}