#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node{
	int data;
	struct Node* next;
};

//Cretae a New Node
struct Node* createNewNode(int element){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data=element;
	(*newNode).next=NULL;
	return newNode;
}

//Insert new node at tail of the linked list
struct Node* insertAtTail(struct Node* head,int element){
	struct Node* newNode = createNewNode(element);
	if(head==NULL){
		head=newNode;
	}else{
		struct Node* tempNode = head;
		while((*tempNode).next!=NULL){
			tempNode=(*tempNode).next;
		}
		(*tempNode).next=newNode;
	}
	return head;
}

//Merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* headA,struct Node* headB){

	struct Node* result=NULL;

	if(headA==NULL){
		return headB;
	}else if(headB==NULL){
		return headA;
	}
	if((*headA).data <= (*headB).data){
		result = headA;
		(*result).next=mergeSortedLists((*headA).next,headB);
	}else if((*headB).data <= (*headA).data){
		result = headB;
		(*result).next=mergeSortedLists(headA,(*headB).next);
	}
	return result;
}

//Print Linked List recursively
void printList(struct Node* head){
	struct Node* tempNode = head;
	if(tempNode==NULL){
		return;
	}
	cout << (*tempNode).data << " ";
	printList((*tempNode).next);
}


int main(){

		struct Node* headA = NULL;
	struct Node* headB = NULL;

	
	headA=insertAtTail(headA,3);
	headA=insertAtTail(headA,17);
	headA=insertAtTail(headA,67);
	headA=insertAtTail(headA,89);
	headA=insertAtTail(headA,110);

	headB=insertAtTail(headB,18);
	headB=insertAtTail(headB,89);
	headB=insertAtTail(headB,110);
	headB=insertAtTail(headB,254);
	headB=insertAtTail(headB,367);

	cout << "Following is our First linked list:" << endl;
	printList(headA);
	cout << endl;
	cout << "Following is our Second linked list:" << endl;
	printList(headB);
	cout << endl;

	struct Node* resultList = mergeSortedLists(headA,headB);
	cout << "Following is the result list after merge:" <<endl;
	printList(resultList);
	cout << endl;

}