/*
 * Rules class checks and updates the game based on its rules
 */
#include "Rules.h"
using namespace std;

// constructor
Rules::Rules() {
	// allocate memory for the updated scoreboard:
	newBoard = new int*[14];

	for (int i = 0; i < 14; i++) {
		newBoard[i] = new int[2];
		newBoard[i][0] = 0;
		newBoard[i][1] = 0;
	}
}

// deconstructor
Rules::~Rules() {}

/*
 * Checks for every single outcome based on the rules. Updates
 * new board and returns it. Takes the current board to only
 * update non-updated cells. Uses the dice outcome to check for posibilities
 * and the player only updates the corresponding cell.
 */
int** Rules::check(int** board, int** dice, int player) {
	copyBoard(board);
	int sum = 0;
	int bonusSum = 0;
	int kinds[6] = {0, 0, 0, 0, 0, 0};

	// check for the input from the dices:
	for (int i = 0; i < 5; i++) {
		sum += dice[i][0];
		kinds[dice[i][0] - 1]++;
	}

	// updates chance
	if(newBoard[12][player] == 0) {
		newBoard[12][player] = sum;
	}

	// checks for large straight and update kinds
	for (int i = 0; i < 6; i++) {
		// checks for bonus sum
		bonusSum += board[i][player];

		// checks for lower bound prizes
		if (newBoard[i][player] == 0 && kinds[i] >= 0) {
			newBoard[i][player] = kinds[i] * (i+1);
		}

		// checks for small straight
		if (i <= 2 && newBoard[10][player] == 0) {
			if (kinds[i] >= 1 && kinds[i+1] >= 1 && kinds[i+2] >= 1 && kinds[i+3] >= 1) {
				newBoard[10][player] = 30;
			}
		}

		// checks for large straight
		if (i <= 1 && newBoard[11][player] == 0) {
			if (kinds[i] >= 1 && kinds[i+1] >= 1 && kinds[i+2] >= 1 && kinds[i+3] >= 1 && kinds[i+4] >= 1) {
				newBoard[11][player] = 30;
			}
		}

		// checks 3 of a kind
		if (kinds[i] >= 3 && newBoard[7][player] == 0) {
			newBoard[7][player] = sum;
		}

		// checks 4 of a kind
		if (kinds[i] >= 4 && newBoard[8][player] == 0) {
			newBoard[8][player] = sum;
		}

		// checks YAHTZEE and BONUS
		if (kinds[i] == 5 && newBoard[13][player] == 0) {
			newBoard[13][player] = 50;
		}
		else if (kinds[i] == 5 && newBoard[13][player] >= 50) {
			newBoard[13][player] = newBoard[13][player] + 100;
		}

		// checks for fullhouse.
		if (kinds[i] == 2 && newBoard[9][player] == 0) {
			for (int j = 0; j < 5; j++) {
				if (kinds[j] == 3) {
					newBoard[9][player] = 25;
				}
			}
		}
	}

	// updates lower bonus if needed directly on the board
	if (bonusSum >= 63) {
		board[6][player] = 35;
	}

	return newBoard;
}

/*
 * copies the board to prevent updating the current board before
 * the user choses to update.
 */
void Rules::copyBoard(int** board) {
	for (int i = 0; i < 14; i++) {
		newBoard[i][0] = board[i][0];
		newBoard[i][1] = board[i][1];
	}
}
