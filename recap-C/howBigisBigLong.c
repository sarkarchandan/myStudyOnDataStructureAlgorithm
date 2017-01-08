#include <stdio.h>

int main(int argc,const char *argv[]){

	long bigLong = 9223372036854775807;
	printf("The Big Long is: %ld\n",bigLong+1);
	/*
	In this program snippet we would like to understand what is really the biggest possible long datatype no we can possibly store
	inside the long datatype in C.
	We have an assumption that the no should be 9223372036854775807. The output in this case with added 1 is -9223372036854775808.
	That indeed proves that the biggest possible long datatype no that we can store inside the long datatype in C is 9223372036854775807.
	And when added by 1 we get the smallest possible no that the long datatype can storein C which is -9223372036854775808.
	*/

}