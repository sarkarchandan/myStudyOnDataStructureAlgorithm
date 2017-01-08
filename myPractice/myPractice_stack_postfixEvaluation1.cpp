/*
Stack Implementation to evaluate a Postfix Expression
*/
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct Stack{
	int data;
	struct Stack* next;
};

//Get a new stack node.
struct Stack* getNewStackNode(int data){
	struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
	(*newNode).data = data;
	(*newNode).next = NULL;
	return newNode;
}

//Push node to the top of the stack.
struct Stack* Push(struct Stack* topOfStack,int data){

	struct Stack* newStackNode = getNewStackNode(data);

	if(topOfStack==NULL){
		topOfStack = newStackNode;
		return topOfStack;
	}else{
		(*newStackNode).next = topOfStack;
		topOfStack = newStackNode;
	}
	return topOfStack;
}

//Pop node from the top of the stack
struct Stack* Pop(struct Stack* topOfStack){

	if(topOfStack==NULL){
		cout << "Stack Underflow !!!" << endl;
	}else{
		struct Stack* temoNode = topOfStack;
		topOfStack = (*temoNode).next;
		free(temoNode);
	}
	return topOfStack;
}

//Top element of the stack
int Top(struct Stack* topOfStack){

	struct Stack* tempNode = topOfStack;

	if(topOfStack==NULL){
		cout << "Stack Underflow !!!" << endl;
	}else{
		return(*tempNode).data;
	}
}

//Check if the stack is empty
bool isEmpty(struct Stack* topOfStack){

	if(topOfStack==NULL){
		return true;
	}else{
		return false;
	}
}

//Check if the character is numeric
bool isNUmeric(char element){
	if(element >= '0' && element <= '9'){
		return true;
	}else{
		return false;
	}
}

//Check if the element is an operator
bool isOperator(char element){
	if(element == '+'){
		return true;
	}else if(element == '-'){
		return true;
	}else if(element == '*'){
		return true;
	}else if(element == '/'){
		return true;
	}else{
		return false;
	}
}

//Perform an
int performOperation(char element, int operandA,int operandB){

	if(element =='+'){
		return (operandA+operandB);
	}else if(element =='-'){
		return (operandA-operandB);
	}else if(element =='*'){
		return (operandA*operandB);
	}else if(element=='/'){
		return (operandA/operandB);
	}else{
		cout << "Something went wrong !!!" <<endl;
	}
}

//Evaluate the post fix expression
int evaluatePostfixExpression(struct Stack* topOfStack,string expression){
	for(int i=0;i<expression.length();i++){
		if(expression[i] == ' ' || expression[i] == ','){
			continue;
		}else if(isOperator(expression[i])){
			int operandB = Top(topOfStack);
			topOfStack = Pop(topOfStack);

			int operandA = Top(topOfStack);
			topOfStack = Pop(topOfStack);
			int intermediateResult = performOperation(expression[i],operandA,operandB);
			topOfStack = Push(topOfStack,intermediateResult);
		}else if(isNUmeric(expression[i])){

			int operand = 0;
			while(isNUmeric(expression[i]) && i<expression.length()){
				operand = (operand*10)+(expression[i]-'0');
				i++;
			}
			i--;
			topOfStack = Push(topOfStack,operand);
		}
	}
	return Top(topOfStack);
}

int main(int argc, char const *argv[])
{
	struct Stack* topOfStack = NULL; // Declaring empty Stack
	string expression;
	cout << "Enter the expression: " << endl;
	cin >> expression;
	int result = evaluatePostfixExpression(topOfStack,expression);
	cout << "The result is: " << result << endl;
	return 0;
}