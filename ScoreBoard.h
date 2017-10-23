#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <iostream>
#include "Printable.h"
#include <cstdlib>
#include <unistd.h>
#include <string.h>
using namespace std;
/*
ScoreBoard class inherits from Printable. See cpp for further details
*/
class ScoreBoard: Printable{
	public:

	//data for updates and labels for the printable table.
	int *updates;
	string nameOfPlayers[2];
	string scoreLabels[14] ={"Ones", "Twos", "Threes", "Fours", "Fives", "Sixes", "BONUS", "Three of a Find", "Four of a Kind", "Full House", "Small Straight", "Large Straight", "Chance", "YAHTZEE"};
	int** scores;
	// Public method. see cpp for further details.
	ScoreBoard();
	~ScoreBoard();
	void setNamesOfPlayers(string p1, string p2);
	void print();
	void print(int** data);
	int** getScore();
	int* getUpdates();
	int updateScore(int** data, int index);

};

#endif