#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node{
	int data;
	struct Node* next;
};


//Insert a node at the end of the list.
struct Node* insertNodeAtTail(struct Node* listHead, int element){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = element;
	(*newNode).next = NULL;

	if(listHead==NULL){
		listHead=newNode;
	}else{
		struct Node* tempNode = listHead;
		while((*tempNode).next!=NULL){
			tempNode = (*tempNode).next;
		}
		(*tempNode).next = newNode;
	}
	return listHead;
}

//Print the initial list.
void printList(struct Node* listHead){

	struct Node* tempNode = listHead;

	while(tempNode!=NULL){
		cout << (*tempNode).data << " ";
		tempNode = (*tempNode).next;
	}
	cout << endl;
}

//Compare two Linked lists and return boolean true or false
bool compareTwoLists(struct Node* headA,struct Node* headB){

	if(headA==NULL && headB==NULL){
		return true;
	}
	if(headA==NULL || headB==NULL){
		return false;
	}

	struct Node* tempA = headA;
	struct Node* tempB = headB;

	bool flag = true;

	while((*tempA).next!=NULL){
		//If there is mismatch between the sizes of two linked lists, this check can catch it.
		//Specifically if the second list is smaller in size, this condition will return false and loop will break;
		if((*tempB).next==NULL){
			flag = false;
			break;
		}

		if((*tempA).data != (*tempB).data){
			flag = false;
			break;
		}

		tempA = (*tempA).next;
		tempB = (*tempB).next;
	}

	if((*tempA).data != (*tempB).data || (*tempB).next !=NULL){
		flag = false;
	}
	return flag;
}


int main(){

	struct Node* headA = NULL; // Empty List
	struct Node* headB = NULL; //Empty List

	int noA,noB;
	int elementA,elementB;

	cout << "First Link List: " << endl;
	cout << "Enter the no of elements that you want: " << endl;
	cin >> noA;

	for(int i=1;i<=noA;i++){

		cout << "Enter the element: " << endl;
		cin >> elementA;
		headA = insertNodeAtTail(headA,elementA);
	}
	printList(headA);
	cout << endl;

	cout << "Second Linked List: " << endl;
	cout << "Enter the no of elements that you want: " << endl;
	cin >> noB;

	for(int j=1;j<=noB;j++){
		cout << "Enter the element: " << endl;
		cin >> elementB;
		headB = insertNodeAtTail(headB,elementB);
	}
	printList(headB);
	cout << endl;

	cout << "Comparing the Linked Lists, we have concluded that: " << endl;
	cout << endl;
	if(compareTwoLists(headA,headB)==true){
		cout << "Two Lists are Equal..." << endl;
	}else{
		cout << "Two Lists fight each other !!!" << endl;
	}

}