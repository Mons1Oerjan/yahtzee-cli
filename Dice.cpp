/*
 * Class Dice stores the numbers of 5 diffrent dices.
 * INHERITS FROM printable.
 */
#include "Dice.h"
#define NUM_DICE 5
#define NOT_RESERVED 1
#define RESERVED 0

// Constructor
Dice::Dice() {
	// initialize an array of dices:
	dices = new int*[NUM_DICE];
	for(int i = 0; i < NUM_DICE; i++) {
		// initialize roll flags:
		dices[i] = new int[2];
		dices[i][0] = RESERVED;
		dices[i][1] = NOT_RESERVED;
	}
}

// deconstructor
Dice::~Dice() {}

// roll the dices that the user would like to roll
void Dice::rollDice() {
	for(int i = 0; i < NUM_DICE; i++) {
		// check for roll flag stored at [i][1]
		if(dices[i][1] == NOT_RESERVED) {
			// assign random number between 1-6:
			dices[i][0] = rand() % 6 + 1;
		}
	}
}

/*
 * Flags the dice to prevent rolling. User inputs the index
 */
void Dice::reserveDice(int index) {
	dices[index][1] = RESERVED;
}

/*
 * Resets all dices to be roll after each roll
 */
void Dice::reset() {
	for (int i = 0; i < NUM_DICE; i++) {
		dices[i][1] = NOT_RESERVED;
	}
}

/*
 * Returns Dices
 */
int** Dice::getDices() {
	return dices;
}

/*
 * Prints the dices
 */
void Dice::print() {
	for (int i = 0; i < NUM_DICE; i++) {
		cout << "DICE " << (i + 1) << ": " << dices[i][0] << endl;
	}
}
