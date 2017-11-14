#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string.h>
using namespace std;

class Game{
	protected: 
		// variables
		int num_of_players;
		int winnerId;
		int winnerScore;
		int* score;
		int totalTurns=-1;
		int turn=0;
	
		// constructor with num_of_players input
		Game(int num) {
			num_of_players = num;
			score = new int[num]; // ALLOCATES MEMORY
		}
		
		// deconstructor
		~Game(){}
	
		// function to increment the turn
		void updateTurn(){
			turn++;
		}

		// getter for the turn
		int checkTurn(){
			return turn;
		}
	
		// setter for totalTurns
		void setRounds(int r){
			totalTurns = r;
		}

		// returns 1 while there are turns remaining
		int gameOn(){
			if (turn > totalTurns) {
				return 0;
			} else {
				return 1;
			}
		}

		// updated the score and winner
		void updateScore(int player, int points) {
			score[player] = points;
			
			if (points > winnerScore) {
				winnerScore = points;
				winnerId = player;
			}
		}
	
		// returns the winner and prints the points
		int getWinner() {
			cout << "POINTS: " << winnerScore << endl;
			return winnerId;
		}
};

#endif
