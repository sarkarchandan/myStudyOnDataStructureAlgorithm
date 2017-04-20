#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Custom datatype that will be returned post the game status check by the method checkGameStatus()
//Values wrapped into this datatype will decide the end of the game and the winner.
struct TicTac{
	bool isMatch;
	char winingSymbol;
};

//Custom datatype that will be declared in static scope and will decide the first turn and the symbols for both
//the human and computer player.
struct GameTurnSymbol{
	char whoseTurn;
	char computerSymbol;
	char humanSymbol;
};

//Custom datatype that will be used by the helpComputerBeatTheHuman() method to decide a random move for the computer
//based on the free positions.
struct FreeSpace{
	int rowIndex;
	int columnIndex;
};

//Static declaration of the custom datatype GameTurnSymbol. This datatype will be initialized at the very begining 
//and will control the turns of the player throughout the game.
struct GameTurnSymbol gameTurnSymbol;

//Enum Constants declaration. This will be used in conjunction with the switch case in the checkGameStatus() method
//and the main() method to track the game status.
enum CheckAttributes {
	Vertical = 0,
	Horizontal = 1,
	CornerToCornerLeft = 2,
	CornerToCornerRight = 3
};

/**
* This tiny method is helper module in deciding the first turn in the game.
* This is an effort to make the process considerably random. 
*/
bool isPrime(int randomNumber){
	bool isPrime = true;
	for(int i=2;i<randomNumber;i++){
		if((randomNumber % i) == 0){
			isPrime = false;
			break;
		}
	}
	return isPrime;
}

/**
* Determines whether the computer will prevail over Human and take the first turn of the game.
* This method makes use of isPrime() method.
*/
bool isComputerFirstTurn(){
	srand(time(0));
	int turn = 2 + (rand() % 50);
	if(isPrime(turn) == true){
		return true;
	}else{
		return false;
	}
}

/**
* Computer needs help sometimes in decision making.
* This method again makes use of isPrime() helper method and helps the computer to decide on its symbol.
*/
void helpComputerPickASymbol(){
	srand(time(0));
	int randomNumber;
	randomNumber = rand() % 50;
	if(isPrime(randomNumber) == true){
		gameTurnSymbol.computerSymbol = 'o';
		gameTurnSymbol.humanSymbol = 'x';
	}else{
		gameTurnSymbol.computerSymbol = 'x';
		gameTurnSymbol.humanSymbol = 'o';
	}
}

/**
* This method decides the turn for the Human and Computer starting players as well as their respective symbols.
* Symbols remain static trought the game.
* Once decided it stores the information in a custom datatype.
*/
void decideFirstTurnAndSymbol(){
	if(isComputerFirstTurn() == true){
		gameTurnSymbol.whoseTurn = 'c';
		helpComputerPickASymbol();
		cout << "It is Computer's turn and Computer has chosen its Symbol !!!" << endl;
	}else{
		gameTurnSymbol.whoseTurn = 'h';
		char humanChoice;
		cout << "Wow, it's your turn. You need a symbol to proceed with the game..." << endl;
		do{
			cout << "Which Symbol do you prefer for the game 'o' or 'x': " <<endl;
			cin >> humanChoice;
			if(humanChoice == 'o' || humanChoice == 'x'){
				break;
			}else{
				cout << "Looks like you have limited choices to pick one. So be nice and pick again.." <<endl;
			}
		}while(1);

		if(humanChoice == 'o'){
			gameTurnSymbol.humanSymbol = 'o';
			gameTurnSymbol.computerSymbol = 'x';
		}else{
			gameTurnSymbol.humanSymbol = 'x';
			gameTurnSymbol.computerSymbol = 'o';
		}
	}
}

/**
* Tracks the winning status of the game and returns the custom datatype TicTac upon calling.
* This implementation will be improved going forward to make it more robust. 
*/
struct TicTac checkGameStatus(char **ticTacArray, CheckAttributes checkAttributes){
	
	struct TicTac ticTacToe;

	switch(checkAttributes){
		case Vertical:
		for(int j=0;j<3;j++){
			if(((*(*(ticTacArray+0)+j)) == 'x' && (*(*(ticTacArray+1)+j)) == 'x' && (*(*(ticTacArray+2)+j)) == 'x') 
				|| ((*(*(ticTacArray+0)+j)) == 'o' && (*(*(ticTacArray+1)+j)) == 'o' && (*(*(ticTacArray+2)+j)) == 'o')){

				ticTacToe.isMatch = true;
				ticTacToe.winingSymbol = *(*(ticTacArray+0)+j);
				break;
			}
		}
		break;
		case Horizontal:
		for(int i=0;i<3;i++){
			if(((*(*(ticTacArray+i)+0)) == 'x' && (*(*(ticTacArray+i)+1)) == 'x' && (*(*(ticTacArray+i)+2)) == 'x') 
				|| ((*(*(ticTacArray+i)+0)) == 'o' && (*(*(ticTacArray+i)+1)) == 'o' && (*(*(ticTacArray+i)+2)) == 'o')){

				ticTacToe.isMatch = true;
				ticTacToe.winingSymbol = *(*(ticTacArray+i)+0);
				break;
			}
		}
		break;
		case CornerToCornerLeft:
		if(((*(*(ticTacArray+0)+0)) == 'x' && (*(*(ticTacArray+1)+1)) == 'x' && (*(*(ticTacArray+2)+2)) == 'x') 
				|| ((*(*(ticTacArray+0)+0)) == 'o' && (*(*(ticTacArray+1)+1)) == 'o' && (*(*(ticTacArray+2)+2)) == 'o')){
			ticTacToe.isMatch = true;
			ticTacToe.winingSymbol = *(*(ticTacArray+0)+0);
		}
		break;
		case CornerToCornerRight:
		if(((*(*(ticTacArray+0)+2)) == 'x' && (*(*(ticTacArray+1)+1)) == 'x' && (*(*(ticTacArray+2)+0)) == 'x') 
				|| ((*(*(ticTacArray+0)+2)) == 'o' && (*(*(ticTacArray+1)+1)) == 'o' && (*(*(ticTacArray+2)+0)) == 'o')){
			ticTacToe.isMatch = true;
			ticTacToe.winingSymbol = *(*(ticTacArray+1)+1);
		}
		break;
		default:
		cout << "Something Went Wrong. It's Armageddon !!!" << endl;
		break;
	}
	return ticTacToe;
}

/**
* Tracks if all the positions in the Tic Tac Board is exhausted.
*/
bool isGameExhausted(char **ticTacArray){
	bool isExhausted = true;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(*(*(ticTacArray+i)+j) == '.'){
				isExhausted = false;
				break;
			}
		}
	}
	return isExhausted;
}


/**
* Displays the Tic Tac Board on demand.
*/
void displayTicTacArray(char **ticTacArray){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout << *(*(ticTacArray+i)+j) << " ";
		}
		cout << endl;
	}
}

/**
*This function provides the implementation of computer's move. For now we are going for the naive approach to get things up and
*running. Smarter implementation is upcoming.
*With this implementation Computer might miss its move in rare circumstances. We are trying replace it with a better implementation.
*/
void helpComputerBeatTheHuman(char **ticTacArray){

	//Dynamically allocting memory for an array of FreeSpace custom datatype.
	//This Array will record all current free spaces and will help computer to randomly pick a move 'often the bad move'.
	struct FreeSpace* freeSpace = new FreeSpace[9];
	int k = 0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(*(*(ticTacArray+i)+j) == '.'){
				(freeSpace+k) -> rowIndex = i;
				(freeSpace+k) -> columnIndex = j;
				k++;
			}
		}
	}
	//Randomly choosing a free space.
	if(k > 1){
		srand(time(0));
		int randomPositionIndex = rand()% (k+1);
		int computerMoveRowPosition = (freeSpace+randomPositionIndex) -> rowIndex;
		int computerMovieColumnPosition = (freeSpace+randomPositionIndex) -> columnIndex;

		//Set Computer Move...
		*(*(ticTacArray+computerMoveRowPosition)+computerMovieColumnPosition) = gameTurnSymbol.computerSymbol;
	}else if(k == 1){
		int lastRemainingRowPosition = (freeSpace+0) -> rowIndex;
		int lastRemainingColumnPosition = (freeSpace+0) -> columnIndex;
		*(*(ticTacArray+lastRemainingRowPosition)+lastRemainingColumnPosition) = gameTurnSymbol.computerSymbol;
	}

	//Deallocating the Dynamic memory to avoid Memory Leaks.
	delete []freeSpace;

	cout << "Computer has placed its move..." <<endl;
}

/**
* Places the move of the human player in the game.
*/
bool setUserData(char **ticTacArray,int row,int column,char symbol){
	if(*(*(ticTacArray+row)+column) == '.' && (symbol == gameTurnSymbol.humanSymbol)){
		*(*(ticTacArray+row)+column) = symbol;
		return true;
	}else{
		return false;
	}
}

int main(int argc, char const *argv[])
{
	//Declaring 2D Array and dynamically allocating memory for the same.
	//This 2D Array will emulate our Tic-Tac-Toe game board.
	char **ticTacArray = new char*[3];
	for(int count=0;count<3;count++){
		*(ticTacArray+count) = new char[3];
	}

	//Initializing our Tic-Tac-Toe gameboard for better visual.
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			*(*(ticTacArray+i)+j) = '.';
		}
	}

	cout << "Welcome To Our Game Of Tic Tac Toe, The Next Program You Should Try After Hello World..." <<endl;
	cout << "Or May Be Not." << endl;
	cout << "This is a starter code and is in development. Could break at any point." <<endl;
	cout << "In case it breaks, developer is just want to say Sorry and humbly request you to.." << endl;
	cout << "highlight the things that in your opinion, could be handled in a better way." << endl;
	cout << endl;
	cout << "Now there are certain known issues with this game.." <<endl;
	cout << "First Issue:" <<endl;
	cout << "Computer playing against you is not very smart yet."<<endl;
	cout << "Could act like the MadKing. Developer is working to make it smarter." <<endl;
	cout << "As we'd proceed with solving our known/unknown issues, our  Computer will become smarter..." <<endl;
	cout << "But not smarter than you. That’s a Promise." << endl;
	cout <<endl;
	cout << "Second Issue:" <<endl;
	cout << "Following is your playground. We call it Tic Tac Board...."<<endl;

	displayTicTacArray(ticTacArray);
	cout << endl;

	cout << "And following is the developer's view:" <<endl;
	cout << "00 01 02"<<endl;
	cout << "10 11 12"<<endl;
	cout << "20 21 22"<<endl;
	cout << "You need to take the pain and follow along the developer's view."<<endl;
	cout << "First digit is the row qualifier and second is the column qualifier." <<endl;
	cout << "You also need to choose a symbol for your play out of 'x' and 'o' and for now you need to stick to lower-case."<<endl;
	cout << "Valid Input Syntax for you is: int <spacebar> int <spacebar> 'char' " <<endl;
	cout << endl;
	cout << "Here Our Issue Is Error Handling Is Not Working For The Row & Column Qualifiers." <<endl;
	cout << "We are trying different stuff for the Integer Validation without an working solution." <<endl;
	cout << "So an inappropriate and/or non-number input may ruin the execution at the moment." <<endl;
	cout <<endl;
	cout << "Third Issue:" <<endl;
	cout << "Yeah, We have quite a lot of known issues at the moment. Let's not count the unknown ones.." <<endl;
	cout << "For now it is a single-game instance code. After one game, code will exit." <<endl;
	cout << "We know it is annoying. We will fix it soon." <<endl;

	cout << "A dice roll will happen automatically and the starting player will proceed." <<endl;
	cout <<endl;
	cout << "Now Let's play.."<<endl;

	decideFirstTurnAndSymbol();
	if(gameTurnSymbol.whoseTurn == 'h'){
		cout << "First Turn: " << "Human" << endl;
		cout << "Human Symbol: " << gameTurnSymbol.humanSymbol << endl;
		cout << "Computer Symbol: " << gameTurnSymbol.computerSymbol << endl;
	}else{
		cout << "First Turn: " << "Computer" << endl;
		cout << "Computer Symbol: " << gameTurnSymbol.computerSymbol << endl;
		cout << "Human Symbol: " << gameTurnSymbol.humanSymbol << endl;
	}

	//Play Tic-Tac-Toe start.
	int rowInput,columnInput;
	char turn;
	int turnCount = 0;
	struct TicTac ticTacToe;

	//Game starts here. While the game is in progress the turn is periodically switched between the
	//human player and computer player.
	do{
		if(gameTurnSymbol.whoseTurn == 'h'){
			cout << "Your Turn: " << "Row <space> Column <space> Symbol" << endl;
			cin >> rowInput >> columnInput >> turn;
			bool setDataFlag;

			if(rowInput >= 0 && rowInput <= 2 
				&& columnInput >= 0 && columnInput <=2){

				setDataFlag = setUserData(ticTacArray,rowInput,columnInput,turn);
				if(setDataFlag == true){
					cout << "You have placed your move.." << endl;
					gameTurnSymbol.whoseTurn = 'c';
					turnCount++;
				}else{
					cout << "Invalid Symbol and/or Position"<< endl;
					cout << "Only Use Your Symbol and Free Position !!!" << endl << endl;
				}
			}else{
				cout << "Invalid Row or Column Index. Please follow the rule of the game !!!" << endl;
			}
		}else{
			helpComputerBeatTheHuman(ticTacArray);
			gameTurnSymbol.whoseTurn = 'h';
		}
		

		displayTicTacArray(ticTacArray);
		cout << endl;

		//After each move game status will be checked for all matching patterns.
		ticTacToe = checkGameStatus(ticTacArray,Vertical);
		ticTacToe = checkGameStatus(ticTacArray,Horizontal);
		ticTacToe = checkGameStatus(ticTacArray,CornerToCornerLeft);
		ticTacToe = checkGameStatus(ticTacArray,CornerToCornerRight);

		//If any match is found game will break and declare the winner.
		if(ticTacToe.isMatch == true){
			break;
		}
	}while(checkGameStatus(ticTacArray,Vertical).isMatch == false 
		&& checkGameStatus(ticTacArray,Horizontal).isMatch == false
		&& checkGameStatus(ticTacArray,CornerToCornerLeft).isMatch == false
		&& checkGameStatus(ticTacArray,CornerToCornerRight).isMatch == false
		&& isGameExhausted(ticTacArray) == false);

	if(ticTacToe.winingSymbol == gameTurnSymbol.computerSymbol){
		cout << "Computer Wins The Game!!!" <<endl;
	}else if(ticTacToe.winingSymbol == gameTurnSymbol.humanSymbol){
		cout << "You Win The Game !!!" <<endl;
	}else{
		cout << "Game is a Draw !!!" <<endl;
	}

	//Play Tic-Tac-Toe End

	//Deallocating the Dynamic memory to avoid Memory Leaks.
	for(int count=0;count<3;count++){
		delete(*(ticTacArray+count));
	}
	delete []ticTacArray;
	return 0;
}