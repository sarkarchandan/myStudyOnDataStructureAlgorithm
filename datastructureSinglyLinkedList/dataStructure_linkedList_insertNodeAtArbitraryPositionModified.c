#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* listHead; // Globally declared the head.

/*
Our logic is if the positionToInsert value is entered as 0 then function will always insert at the begining. So for demonstration we will
enter few nodes at the begining and then whenever we will enter any other position, coresponding node will be entered at the definite
position.
*/
void insertElementAtPosition(int inputElement,int positionToInsert){

	struct Node* tempNodeOne = (struct Node*)malloc(sizeof(struct Node));

/*
At this moment we have created the new node in heap. In any case we don't have any doubt about the data part of the node. But the next part
of this new node is interesting.
If our chosen position is 0 then the node will be inserted at the begining. And there could be two scenarios when we enter a node at the
beginning:
	List is Empty: If the list is empty than listHead = NULL and if we want enter the new node to the empty list then this node will be
	the sole element of the list and next part of this new node will be tail and point to NULL. hence we write (*tempNodeOne).next = listHead;
	And then we want our head to point the new node i.e. head to have the address the new node. Therefore, listHead = tempNodeOne;

	List is non-Empty: If the List is nonEmpty and we want to insert the new node at the begining, then also our statements can deal with that.
	List is nonEmpty necessarily means that the listHead now points to the first node or head node i.e. listHead is having the address of the
	current head node. And while inserting the new node at the beginng we want the current head node address to be in the next part of the new node
	(*tempNodeOne).next = listHead; statement does just that. listHead has the address of the current head. and the statement assigns that address
	to the next part of the new node.
	Then we want the new node to be our current head. That means listHead to point the new Node. listHead = tempNodeOne; statement does that.

If our chosen position is something apart from 0 then the else part comes into picture. In else part first we declare another pointer to Node.
The real purpose of this pointer to Node (tempNodeTwo) is to participate in the iteration and reach to a position which is just one position
prior to our desired position. 

We want the iteration to range from 0 to < than desiredPosition-1 because if we start indexing from 0 
than our desired position must be at (n-1). But in linked list in order to insert a node at (n-1) position we need to reach to 1 position 
back than our desired position. That's why (int i=0;i<positionToInsert-1;i++).
And then what we are basically doing is we are adjusting the next parts. If our position is p then currently p-1 points to p. Now we
introduce newNode and first we point (newNode.next) to current (p) and then current (p-1) to point (newNode). So basically we are introducing
our (newNode) between the current (p-1) and current (p) at the pth position. Following two statement accomplishes that.
		(*tempNodeOne).next = (*tempNodeTwo).next;
		(*tempNodeTwo).next = tempNodeOne;
*/
	(*tempNodeOne).data = inputElement;
	if(positionToInsert==0){
		(*tempNodeOne).next = listHead;
		listHead = tempNodeOne;
	}else{
		struct Node* tempNodeTwo = listHead;
		for(int i=0;i<positionToInsert-2;i++){
			tempNodeTwo = (*tempNodeTwo).next;
		}
		(*tempNodeOne).next = (*tempNodeTwo).next;
		(*tempNodeTwo).next = tempNodeOne;
	}
}

void printList(){
	struct Node* tempNode = listHead;
	while(tempNode!=NULL){
		printf("%d ",(*tempNode).data);
		tempNode = (*tempNode).next;
	}
	printf("\n");
}

int main(){
	listHead = NULL; // Empty List

	int numberOfElements,inputElement,positionToInsert;

	printf("Enter the No of Elements in the List\n");
	scanf("%d",&numberOfElements);

	for(int i=0;i<numberOfElements;i++){
		printf("Enter the element: \n");
		scanf("%d",&inputElement);
		printf("Enter the Position: ");
		scanf("%d",&positionToInsert);
		
		insertElementAtPosition(inputElement,positionToInsert);
		printList();
	}

}