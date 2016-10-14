#include<stdio.h>
#include<math.h>

/*
This is a basic implementation of call-back function using function pointer.
*/

/*
void sayHello(){
	printf("Hello\n");
}

void callHello(void (*ptr)()){
	ptr();
}

int main(){
	void (*p)();
	p=&sayHello;
	callHello(p);
}
*/

/*
Use Case of call-back function using function pointer.
Implementing bubble sort.
*/

int compareNumbers(int a,int b){
	if(a>b){
		return 1;
	}else{
		return -1;
	}

}

int absoluteCompare(int a,int b){
	if(abs(a)>abs(b)){
		return 1;
	}else{
		return -1;
	}
}

void bubbleSort(int *myArray,int n,int (*ptr)(int,int)){
	int temp;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(ptr(myArray[j],myArray[j+1])>0){
				temp = myArray[j];
				myArray[j]=myArray[j+1];
				myArray[j+1]=temp;	
			}
		}
	}
}

int main(){

	int myArray[] = {-31,22,-1,50,-6,4};
	int size = sizeof(myArray)/sizeof(int);
	bubbleSort(myArray,size,compareNumbers);
	//bubbleSort(myArray,size,absoluteCompare);
	for(int i=0;i<size;i++){
		printf("%d \n",myArray[i]);
	}
}

