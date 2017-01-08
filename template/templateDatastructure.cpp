#include <iostream>
#include <stdlib.h>
using namespace std;

/**
Structure definition if needed.
*/

/**
Function definitions
*/


int main(){

	cout << "This is the <Name of the Implementation> implementation." << endl;
	cout << "Enter 1 to <functionality 1>" << endl;
	cout << "Enter 2 to <functionality 2>" << endl;
	cout << "Enter 3 to <functionality 3>" << endl;
	cout << "Enter other number to exit." << endl;

	int choice;

	do{

		cout << "Enter your choice: " << endl;
		cin >> choice;

		switch(choice){
			case 1:
				/**
				code for functionality 1
				*/
				break;
			case 2:
				/**
				code for functionality 2
				*/
				break;
			case 3:
				/**
				code for functionality 3
				*/
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