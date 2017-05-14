#include <iostream>
#include <cmath>
#include <ctime>

/*
Two players: one human, one computer AI.
The rules:
Each player gets one turn per round.
On a turn the player rolls two six-sided dice.
The player that gets a double (or highest double) wins the round.
If neither player gets a double, the highest total wins.
If both players roll the same total, then it’s a draw.
On the next round, the player swap turns.
Previous second roller is now the first roller etc.
The game rounds continue, until the human player decides to quit.
There is one final requirement…
The computer AI must have a winning average of close to 70%.
However, the game should still appear random
And hence fair to the player…
*/
int roll();
int game(bool order);

int main(int argc, char* argv[])
{


	srand(time(0));
	bool order = true;

	int win = 0;
	int draw = 0;
	int lose = 0;

	while (true) {
		
		int f = game(order);
		std::cout << "Do You want to play again? Y or N" << std::endl;


		//Wait for a key press.
		char inputKey = 0;
		std::cin >> inputKey;

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

		
		if (inputKey == 121 || inputKey == 89){
			std::cout << "lets Play again" << std::endl;
			std::cout << std::endl;
			order = !order;
		}
		else {
			std::cout << "Thanks For Playing" << std::endl;
			break;
		}
		

	}

	
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
	comRoll1 = roll();
	comRoll2 = roll();

	if (chance <= 50){
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
	std::cout << "Enter any key to roll a dice " << std::endl;

	char inputKey = 0;
	std::cin >> inputKey;

	if (order){
		
		std::cout << "You rolled: " << diceroll1 << " & " << diceroll2 << std::endl;
		std::cout << "The Computer rolled: " << comRoll1 << " & " << comRoll2 << std::endl<< std::endl;
	}
	else{
		std::cout << "The Computer rolled: " << comRoll1 << " & " << comRoll2 << std::endl;
		std::cout << "You rolled: " << diceroll1 << " & " << diceroll2 << std::endl << std::endl;
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
		std::cout << "You Won the game"  << std::endl;
	}
	else {
		if (victory == 2) {
			std::cout  << "You Lost the Game" << std::endl;
		}
		else {
			std::cout  << "Its a Draw" << std::endl;
		}
	}

	return victory;
}

int roll(){
	int diceRoll = 0;
	diceRoll = (rand() % 6) + 1;
	return diceRoll;
}
