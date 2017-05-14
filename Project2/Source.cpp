#include <iostream>
#include <cmath>
#include <ctime>

/*
Two  human  players  will  take  turns  to  place  pieces  on  the  board.  They  will  specific  location  via
entering a letter on the keyboard which corresponds to a position on the board.

As each turn plays out, check for the winning condition. Three playing-pieces of the same type in a
row (either: horizontal, vertical, or diagonal) causes the player to win, and the game to end. If all
spaces are filled, and there is no winner, the game is declared a draw.

Upon completion of the game, the result should be announced, and the board should look similar to
the following:
*/

void playGame(bool player);
bool checkWin();

bool game = true;
char board[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };



int main(int argc, char* argv[])
{
	

	while (game){

		playGame(true);
		if (!checkWin()){
			std::cout << std::endl << "Player 1 Wins";
			break;
		}

		if (board[0] != 'A' && board[1] != 'B' && board[2] != 'C' && board[3] != 'D' && board[4] != 'E' && board[5] != 'F' && 	board[6] != 'G' && board[7] != 'H' && board[8] != 'I'){
			std::cout << "Game Over" << std::endl << "NOBODY WINS";
			break;
		}

		playGame(false);
		if (!checkWin()){
			std::cout << std::endl << "Player 2 Wins";
			break;
		}

		if (board[0] != 'A' && board[1] != 'B' && board[2] != 'C' && board[3] != 'D' && board[4] != 'E' && board[5] != 'F' && 	board[6] != 'G' && board[7] != 'H' && board[8] != 'I'){
			std::cout << "Game Over" << std::endl << "NOBODY WINS";
			break;
		}
	}


	return (0);
}

void printGame(){

}

void playGame(bool player){
	bool play = false;

	std::cout << std::endl <<
		"     |     |     " << std::endl <<
		"  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << std::endl <<
		"     |     |     " << std::endl <<
		"-----+-----+------" << std::endl <<
		"     |     |     " << std::endl <<
		"  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << std::endl <<
		"     |     |     " << std::endl <<
		"-----+-----+------" << std::endl <<
		"     |     |     " << std::endl <<
		"  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << std::endl <<
		"     |     |     " << std::endl << std::endl;

	if (player){
		std::cout << "Player 1's";
	}
	else {
		std::cout << "Player 2's";

	}

	std::cout << " Turn please enter a key: ";

	char inputKey = 0;
	std::cin >> inputKey;

	if ((inputKey == 65 || inputKey == 97) && board[0] == 'A'){
		if (player){
			board[0] = 'x';
			play = true;
		}
		else {
			board[0] = '0';
			play = true;
		}
	}
	if ((inputKey == 66 || inputKey == 98) && board[1] == 'B'){
		if (player){
			board[1] = 'x';
			play = true;
		}
		else {
			board[1] = '0';
			play = true;
		}
	}
	if ((inputKey == 67 || inputKey == 99) && board[2] == 'C'){
		if (player){
			board[2] = 'x';
			play = true;
		}
		else {
			board[2] = '0';
			play = true;
		}
	}
	if ((inputKey == 68 || inputKey == 100) && board[3] == 'D'){
		if (player){
			board[3] = 'x';
			play = true;
		}
		else {
			board[3] = '0';
			play = true;
		}
	}
	if ((inputKey == 69 || inputKey == 101) && board[4] == 'E'){
		if (player){
			board[4] = 'x';
			play = true;
		}
		else {
			board[4] = '0';
			play = true;
		}
	}
	if ((inputKey == 70 || inputKey == 102) && board[5] == 'F'){
		if (player){
			board[5] = 'x';
			play = true;
		}
		else {
			board[5] = '0';
			play = true;
		}
	}
	if ((inputKey == 71 || inputKey == 103) && board[6] == 'G'){
		if (player){
			board[6] = 'x';
			play = true;
		}
		else {
			board[6] = '0';
			play = true;
		}
	}
	if ((inputKey == 72 || inputKey == 104) && board[7] == 'H'){
		if (player){
			board[7] = 'x';
			play = true;
		}
		else {
			board[7] = '0';
			play = true;
		}
	}
	if ((inputKey == 73 || inputKey == 105) && board[8] == 'I'){
		if (player){
			board[8] = 'x';
			play = true;
		}
		else {
			board[8] = '0';
			play = true;
		}
	}
	if (!play){
		std::cout << std::endl << "INVALID MOVE" << std::endl;
		playGame(player);
	}
}


bool checkWin(){

	//Check horizontal
	if (board[0] == board[1] && board [1] == board[2]){
		std::cout << "1st row win";
		std::cout << std::endl <<
			"     |     |     " << std::endl <<
			"==" << board[0] << "==|==" << board[1] << "==|==" << board[2] << "==" << std::endl <<
			"     |     |     " << std::endl <<
			"-----+-----+------" << std::endl <<
			"     |     |     " << std::endl <<
			"  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << std::endl <<
			"     |     |     " << std::endl <<
			"-----+-----+------" << std::endl <<
			"     |     |     " << std::endl <<
			"  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << std::endl <<
			"     |     |     " << std::endl << std::endl;
		return  false;
	}
	if (board[3] == board[4] && board[4] == board[5]){
		std::cout << "2nd row win";
		std::cout << std::endl <<
			"     |     |     " << std::endl <<
			"  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << std::endl <<
			"     |     |     " << std::endl <<
			"-----+-----+------" << std::endl <<
			"     |     |     " << std::endl <<
			"==" << board[3] << "==|==" << board[4] << "==|==" << board[5] << "==" << std::endl <<
			"     |     |     " << std::endl <<
			"-----+-----+------" << std::endl <<
			"     |     |     " << std::endl <<
			"  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << std::endl <<
			"     |     |     " << std::endl << std::endl;
		return  false;
	}
	if (board[6] == board[7] && board[7] == board[8]){
		std::cout << "3rd row win";
		std::cout << std::endl <<
			"     |     |     " << std::endl <<
			"  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << std::endl <<
			"     |     |     " << std::endl <<
			"-----+-----+------" << std::endl <<
			"     |     |     " << std::endl <<
			"  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << std::endl <<
			"     |     |     " << std::endl <<
			"-----+-----+------" << std::endl <<
			"     |     |     " << std::endl <<
			"==" << board[6] << "==|==" << board[7] << "==|==" << board[8] << "==" << std::endl <<
			"     |     |     " << std::endl << std::endl;
		return  false;
	}

	//Check vertical
	if (board[0] == board[3] && board[3] == board[6]){
		std::cout << "1st column win";
		std::cout << std::endl <<
			"  |  |     |     " << std::endl <<
			"  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << std::endl <<
			"  |  |     |     " << std::endl <<
			"-----+-----+------" << std::endl <<
			"  |  |     |     " << std::endl <<
			"  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << std::endl <<
			"  |  |     |     " << std::endl <<
			"-----+-----+------" << std::endl <<
			"  |  |     |     " << std::endl <<
			"  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << std::endl <<
			"  |  |     |     " << std::endl << std::endl;
		return  false;
	}
	if (board[1] == board[4] && board[4] == board[7]){
		std::cout << "2nd column win";
		std::cout << std::endl <<
			"     |  |  |     " << std::endl <<
			"  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << std::endl <<
			"     |  |  |     " << std::endl <<
			"-----+-----+------" << std::endl <<
			"     |  |  |     " << std::endl <<
			"  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << std::endl <<
			"     |  |  |     " << std::endl <<
			"-----+-----+------" << std::endl <<
			"     |  |  |     " << std::endl <<
			"  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << std::endl <<
			"     |  |  |     " << std::endl << std::endl;
		return  false;
	}
	if (board[2] == board[5] && board[5] == board[8]){
		std::cout << "3rd column win";
		std::cout << std::endl <<
			"     |     |  |  " << std::endl <<
			"  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << std::endl <<
			"     |     |  |  " << std::endl <<
			"-----+-----+------" << std::endl <<
			"     |     |  |  " << std::endl <<
			"  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << std::endl <<
			"     |     |  |  " << std::endl <<
			"-----+-----+------" << std::endl <<
			"     |     |  |  " << std::endl <<
			"  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << std::endl <<
			"     |     |  |  " << std::endl << std::endl;
		return  false;
	}

	//Check diagonally
	if (board[0] == board[4] && board[4] == board[8]){
		std::cout << "\\ win";
		std::cout << std::endl <<
			" \\   |     |     " << std::endl <<
			"  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << std::endl <<
			"    \\|     |     " << std::endl <<
			"-----+-----+------" << std::endl <<
			"     | \\   |     " << std::endl <<
			"  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << std::endl <<
			"     |    \\|     " << std::endl <<
			"-----+-----+------" << std::endl <<
			"     |     | \\   " << std::endl <<
			"  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << std::endl <<
			"     |     |    \\ " << std::endl << std::endl;
		return  false;
	}
	if (board[2] == board[4] && board[4] == board[6]){
		std::cout << "/ win";
		std::cout << std::endl <<
			"     |     |    / " << std::endl <<
			"  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << std::endl <<
			"     |     | /   " << std::endl <<
			"-----+-----+------" << std::endl <<
			"     |    /|     " << std::endl <<
			"  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << std::endl <<
			"     | /   |     " << std::endl <<
			"-----+-----+------" << std::endl <<
			"    /|     |     " << std::endl <<
			"  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << std::endl <<
			" /   |     |     " << std::endl << std::endl;
		return  false;
	}

	return true;
}