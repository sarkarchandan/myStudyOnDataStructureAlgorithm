/*
All Strings are treated as character arrays in C and the most crucial concept is in C all strings are null terminated.
*/

#include<stdio.h>
#include<string.h>

int main(){

	char charArray[10];

	charArray[0]='J';
	charArray[1]='O';
	charArray[2]='H';
	charArray[3]='N';
	charArray[4]='\0';

	printf("%s\n",charArray);

	printf("The length of the string is: %d\n", strlen(charArray));


	/*
	However we can use the String literal to store a string in the character array.
	While using String literal, null(\0) character is implicit i.e. program automatically puts a null character at the end of the string.
	*/

	char newCharArray[10] = "MARTIN";
	printf("%s\n", newCharArray);

	char* p;
	p = &newCharArray;
	printf("%c\n",*(p+1));
	printf("%c\n", p[2]);
	printf("%d\n", p);
}