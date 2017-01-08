#include <stdio.h>

int main(int argc, const char *argv[]){

	int bigInt = 2147483647;
	printf("The Big Integer is: %d\n",bigInt+1);
	/*In here we are trying to see how big is Integer datatype in C. Our assumption is the maximum number we can store in Integer
	datatype is 2147483647 and what if we print the no with an added 1 to it.
	We will get a negative number which is exactly -2147483647 .
	This no is the smallest posssible no that we can store in an Integer datatype in C. That proves that the 2147483647 is the 
	maximum no that we can store inside the Integer datatype in C.

}