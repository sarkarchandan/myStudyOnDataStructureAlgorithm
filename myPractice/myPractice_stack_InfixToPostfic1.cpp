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
		cout << "Stack Underflow from Pop!!!" <<endl;
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
		cout << "Stack Underflow from Top!!!" <<endl;
	}else{
		return (*topOfStack).data;
	}
}

//Check if the character is an operator
bool isOperator(char element){
	if(element == '+' || element == '-' || element == '*' || element == '/'){
		return true;
	}else{
		return false;
	}
}

//Check if the character is an operand
bool isOperand(char element){
	if(element >= '0' && element <= '9'){
		return true;
	}else if(element >= 'a' && element <= 'z'){
		return true;
	}else if(element >= 'A' && element <= 'Z'){
		return true;
	}else {
		return false;
	}
}

//Check if the the Top(stack) has the higher priority
bool hasHigherPriority(struct Stack* topOfStack,char element){
	if(isEmpty(topOfStack)){
		return false;
	}
	if(Top(topOfStack) == '/' && element == '*'){
		return true;
	}else if(Top(topOfStack) == '/' && element == '+'){
		return true;
	}else if(Top(topOfStack) == '/' && element == '-'){
		return true;
	}else if(Top(topOfStack) == '*' && element == '+'){
		return true;
	}else if(Top(topOfStack) == '*' && element == '-'){
		return true;
	}else if(Top(topOfStack) == '+' && element == '-'){
		return true;
	}else{
		return false;
	}
}

//Convert the expression from Infix to Postfix
string convertInfixToPostfix(struct Stack* topOfStack,string expression){
	string resultString;
	for(int i=0;i<expression.length();i++){
		if(isOperand(expression[i])){
			resultString = resultString + expression[i];
		}else if(isOperator(expression[i])){
			if(isEmpty(topOfStack)){
				topOfStack = Push(topOfStack,expression[i]);
			}else if(!hasHigherPriority(topOfStack,expression[i])){
				topOfStack = Push(topOfStack,expression[i]);
			}else if(hasHigherPriority(topOfStack,expression[i])){

				while(hasHigherPriority(topOfStack,expression[i]) && isEmpty(topOfStack)==false){
					resultString = resultString + Top(topOfStack);
					topOfStack = Pop(topOfStack);
				}
				topOfStack = Push(topOfStack,expression[i]);
			}

		}
	}
	while(isEmpty(topOfStack)==false){
		resultString = resultString + Top(topOfStack);
		topOfStack = Pop(topOfStack);
	}
	return resultString;
}


int main(int argc, char const *argv[])
{
	struct Stack* topOfStack = NULL; // Declaring the empty Stack.
	string expression;
	cout << "Enter the expression: " << endl;
	cin >> expression;
	string resultString = convertInfixToPostfix(topOfStack,expression);
	cout << "The resulting postfix expression is: " << resultString << endl;
	return 0;
}