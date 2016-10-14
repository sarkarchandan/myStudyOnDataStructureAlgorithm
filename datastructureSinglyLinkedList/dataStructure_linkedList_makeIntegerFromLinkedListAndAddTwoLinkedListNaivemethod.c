#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
	int data;
	struct Node* next;
};


//Insert element at the end
struct Node* insertAtEnd(struct Node** listHead,int element){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = element;
	(*newNode).next = NULL;

	if((*listHead)==NULL){
		(*listHead) = newNode;
		return (*listHead);
	}else{
		struct Node* tempNode = (*listHead);
		while((*tempNode).next!=NULL){
			tempNode = (*tempNode).next;
		}
		(*tempNode).next = newNode;
	}
	return (*listHead);
}

//Make Integer from List
int makeIntegerFromList(struct Node* listHead){
	int numberOfElements = 0;
	int result = 0;
	int myArray[10];
	int count;

	while(listHead!=NULL){

		myArray[numberOfElements] = ((*listHead).data);
		listHead = (*listHead).next;
		numberOfElements++;
	}

	count = numberOfElements-1;

	for (int i=0;i<numberOfElements;i++){
		
		if(count>=0)
		result = result + (myArray[i]*(int)pow(10,count));
		count --;
	}
	
	return result;
}

//Make List from Integer
struct Node* makeListFromInteger(struct Node** listResult,int element){

	int reminder;
	int quotient = element;

	while(quotient!=0){

		quotient = (element/10);
		reminder = (element%10);

		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		(*newNode).data = reminder;

		if((*listResult)==NULL){
			(*newNode).next = NULL;
			(*listResult) = newNode;
		}else{
			(*newNode).next = (*listResult);
			(*listResult) = newNode;
		}

		element = quotient;
	}

	return (*listResult);
}

//Naive recursive print
void printList(struct Node* listResult){

	if(listResult==NULL){
		return;
	}
	printf("%d ",(*listResult).data);
	printList((*listResult).next);
}



int main(){

	struct Node* listHeadFirst = NULL;
	////////////////////////////////////
	listHeadFirst = insertAtEnd(&listHeadFirst,2);
	listHeadFirst = insertAtEnd(&listHeadFirst,4);
	listHeadFirst = insertAtEnd(&listHeadFirst,6);
	listHeadFirst = insertAtEnd(&listHeadFirst,8);
	listHeadFirst = insertAtEnd(&listHeadFirst,1);
	////////////////////////////////////

	struct Node* listHeadSecond = NULL;
	///////////////////////////////////
	listHeadSecond = insertAtEnd(&listHeadSecond,1);
	listHeadSecond = insertAtEnd(&listHeadSecond,9);
	listHeadSecond = insertAtEnd(&listHeadSecond,5);
	listHeadSecond = insertAtEnd(&listHeadSecond,3);
	//////////////////////////////////

	int Sum = makeIntegerFromList(listHeadFirst)+makeIntegerFromList(listHeadSecond);

	struct Node* listResult = NULL;

	listResult = makeListFromInteger(&listResult,Sum);

	printf("First Input List: \n");
	printList(listHeadFirst);
	printf("\n");

	printf("Second Input List: \n");
	printList(listHeadSecond);
	printf("\n");
	
	printf("The Result List is: \n");
	printList(listResult);
	printf("\n");

}