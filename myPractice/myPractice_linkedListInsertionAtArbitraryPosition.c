#include<stdio.h>
#include<stdlib.h>

//Creating the Datatype for Node
struct Node{
	int data;
	struct Node* next;
};

struct Node* insertElementToPosition(struct Node** listHead,int inputElement,int position){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // New Node created in the Heap
	(*newNode).data = inputElement; // Assigning value to the data part

	if(position==0){
		(*newNode).next= *listHead;
		*listHead = newNode;
	}else{

		struct Node* tempNode = *listHead;
		for(int i=0;i<position-2;i++){
			tempNode = (*tempNode).next;
		}
		(*newNode).next = (*tempNode).next;
		(*tempNode).next = newNode;

	}
	return (*listHead);
}

void printList(struct Node* listHead){

	while(listHead!=NULL){
		printf("%d ",(*listHead).data);
		listHead = (*listHead).next;
	}
	printf("\n");

}


// main function
int main(){
	//declaring the pointer to Node which will point the head(will have the address of the head node)
	struct Node* listHead=NULL; // listHead points to NULL means our list is current ly Empty.

	int numberOfElements,inputElement,position;

	printf("Enter the total no of Elements in the list: \n");
	scanf("%d",&numberOfElements);

	for(int i = 0;i<numberOfElements;i++){
		printf("Enter the element: \n");
		scanf("%d",&inputElement);
		printf("Enter the position you want to enter the element to: \n");
		scanf("%d",&position);

		listHead = insertElementToPosition(&listHead,inputElement,position); // Call by reference
		printList(listHead); // Call by value
	}

}