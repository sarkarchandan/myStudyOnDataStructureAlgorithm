#include <stdio.h>
#include <math.h>
#include <float.h>

int main(int argc,const char *argv[]){

	printf("Minimum Floating Point no that we can store under the float datatype is: %e\n",FLT_MIN);
	printf("Maximum Floating Point no that we can store under the float datatype is: %e\n",FLT_MAX);
	/*
	We are going to get the following output:
	Minimum Floating Point no that we can store under the float datatype is: 1.175494e-38
	Maximum Floating Point no that we can store under the float datatype is: 3.402823e+38
	These are the minimum and maximum possible floating point no we can deal with in our system. FLT_MIN and FLT_MAX are the
	constants that we can use as a result of including the math.h and float.h header files.
	*/

	/*
	Float and Double datatypes practically loose precision after 6 digits after decimal point. We can write few more statements
	to see what's actually going on..
	*/
	printf("This is about the precision regarding decimal digits..\n");
	float pi = 3.1415926;
	printf("3.1415926 + 0.0000001 = %.7f\n",pi+0.0000001);
	printf("Precision of Decimal digits is: %d\n",FLT_DIG);
	/*
	What we will observe in this case is the following:
	3.1415926 + 0.0000001 = 3.1415926
	Precision of Decimal digits is: 6
	We can see although we have tried to add 0.0000001 to the pi value after 6 digits after decimal point it didn't matter.
	As we have assumed that the decimal maintains the precision upto 6 digist after the decimal point.
	*/

	return 0;
}