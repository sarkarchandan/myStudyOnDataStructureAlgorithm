/*
Using multi-diamensional arrays as function arguments.
*/
#include<stdio.h>

void cool2DPrint(int (*arrayArg)[3]){

	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){

			printf("%d", *(*(arrayArg+i)+j));
		}
		printf("\n");
	}
}

void cool3DPrint(int (*arrayArg)[2][2]){

	for(int i=0;i<3;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){

			printf("%d ",*(*(*(arrayArg+i)+j)+k));
			}
		printf("\n");
		}	

	}
}

int main(){

int my2DArray[2][3] = {1,2,3,4,5,6};
int my3DArray[3][2][2] = {1,2,3,4,5,6,7,8,9,10,11,12};
cool2DPrint(my2DArray);
printf("\n");
cool3DPrint(my3DArray);

}