#include<stdio.h>


int main(){

/*
	int myArray[5] = {1,2,3,4,5};
	int *p = myArray;

	printf("%d\n", p);
	printf("%d\n", *p);
	printf("%d\n", *(p+2));

	printf ("%d\n", myArray);
	printf ("%d\n", *myArray);
	printf ("%d\n", *(myArray+2));

*/

	int myArray[2][3] = {2,4,6,1,7,8};
	/*
	myArray[0][0]= 2
	myArray[0][1]= 4
	myArray[0][2]= 6
	myArray[1][0]= 1
	myArray[1][1]= 7
	myArray[1][2]= 8
	*/

	int (*p)[3] = myArray;

	printf("%d\n", p); // Returns the base address of the two diamentional array
	printf("%d\n",myArray);
	
	printf("%d\n", *p);
	printf("%d\n", *myArray);

	printf("%d\n", *(*p));
	printf("%d\n", *(*p+1));
	printf("%d\n", *(*p+2));
	printf("%d\n", *(*(p+1)));
	printf("%d\n", *(*(p+1)+1));
	printf("%d\n", *(*(p+1)+2));

	for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			printf("%d",*(*(p+i)+j));
		}
		printf("\n");
	}

}
