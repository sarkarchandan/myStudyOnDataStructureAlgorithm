/*
Accessing values from a 3-d array using pointer.
*/
#include<stdio.h>

int main(){

int myArray[3][2][2] = {1,2,3,4,5,6,7,8,9,10,11,12};

int (*p)[2][2] = myArray;

for(int i=0;i<3;i++){
	for(int j=0;j<2;j++){
		for(int k=0;k<2;k++){

			printf("%d",*(*(*(p+i)+j)+k));
			}
		printf("\n");
		}	

	}

}

