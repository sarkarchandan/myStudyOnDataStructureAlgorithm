#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

//Check if the stack is empty
bool isEmpty(struct Node* topOfStack){
	if(topOfStack==NULL){
		return true; 
	}else{
		return false;
	}
}

//Create a new Stack Node
struct Node* createNewStackNode(int element){
	struct Node* newNode = new Node();
	(*newNode).data = element;
	(*newNode).next = NULL;
	return newNode;
}

//Insert data into stack
struct Node* Push(struct Node* topOfStack,int element){
	struct Node* newNode = createNewStackNode(element);
	if(isEmpty(topOfStack)){
		topOfStack=newNode;
	}else{
		(*newNode).next=topOfStack;
		topOfStack=newNode;
	}
	return topOfStack;
}

//Remove data from the stack and return
struct Node* Pop(struct Node* topOfStack){
	if(isEmpty(topOfStack)){
		cout << "We have an empty Stack!!!"<<endl;
		return topOfStack;
	}else{
		struct Node* tempNode = topOfStack;
		topOfStack=(*tempNode).next;
		free(tempNode);
	}
	return topOfStack;
}

//Show the top element of the stack
void Top(struct Node* topOfStack){
	if(isEmpty(topOfStack)){
		cout << "We have an empty Stack!!!"<<endl;
	}else{
		cout << "The current top element of the stack is: "<<(*topOfStack).data <<endl;
	}
}

//Print the Stack in its current state
void printStack(struct Node* topOfStack){
	if(isEmpty(topOfStack)){
		cout << "We have an empty Stack!!!"<<endl;
	}else{
		struct Node* tempNode = topOfStack;
		while(tempNode!=NULL){
			cout << (*tempNode).data << " ";
			tempNode=(*tempNode).next;
		}
	}
	cout << endl;
}



int main(){

	struct Node* topOfStack=NULL;//Empty Stack

	cout << "This is the Lined List Implementation of Stack." << endl;
	cout << "Enter 1 to Push an element to the Stack." << endl;
	cout << "Enter 2 to Pop an element from the Stack." << endl;
	cout << "Enter 3 to see the current Top element of the Stack." << endl;
	cout << "Enter 4 to print the current state of the Stack." << endl;
	cout << "Enter other number to exit." << endl;

	int choice,element;

	do{

		cout << "Enter your choice: " << endl;
		cin >> choice;

		switch(choice){
			case 1:
				cout << "Enter the element: " <<endl;
				cin >> element;
				topOfStack=Push(topOfStack,element);
				printStack(topOfStack);
				break;
			case 2:
				topOfStack=Pop(topOfStack);
				cout << "One element is popped from the stack."<<endl;
				cout << "Following is the Stack state now: "<<endl;
				printStack(topOfStack);
				break;
			case 3:
				Top(topOfStack);
				break;
			case 4:
				cout << "The Current State of the Stack is: " <<endl;
				printStack(topOfStack);
				break;
			default:
				cout << "Have a nice day." << endl;
				break;
		}

		if(choice < 1 || choice > 4){
			break;
		}

	}while(choice >= 1 || choice <=4);
}