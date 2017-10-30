/*
 * Class dice inherits from printable
 */
#ifndef DICE_H
#define DICE_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Printable.h"
using namespace std;

class Dice: Printable {
	public:
		Dice();
		~Dice();
		int** dices;
		void rollDice();
		void reserveDice(int index);
		void reset();
		int** getDices();
		void print();
};

#endif
