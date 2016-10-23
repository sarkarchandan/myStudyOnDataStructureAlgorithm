/*
This is stack implementation to find out Balanced Parentheses in an expression.
*/
#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

struct Stack{
	char data;
	struct Stack* next;
};

// Create a new stack node.
struct Stack* getNewStackNode(char symbol){

	struct Stack* newStackNode = (struct Stack*)malloc(sizeof(struct Stack));
	(*newStackNode).data = symbol;
	(*newStackNode).next = NULL;
	return newStackNode;
}

//Push operation for Stack.
struct Stack* Push(struct Stack* topOfStack,char symbol){

	struct Stack* newStackNode = getNewStackNode(symbol);

	if(topOfStack==NULL){
		topOfStack = newStackNode;
		return topOfStack;
	}else{
		(*newStackNode).next = topOfStack;
		topOfStack = newStackNode;
	}
	return topOfStack;
}

//Pop operation for Stack
struct Stack* Pop(struct Stack* topOfStack){

	if(topOfStack==NULL){
		cout << "Stack Underflow. Invalid operation !!!" << endl;
		return topOfStack;
	}else{
		struct Stack* nodeToBeDeleted = topOfStack;
		topOfStack = (*nodeToBeDeleted).next;
		free(nodeToBeDeleted);
	}
	return topOfStack;
}

//Top operation for Stack
char Top(struct Stack* topOfStack){

	if(topOfStack==NULL){
		cout << "Stack Underflow. Invalid operation !!!" << endl;
	}else{
		return (*topOfStack).data;
	}
}

//isEmpty operation for Stack
bool isEmpty(struct Stack* topOfStack){

	if(topOfStack==NULL){
		return true;
	}else{
		return false;
	}
}

//Check if two characters forms a pair or not
bool checkValidPair(char symbolA,char symbolB){

	if(symbolA== '(' && symbolB== ')'){
		return true;
	}else if(symbolA== '{' && symbolB== '}'){
		return true;
	}else if(symbolA== '[' && symbolB== ']'){
		return true;
	}else{
		return false;
	}
}

//Check for Balanced Parentheses
bool checkBalancedParentheses(struct Stack* topOfStack,string expression){

	for(int i=0;i<expression.length();i++){

		if(expression[i]== '(' || expression[i]== '{' || expression[i]== '['){
			topOfStack = Push(topOfStack,expression[i]);
		}else if(expression[i]== ')' || expression[i]== '}' || expression[i]== ']'){
			if(isEmpty(topOfStack)==true){
				return false;
			}else if(checkValidPair(Top(topOfStack),expression[i])==true){
				topOfStack = Pop(topOfStack);
			}else{
				return false;
			}
		}
	}
	if(isEmpty(topOfStack)==true){
		return true;
	}else{
		return false;
	}
}

//Print the Stack.
void printStack(struct Stack* topOfStack){

	while(topOfStack!=NULL){
		cout << (*topOfStack).data;
		topOfStack = (*topOfStack).next;
	}
	cout << endl;
}


int main(){

	struct Stack* topOfStack = NULL;

	string expression;
	cout << "Enter the expression:" << endl;
	cin >> expression;

	if (checkBalancedParentheses(topOfStack,expression)==true){
		cout << "Expression is Balanced" << endl;
	}else{
		cout << "Expression is not Balanced" << endl;
	}

}