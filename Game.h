#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string.h>
using namespace std;
//CLASS GAME
class Game{
		protected: // VAROIABLES
			int num_of_players;
			int winnerId;
			int winnerScore;
			int* score;
			int totalTurns=-1;
			int turn=0;
			// CONSTRUCTR PARAETER NUM = NUMBER OF PAYLES
			Game(int num){
				num_of_players=num;
				score = new int[num]; // ALLOCATES MEMORY
			}
			~Game(){} // DECONSTRUCTOR
			// UDATE TURN INCREASES THE TURN
			void updateTurn(){
				turn++;
			}

			// CHECK TURN RETURNSTURN
			int checkTurn(){
				return turn;
			}
			// SET ROUND UPDATES THE MAX NUMBER OF ROUNDS
			void setRounds(int r){
				totalTurns=r;
			}

			// GAME ON RETURNS ONE WHILE THERE ARE TURN REMAINING
			int gameOn(){
				if(turn>totalTurns){
					return 0;
				}
				else{
					return 1;
				}
			}

			// UPDATE SCORE  and winner
			void updateScore(int player, int points){
				score[player] = points;
				if(points>winnerScore){
					winnerScore=points;
					winnerId=player;
				}
			}
			// returns the winner and prints the points
			int getWinner(){

				cout<<"POINTS: "<< winnerScore<<endl;
				return winnerId;
			}
};

#endif