#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

struct Node* front = NULL; // Empty Queue
struct Node* rear = NULL; // Empty Queue


//Create a new node.
struct Node* createNewNode(int element){
	struct Node* newNode = new Node();
	(*newNode).data = element;
	(*newNode).next = NULL;
	return newNode;
}

//To check if the queue is empty
bool isEmpty(){
	if(front==NULL && rear==NULL){
		return true;
	}else{
		return false;
	}
}

//To insert an element to the queue
void enQueue(int element){
	struct Node* newNode = createNewNode(element);
	if(isEmpty()){
		front=newNode;
		rear=newNode;
	}else{
		(*rear).next=newNode;
		rear=newNode;
	}
}

//To delete and return an element to the queue
int deQueue(){
	int element;
	if(isEmpty()){
		cout << "The Queue is empty" << endl;
	}else if(front==rear){
		element=(*rear).data;
		front=NULL;
		rear=NULL;
	}else{
		element=(*front).data;
		front=(*front).next;
	}
	return element;
}

//Front of the Queue
void frontElement(){
	if(isEmpty()){
		cout << "The Queue is empty"<<endl;
	}else{
		cout << "Current front: " << (*front).data << endl;
	}
	cout << endl;
}

//Print the Queue
void printQueue(){
	struct Node* tempFront = front;
	struct Node* tempRear = rear;

	if(isEmpty()){
		cout << "We have empty queue." << endl;
	}else{
		while(tempFront!=tempRear){
			cout << (*tempFront).data;
			tempFront = (*tempFront).next;
		}
		cout << (*tempFront).data;
	}
	cout << endl;
}


int main(){

	cout << "This is the Linked List implementation of the Queue." << endl;
	cout << "Enter 1 to enQueue an element to the Queue." << endl;
	cout << "Enter 2 to deQueue an element from the Queue." << endl;
	cout << "Enter 3 to see the current front element of the Queue." << endl;
	cout << "Enter any other number to exit." << endl;

	int choice,element,retElement;

	do{

		cout << "Enter your choice: " << endl;
		cin >> choice;

		switch(choice){
			case 1:
				cout << "Enter an element:" << endl;
				cin >> element;
				enQueue(element);
				printQueue();
				break;
			case 2:
				retElement = deQueue();
				cout << "The Retrieved element from the Queue is: "<<retElement << endl;
				printQueue();
				break;
			case 3:
				frontElement();
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