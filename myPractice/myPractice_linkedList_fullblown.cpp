//Linked List Implementation full blown

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

//Create a new Node for the list
struct Node* createNewNode(int element){
	struct Node* newNode = new Node();
	(*newNode).data = element;
	(*newNode).next = NULL;
	return newNode;
}

//Check if the list is empty
bool isEmpty(struct Node* head){
	if(head==NULL){
		return true;
	}else{
		return false;
	}
}

//Insert a Node at the head of the list
struct Node* insertAtHead(struct Node* head,int element){
	struct Node* newNode = createNewNode(element);
	if(isEmpty(head)){
		head=newNode;
	}else{
		(*newNode).next = head;
		head = newNode;
	}
	return head;
}

//Insert a Node at tail
struct Node* insertAtTail(struct Node* head,int element){
	struct Node* newNode = createNewNode(element);
	if(isEmpty(head)){
		head=newNode;
	}else{
		struct Node* tempNode = head;
		while((*tempNode).next!=NULL){
			tempNode=(*tempNode).next;
		}
		(*tempNode).next = newNode;
	}
	return head;
}

//Insert a Node at arbitrary position
struct Node* insertAtAPosition(struct Node* head,int element,int position){
	struct Node* newNode = createNewNode(element);
	if(isEmpty(head)){
		head=newNode;
		cout << "We have the empty list. Thus inserting to head." << endl;
	}else{
		struct Node* tempNode = head;
		for(int i=0;i<position-2;i++){
			tempNode = (*tempNode).next;
		}
		(*newNode).next = (*tempNode).next;
		(*tempNode).next = newNode;
	}
	return head;
}

//Delete a Node from head
struct Node* deleteANodeFromHead(struct Node* head){
	if(isEmpty(head)){
		cout << "We have an empty list !!!" << endl;
	}else{
		cout << "Deleting the node : " << endl;
		struct Node* tempNode = head;
		head = (*tempNode).next;
		delete(tempNode);
	}
	return head;
}

//Delete a Node from tail
struct Node* deleteANodeFromTail(struct Node* head){
	if(isEmpty(head)){
		cout << "We have an empty list !!!"<<endl;
	}else{
		cout << "Deleting the node : " << endl;
		struct Node* tempNode = head;
		struct Node* previoustoTail;
		while((*tempNode).next!=NULL){
			previoustoTail = tempNode;
			tempNode=(*tempNode).next;
		}
		(*previoustoTail).next = NULL;
		delete(tempNode);
	}
	return head;
}

//Delete a Node from arbitrary position
struct Node* deleteANodeFromAPosition(struct Node* head,int position){
	if(isEmpty(head)){
		cout << "We have an empty list !!!" <<endl;
	}else{
		cout << "Deleting the node : " << endl;
		struct Node* tempNode = head;
		struct Node* nextNode;
		for(int i=0;i<position-2;i++){
			tempNode=(*tempNode).next;
		}
		nextNode=(*tempNode).next;
		(*tempNode).next = (*nextNode).next;
		delete(nextNode);
	}
	return head;
}

//Print List Forward to reverse
void printListRevFor(struct Node* head, bool revFlag){
	struct Node* tempNode = head;
	if(revFlag==true){
		if(tempNode==NULL){
			return;
		}

		printListRevFor((*tempNode).next,true);
		cout << (*tempNode).data << " ";
	}else{
		if(tempNode==NULL){
			return;
		}else{
			cout << (*tempNode).data << " ";
			printListRevFor((*tempNode).next,false);
		}
	}
}

//Revert a Linked List with iterative method
struct Node* revertListIterative(struct Node* head){
	if(isEmpty(head)){
		cout << "We have an empty list !!!" << endl;
	}else{
		struct Node *previous,*current,*next;
		previous=NULL;
		current = head;
		while(current!=NULL){
			next = (*current).next;
			(*current).next = previous;
			previous = current;
			current=next;
		}
		head=previous;
	}
	return head;
}

//Revert a Linked List with recursive method
struct Node* revertListRecusrsive(struct Node* head){
	struct Node* restOfTheList;
	if(isEmpty(head)){
		cout << endl;
	}else{
		struct Node* tempNode = head;
		if((*tempNode).next==NULL){
			return tempNode;
		}
		restOfTheList = revertListRecusrsive((*tempNode).next);
		struct Node* currentHead = (*tempNode).next;
		(*currentHead).next = tempNode;
		(*tempNode).next = NULL;
	}
	return restOfTheList;
}



int main(){

	struct Node* head = NULL; //Declaring an empty list.

	cout << "This is the Simple Linked List Implementation." << endl;
	cout << "Enter 1 to insert a node at head." << endl;
	cout << "Enter 2 to insert a node at tail." << endl;
	cout << "Enter 3 to insert a node at a given position." << endl;
	cout << "Enter 4 to delete a node from head." << endl;
	cout << "Enter 5 to delete a node from tail." << endl;
	cout << "Enter 6 to delete a node from a given position." << endl;
	cout << "Enter 7 to print a list reverse." << endl;
	cout << "Enter 8 to print a list forward." <<endl;
	cout << "Enter 9 to revert a list using iterative methods." << endl;
	cout << "Enter 10 to revert a lit using recursive methods." << endl;

	int choice,element,position;

	do{

		cout << "Enter your choice: " << endl;
		cin >> choice;

		switch(choice){
			case 1:
				cout << "Enter the element: " << endl;
				cin >> element;
				head = insertAtHead(head,element);
				printListRevFor(head,false);
				cout << endl;
				break;
			case 2:
				cout << "Enter the element: "<< endl;
				cin >> element;
				head = insertAtTail(head,element);
				printListRevFor(head,false);
				cout << endl;
				break;
			case 3:
				cout << "Enter the element: "<< endl;
				cin >> element;
				cout << "Enter the position: "<< endl;
				cin >> position;
				head = insertAtAPosition(head,element,position);
				printListRevFor(head,false);
				cout << endl;
				break;
			case 4:
				head = deleteANodeFromHead(head);
				printListRevFor(head,false);
				cout << endl;
				break;
			case 5:
				head = deleteANodeFromTail(head);
				printListRevFor(head,false);
				cout << endl;
				break;
			case 6:
				cout << "Enter the position: "<< endl;
				cin >> position;
				head = deleteANodeFromAPosition(head,position);
				printListRevFor(head,false);
				cout << endl;
				break;
			case 7:
				cout << "Following is the current list in reverse: " << endl;
				printListRevFor(head,true);
				cout << endl;
				break;
			case 8:
				cout <<"Following is the current list in order: " << endl;
				printListRevFor(head,false);
				cout << endl;
				break;
			case 9:
				cout << "Reverting a list using iterative method: " << endl;
				head = revertListIterative(head);
				printListRevFor(head,false);
				cout << endl;
				break;
			case 10:
				cout << "Reverting the list using recursive method: "<< endl;
				head = revertListRecusrsive(head);
				printListRevFor(head,false);
				cout << endl;
				break;
			default:
				cout << "Have a nice day." << endl;
				break;
		}

		if(choice < 1 || choice > 10){
			break;
		}

	}while(choice >= 1 || choice <=10);
}