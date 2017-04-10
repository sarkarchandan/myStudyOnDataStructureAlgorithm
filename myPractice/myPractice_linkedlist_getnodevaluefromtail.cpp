#include <iostream>
#include <stdlib.h>
using namespace std;


struct Node{
	int data;
	struct Node* next;
};

//Create a new List Node
struct Node* createNewNode(int element){
	struct Node* newNode = new Node();
	(*newNode).data = element;
	(*newNode).next = NULL;
	return newNode;
}

//Check if the list is empty
bool isEmpty(struct Node* head){
	if(head == NULL){
		return true;
	}else{
		return false;
	}
}

//Insert into the head of the list;
struct Node* insertIntoHead(struct Node* head,int element){
	struct Node* newNode = createNewNode(element);
	if(isEmpty(head)){
		head = newNode;
	}else{
		(*newNode).next = head;
		head = newNode;
	}
	return head;
}

//Print the currrent List
void printList(struct Node* head){
	struct Node* tempNode = head;
	if(tempNode == NULL){
		return;
	}
	cout << (*tempNode).data << " ";
	printList((*tempNode).next);
}

//Get the value of the nth node counted from the tail node of the list
int getNodeValueFromTail(struct Node* head,int positionFromTail){
	struct Node* pointerOne = head;
	struct Node* pointerTwo = head;

	while((*pointerOne).next != NULL){
		if(positionFromTail > 0){
			pointerOne = (*pointerOne).next;
			positionFromTail --;
		}else{
			pointerOne = (*pointerOne).next;
			pointerTwo = (*pointerTwo).next;
		}
	}
	return (*pointerTwo).data;
}

int main(int argc, char const *argv[])
{
	struct Node* head = NULL; //Declaring an empty list
	head = insertIntoHead(head,3);
	head = insertIntoHead(head,6);
	head = insertIntoHead(head,2);
	head = insertIntoHead(head,7);
	head = insertIntoHead(head,9);
	head = insertIntoHead(head,1);
	head = insertIntoHead(head,5);
	head = insertIntoHead(head,4);
	cout << "The List is: " << endl;
	printList(head);
	cout << endl;
	int positionFromTail;
	cout << "Enter the position from tail: " << endl;
	cin >> positionFromTail;
	cout << "The value at the given position is: " << getNodeValueFromTail(head,positionFromTail) << endl;
	return 0;
}