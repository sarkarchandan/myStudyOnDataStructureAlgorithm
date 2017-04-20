#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void setData(char **array,int row,int column,char symbol){
	*(*(array+row)+column) = symbol;
}


int main(int argc, char const *argv[])
{
	//we are declaring Pointer to Pointer to character
	char **array;

	//We are 
	array = new char *[3];

	for(int count = 0;count < 3;count++){
		*(array+count) = new char[3];
	}

	for(int i=0;i < 3;i++){
		for(int j=0;j < 3;j++){
			*(*(array+i)+j) = '+';
		}
	}

	for(int i=0;i < 3;i++){
		for(int j=0;j < 3;j++){
			cout << *(*(array+i)+j) << " ";
		}
		cout << endl;
	}

	cout << endl;

	// int row,column;
	// char charc;

	// cout << "Enter the row,column and the character value sperated by the space: " << endl;
	// cin >> row >> column >> charc;

	// setData(array,row,column,charc);

	// for(int i=0;i < 3;i++){
	// 	for(int j=0;j < 3;j++){
	// 		cout << *(*(array+i)+j) << " ";
	// 	}
	// 	cout << endl;
	// }

	for(int count=0;count < 3;count++){
		delete(*(array+count));
	}
	delete []array;

	srand(time(0));
	for(int i=0;i<10;i++){
		cout << rand() % 1 << "," ;
	}
	cout << endl;

	return 0;
}