#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

//Declaring an empty queue
struct Node* front=NULL;
struct Node* rear=NULL;

//Create a new Node
struct Node* createNewNodeForQueue(int element){
	struct Node* newNode = new Node();
	(*newNode).data=element;
	(*newNode).next=NULL;
	return newNode;
}

//To check if the Queue is empty
bool isEmpty(){
	if(front==NULL && rear==NULL){
		return true;
	}else{
		return false;
	}
}

//enQueue function
void enQueue(int element){
	struct Node* newNode = createNewNodeForQueue(element);
	if(isEmpty()){
		front=newNode;
		rear=newNode;
	}else{
		(*rear).next=newNode;
		rear=newNode;
	}
}

//deQueue functon
int deQueue(){
	int element;
	if(isEmpty()){
		cout << "Error.. We have an empty Queue. "<<endl;
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

//Front of the Queue
void frontElement(){
	if(isEmpty()){
		cout << "Error...We have an empty Queue."<<endl;
	}else{
		cout << "The Front element is: "<<(*front).data;
	}
	cout << endl;
}

//Print the Queue
void printQueue(){
	if(isEmpty()){
		cout << "We have an empty Queue !!!"<<endl;
	}else{
		struct Node* tempFront = front;
		struct Node* tempRear = rear;
		while(tempFront!=tempRear){
			cout<< (*tempFront).data << " ";
			tempFront=(*tempFront).next;
		}
		cout << (*tempFront).data;
	}
	cout << endl;
}


int main(){

	cout << "This is the Linked List implementation of the Queue." << endl;
	cout << "Enter 1 to enQueue an element." << endl;
	cout << "Enter 2 to deQueue an element." << endl;
	cout << "Enter 3 print the Queue at its current state." << endl;
	cout << "Enter other number to exit." << endl;

	int choice,element,retrieved;

	do{

		cout << "Enter your choice: " << endl;
		cin >> choice;

		switch(choice){
			case 1:
				cout << "Enter an element: "<<endl;
				cin >> element;
				enQueue(element);
				printQueue();
				break;
			case 2:
				retrieved=deQueue();
				cout<< "The retrived element from the Queue is: "<< retrieved<<endl;
				break;
			case 3:
				printQueue();
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