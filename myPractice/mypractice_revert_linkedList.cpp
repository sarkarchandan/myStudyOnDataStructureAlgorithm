#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

//Create a new Node
struct Node* createNewNode(int element){
	struct Node* newNode = new Node();
	(*newNode).data=element;
	(*newNode).next=NULL;
	return newNode;
}

//Insert at head
struct Node* insertAtHead(struct Node* head,int element){

	struct Node* newNode = createNewNode(element);
	if(head==NULL){
		head=newNode;
	}else{
		(*newNode).next = head;
		head=newNode;
	}
	return head;
}

//Revert the linked list using recursion
struct Node* revertUsingRecusrsion(struct Node* head){

	if((*head).next==NULL){
		return head;
	}

	struct Node* restOfTheList = revertUsingRecusrsion((*head).next);
	struct Node* tempNode = (*head).next;
	(*tempNode).next=head;
	(*head).next=NULL;
	return restOfTheList;
}

//Print the list using recursion
void printList(struct Node* head){
	struct Node* tempNode = head;
	if(tempNode==NULL){
		return;
	}
	cout << (*tempNode).data;
	printList((*tempNode).next);
}


int main(){

	struct Node* head = NULL;

	cout << "This is the implementation of reverting a linked list using recursion." << endl;
	cout << "Enter 1 to add an element to the head of the list." << endl;
	cout << "Enter 2 to revert the list." << endl;
	cout << "Enter 3 to print the current list." << endl;
	cout << "Enter other number to exit." << endl;

	int choice,element;

	do{

		cout << "Enter your choice: " << endl;
		cin >> choice;

		switch(choice){
			case 1:
				cout << "Enter the element: "<<endl;
				cin >> element;
				head=insertAtHead(head,element);
				printList(head);
				cout << endl;
				break;
			case 2:
				head = revertUsingRecusrsion(head);
				printList(head);
				cout << endl;
				break;
			case 3:
				printList(head);
				cout << endl;
				break;
			default:
				cout << "Have a nice day." << endl;
				break;
		}

		if(choice < 1 || choice > 3){
			break;
		}

	}while(choice >= 1 || choice <=3);

}