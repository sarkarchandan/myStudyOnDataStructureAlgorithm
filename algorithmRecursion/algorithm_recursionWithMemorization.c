#include<stdio.h>

//Array is declared global so that it could be accessed from anywhere in the program.
int fibArray[51];

int getFibonacci(int n){

	if(n<=1){
		return n;
	}else{

		if(fibArray[n]!=-1){
			return fibArray[n];
		}else{
		fibArray[n] = getFibonacci(n-1)+getFibonacci(n-2);	
		return fibArray[n];
		}
		
	}

}


int main(){

	int inputElement,fibResult;

	for(int i=0;i<51;i++){
		fibArray[i]=-1;
	}

	printf("Enter the integer number: \n");
	scanf("%d",&inputElement);
	fibResult = getFibonacci(inputElement);
	printf("The Fibonacci result is: %d\n",fibResult);
}

