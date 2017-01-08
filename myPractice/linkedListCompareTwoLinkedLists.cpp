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

//Compare two linked lists and return boolean
bool compareTwoLinkedLists(struct Node* headA,struct Node* headB){

	struct Node* tempA = headA;
	struct Node* tempB = headB;

	bool flag=true;
	while((*tempA).next!=NULL){
		if((*tempB).next==NULL){
			flag=false;
			break;
		}else if((*tempA).data!=(*tempB).data){
			flag=false;
			break;
		}
		tempA=(*tempA).next;
		tempB=(*tempB).next;
	}
	if((*tempA).data != (*tempB).data || (*tempB).next!=NULL){
		flag=false;
	}
	return flag;
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

	bool flag;
	
	headA=insertAtTail(headA,3);
	headA=insertAtTail(headA,3);
	headA=insertAtTail(headA,3);
	headA=insertAtTail(headA,3);
	headA=insertAtTail(headA,3);

	headB=insertAtTail(headB,3);
	headB=insertAtTail(headB,3);
	headB=insertAtTail(headB,3);
	headB=insertAtTail(headB,3);
	headB=insertAtTail(headB,3);
	
	cout << "Following is our First linked list:" << endl;
	printList(headA);
	cout << endl;
	cout << "Following is our Second linked list:" << endl;
	printList(headB);
	cout << endl;

	flag=compareTwoLinkedLists(headA,headB);
	if(flag==true){
		cout << "The Linked Lists are Equal."  << endl;
	}else{
		cout << "The Linked Lists are NOT Equal."  <<endl;
	}
}