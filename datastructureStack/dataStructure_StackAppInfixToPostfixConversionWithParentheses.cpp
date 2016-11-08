#include<iostream>
#include<stdlib.h>
#include<string>

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


//Operation to convert Infix expression to Postfix expression
string convertInfixToPostfixWithParentheses(struct Stack* topOfStack,string Expression){

	string resultString;

	for(int i=0;i<Expression.length();i++){

		/*
		If Opening Bracket, Push to Stack without any exception.
		*/
		if(Expression[i]=='('){
			topOfStack = Push(topOfStack,Expression[i]);

			/*
			If Operand, Append to Postfix String without any exception.
			*/
		}else if(isOperand(Expression[i])==true){
			resultString = resultString+Expression[i];

			/*
			If Operator, three possible cases
			*/
		}else if(isOperator(Expression[i])==true){

			/*
			Case I: If Operator, and Empty Stack, Push to Stack without exception.
			*/
			if(isEmpty(topOfStack)==true){

				topOfStack = Push(topOfStack,Expression[i]);

				/*
				Case II: If Operator, Not Empty Stack and Not Top of Stack has higer priority, Push the character to Stack.
				*/
			}else if(!hasHigherPriority(topOfStack,Expression[i])){
				
				topOfStack = Push(topOfStack,Expression[i]);

				/*
				Case III: If Operator, Not Empty Stack and Top of Stack has higher priority, Iterate loop until the top Of
				Stack has higher priority operator and append to the Postfix string.
				*/
			}else if(hasHigherPriority(topOfStack,Expression[i])==true){

				while(!isEmpty(topOfStack) && hasHigherPriority(topOfStack,Expression[i])==true){

					resultString=resultString+Top(topOfStack);
					topOfStack = Pop(topOfStack);
				}
				topOfStack = Push(topOfStack,Expression[i]);
			}

			/*
			If Closing Bracket, Iterate loop and Pop the top elements from the Stack and append to the Postfix string
			until opening bracket appears at the top of Stack.
			*/
		}else if(Expression[i]==')'){

			while(!isEmpty(topOfStack) && Top(topOfStack)!='('){

				resultString = resultString+Top(topOfStack);
				topOfStack = Pop(topOfStack);
			}
			//When opening Bracket appears get out of the loop and then pop the opening bracket as well.
			topOfStack = Pop(topOfStack);
		}
	}
	//When done with iterating through the input Expression flush the stack and add all top elements to the Postfix String.
	while(!isEmpty(topOfStack)){
		resultString = resultString+Top(topOfStack);
		topOfStack = Pop(topOfStack);
	}
	return resultString;
}

int main(){

	struct Stack* topOfStack = NULL; //Empty Stack

	string expression;

	cout << "Enter the Infix expression: " << endl;
	cin >> expression;
	cout << "Postfix Expression is: " << endl;
	cout << convertInfixToPostfixWithParentheses(topOfStack,expression) << endl;

}