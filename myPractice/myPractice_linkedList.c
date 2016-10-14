#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

void insertInto(struct Node** head,int listChar){

	struct Node* tempNode=(struct Node*)malloc(sizeof(struct Node));
	(*tempNode).data = listChar;
	(*tempNode).next = *head;
	*head = tempNode;

}

void printList(struct Node* head){

	while(head!=NULL){
		printf("%d ",(*head).data);
		head = (*head).next;
	}
	printf("\n");
}

int main(){
	struct Node* head = NULL;

	printf("Enter the no of elements: ");
	int number,i;
	int listChar;
	scanf("%d",&number);

	for(i=0;i<number;i++){
		printf("Enter the character: \n");
		
		scanf("%d",&listChar);

		insertInto(&head,listChar);
		printList(head);
	}
}