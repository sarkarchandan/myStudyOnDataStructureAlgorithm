/*
Recursive implementation for merging two sorted linked lists.
*/

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

//Merge Two Sorted Lists using Recursive methods.
struct Node* mergeSoredtedLists(struct Node* headA,struct Node* headB){

	struct Node* resultList = NULL; // Empty Result List.

	if(headA==NULL){
		return headB;
	}else if(headB==NULL){
		return headA;
	}

	if((*headA).data < (*headB).data){
		resultList = headA;
		(*resultList).next = mergeSoredtedLists((*headA).next,headB);
	}else{
		resultList = headB;
		(*resultList).next = mergeSoredtedLists(headA,(*headB).next);
	}
	return resultList;
}

int main(){

	struct Node* headA = NULL; // Empty List
	struct Node* headB = NULL; //Empty List

	int noA,noB;
	int elementA,elementB;

	cout << "First Sorted Link List: " << endl;
	cout << "Enter the no of elements that you want: " << endl;
	cin >> noA;

	for(int i=1;i<=noA;i++){

		cout << "Enter the element in sorted order: " << endl;
		cin >> elementA;
		headA = insertNodeAtTail(headA,elementA);
	}
	printList(headA);
	cout << endl;

	cout << "Second Sorted Linked List: " << endl;
	cout << "Enter the no of elements that you want: " << endl;
	cin >> noB;

	for(int j=1;j<=noB;j++){
		cout << "Enter the element in sorted order: " << endl;
		cin >> elementB;
		headB = insertNodeAtTail(headB,elementB);
	}
	printList(headB);
	cout << endl;

	cout << "Merging the Sorted Linked Lists: " << endl;
	cout << endl;

	struct Node* result = mergeSoredtedLists(headA,headB);
	printList(result);
	cout << endl;

}