#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

struct Node* front=NULL;
struct Node* rear=NULL;

//Create a new Node
struct Node* createNewNode(int element){
	struct Node* newNode=new Node();
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


//Insert element to the Queue
void enQueue(int element){

	struct Node* newNode=createNewNode(element);
	if(isEmpty()){
		front=newNode;
		rear=newNode;
	}else{
		(*rear).next=newNode;
		rear=newNode;
	}
}

//Delete and return an element for the Queue
int deQueue(){
	int element;
	if(isEmpty()){
		cout<< "We have an empty Queue." << endl;
	}else if(front==rear){
		element=(*front).data;
		front=NULL;
		rear=NULL;
		cout<<"The Queue is now empty."<<endl;
	}else{
		struct Node* tempNode=front;
		element=(*front).data;
		front=(*front).next;
		delete(tempNode);
	}
	return element;
}

//Print the front of the Queue
void frontElement(){
	if(isEmpty()){
		cout<<"We have an empty Queue."<<endl;
	}else{
		cout<<(*front).data;
	}
	cout<<endl;
}

//Print the Queue
void printQueue(){

	if(!isEmpty()){
		struct Node* tempFront=front;
		struct Node* tempRear=rear;
		while(tempFront!=tempRear){
			cout<<(*tempFront).data<< " ";
			tempFront=(*tempFront).next;
		}
		cout<<(*tempFront).data;
	}
	cout<<endl;
}



int main(){

	cout << "This is the linked list implementation of the Queue." << endl;
	cout << "Enter 1 to insert an element to the Queue." << endl;
	cout << "Enter 2 to delete and return an element from the Queue." << endl;
	cout << "Enter 3 to print the front elelemt of the Queue." << endl;
	cout << "Enter other number to exit." << endl;

	int choice,element,retrieved;

	do{

		cout << "Enter your choice: " << endl;
		cin >> choice;

		switch(choice){
			case 1:
				cout<<"Enter the element: "<<endl;
				cin>>element;
				enQueue(element);
				printQueue();
				break;
			case 2:
				cout<<"Trying to delete the element from the Queue..."<<endl;
				retrieved=deQueue();
				cout<<"The retrieved element is: "<<retrieved<<endl;
				printQueue();
				break;
			case 3:
				cout<<"The front element now is: "<<endl;
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