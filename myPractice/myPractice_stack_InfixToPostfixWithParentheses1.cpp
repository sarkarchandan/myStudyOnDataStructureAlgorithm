#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct Stack{
	char data;
	struct Stack* next;
};

//Create New Stack Node
struct Stack* createNewStackNode(char element){
	struct Stack* newStackNode = (struct Stack*)malloc(sizeof(struct Stack));
	(*newStackNode).data = element;
	(*newStackNode).next = NULL;
	return newStackNode;
}

//isEmpty operation for Stack
bool isEmpty(struct Stack* topOfStack){
	if(topOfStack==NULL){
		return true;
	}else{
		return false;
	}
}

//Push operation for Stack
struct Stack* Push(struct Stack* topOfStack,char element){

	struct Stack* newStackNode = createNewStackNode(element);
	if(isEmpty(topOfStack)==true){
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

	if(isEmpty(topOfStack)==true){
		cout << "Stack Underflow !!!" <<endl;
	}else{
		struct Stack* nodeToBeDeleted = topOfStack;
		topOfStack = (*nodeToBeDeleted).next;
		free(nodeToBeDeleted);
	}
	return topOfStack;
}

//Top operation for Stack
char Top(struct Stack* topOfStack){

	if(isEmpty(topOfStack)==true){
		cout << "Stack Underflow !!!" <<endl;
	}else{
		return (*topOfStack).data;
	}
}

//Method to check whether the current top element of the stack has the higher priority over the current character of the expression.
bool hasHigherPriority(struct Stack* topOfStack,char currentChar){
	if(isEmpty(topOfStack)){
		return false;
	}
	if(Top(topOfStack)=='/' && currentChar=='*'){
		return true;
	}else if(Top(topOfStack)=='/' && currentChar=='+'){
		return true;
	}else if(Top(topOfStack)=='/' && currentChar=='-'){
		return true;
	}else if(Top(topOfStack)=='*' && currentChar=='+'){
		return true;
	}else if(Top(topOfStack)=='*' && currentChar=='-'){
		return true;
	}else if(Top(topOfStack)=='+' && currentChar=='-'){
		return true;
	}else{
		return false;
	}

}

//Check if the character is an operand
bool isOperand(char element){
	
	if(element >='0' && element <='9'){
		return true;
	}else if(element >='a' && element <='z'){
		return true;
	}else if(element >='A' && element <='Z'){
		return true;
	}else{
		return false;
	}
}

//Check if the element is an operator
bool isOperator(char element){
	if(element =='+'){
		return true;
	}else if(element =='-'){
		return true;
	}else if(element =='*'){
		return true;
	}else if(element =='/'){
		return true;
	}else{
		return false;
	}
}

//Convert the Infix expression with parentheses to the Postfix
string convertInfixToPostfixWithParentheses(struct Stack* topOfStack,string expression){
	string resultString;
	for(int i=0;i<expression.length();i++){

		if(expression[i] == '('){
			topOfStack = Push(topOfStack,expression[i]);
		}else if(isOperand(expression[i])){
			resultString = resultString + expression[i];
		}else if(isOperator(expression[i])){

			if(isEmpty(topOfStack)){
				topOfStack = Push(topOfStack,expression[i]);
			}else if(!hasHigherPriority(topOfStack,expression[i])){
				topOfStack = Push(topOfStack,expression[i]);
			}else if(hasHigherPriority(topOfStack,expression[i])){

				while(hasHigherPriority(topOfStack,expression[i]) && !isEmpty(topOfStack)){
					resultString = resultString + Top(topOfStack);
					topOfStack = Pop(topOfStack);
				}
				topOfStack = Push(topOfStack,expression[i]);
			}


		}else if(expression[i] == ')'){
			while(Top(topOfStack) != '(' && !isEmpty(topOfStack)){
				resultString = resultString + Top(topOfStack);
				topOfStack = Pop(topOfStack);
			}
			topOfStack = Pop(topOfStack);
		}
	}
	while(!isEmpty(topOfStack)){
		resultString = resultString + Top(topOfStack);
		topOfStack = Pop(topOfStack);
	}
	return resultString;
}




int main(int argc, char const *argv[])
{
	struct Stack* topOfStack = NULL; // Declaring empty Stack
	string expression;
	cout << "Enter the Infix String that you want to convert to Postfix: " << endl;
	cin >> expression;
	string resultString = convertInfixToPostfixWithParentheses(topOfStack,expression);
	cout << "The converted Postfix String is: "<< resultString << endl;
	return 0;
}