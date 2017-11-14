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
	private:
		int** dices;
	public:
		Dice();
		~Dice();
		void rollDice();
		void reserveDice(int index);
		void reset();
		int** getDices();
		void print();
};

#endif
