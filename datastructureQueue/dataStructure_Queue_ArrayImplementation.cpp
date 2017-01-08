#include <iostream>

using namespace std;

int integerQueue[10];
int front=-1;
int rear=-1;

//Check if the queue is empty.
bool isEmpty(){
	if(front ==-1 && rear ==-1){
		return true;
	}else{
		return false;
	}
}

//Check if the queue is full
bool isFull(){
	int size = sizeof(integerQueue)/sizeof(int);
	if(rear==size-1){
		return true;
	}else{
		return false;
	}
}

//Add element to the queue
void enQueue(int element){

	if(isFull()){
		cout << "The Queue is full." << endl;
		return;
	}else if(isEmpty()){
		front=front+1;
		rear=rear+1;
	}else{
		rear=rear+1;
	}
	integerQueue[rear]=element;
}


//Remove element from the queue
int deQueue(){

	int element;

	if(isEmpty()){
		cout << "Queue is Empty." << endl;
	}else if(front==rear){
		element=integerQueue[front];
		front=-1;
		rear=-1;
	}else{
		element=integerQueue[front];
		front=front+1;
	}
	return element;
}

//Peek at the fromnt of the queue
void frontElement(){

	if(isEmpty()){
		return;
	}else{
		cout << integerQueue[front] <<endl;
	}
}

//Print the current queue at any point in time
void printQueue(){
	if(isEmpty()){
		cout << "Queue is empty." << endl;
	}else{
		int fIndex=front;
		int rIndex=rear;
		while(fIndex<=rIndex){
			cout << integerQueue[fIndex] << " ";
			fIndex++;
		}
	}
	cout << endl;
}


int main(){

	cout << "This is the array implementation of the queue." << endl;
	cout << "The queuesize is 10." << endl;
	cout << "Enter 1 to insert an integer to the queue." << endl;
	cout << "Enter 2 to remove an element from the queue." << endl;
	cout << "Enter 3 to have the front of the queue." << endl;
	cout << "Enter anything lesser than 1 or greater than 3 to exit." << endl;

	int choice,element,number;

	do{

		cout << "Enter your choice: " << endl;
		cin >> choice;

		switch(choice){
			case 1:
				cout << "Enter the element: " << endl;
				cin >> element;
				enQueue(element);
				printQueue();
				cout << endl;
				break;
			case 2:
				cout << "We are trying to dequeue from the queue." << endl;
				number=deQueue();
				cout << "The dequeued number is: " << number << endl;
				printQueue();
				break;
			case 3:
				cout << "Following is the front of the queue now: " << endl;
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