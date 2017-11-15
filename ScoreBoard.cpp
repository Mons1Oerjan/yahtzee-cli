/*
 * ScoreBoard Class inherits from printable
 */
#include <iostream>
#include "ScoreBoard.h"
using namespace std;

// constructor
ScoreBoard::ScoreBoard() {
	scores = new int*[14]; // stores the player's current points.
	updates = new int[14]; // Keeps track of the positions available for the player

	// allocate memory:
	for (int i = 0; i < 14; i++) {
		scores[i] = new int[2];
		scores[i][0] = 0;
		scores[i][1] = 0;
		updates[i] = 0;
	}
}

// deconstructor
ScoreBoard::~ScoreBoard() {}

// prints the board in a specific format.
void ScoreBoard::print() {
	for (int i = 0; i < 2; i++) {
		if (i == 0) {
			printf("%20s", "");
		}
		printf("|%-10s|", nameOfPlayers[i].c_str());
	}

	cout << endl << "-------------------------------------------" << endl;

	for (int i = 0; i < 14; i++) {
		printf("%-20s|%6d    ||%6d    |\n", scoreLabels[i].c_str(), scores[i][0], scores[i][1]);
		cout << "-------------------------------------------" << endl;
	}
}

/*
 * This method is different from print(). Here we print the data passed as
 * parameters, which is passed by the Rules class.
 * This allows to display the options without modifying the current data.
 * Keeps track of data updates.
 * Same format as print but extra update option.
 */
void ScoreBoard::print(int** data) {
	for (int i = 0; i < 2; i++) {
		if (i == 0) {
			printf("%20s", "");
		}
		printf("|%-10s|", nameOfPlayers[i].c_str());
	}

	cout << endl << "-------------------------------------------" << endl;

	for (int i = 0; i < 14; i++) {
		printf("%-20s|%6d    ||%6d    |", scoreLabels[i].c_str(), data[i][0], data[i][1]);

		// check if cell can be updated:
		if (data[i][0] != scores[i][0] || data[i][1] != scores[i][1]) {
			cout << "######-  " << i << "  -######" << endl;
			updates[i] = 1;
		} else {
			cout << endl;
			updates[i] = 0;
		}
		cout << "-------------------------------------------" << endl;
	}
}

/*
 * Updates the score of the current data given an index and the
 * data generated by the Rules class.
 * returns 1 if data has been updated or cannot be updated.
 * 0 if user enter the incorrect data
 */
int ScoreBoard::updateScore(int** data, int index) {
	int noPossibleMoves = 0; // in case no possible moves allowed

	for (int i = 0; i < 14; i++) {
		if (updates[i] == 1) {
			noPossibleMoves = 1;
		}
	}

	if (noPossibleMoves == 0) {
		cout << "You Got No Possible Moves!!!" << endl;
		return 1;
	}

	if (updates[index] == 1) {
		// updates data of the index provided.
		if (scores[index][0] != data[index][0]) {
			scores[index][0] = data[index][0];
		} else {
			scores[index][1] = data[index][1];
		}

		return 1;
	}
	else {
		cout << "Error: Please Enter a valid number." << endl;
		return 0;
	}
}

/*
 * returns the current score
 */
int** ScoreBoard::getScore() {
	return scores;
}


/*
 * returs the updated positions
 */
int* ScoreBoard::getUpdates() {
	return updates;
}

/*
 * Returns the total score for the selected player
 */
int ScoreBoard::getScore(int player) {
	int sum = 0;

	for (int i = 0; i < 14; i++) {
		sum = sum + scores[i][player];
	}

	return sum;
}

/*
 * Sets the names of each player on the scoreboard
 */
void ScoreBoard::setNamesOfPlayers(string p1, string p2) {
	nameOfPlayers[0] = p1;
	nameOfPlayers[1] = p2;
}
