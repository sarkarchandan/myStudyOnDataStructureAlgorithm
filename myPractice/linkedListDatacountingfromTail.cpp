#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node{
	int data;
	struct Node* next;
};

//Cretae a New Node
struct Node* createNewNode(int element){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data=element;
	(*newNode).next=NULL;
	return newNode;
}

//Insert new node at tail of the linked list
struct Node* insertAtTail(struct Node* head,int element){
	struct Node* newNode = createNewNode(element);
	if(head==NULL){
		head=newNode;
	}else{
		struct Node* tempNode = head;
		while((*tempNode).next!=NULL){
			tempNode=(*tempNode).next;
		}
		(*tempNode).next=newNode;
	}
	return head;
}


//Find the data from a node located at a given position from the tail node
int findDatafromTailDistance(struct Node* head,int positionFromTail){

	struct Node* pointerA = head;
	struct Node* pointerB = head;

	while((*pointerA).next!=NULL){
		if(positionFromTail > 0){
			pointerA=(*pointerA).next;
			positionFromTail--;
		}else{
			pointerA=(*pointerA).next;
			pointerB=(*pointerB).next;
		}
	}
	return (*pointerB).data;
}

//Print the linked list using recursion
void printList(struct Node* head){
	struct Node* temNode = head;
	if(temNode==NULL){
		return;
	}
	cout << (*temNode).data << " ";
	printList((*temNode).next);
}


int main(){

	struct Node* head=NULL; //Empty List

	cout << "This is a linked list implementation to find out data of a node with a given position from the tail node." << endl;
	cout << "Enter 1 to add a node at the tail node of the linked list." << endl;
	cout << "Enter 2 to find the data of a given position from the tail node." << endl;
	cout << "Enter any value lesser than 1 or greater than 2 to exit from the implementation." << endl;

	int choice,element,position,value;

	do{
		cout << "Enter you choice: " << endl;
		cin >> choice;

		switch(choice){
			case 1:
				cout << "Enter the element you want to insert at tail: " << endl;
				cin >> element;
				head = insertAtTail(head,element);
				printList(head);
				cout<< endl;
				break;
			case 2:
				cout << "Enter the position from the tail: " << endl;
				cin >> position;
				value = findDatafromTailDistance(head,position);
				cout << endl;
				cout << "The value at the given position from the tail is: " << value << endl;
				cout << endl;
				break;
			default:
				cout << "Have nice day."<< endl;
				break;			
		}
		if(choice < 1 || choice > 2){
			break;
		}
	}while(choice >= 1 || choice <=2);

}