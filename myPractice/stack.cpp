//
//  practice_Stack_LinkedListImplementation.cpp
//  HelloWorld
//
//  Created by Chandan Sarkar on 21/12/2016.
//  Copyright © 2016 Chandan. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

//Defining the structure of the Node
struct Node{
    int data;
    struct Node* next;
};

//Method for checking if the Stack is empty
bool isEmpty(struct Node* topOfStack){
    if(topOfStack==NULL){
        return true;
    }else{
        return false;
    }
}

//Method for creating a new Node for the Stack
struct Node* createNewStackNode(int element){
    struct Node* newNode = new Node();
    (*newNode).data=element;
    (*newNode).next=NULL;
    return newNode;
}

//Method for pushing an integer to the Stack
struct Node* Push(struct Node* topOfStack,int element){
    struct Node* newNode = createNewStackNode(element);
    if(isEmpty(topOfStack)){
        topOfStack=newNode;
    }else{
        (*newNode).next=topOfStack;
        topOfStack=newNode;
    }
    return topOfStack;
}

//Method for poping an integer from the Stack
struct Node* Pop(struct Node* topOfStack){
    if(isEmpty(topOfStack)){
        cout << "We have an empty Stack !!!"<<endl;
        return topOfStack;
    }else{
        struct Node* tempNode = topOfStack;
        topOfStack=(*tempNode).next;
        cout << "The popped element from the Stack is: "<<(*tempNode).data<<endl;
        delete (tempNode);
    }
    return topOfStack;
}

//Method for seeing the current top element of the Stack
void Top(struct Node* topOfStack){
    if(isEmpty(topOfStack)){
        cout << "We have an empty Stack !!!"<<endl;
    }else{
        cout << "The current top element of the Stack is: "<<(*topOfStack).data<<endl;
    }
}

//Method for printing the current state of the Stack
void printStack(struct Node* topOfStack){
    if(isEmpty(topOfStack)){
        cout << "We have an empty Stack !!!"<<endl;
    }else{
        struct Node* tempNode = topOfStack;
        while(tempNode!=NULL){
            cout<<(*tempNode).data << " ";
            tempNode=(*tempNode).next;
        }
        cout << endl;
    }
}

int main(){
    
    //Defining an empty Stack.
    struct Node* topOfStack=NULL;
    
    cout << "This is the Linked List Implementation of the Stack !!!" << endl;
    cout << "Enter 1 to Push an element to the Stack." << endl;
    cout << "Enter 2 to Pop an element from the Stack." << endl;
    cout << "Enter 3 to see the current top element of the Stack." << endl;
    cout << "Enter other number to exit." << endl;
    
    int choice,element;
    
    do{
        
        cout << "Enter your choice: " << endl;
        cin >> choice;
        
        switch(choice){
            case 1:
                cout << "Enter an element: "<<endl;
                cin >>element;
                topOfStack=Push(topOfStack,element);
                cout << "One element pushed !!!"<<endl;
                printStack(topOfStack);
                break;
            case 2:
                cout << "Trying to pop the top element from the Stack !!!" << endl;
                topOfStack=Pop(topOfStack);
                printStack(topOfStack);
                break;
            case 3:
                Top(topOfStack);
                break;
            default:
                cout << "Have a nice day." << endl;
                break;
        }
        
        if(choice < 1 || choice > 3){
            break;
        }
        
    }while(choice >= 1 || choice <=3);
    
}