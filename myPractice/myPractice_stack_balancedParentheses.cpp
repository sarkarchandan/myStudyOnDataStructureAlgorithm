#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Stack{
	char data;
	struct Stack* next;
};

//Create a new Stack Node
struct Stack* createStackNode(char element){
	struct Stack* newStackNode = new Stack();
	(*newStackNode).data = element;
	(*newStackNode).next = NULL;
	return newStackNode;
}

//isEmpty Stack operation
bool isEmpty(struct Stack* topOfStack){
	if(topOfStack==NULL){
		return true;
	}else{
		return false;
	}
}

//Push operation for the Stack
struct Stack* Push(struct Stack* topOfStack,char element){
	struct Stack* newStackNode = createStackNode(element);
	if(isEmpty(topOfStack)){
		topOfStack = newStackNode;
	}else{
		(*newStackNode).next = topOfStack;
		topOfStack = newStackNode;
	}
	return topOfStack;
}

//Pop operation for the Stack
struct Stack* Pop(struct Stack* topOfStack){
	if(isEmpty(topOfStack)){
		cout << "Stack underflow !!!" << endl;
	}else{
		struct Stack* tempStack = topOfStack;
		topOfStack = (*tempStack).next;
		delete(tempStack);
	}
	return topOfStack;
}

//Top operation for the Stack
char Top(struct Stack* topOfStack){
	char topChar;
	if(isEmpty(topOfStack)){
		cout << "Stack underflow !!!" << endl;
	}else{
		topChar =  (*topOfStack).data;
	}
	return topChar;
}

//Check for valid pair of parenthesess
bool checkValid(char charA,char charB){
	if(charA == '(' && charB == ')'){
		return true;
	}else if(charA == '{' && charB == '}'){
		return true;
	}else if(charA == '[' && charB == ']'){
		return true;
	}else{
		return false;
	}
}

//Check for balanced parentheses operation
bool checkBalancedParentheses(struct Stack* topOfStack,string expression){
	for(int i=0;i<expression.length();i++){
		if(expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
			topOfStack = Push(topOfStack,expression[i]);
		}else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']'){
			if(isEmpty(topOfStack)){
				return false;
			}else if(checkValid(Top(topOfStack),expression[i])){
				topOfStack = Pop(topOfStack);
			}else{
				return false;
			}
		}
	}
	if(isEmpty(topOfStack)){
		return true;
	}else{
		return false;
	}
}


int main(){

	struct Stack* topOfStack = NULL; //Declaring empty Stack
	string expression,choice;
	cout << "This is a Stack implementation of the balanced parentheses problem !!!" << endl;
	do{
		cout << "Do you want to try an expression. Enter Yes to proceed. Enter anything else to exit: " << endl;
		cin >> choice;
		if(choice != "Yes"){
			cout << "Thanks for trying out the program." << endl;
			break;
		}
		cout << "Enter an expression to check if it is balanced or not: " << endl;
		cin >> expression;
		if(checkBalancedParentheses(topOfStack,expression)){
			cout << "The expression is balanced !!!" << endl;
		}else{
			cout << "The expression is not balanced !!!" << endl;
		}
		
	}while(choice == "Yes");
	
}