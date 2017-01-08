#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Stack{
	char data;
	struct Stack* next;
};

//Check if the Stack is empty
bool isEmpty(struct Stack* topOfStack){
	if(topOfStack==NULL){
		return true;
	}else{
		return false;
	}
}

//Create new Stack Node
struct Stack* createNewStackNode(char element){
	struct Stack* newStackNode = new Stack();
	(*newStackNode).data = element;
	(*newStackNode).next = NULL;
	return newStackNode;
}

//Push to Stack
struct Stack* Push(struct Stack* topOfStack,char element){
	struct Stack* newStackNode = createNewStackNode(element);
	if(isEmpty(topOfStack)){
		topOfStack = newStackNode;
	}else{
		(*newStackNode).next = topOfStack;
		topOfStack = newStackNode;
	}
	return topOfStack;
}

//Pop from Stack
char Pop(struct Stack* topOfStack){
	char topElement;
	if(isEmpty(topOfStack)){
		cout << "We have an empty stack !!!" <<endl;
	}else{
		topElement = (*topOfStack).data;
	}
	return topElement;
}

//Top element of the Stack
void Top(struct Stack* topOfStack){
	if(isEmpty(topOfStack)){
		cout << "We have an empty Stack !!!" << endl;
	}else{
		cout << (*topOfStack).data << endl;
	}
}

//Print the current Stack
void printStack(struct Stack* topOfStack){
	struct Stack* tempStack = topOfStack;
	if(tempStack==NULL){
		return;
	}
	cout << (*topOfStack).data;
	printStack((*topOfStack).next);
}

//Revert a String
void revertString(struct Stack* topOfStack,string myString,int length){

	if(length == 0){
		cout << "We have been passed an empty string" << endl;
	}else{
		for(int i=0;i<length;i++){
			topOfStack = Push(topOfStack,*(myString+i));
		}

		while(isEmpty(topOfStack)==false){
			cout << (*topOfStack).data << " ";
			Pop(topOfStack);
		}
	}
}

int main(){

	struct Stack* topOfStack = NULL; // Declaring empty Stack 
	string myString = "hello";
	cout << "This is the String reversed: "<< endl;
	revertString(topOfStack,myString,5);
}