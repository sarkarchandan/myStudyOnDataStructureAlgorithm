#include <stdio.h>


int main(int argc,const char *argv[]){

	int age;
	printf("Enter your age: \n");
	scanf("%d",&age);

	if(age < 13){
		printf("You are in kinder garten!!!.\n");
	}else if(age > 13 && age < 18){
		printf("You are in elementary school !!!.\n");
	}else{
		printf("You are in high school !!!\n");
	}

	int result = (age < 13) ? 0 : 1;
	if(result == 0){
		printf("You are a kid !!!\n");
	}else{
		printf("You are not a kid !!!\n");
	}

	/*
	This program snippet was a demonstrarion of how normal conditional statements work in C language.
	*/

}