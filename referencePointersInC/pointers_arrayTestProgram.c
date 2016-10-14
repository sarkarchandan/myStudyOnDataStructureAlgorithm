//
// Created by chandan on 18.09.16.






#include<stdio.h>
#include<string.h>

int main() {

    char charArray[4];

    charArray[0] = 'J';
    charArray[1] = 'O';
    charArray[2] = 'H';
    charArray[3] = 'N';
//    charArray[4] = '\0';

    printf("%s\n", charArray);

    printf("The length of the string is: %d\n", strlen(charArray));
}