/*
Stack Implementation to evaluate a Postfix Expression
*/

#include<iostream>
#include<stdlib.h>
#include<string>

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

//Check if the given element is an operator
bool isOperator(char element){

	if(element =='+' || element =='-' || element =='*' || element =='/'){
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

int evaluatePostfixExpression(struct Stack* topOfStack, string expression){

	for(int i=0;i<expression.length();i++){
		
		if(expression[i] == ' ' || expression[i] == ','){
			continue;
		}else if(isOperator(expression[i])==true){

			int operandB = Top(topOfStack);
			topOfStack = Pop(topOfStack);

			int operandA = Top(topOfStack);
			topOfStack = Pop(topOfStack);

			int intermediateResult = performOperation(expression[i],operandA,operandB);
			
			topOfStack = Push(topOfStack,intermediateResult);
		}else if(isNumeric(expression[i])==true){

			/*
			This implementation needs an explanation. In this implementation, we are constituting the integer from the the character.
			In brief what is happening here is we are iterating through the expression and if an element is numeric, we are extracting
			the numeric value from the caharacter.
			Here computer understands each character with it's ASCII value. Suppose our charater is '2'. What we will do to exract the
			2 as an integer is we will subtract the character '2' with charater '0'. ASCII for character '2' is 50 and ASCII for character
			'0' is 48. With subtracting we will get 2 as integer.
			If our element is a number with 2 digits then the underlying while loop will iterate twice and (operand*10) will help us to 
			constitute the two digit number. In case of three digit the loop will iterate thrice. Likewise in case it's only one digit,
			loop will iterate only once.
			But what's more important is after getting out of the loop we must decrement the i again as i--; .
			This is required because the for loop will eventually increment i. At the point we are getting out of the while loop, i's 
			value always remains so that expression[i] is our delimiter e.g. ','. Since from the persepective of for loop, we have
			processed till the character element before the delimeter so far, we want for loop to increment i in it's own pace and read
			the delimeter. Henece, it's necessary to decrement the i as i-- once we are out of the while loop.
			This way for loop will naturally increment i and read the delimeter. Otherwise delimeter will be skipped and there will be
			a problem in the normal iteration of the imput expression.
			*/
			int operand = 0;
			while(isNumeric(expression[i])==true && i < expression.length()){

				operand = (operand*10)+(expression[i]-'0');
				i++;
			}
			i--;
			topOfStack = Push(topOfStack,operand);
		}	
	}
	return Top(topOfStack);
}


int main(){

	struct Stack* topOfStack = NULL; // Empty Stack.

	string expression;
	cout << "Enter the Expression: " << endl;
	cin >> expression;

	cout << "Evaluation of given Postfix expression produces: " << evaluatePostfixExpression(topOfStack,expression) << endl;
}