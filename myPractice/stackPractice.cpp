#include<iostream>
#include<stdlib.h>

using namespace std;

struct Stack{
	int data;
	struct Stack* next;
};

struct Stack* createStackNode(int element){

	struct Stack* newStackNode = (struct Stack*)malloc(sizeof(struct Stack));
	(*newStackNode).data = element;
	(*newStackNode).next = NULL;
}

//Check if the Stack is empty.
bool isEmpty(struct Stack* topOfStack){

	if(topOfStack==NULL){
		return true;
	}else{
		return false;
	}
}

//Push to Stack
struct Stack* Push(struct Stack* topOfStack,int element){

struct Stack * newStackNode = createStackNode(element);

	if(topOfStack==NULL){
		topOfStack = newStackNode;
		return topOfStack;
	}else{
		(*newStackNode).next = topOfStack;
		topOfStack = newStackNode;
		return topOfStack;
	}
}


//Pop the top element from Stack
struct Stack* Pop(struct Stack* topOfStack){

	struct Stack* nodeToBeDeleted = topOfStack;
	if(isEmpty(topOfStack)){
		cout << "Stack Underfow !!!" << endl;
	}else{
		topOfStack = (*nodeToBeDeleted).next;
		free(nodeToBeDeleted);
	}
	return topOfStack;
}

//Fetch the top element from the stack
int Top(struct Stack* topOfStack){

	if(isEmpty(topOfStack)){
		cout << "Stack Underfow !!!" << endl;
	}else{
		return (*topOfStack).data;
	}
}

//Print the Stack
void printStack(struct Stack* topOfStack){

	struct Stack* tempNode = topOfStack;
	while(tempNode!=NULL){
		cout << (*tempNode).data;
		cout << " " ;
		tempNode = (*tempNode).next;
	}
	cout << endl;
}


int main(){

	struct Stack* topOfStack = NULL; //Empty Stack

	cout << "Push to Stack: Choose 1" << endl;
	cout << "Pop from Stack: Choose 2" << endl;
	cout << "Fetch Top element from Stack: Choose 3" << endl;
	cout << "Press 0 t exit." << endl;


	int choice,element;

	do{
		cout << "Enter your choice: " << endl;
		cin >> choice;

		switch(choice){
			case 1:
			cout << "Enter the element" << endl;
			cin >> element;
			topOfStack = Push(topOfStack,element);
			printStack(topOfStack);
			break;

			case 2:
			cout << "Stack will be popped: " << endl;
			topOfStack = Pop(topOfStack);
			cout << endl;
			cout << "Current Stack: " << endl;
			printStack(topOfStack);
			break;

			case 3:
			cout << "This is the current top element: " << endl;
			cout << Top(topOfStack);
			cout << "Current Stack" << endl;
			printStack(topOfStack);
			break;

			default:
			if(choice !=0 && choice < 1 || choice > 3){	
				cout << "Please enter valid choice" << endl;
			}else
			break;
		}
		if(choice==0){
			cout << "Have a nice day !!!" ;
			break;
		}
	}while(choice >= 1 || choice <= 3);

cout << endl;
}