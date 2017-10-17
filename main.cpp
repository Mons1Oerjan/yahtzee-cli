#include "Player.h"
#include <iostream>

#define MAX_TURNS 15

using namespace std;

void player_plays_game(Player* p) {
    // TODO: Add game logic here.
}

int main(void) {
    int turn = 0;
    string player1_name;
    string player2_name;

    cout << "Welcome to Yahtzee!" << endl;
    cout << "Please enter the name of Player1: ";
    cin >> player1_name;
    cout << "Please enter the name of Player2: ";
    cin >> player2_name;

    Player* p1 = new Player(1, player1_name);
    Player* p2 = new Player(2, player2_name);

    // Start game:
    while(turn <= MAX_TURNS) {
        cout << "Round " << turn << endl;

        // Player1's turn:
        cout << p1->getName() << " rolls 5 dices:" << endl;
        player_plays_game(p1);

        // Player2's turn:
        cout << p2->getName() << " rolls 5 dices:" << endl;
        player_plays_game(p2);

        turn++;
    }

    // TODO: Calculate total score and print winner.
    cout << "The winner is: " << endl;

    // Free memory and exit program:
    delete p1;
    delete p2;
    p1 = NULL;
    p2 = NULL;
    return 0;
}
