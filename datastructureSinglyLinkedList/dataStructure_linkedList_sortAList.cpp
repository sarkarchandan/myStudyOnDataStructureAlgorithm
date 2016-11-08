/*
Naive implementation for merging two linked lists.
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

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

//Print the initial list.
void printList(struct Node* listHead){

	struct Node* tempNode = listHead;

	while(tempNode!=NULL){
		cout << (*tempNode).data << " ";
		tempNode = (*tempNode).next;
	}
	cout << endl;
}

struct Node* sortAList(struct Node* listHead){

	struct Node *currentNode,*nextNode;
	struct Node* swap;
	struct Node* headPointer = listHead;
	currentNode = listHead;

	while((*headPointer).next!=NULL){

		nextNode = (*currentNode).next;
		
		if((*currentNode).data > (*nextNode).data){

			(*currentNode).next = (*nextNode).next;
			(*nextNode).next = currentNode;
		}
		headPointer = (*headPointer).next;
	}
	return listHead;
}


int main(){

	struct Node* listHead = NULL; // Empty List

	int numberOfElements,element;

	cout << "First Link List: " << endl;
	cout << "Enter the no of elements that you want: " << endl;
	cin >> numberOfElements;

	for(int i=1;i<=numberOfElements;i++){

		cout << "Enter the element: " << endl;
		cin >> element;
		listHead = insertNodeAtTail(listHead,element);
	}
	printList(listHead);
	cout << endl;

	listHead = sortAList(listHead);
	printList(listHead);
	cout << endl;
	

}