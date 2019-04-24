#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "CDominoes.h"
#include "CPlayer.h"
#include "CRandom.h"
#include "CTable.h"

void CTable::playDomino(CDominoes toPlay, bool isHead) {
    if(playedDominoes.size() == 0) {
        playedDominoes.push_back(toPlay);
    }
    else if(isHead) {
        if(toPlay.getLeft() != playedDominoes[head].getRight())
        {
            cout << "flip" << endl;
            toPlay.flip();
        }
        playedDominoes.push_back(toPlay);
        head++;
    }
    else {
        if(toPlay.getRight() != playedDominoes[tail].getLeft())
        {
            toPlay.flip();
        }
        playedDominoes.insert(playedDominoes.begin(), toPlay);
        head++;
    }

}
CTable::CTable() {
    bag = new CRandom();
    player1 = new CPlayer();
    player2 = new CPlayer();
    playDomino(bag->getRand(), true);
    for(int i = 0; i < 10; i++) {
        player1->addDomino(bag->getRand());
        player2->addDomino(bag->getRand());
    }
}
CTable::~CTable()
{
    delete[] &bag;
    delete[] &player1;
    delete[] &player2;
}
void CTable::printBoard() {
    printf("Current Board: \n");
    for(int i = 0; i < playedDominoes.size(); i++) {
        playedDominoes[i].printDomino();
    }
    printf("\n");
}
bool CTable::noPlays(CPlayer* turnTaker)
{
    return !(turnTaker->contains(playedDominoes[tail].getLeft())
        || turnTaker->contains(playedDominoes[head].getRight()));
}
bool CTable::takeTurn(int* playerTurn, bool automated)
{
    CPlayer * turnTaker;
    std::string input;
    int toPlay;
    int position;
    cout << "Player " << *playerTurn << "'s turn!" << endl;
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
    if(automated)
    {
        while(noPlays(turnTaker))
        {
            if(bag->Dominoes.size() == 0)
            {
                return false;
            }
            printf("No current move can be made, drawing a tile!");
            turnTaker->addDomino(bag->getRand());
            printBoard();
            turnTaker->printHand();
        }
        std::vector<CDominoes> player = turnTaker->getHand();
        for(int x = 0; x < player.size(); x++)
        {
            if(player[x].getLeft() == playedDominoes[head].getRight() || player[x].getRight() == playedDominoes[head].getRight())
            {
                playDomino(player[x], true);
                turnTaker->removeDomino(x);
            }
            else if(player[x].getLeft() == playedDominoes[tail].getLeft() || player[x].getRight() == playedDominoes[tail].getLeft())
            {
                playDomino(player[x], false);
                turnTaker->removeDomino(x);
            }
        }

        return true;
    }
    else
    {
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
            printBoard();
            turnTaker->printHand();
        }
        bool choosing = true;
        while(choosing)
        {
            printf("Which tile do you want to play? (select with the numbers below them)");
            getline(std::cin, input);
            if(std::stringstream(input) >> toPlay)
            {
                printf("Do you want to place this tile on the right or left? (0 for right, 1 for left)");
                getline(std::cin, input);
                if(std::stringstream(input) >> position)
                {
                    if(position == 0)
                    {
                        if(playedDominoes[head].getRight() == turnTaker->getHand()[toPlay].getLeft() ||
                            playedDominoes[head].getRight() == turnTaker->getHand()[toPlay].getRight())
                            {
                                playDomino(turnTaker->getHand()[toPlay], true);
                                turnTaker->removeDomino(toPlay);
                                choosing = false;
                            }
                        else
                        {
                            printf("Invalid Play\n");
                            printBoard();
                            turnTaker->printHand();
                        }
                    }
                    else
                    {
                        if(playedDominoes[tail].getLeft() == turnTaker->getHand()[toPlay].getLeft() ||
                            playedDominoes[tail].getLeft() == turnTaker->getHand()[toPlay].getRight())
                            {
                                playDomino(turnTaker->getHand()[toPlay], false);
                                turnTaker->removeDomino(toPlay);
                                choosing = false;
                            }
                        else
                        {
                            printf("Invalid Play");
                            printBoard();
                            turnTaker->printHand();
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
    }
    return true;
}
int CTable::getWinner()
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
