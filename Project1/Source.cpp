#include <iostream>
#include <cmath>
#include <ctime>

/*
Record the winner of each round.
Allow a round to be played automatically without any human interaction with the game.
When the program is run, the first prompt must ask how many rounds are to be played.
The game must play the requested number of rounds.
Upon completion of all rounds, report statistics for the following:
Total number of rounds played.
Total number of rounds won by the human player.
Total number of rounds won by the computer AI player.
Human player winning average.
Computer AI winning average.
Allow the above debugging features to be turned off and on.
*/
int roll();
int comRoll();
int game(bool order);

int main(int argc, char* argv[])
{
	std::cout << "How Many Rounds you want to play? " << std::endl;

	int number = 0;
	std::cin >> number;

	srand(time(0));
	bool order = true;
	
	double win = 0;
	double draw = 0;
	double lose = 0;

	for (int i = 1; i <= number; ++i){

		int f = game(order);
		
		if (f == 1){
			win++;
		}
		else {
			if (f == 2){
				lose++;
			}
			if (f == 3){
				draw++;
			}
		}

		double winAvg = win / number;
		winAvg *= 100;

		double loseAvg = lose / number;
		loseAvg *= 100;

		double drawAvg = draw / number;
		drawAvg *= 100;

		std::cout << "Game Count: " << i << " Wins: " << win << " Loses:" << lose << " Draws:" << draw  << std::endl 
			<< "Wining Average: " << winAvg << "% , Losing Average:" << loseAvg << "% , Drawing Average:" << drawAvg << "%" << std::endl << std::endl;


	}
	std::cout << "Thanks For Playing" << std::endl;

	return (0);
}

int game(bool order){
	int victory = 0;
	int diceroll1 = 0;
	int diceroll2 = 0;
	int comRoll1 = 0;
	int comRoll2 = 0;
	int chance = (rand() % 100) + 1;

	diceroll1 = roll();
	diceroll2 = roll();
	comRoll1 = comRoll();
	comRoll2 = comRoll();

	if (chance <= 70){
		if (comRoll1 == comRoll2 && diceroll1 == diceroll2) {
			if (diceroll1 + diceroll2 > comRoll1 + comRoll2){
				int temp1 = comRoll1;
				int temp2 = comRoll2;

				comRoll1 = diceroll1;
				comRoll2 = diceroll2;

				diceroll1 = temp1;
				diceroll2 = temp2;
			}
		}
		else {
			if (diceroll1 == diceroll2){
				int temp1 = comRoll1;
				int temp2 = comRoll2;

				comRoll1 = diceroll1;
				comRoll2 = diceroll2;

				diceroll1 = temp1;
				diceroll2 = temp2;
			}
			else {
				if (comRoll1 == comRoll2){

				}
				else {
					if (diceroll1 + diceroll2 > comRoll1 + comRoll2){
						int temp1 = comRoll1;
						int temp2 = comRoll2;

						comRoll1 = diceroll1;
						comRoll2 = diceroll2;

						diceroll1 = temp1;
						diceroll2 = temp2;
					}
				}
			}
		}
	}


	if (order){

		std::cout << "You rolled: " << diceroll1 << " & " << diceroll2;
		std::cout << ", The Computer rolled: " << comRoll1 << " & " << comRoll2 << std::endl;
	}
	else{
		std::cout << "The Computer rolled: " << comRoll1 << " & " << comRoll2;
		std::cout << ", You rolled: " << diceroll1 << " & " << diceroll2 << std::endl;
	}



	if (diceroll1 == diceroll2){
		if (comRoll1 == comRoll2){
			if (comRoll1 > diceroll1) {
				std::cout << "The Computer Rolled a Higher Double" << std::endl;
				victory = 2;
			}

			if (comRoll1 < diceroll1){
				std::cout << "You Rolled a Higher Double" << std::endl;
				victory = 1;
			}
			if (comRoll1 == diceroll1){
				std::cout << "You Rolled the same" << std::endl;
				victory = 3;
			}

		}
		else {
			std::cout << "You Rolled a Double, but computer didn't" << std::endl;
			victory = 1;
		}

	}
	else {
		if (comRoll1 == comRoll2) {
			std::cout << "The Computer a Double, but you didn't" << std::endl;
			victory = 2;
		}
		else {
			if (comRoll1 + comRoll2 > diceroll1 + diceroll2) {
				std::cout << "The Computer Rolled a higher set of numbers" << std::endl;
				victory = 2;
			}
			if (comRoll1 + comRoll2 < diceroll1 + diceroll2) {
				std::cout << "You Rolled a higher set of numbers" << std::endl;
				victory = 1;
			}
			if (comRoll1 + comRoll2 == diceroll1 + diceroll2){
				std::cout << "You Rolled the same total of numbers" << std::endl;
				victory = 3;

			}
		}
	}

	if (victory == 1){
		std::cout << "You Won the game" << std::endl;
	}
	else {
		if (victory == 2) {
			std::cout << "You Lost the Game" << std::endl;
		}
		else {
			std::cout << "Its a Draw" << std::endl;
		}
	}

	return victory;
}

int roll(){
	int diceRoll = 0;
	diceRoll = (rand() % 6) + 1;
	return diceRoll;
}

int comRoll(){

	int diceRoll = 0;

	diceRoll = (rand() % 6) + 1;

	return diceRoll;
}
