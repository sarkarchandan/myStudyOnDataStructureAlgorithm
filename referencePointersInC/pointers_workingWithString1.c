#include<stdio.h>


void coolPrint(char stringArray[]){

	while(*stringArray != '\0'){

		printf("%c", *stringArray);
		stringArray++;
	}
}


int main(){

	char myString[] = "Hello World";

	coolPrint(myString);
	printf("\n");
}