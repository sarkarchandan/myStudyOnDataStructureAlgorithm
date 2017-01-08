#include <stdio.h>

int main(int argc,const char *argb[]){

	/*
	This small program will demonstrate simple increment operations in C.
	*/
	int a = 0;
	printf("%d\n",a++); // In this statement the print action happened before and then the increment. O/P = 0
	printf("%d\n",++a); // In this statement the increment action happened before and then the print. O/P = 2
	return 0;
}