/*
 * Authors: Daniel Reed and Kyle Atchley
 * Class: CS380
 * Project: 1
 */
#include <stdlib.h>
#include <vector>
#include <random>
#include "CDominoes.h"
#include "CPlayer.h"
#include "CRandom.h"
#include "CTable.h"
#include <stdlib.h>
using namespace std;
bool checkConditions(bool player1, bool player2)
{
	return player1 || player2;
}
int main() {
    CTable table = *(new CTable());
    int playerTurn = rand() % 2 + 1;
	printf("Player %i starts! \n", playerTurn);
	bool playing = true;
	bool player1 = false;
	bool player2 = false;
	bool automated = true;
	while(playing)
	{
	    if(playerTurn == 1)
        {
            player1 = table.takeTurn(&playerTurn, automated);
        }
        else if (playerTurn == 2)
        {
            player2 = table.takeTurn(&playerTurn, automated);
        }
		checkConditions(player1, player2);
		if(table.player1->isEmpty() || table.player2->isEmpty())
		{
			playing = false;
		}
	}

	int winner = table.getWinner();
	if (winner == 0)
	{
		printf("It's a tie!");
	}
	else{
	printf("Player %i wins! \nRemaining tiles:", winner);
	if(winner == 1)
        table.player2->printHand();
    else
        table.player1->printHand();
	}
	delete[]&table;
	return 0;
}
