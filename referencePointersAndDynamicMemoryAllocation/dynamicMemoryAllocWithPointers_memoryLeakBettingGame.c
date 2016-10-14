/*
This is a simulation of Betting Game.
We have following three cards in the given order:

"Jack" "Queen" "King" : Computer shuffles these cards to randomize their positions.
Now player needs to guess the position of the queen. If he guesses the position correct, he'll get 3*of his amount but if his guess is wrong
he simple looses the entire bet amount.
Player has $100 of virtual currency and he can bet as long as there is money left.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cash = 100; // cash is our global variable that we want to access from anywhere of the program.

void playBettingGame(int bet){
	//char gameArray[]={'J','Q','K'};
	char* gameArray = (char*)malloc(3*sizeof(char));
	*(gameArray)='J';
	*(gameArray+1)='Q';
	*(gameArray+2)='K';
	printf("Shuffling....\n");
	srand(time(NULL)); //We are seeding the random no generator

	for(int i=0;i<5;i++){
		int x = rand() % 3;
		int y = rand() % 3;
		/*
		We are shuffling the characters randomly. We are generating 2 random no in each of our 5 iterations and using them as index
		for swapping. Essentially, we are generating two random no and swapping for 5 times.
		We are doing modulo operation by 3 so that our random happnes to be among (0,1,2).
		*/
		int temp = gameArray[x];
		gameArray[x] = gameArray[y];
		gameArray[y] = temp;
	}

	int playerGuess;
	printf("What do you think to be the position of the Queen? 1,2 or 3: \n");
	scanf("%d",&playerGuess);
	if(gameArray[playerGuess-1]=='Q'){
		cash+=3+bet;
		printf("You Win. Result=\"%c %c %c\" Total Cash: %d\n",gameArray[0],gameArray[1],gameArray[2],cash);
	}else{
		cash-=bet;
		printf("You Loose. Result=\"%c %c %c\" Total Cash: %d\n",gameArray[0],gameArray[1],gameArray[2],cash);
	}
	free(gameArray);
}


int main(){

	int bet;
	printf("Welcome to the Casino Royale !!\n");
	printf("Your Total Cash: $%d\n",cash);
	while(cash >0){
		printf("What is your bet: \n");
		scanf("%d",&bet);
		if(bet==0||bet>cash){
			break;
		}else {
			playBettingGame(bet);
			printf("\n************************************\n");
		}
	}
}



