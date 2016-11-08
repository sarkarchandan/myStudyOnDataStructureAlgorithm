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

// Return the Node value from a given position counted backwards from tail.
int getNodeValueFromGivenPositionFromTail(struct Node* listHead, int positionFromTail){

	struct Node* tempA = listHead;
	struct Node* tempB = listHead;

	while((*tempA).next!=NULL){

		if(positionFromTail > 0){
			tempA = (*tempA).next;
			positionFromTail --;
		}else{
			tempA = (*tempA).next;
			tempB = (*tempB).next;
		}
	}
	return (*tempB).data;
}

int main(){

	struct Node* listHead = NULL; // Empty List

	int numberOfElements,position;
	cout << "Enter the no of elements that you want: " << endl;
	cin >> numberOfElements;

	for(int i=1;i<=numberOfElements;i++){

		listHead = insertNodeAtTail(listHead,i);
	}
	cout << endl;

	printList(listHead);
	cout << endl;

	cout << "Enter the position from tail: " << endl;
	cin >> position;

	cout << "The data at the given node position from Tail is: " << getNodeValueFromGivenPositionFromTail(listHead,position) << endl;

}