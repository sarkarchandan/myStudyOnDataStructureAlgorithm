#include <stdio.h>

int main(int argc, const char *argv[]){

	float fTemp;
	printf("Enter temperature in Fahrenheit: \n");
	scanf("%f",&fTemp);

	float cTemp = (fTemp-32)/1.8;
	printf("The temperature in Celsius scale is: %.1f\n",cTemp);
	/*
	In this small program snippet we would like to see simple datatype like float and how we can take a float input and display
	the output in float as well.
	The %.1f denotes that in our output we want just 1 number after the decimal point. Similarly adding %.2f will allow two numbers
	after the decimal point in output.
	*/
	return 0;
} 