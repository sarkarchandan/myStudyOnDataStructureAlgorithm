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

//convert Infix expression to Postfix expression with parentheses
string convertInfixToPostFix(struct Stack* topOfStack,string expression){
	string resultString;

	for(int i=0;i<expression.length();i++){

		if(expression[i] == '('){
			topOfStack = Push(topOfStack,expression[i]);
		}else if(isOperand(expression[i])){
			resultString = resultString + expression[i];
		}else if(isOperator(expression[i])){

			//Case I
			if(isEmpty(topOfStack)){
				topOfStack = Push(topOfStack,expression[i]);
				//Case II
			}else if(!hasHigherPriority(topOfStack,expression[i])){
				topOfStack = Push(topOfStack,expression[i]);
			}else if(hasHigherPriority(topOfStack,expression[i])){
				//Case III
				while(!isEmpty(topOfStack) && hasHigherPriority(topOfStack,expression[i])){
					resultString = resultString + Top(topOfStack);
					topOfStack = Pop(topOfStack);
				}
				topOfStack = Push(topOfStack,expression[i]);
			}


		}else if(expression[i] == ')'){
			while(!isEmpty(topOfStack) && Top(topOfStack)!='('){
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
	string expression,resultString;
	cout << "Enter the Infix exporession with parentheses: " << endl;
	cin >> expression;
	resultString = convertInfixToPostFix(topOfStack,expression);
	cout << "The Postfix string is : " << resultString << endl;

	return 0;
}