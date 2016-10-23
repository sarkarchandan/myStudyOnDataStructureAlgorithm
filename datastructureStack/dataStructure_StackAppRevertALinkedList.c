/*
In this implementation we are reverting the original list itself using a stack i.e. we are adjusting the memory addresses for real and
not just printing the elements in reverse order.
*/

#include<stdio.h>
#include<stdlib.h>

//Node datatype.
struct Node{
	int data;
	struct Node* next;
};

//Stack datatype.
struct Stack{
	struct Node* node;
	struct Stack* next; 
};

//Create a new Node of the linked list.
struct Node* getNewListNode(int element){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = element;
	(*newNode).next = NULL;
	return newNode;
}

//Create a new Node for the Stack
struct Stack* getNewStackNode(struct Node* listNode){

	struct Stack* newStackNode = (struct Stack*)malloc(sizeof(struct Stack));
	(*newStackNode).node = listNode;
	(*newStackNode).next = NULL;
	return newStackNode;
}



//Insert New Node
struct Node* insertNodeAtEnd(struct Node* head,int element){

	struct Node* newNode = getNewListNode(element);

	if(head==NULL){
		head = newNode;
		return head;
	}else{
		struct Node* tempNode = head;
		while((*tempNode).next!=NULL){
			tempNode = (*tempNode).next;
		}
		(*tempNode).next = newNode;
	}
	return head;
}

//isEmpty check for stack
int isEmpty(struct Stack* topOfStack){

	if(topOfStack==NULL){
		return 0;
	}else{
		return 1;
	}
}

//Push operation for stack
struct Stack* Push(struct Stack* topOfStack,struct Node* node){

	struct Stack* newStackNode = getNewStackNode(node);

	if(isEmpty(topOfStack)==0){
		topOfStack = newStackNode;
		return topOfStack;
	}else{
		(*newStackNode).next = topOfStack;
		topOfStack = newStackNode;
	}
	return topOfStack;
}

//Pop operation for stack
struct Stack* Pop(struct Stack* topOfStack){

	if(isEmpty(topOfStack)==0){
		printf("Stack Underflow...Invalid Operation !!!\n");
	}else{
		struct Stack* stackNodeTobeDeleted = topOfStack;
		topOfStack = (*stackNodeTobeDeleted).next;
		free(stackNodeTobeDeleted);
	}
	return topOfStack;
}

//Top operation for the stack
struct Node* Top(struct Stack* topOfStack){

	if(isEmpty(topOfStack)==0){
		printf("Stack Underflow...Invalid Operation !!!\n");
	}else{
		return (*topOfStack).node;
	}
}


//Revert operation for linked list
struct Node* revertLinkedList(struct Stack* topOfStack,struct Node* head){

	// Pushing all the nodes of the linked list in our stack.
	struct Node* tempNode = head;

	if(head!=NULL){
		while(tempNode!=NULL){
			topOfStack = Push(topOfStack,tempNode);
			tempNode = (*tempNode).next;
		}
	}else{
		printf("Something is wrong with the list !!!\n");
	}

	//Now the stack has all my nodes of the linked list.
	/*Now the key idea of reverting our linked list is, we will make the current top element i.e. the last inserted element in the stack
	  (which is also the last node of our linked list) to be our new head of the linked list. We will iterate while stack is not empty.
	  When the stack is empty, the last popped element is the head node of the initial linked list which we are reverting.
	  This node is now our tail node of the reverted linked list. Hence, we will set it's next field to NULL.
	*/

	if(isEmpty(topOfStack)==1){

		struct Node* tempHeadNode = Top(topOfStack);
		topOfStack = Pop(topOfStack);
		head = tempHeadNode;
		while(isEmpty(topOfStack)==1){

			(*tempHeadNode).next = Top(topOfStack);
			topOfStack = Pop(topOfStack);
			tempHeadNode = (*tempHeadNode).next;
		}
		(*tempHeadNode).next = NULL;
	}else{
		printf("Something is wrong with stack operation !!!\n");
	}
	return head;
}

//Print the linked list.
void printList(struct Node* head){

	struct Node* tempNode = head;
	while(tempNode!=NULL){
		printf("%d ",(*tempNode).data);
		tempNode = (*tempNode).next;
	}
	printf("\n");

}


int main(){

	struct Node* listHead = NULL;// Empty List
	struct Stack* topOfStack = NULL;//Empty Stack

	int numberOfElements,element;

	printf("Enter the no of elements in the linked list: ");
	scanf("%d",&numberOfElements);

	for(int i=0;i<numberOfElements;i++){
		printf("Enter the number: \n");
		scanf("%d",&element);
		listHead = insertNodeAtEnd(listHead,element);
	}
	printf("\n");
	printList(listHead);

	printf("We are going to revert the original linked list using a stack....\n");
	printf("Folowing is the reverted linked list: \n");

	listHead = revertLinkedList(topOfStack,listHead);
	printf("\n");

	printList(listHead);

}