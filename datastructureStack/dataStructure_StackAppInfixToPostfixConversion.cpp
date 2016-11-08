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
string convertInfixToPostfix(struct Stack* topOfStack,string Expression){

	string resultString;

	for(int i=0;i<Expression.length();i++){
		/*
		If the current character is an operand, append the character to Postfix string.	
		*/
		if(isOperand(Expression[i])==true){
			resultString = resultString+Expression[i];
		/*
		If the charater is an operator there could be three cases.
		*/
		}else if(isOperator(Expression[i])==true){

			/*
			If the character is an operator and Stack is empty, Push the character to the Stack
			*/
			if(isEmpty(topOfStack)){
				topOfStack = Push(topOfStack,Expression[i]);

			/*
			If the character is an operator and stack is NOT empty, check if the Top(topOfStack) has a higher priority operator.
			If Top(topOfStack) is not a higher priority operator, Push the character to the Stack.
			*/	
			}else if(!hasHigherPriority(topOfStack,Expression[i])){
			
				topOfStack = Push(topOfStack,Expression[i]);
			
			/*
			If the character is an operator and stack is NOT empty, check if the Top(topOfStack) has a higher priority operator.
			If the Top(topOfStack) is indeed a higher priority operator, Start a Loop with the condition that as long as Stack is
			not empty and Top(topOfStack) has higher priority operator.
			*/
			}else if(hasHigherPriority(topOfStack,Expression[i])){

				//Loop Start: Pop each character from the Stack and append to Postfix String.
				while(!isEmpty(topOfStack) && hasHigherPriority(topOfStack,Expression[i])==true){
					resultString = resultString+Top(topOfStack);
					topOfStack = Pop(topOfStack);
				}
				//Loop End: When Top(topOfStack) no longer has a higher priority operator loop ends And Push the current
				//character from the expression to the Stack.
				topOfStack = Push(topOfStack,Expression[i]);
			}
		}
	}
	/*
	Done with the iteration across the Infix expression. Now flush the stack and append the Top(topOfStack) characters to
	Postfix string.
	*/
	while(!isEmpty(topOfStack)){
		resultString=resultString+Top(topOfStack);
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
	cout << convertInfixToPostfix(topOfStack,expression) << endl;

}