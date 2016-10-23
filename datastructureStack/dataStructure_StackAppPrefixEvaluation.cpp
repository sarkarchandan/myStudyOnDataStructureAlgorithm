/*
Stack implementation for Evaluation of Prefix Expression.
*/

#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

struct Stack{
	int data;
	struct Stack* next;
};


//Create a new Stack Node
struct Stack* createNewStackNode(int data){

	struct Stack* newStackNode = (struct Stack*)malloc(sizeof(struct Stack));
	(*newStackNode).data = data;
	(*newStackNode).next = NULL;
	return newStackNode;
}

//isEmpty operation for a Stack
bool isEmpty(struct Stack* topOfStack){

	if(topOfStack==NULL){
		return true;
	}else{
		return false;
	}
}

//Push operation for Stack
struct Stack* Push(struct Stack* topOfStack,int data){

	struct Stack* newStackNode = createNewStackNode(data);

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

	struct Stack* nodeToBeDeleted = topOfStack;
	if(isEmpty(topOfStack)==true){
		cout << "Stack Underflow" << endl;
	}else{
		topOfStack = (*nodeToBeDeleted).next;
		free(nodeToBeDeleted);
	}
	return topOfStack;

}



//Top operation for Stack
int Top(struct Stack* topOfStack){

	if(isEmpty(topOfStack)==true){
		cout << "Stack Underflow" << endl;
	}else{
		return (*topOfStack).data;
	}
}



//Check if the charater element is numeric
bool isNumeric(char element){

	if(element >= '0' && element <= '9'){
		return true;
	}else{
		return false;
	}
}

//Check if the character element is an arithmetic operator
bool isOperator(char element){

	if(element =='+' || element=='-' || element=='*' || element=='/'){
		return true;
	}else{
		return false;
	}
}

//Perform a specified operation
int performOperation(char charOperator, int operandA, int operandB){
	if(charOperator =='+'){
		return (operandA+operandB);
	}else if(charOperator =='-'){
		return (operandB-operandA);
	}else if(charOperator=='*'){
		return (operandA*operandB);
	}else if(charOperator=='/'){
		return (operandA/operandB);
	}else{
		cout << "Something went Wrong !!!" <<endl;
	}
}

int evaluatePrefixExpression(struct Stack* topOfStack,string expression){

	for(int i=(expression.length()-1);i>=0;i--){

		if(expression[i]== ' ' || expression[i]==','){
			continue;
		}else if(isOperator(expression[i])==true){

			int operandB = Top(topOfStack);
			topOfStack = Pop(topOfStack);

			int operandA = Top(topOfStack);
			topOfStack = Pop(topOfStack);
			cout << expression[i] << endl;
			int intermediateResult = performOperation(expression[i],operandA,operandB);
			cout << intermediateResult << endl;
			topOfStack = Push(topOfStack,intermediateResult);
		}else if(isNumeric(expression[i])==true){

			int operand = 0;
			while(i>=0 && isNumeric(expression[i])==true){

				operand = (operand*10)+(expression[i]-'0');
				i--;
				
			}
			i++;
			cout << operand << endl;
			topOfStack = Push(topOfStack,operand);
		}

	}
	return Top(topOfStack);
}


int main(){

	struct Stack* topOfStack = NULL; //Empty Stack

	string expression;
	cout << "Enter the Prefix Expression with delimeter: " << endl;
	cin >> expression;

	cout << "Evalutation of the Prefix Expression has produced: " << evaluatePrefixExpression(topOfStack,expression) << endl;

}