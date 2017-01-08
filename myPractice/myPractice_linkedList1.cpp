#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

//Create a new Node for the Linked List
struct Node* createNewNode(int element){
	struct Node* newNode = new Node();
	(*newNode).data=element;
	(*newNode).next=NULL;
	return newNode;
}

//Check if the list is empty.
bool isEmptyList(struct Node* head){
	if(head==NULL){
		return true;
	}else{
		return false;
	}
}

//Insert a new Node at head
struct Node* insertAtHead(struct Node* head,int element){

	struct Node* newNode = createNewNode(element);
	if(isEmptyList(head)){
		head=newNode;
	}else{
		(*newNode).next=head;
		head=newNode;
	}
	return head;
}

//Insert a new Node at tail
struct Node* insertAtTail(struct Node* head,int element){
	struct Node* newNode = createNewNode(element);
	if(isEmptyList(head)){
		head=newNode;
	}else{
		struct Node* tempNode=head;
		while((*tempNode).next!=NULL){
			tempNode=(*tempNode).next;
		}
		(*tempNode).next=newNode;
	}
	return head;
}

//Insert a new Node at any given position
struct Node* insertAtPosition(struct Node* head,int element,int position){

	if(isEmptyList(head)){
		cout<<"We have an empty list."<<endl;
	}else{
		struct Node* newNode=createNewNode(element);
		struct Node* tempNod=head;
		for(int i=0;i<position-2;i++){
			tempNod=(*tempNod).next;
		}
		(*newNode).next=(*tempNod).next;
		(*tempNod).next=newNode;
	}
	return head;
}

//Delete a Node from head
struct Node* deleteFromHead(struct Node* head){

	if(isEmptyList(head)){
		cout << "We have an empty list."<<endl;
	}else if((*head).next==NULL){

		struct Node* tempNode=head;
		delete(tempNode);
		cout << "The list is now empty."<<endl;
	}
	else{
		struct Node* tempNode = head;
		head=(*tempNode).next;
		delete(tempNode);
	}
	return head;
}

//Delete a Node from tail
struct Node* deleteFromTail(struct Node* head){

	if(isEmptyList(head)){
		cout << "We have an empty list."<<endl;
	}else if((*head).next==NULL){
		struct Node* tempNode=head;
		delete(tempNode);
		cout<<"The list is now empty."<<endl;
	}
	else{
		struct Node* tempNode=head;
		struct Node* previoustoTail;
		while((*tempNode).next!=NULL){
			previoustoTail=tempNode;
			tempNode=(*tempNode).next;
		}
		(*previoustoTail).next=NULL;
		delete(tempNode);
	}
	return head;
}

//Delete a Node from a given position
struct Node* deleteFromPosition(struct Node* head,int position){

	if(isEmptyList(head)){
		cout <<"We have an empty list."<<endl;
	}else{
		struct Node* tempNode=head;
		for(int i=0;i<position-2;i++){
			tempNode=(*tempNode).next;
		}
		struct Node* nodeToBeDeleted = (*tempNode).next;
		(*tempNode).next=(*nodeToBeDeleted).next;
		delete(nodeToBeDeleted);
	}
	return head;
}

//Print the Linked List forward or reverese recursively
void printList(struct Node* head,bool forwardFlag){

	struct Node* tempNode=head;
	if(tempNode==NULL){
		return;
	}
	if(forwardFlag==true){
		cout<<(*tempNode).data<<" ";
		printList((*tempNode).next,true);
	}else{
		printList((*tempNode).next,false);
		cout << (*tempNode).data<<" ";
	}
	cout << endl;
}

//Revert linked list iteratively
struct Node* revertList(struct Node* head){

	if(isEmptyList(head)){
		cout<< "We hav an empty list."<<endl;
	}else{
		struct Node *previous,*current,*next;
		current=head;
		previous=NULL;
		while(current!=NULL){
			next=(*current).next;
			(*current).next=previous;
			previous=current;
			current=next;
		}
		head=previous;
	}
	return head;
}

//Revert linked list recirsively
struct Node* revertListRecursive(struct Node* head){
	if((*head).next==NULL){
		return head;
	}
	struct Node* restOfTheList=revertListRecursive((*head).next);
	struct Node* pointer=(*head).next;
	(*pointer).next=head;
	(*head).next=NULL;
	return restOfTheList;
}


int main(){

	struct Node* head= NULL;

	cout << "This is the practice Linked List Implementation." << endl;
	cout << "Enter 1 to Insert an element at head." << endl;
	cout << "Enter 2 to Insert an element at tail." << endl;
	cout << "Enter 3 to Insert an element at the given position." << endl;
	cout << "Enter 4 to Delete an element from the head." << endl;
	cout << "Enter 5 to Delete an element from the tail." << endl;
	cout << "Enter 6 to Delete an element from a given position." << endl;
	cout << "Enter 7 to Revert the list iteratively." << endl;
	cout << "Enter 8 to Revert the list recursively." << endl;
	cout << "Enter other number to exit." << endl;

	int choice,element,position;

	do{

		cout << "Enter your choice: " << endl;
		cin >> choice;

		switch(choice){
			case 1:
				cout<<"Enter the Element: "<<endl;
				cin>>element;
				head=insertAtHead(head,element);
				printList(head,true);
				break;
			case 2:
				cout<<"Enter the Element:"<<endl;
				cin>>element;
				head=insertAtTail(head,element);
				printList(head,true);
				break;
			case 3:
				cout<<"Enter the Element: "<<endl;
				cin>>element;
				cout<<"Enter the Position: "<<endl;
				cin>>position;
				head=insertAtPosition(head,element,position);
				printList(head,true);
				break;
			case 4:
				cout<< "Trying to delete node from head.."<<endl;
				head=deleteFromHead(head);
				printList(head,true);
				break;
			case 5:
				cout<<"Trying to delete node from tail.."<<endl;
				head=deleteFromTail(head);
				printList(head,true);
				break;
			case 6:
				cout<<"Enter the position: "<<endl;
				cin>>position;
				head=deleteFromPosition(head,position);
				printList(head,true);
				break;
			case 7:
				cout<<"Reverting the list using iterative method..."<<endl;
				head=revertList(head);
				printList(head,true);
				break;
			case 8:
				cout<<"Reverting the list using recursive method..."<<endl;
				head=revertListRecursive(head);
				printList(head,true);
				break;
			default:
				cout << "Have a nice day." << endl;
				break;
		}

		if(choice < 1 || choice > 8){
			break;
		}

	}while(choice >= 1 || choice <=8);
}