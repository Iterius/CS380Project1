#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "CDominoes.hpp"
#include "CPlayer.hpp"
#include "CRandom.hpp"

class CTable {
    private:
    /**
     * @param head is the right side of the train.
     * @param tail is the left side of the train.
     */
    int head = 0;
    int tail = 0;
    std::vector<CDominoes> playedDominoes;
    CRandom * bag;
    public:
	CPlayer * player1;
    CPlayer * player2;
    void playDomino(CDominoes toPlay, bool isHead) {
        if(playedDominoes.size() == 0) {
            playedDominoes.push_back(toPlay);
        }
        else if(isHead) {
            playedDominoes.push_back(toPlay);
            head++;
        } 
        else {
            playedDominoes.insert(playedDominoes.begin(), toPlay);
            head++;
        }

    }
    CTable() {
        bag = new CRandom();
        player1 = new CPlayer();
        player2 = new CPlayer();
        playDomino(bag->getRand(), true);
        for(int i = 0; i < 10; i++) {
            player1->addDomino(bag->getRand());
            player2->addDomino(bag->getRand());
        }
    }
    void printBoard() {
		printf("Current Board: \n");
        for(int i = 0; i < playedDominoes.size(); i++) {
            playedDominoes[i].printDomino();
        }
        printf("\n");
    }
	bool noPlays(CPlayer* turnTaker)
	{
		return !(turnTaker->contains(playedDominoes[tail].getLeft())
			|| turnTaker->contains(playedDominoes[head].getRight()));
	}
	bool takeTurn(int * playerTurn)
	{
		CPlayer * turnTaker;
		std::string input;
		int toPlay;
		int position;
		if(*playerTurn == 1)
		{
			turnTaker = player1;
			*playerTurn = 2;
		}
		else
		{
			turnTaker = player2;
			*playerTurn = 1;
		}
		printBoard();
		turnTaker->printHand();
		while(noPlays(turnTaker))
		{
			if(bag->Dominoes.size() == 0)
			{
				return false;
			}
			printf("No current move can be made, press enter to draw a tile!");
			getline(std::cin, input);
			input = "";
			turnTaker->addDomino(bag->getRand());
		}
		bool choosing = true;
		while(choosing)
		{
			printf("Which tile do you want to play? (select with the numbers below them)");
			getline(std::cin, input);
			if(std::stringstream(input) >> toPlay)
			{
				printf("Do you want to place this tile at the head or tail? (0 for head, 1 for tail");
				getline(std::cin, input);
				if(std::stringstream(input) >> position)
				{
					if(position == 0)
					{
						if(playedDominoes[head].getRight() == turnTaker->getHand()[toPlay].getLeft() || 
							playedDominoes[head].getRight() == turnTaker->getHand()[toPlay].getRight())
							{
								if(playedDominoes[head].getRight() == turnTaker->getHand()[toPlay].getRight()) 
								{
									int temp = turnTaker->getHand()[toPlay].getLeft();
									turnTaker->getHand()[toPlay].setLeft(turnTaker->getHand()[toPlay].getRight());
									turnTaker->getHand()[toPlay].setRight(temp);
								}
								playDomino(turnTaker->getHand()[toPlay], true);
								turnTaker->removeDomino(toPlay);
								choosing = false;
							}
					}
					else
					{
						if(playedDominoes[tail].getLeft() == turnTaker->getHand()[toPlay].getLeft() || 
							playedDominoes[tail].getLeft() == turnTaker->getHand()[toPlay].getRight())
							{
								if(playedDominoes[head].getLeft() == turnTaker->getHand()[toPlay].getLeft()) 
								{
									int temp = turnTaker->getHand()[toPlay].getLeft();
									turnTaker->getHand()[toPlay].setLeft(turnTaker->getHand()[toPlay].getRight());
									turnTaker->getHand()[toPlay].setRight(temp);
								}
								playDomino(turnTaker->getHand()[toPlay], false);
								turnTaker->removeDomino(toPlay);
								choosing = false;
							}
					}
				}
				else
				{
					printf("Invalid input!");
					printBoard();
					turnTaker->printHand();
				}
			}
			else
			{
				printf("Invalid input!");
				printBoard();
				turnTaker->printHand();
			}
		}
		
		return true;
	}
	int getWinner()
	{
		if(player1->isEmpty())
		{
			return 1;
		}
		else if (player2->isEmpty())
		{
			return 2;
		}
		else if (player1->getHand().size() < player2->getHand().size())
		{
			return 1;
		}
		else if (player1->getHand().size() > player2->getHand().size())
		{
			return 2;
		}
		return 0;
	}
}