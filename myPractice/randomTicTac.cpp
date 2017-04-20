#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	char tictacArray[3][3];

	char* array[3] = new char[3];

	for(int i=0;i < 3;i++){
		for(int j=0;j < 3;j++){
			*(*(tictacArray+i)+j) = '+';
		}
	}

	for(int i=0;i < 3;i++){
		for(int j=0;j < 3;j++){
			cout << *(*(tictacArray+i)+j) << " ";
		}
		cout << endl;
	}

	int row,column;
	char symbol;
	cout << "Enter the position in space separted manner for the row and the column: " << endl;
	cin >> row >> column >> symbol;
	
	*(*(tictacArray+row)+column) = symbol;

	for(int i=0;i < 3;i++){
		for(int j=0;j < 3;j++){
			cout << *(*(tictacArray+i)+j) << " ";
		}
		cout << endl;
	}

	return 0;
}