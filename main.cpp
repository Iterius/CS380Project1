#include <stdlib.h>
#include <vector>
#include "CDominoes.hpp"
#include "CPlayer.hpp"
#include "CRandom.hpp"
#include "CTable.hpp"

int main() {
    CTable * table = new CTable();
    std::default_random_engine generation;
	std::uniform_int_distribution<int> distribution(1, 2);
    int playerTurn = distribution(generation);
	printf("Player %i starts!", playerTurn);
	bool playing = true;
	while(playing)
	{
		playing = checkConditions(table->takeTurn(&playerTurn), table->takeTurn(&playerTurn));
		if(table->player1->isEmpty() || table->player2->isEmpty())
		{
			playing = false;
		}
	}
	
	int winner = table->getWinner();
	if (winner == 0)
	{
		printf("It's a tie!");
	}
	else{
	printf("Player %i wins!", winner);
	}
}
bool checkConditions(bool player1, bool player2)
{
	return player1 || player2;
}