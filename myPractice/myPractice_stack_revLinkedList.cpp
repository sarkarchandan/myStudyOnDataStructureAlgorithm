#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	struct Node* next;
};

struct Stack{
	struct Node* node;
	struct Stack* next;
};

//Create a new List Node
struct Node* createNewListNode(int element){
	struct Node* newListNode = new Node();
	(*newListNode).data = element;
	(*newListNode).next = NULL;
	return newListNode;
}

//Create a new Stack Node
struct Stack* createNewStackNode(struct Node* listNode){
	struct Stack* newStackNode = new Stack();
	(*newStackNode).node = listNode;
	(*newStackNode).next = NULL;
	return newStackNode;
}

//Check if the list is empty
bool isEmptyList(struct Node* head){
	if(head==NULL){
		return true;
	}else{
		return false;
	}
}

//Check if the stack is empty
bool isEmptyStack(struct Stack* topOfStack){
	if(topOfStack==NULL){
		return true;
	}else{
		return false;
	}
}

//Create List with inserting at head;
struct Node* addToList(struct Node* head,int element){
	struct Node* newListNode = createNewListNode(element);
	if(isEmptyList(head)){
		head = newListNode;
	}else{
		(*newListNode).next = head;
		head = newListNode;
	}
	return newListNode;
}

//Push operation for the Stack
struct Stack* Push(struct Stack* topOfStack,struct Node* listNode){
	struct Stack* newStackNode = createNewStackNode(listNode);
	if(isEmptyStack(topOfStack)){
		topOfStack = newStackNode;
	}else{
		(*newStackNode).next = topOfStack;
		topOfStack = newStackNode;
	}
	return topOfStack;
}

//Pop operation for the Stack
struct Stack* Pop(struct Stack* topOfStack){
	if(isEmptyStack(topOfStack)){
		cout << "Stack Underflow !!!" << endl;
	}else{
		struct Stack* tempStackNode = topOfStack;
		topOfStack = (*tempStackNode).next;
		delete(tempStackNode);
	}
	return topOfStack;
}

//Top operation for the Stack
struct Node* Top(struct Stack* topOfStack){
	struct Node* tempNode;
	if(isEmptyStack(topOfStack)){
		cout << "Stack Underflow !!!" << endl;
	}else{
		tempNode =  (*topOfStack).node;
	}
	return tempNode;
}

//print The current List
void printCurrentList(struct Node* head){
	struct Node* tempNode = head;
	if(tempNode==NULL){
		return;
	}
	cout << (*tempNode).data << " ";
	printCurrentList((*tempNode).next);
}

//Print the list Reverse
void printTheListReverse(struct Stack* topOfStack,struct Node* head){

	if(isEmptyList(head)){
		cout << "We have an empty list.." << endl;
	}else{
		struct Node* tempNode = head;
		while(tempNode!=NULL){
			topOfStack = Push(topOfStack,tempNode);
			tempNode=(*tempNode).next;
		}
	}

	while(isEmptyStack(topOfStack)==false){
		struct Node* node = Top(topOfStack);
		cout << (*node).data<< " ";
		topOfStack = Pop(topOfStack);
	}
	cout << endl;
}


//Revert the list
struct Node* revertTheList(struct Stack* topOfStack,struct Node* head){
	
	struct Node* tempNode = head;
	while(tempNode!=NULL){
		topOfStack = Push(topOfStack,tempNode);
		tempNode = (*tempNode).next;
	}

	struct Node* tempHeadNode = Top(topOfStack);
	topOfStack = Pop(topOfStack);
	head = tempHeadNode;

	while(isEmptyStack(topOfStack)==false){
		(*tempHeadNode).next = Top(topOfStack);
		topOfStack = Pop(topOfStack);
		tempHeadNode = (*tempHeadNode).next;
	}
	(*tempHeadNode).next = NULL;
	return head;
}



int main(){

	struct Node* head = NULL;
	struct Stack* topOfStack = NULL;

	head = addToList(head,1);
	head = addToList(head,2);
	head = addToList(head,3);
	head = addToList(head,4);
	head = addToList(head,5);

	int choice;
	cout << "This is the Stack Application. " << endl;

	do{

		cout << "Enter your choice: " << endl;
		cin >> choice;

		switch(choice){
			case 1:
				cout << "Following is the current List: " << endl;
				printCurrentList(head);
				cout << endl;
				cout << "Folloiwng is the reverse order of the list: " << endl;
				printTheListReverse(topOfStack,head);
				break;
			case 2:
				cout << "Following is the current List: " << endl;
				printCurrentList(head);
				cout << endl;
				cout << "Following is the list reverted: "<< endl;
				head = revertTheList(topOfStack,head);
				printCurrentList(head);
				cout << endl;
				break;
			default:
				cout << "Have a nice day." << endl;
				break;
		}

		if(choice < 1 || choice > 2){
			break;
		}

	}while(choice >= 1 || choice <=2);



}