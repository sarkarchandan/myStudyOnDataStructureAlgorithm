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

//Check if the given element is an operand
bool isNumeric(char element){

	if(element >= '0' && element <= '9'){
		return true;
	}else{
		return false;
	}
}

//Check if some thing is operator
bool isOperator(char character){
	if(character == '+' || character == '-' || character == '*' || character == '/'){
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
		cout << "Someting went Wrong !!!" << endl;
	}
}

//Print current Stack
void printCurrentStack(struct Stack* topOfStack){
	struct Stack* tempStack = topOfStack;
	if(tempStack==NULL){
		return;
	}
	cout << (*tempStack).data << " ";
	printCurrentStack((*tempStack).next);
}


//Evaluate the expression
int evaluatePostFixExpression(struct Stack* topOfStack,string expression){
	for(int i=0;i<expression.length();i++){

		if(expression[i] == ' ' || expression[i] == ','){
			continue;
		}else if(isOperator(expression[i])==true){
			int operandB = Top(topOfStack);
			topOfStack = Pop(topOfStack);

			int operandA = Top(topOfStack);
			topOfStack = Pop(topOfStack);
			
			int intermediateresult = performOperation(expression[i],operandA,operandB);


			topOfStack = Push(topOfStack,intermediateresult);
		}else if(isNumeric(expression[i])==true){
			int operand = 0;
			while(isNumeric(expression[i])==true && i < expression.length()){
				operand = (operand*10)+(expression[i]-'0');
				cout << "The operand is : "<< operand << endl;
				i++;
			}
			i--;
			topOfStack = Push(topOfStack,operand);
		}
		printCurrentStack(topOfStack);
	}
	return Top(topOfStack);
}


int main(){

	struct Stack* topOfStack = NULL;
	string expression;
	cout << "Enter the Postfix expression with delimiter space or ,:" << endl;
	cin >> expression;
	int result = evaluatePostFixExpression(topOfStack,expression);
	cout << "The Result of Postfix Evaluation is: " << result << endl;

}