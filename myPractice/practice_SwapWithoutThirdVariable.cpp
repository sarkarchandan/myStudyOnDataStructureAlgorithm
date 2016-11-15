#include<iostream>

using namespace std;

int main(){

	int a = 2;
	int b = 3;

	cout << "Old Value of a: " << a << endl;
	cout << "Old Value of b: " << b << endl;

	a = a+b;
	b = a-b;
	a = a-b;

	cout << "New Value of a: " << a << endl;
	cout << "New Value of b: " << b << endl;

}