#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

//Create new Node for the Queue.
struct Node* createNewNode(int element){
	struct Node* newNode = new Node();
	(*newNode).data=element;
	(*newNode).next=NULL;
	return newNode;
}

//Check if the Queue is empty
bool isEmpty(){
	if(front==NULL && rear==NULL){
		return true;
	}else{
		return false;
	}
}

//Insert new element to the Queue
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

//Delete the element from the Queue and return
int deQueue(){
	struct Node* tempNode = front;
	int element;
	if(isEmpty()){
		cout << "Queue is empty." << endl;
	}else if(front==rear){
		element=(*front).data;
		front=NULL;
		rear=NULL;
	}else{
		element=(*front).data;
		front=(*front).next;
	}
	return element;
}

//Print the fron element of the queue
void frontElement(){
	if(isEmpty()){
		cout << "Queue is empty." << endl;
	}else{
		cout << (*front).data << endl;
	}
}

//Print the entire queue at any point
void printQueue(){
	if(!isEmpty()){
		struct Node* tempFront = front;
		struct Node* tempRear = rear;
		while(tempFront!=tempRear){
			cout << (*tempFront).data << " ";
			tempFront=(*tempFront).next;
		}
		cout << (*tempFront).data;
	}else{
		cout << "Queue is now empty." << endl;
	}
}


int main(){

	cout << "This is the Linked List implementation of a simple Queue." << endl;
	cout << "Enter 1 to insert an element to the Queue." << endl;
	cout << "Enter 2 to delete an element from the Queue." << endl;
	cout << "Enter 3 to print the front element from the Queue." << endl;
	cout << "Enter other number to exit." << endl;

	int choice,element,retrieved;

	do{

		cout << "Enter your choice: " << endl;
		cin >> choice;

		switch(choice){
			case 1:
				cout << "Enter the element: "<< endl;
				cin >> element;
				enQueue(element);
				printQueue();
				cout << endl;
				break;
			case 2:
				cout << "Trying to dequeue.." <<endl;
				retrieved=deQueue();
				cout << "We retrieved: " << endl;
				cout<< retrieved;
				cout <<endl;
				printQueue();
				cout << endl;
				break;
			case 3:
				cout << "The front element of the queue is: " << endl;
				frontElement();
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