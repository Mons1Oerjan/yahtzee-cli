#ifndef YAHTZEE_H
#define YAHTZEE_H
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "Dice.h"
#include "ScoreBoard.h"
#include <string.h>
#include <cstring>
#include "Rules.h"
#include "Player.h"
#include "Game.h"
using namespace std;

class yahtzee: Game {
public:
	void rollTheDice(Rules& r, ScoreBoard& s, Dice& d, int rollsLeft, int turn);
	void selectUpdate(Rules& r, ScoreBoard& s, Dice& d, int player);
	int keeper[5] = {-1, -1, -1, -1, -1};
	char c[2];
	int turns= 0;
	yahtzee(int players);
	~yahtzee();
	void playYathzee();
};

#endif
