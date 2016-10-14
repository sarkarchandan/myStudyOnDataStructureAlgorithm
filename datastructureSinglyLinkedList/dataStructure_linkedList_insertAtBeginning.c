#include<stdio.h>
#include<stdlib.h>

/*
Creating Datatype for the Node.
*/
struct Node{
	int data;
	struct Node* next;
};

struct Node* linkedListHead; // This is a pointer to Node which is for us the sole reference or identity of the list in memory.

/*
Function insertToTheBeginingOfList() inserts a new node to the list both in the situation of when we have an empty list or
we already have elements in the list.
*/
void insertToTheBeginingOfList(int integerElement){
	
	/*
	We are creating (allocating memory dynamically to the Heap) a Node and having it's address in a pointer to Node.
	We are dereferencing the pointer to Node to access and modify it's fields.
	*/
	struct Node* tempNode = (struct Node*)malloc(sizeof(struct Node));

	(*tempNode).data = integerElement; //Alternate syntax: tempNode->data = integerElement;
	/*
	(*tempNode).next = NULL; 
	There is nothing wrong in the statement above. But it's not generic statement.
	
	But we want to be more generic and want our program to handle both the scenarios when
	the list is empty and when there are elements at the list. Following statement serve both the purpose.

		When the List is Empty: 
		linkedListHead is already NULL; [linkedListHead]>NULL
		Henece we can write the following statement.
		When there are elements in the List: 
		linkedListHead will now have the address of the current head node. And we want our newly created node to be the new head.
		Hence it makes sence that the current head node will be the second node after the insertion and currently linkedListHead is 
		having it's address. Hence in the following statement we'll be assigning that address to the next part of our new node.
		That will make our new node to be the new head and current head to be it's next.
	*/
	(*tempNode).next = linkedListHead; //Alternate syntax: tempNode->next = linkedListHead;

	/*
	This statement will assign the address of the new node to the linkedListHead. That essentially means our new node is now the
	head node.
	*/
	linkedListHead=tempNode;
}

/*
Function printList() traverse the list from the beginning and prints each element.
*/
void printList(){

	printf("The Current List is: \n");
	struct Node* nodeIndex = linkedListHead;
	while(nodeIndex!=NULL){
		printf("%d ", (*nodeIndex).data);
		nodeIndex = (*nodeIndex).next;
	}
	printf("\n");

}


int main(){

	linkedListHead = NULL; //This essentially means at this point my pointer to Node points to noting. That means my list is empty.
	/*
	So far we have done the following:
		1. We have created our Node datatype using C structure
		2. We have created a global varibale which is a pointer to Node and it points to nothing denoting that our list is empty.
	*/

	/*
	We will ask from the user to enter the no of integer numbers to be added to the list and we'll also ask for the integer numbers.
	When user will enter a number, we will take the input and call a function insertToList to insert the integer to the list.
	We will call a function printList() to print the current state of the list.
	*/

	printf("Please enter how many integers you want to add to the linked list: \n");
	int numberofIntegers,integerElement;
	scanf("%d",&numberofIntegers);

	for (int i=0;i<numberofIntegers;i++){
		printf("Enter the number: \n");
		scanf("%d",&integerElement);
		insertToTheBeginingOfList(integerElement);
		printList();
	}


}