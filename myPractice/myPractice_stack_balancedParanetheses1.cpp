#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct Stack{
	char data;
	struct Stack* next;
};

//Check for the empty Stack
bool isEmpty(struct Stack* topOfStack){
	if(topOfStack==NULL){
		return true;
	}else{
		return false;
	}
}

//Create a new node for Stack
struct Stack* createStackNode(char element){
	struct Stack* newStackNode = new Stack();
	(*newStackNode).data = element;
	(*newStackNode).next = NULL;
	return newStackNode;
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


//Pop  operation for the Stack
struct Stack* Pop(struct Stack* topOfStack){
	if(isEmpty(topOfStack)){
		cout << "Stack Underflow !!!" << endl;
	}else{
		struct Stack* tempStack = topOfStack;
		topOfStack = (*tempStack).next;
		delete(tempStack);
	}
	return topOfStack;
}


//Top operation for the Stack
char Top(struct Stack* topOfStack){
	if(isEmpty(topOfStack)){
		cout << "Stack Underflow !!!" << endl;
	}else{
		return (*topOfStack).data;
	}
}

//Check for valid pair of characters
bool checkValidPair(struct Stack* topOfStack,char element){
	if(Top(topOfStack) == '(' && element == ')'){
	return true;
	}else if(Top(topOfStack) == '{' && element == '}'){
		return true;
	}else if(Top(topOfStack) == '[' && element == ']'){
		return true;
	}else{
		return false;
	}
}

//Check for balanced parentheses
bool checkBalancedParentheses(struct Stack* topOfStack,string expression){
	for(int i=0;i<expression.length();i++){
		if(expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
			topOfStack = Push(topOfStack,expression[i]);
		}else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']'){
			if(isEmpty(topOfStack)){
				return false;
			}else if(checkValidPair(topOfStack,expression[i])){
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

int main(int argc, char const *argv[])
{
	struct Stack* topOfStack = NULL; // Declaring empty Stack.
	string expression;
	cout << "Enter the expression that you want to evaluate: " << endl;
	cin >> expression;
	if(checkBalancedParentheses(topOfStack,expression)){
		cout << "The expression is balanced." << endl;
	}else{
		cout << "The expression is not balanced." << endl;
	}
	return 0;
}