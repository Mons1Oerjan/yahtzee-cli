#ifndef DICE_H
#define DICE_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Printable.h"
using namespace std;

/*
Class dice inherits from printable
*/
class Dice: Printable {
	/*
	Public classes and variables. See cpp for further detail
	*/
	public:
	Dice();
	~Dice();
	int** dices; // stores data for dices index 0 is for random number index 1 is for roll flag
	void rollDice();
	void reserveDice(int index);
	void reset();
	int** getDices();
	void print();
};

#endif