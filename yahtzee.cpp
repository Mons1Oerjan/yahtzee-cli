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
#include "yahtzee.h"
using namespace std;

yahtzee::yahtzee(int players): Game(players){}

yahtzee::~yahtzee(){}

void yahtzee::rollTheDice(Rules& r, ScoreBoard& s, Dice& d, int rollsLeft, int turn) {
    if (rollsLeft != 0) {
        char pch[10];
        cout << "What dices would you like to keep? " << "[ROLLS LEFT: " << rollsLeft << "]" << endl;
        cin.ignore();
        cin.getline(pch, 10);
        d.reset();

        for (int i = 0; i < 10; i++) {
            if (pch[i] >= 49 && pch[i] <= 53) {
                keeper[pch[i] - 49] = 1;
            }
        }

        for (int i = 0; i < 5; i++) {
            if (keeper[i] == 1) {
                d.reserveDice(i);
            }
        }

        d.rollDice();
        d.print();
        s.print(r.check(s.getScore(), d.getDices(), checkTurn() % 2));

        if (rollsLeft == 1) {
            return;
        }

        cout << "R to roll again, S to select a score." << endl;
        cin >> c;
        int flag = 0;

        while (flag == 0) {
            if(strcmp(c, "R") == 0) {
                flag = 1;
                rollTheDice(r, s, d, rollsLeft-1, checkTurn());
            }
            else if(strcmp(c, "S") == 0) {
                flag = 1;
            }
            else {
                cout << "R to roll again, S to select a score." << "[ROLLS LEFT: " << rollsLeft << "]" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin >> c;
            }
        }
    } else {
        cout << "NO TURNS LEFT!!!" << endl;
    }
}

void yahtzee::selectUpdate(Rules& r, ScoreBoard& s, Dice& d, int player) {
    int flag = 0;
    int num;
    cout << "Please Select Your Points!!!" << endl;

    while (flag == 0) {
        cin >> num;
        if (num >= 0 && num <= 13) {
            while (flag == 0 ) {
                flag = s.updateScore(r.check(s.getScore(), d.getDices(), checkTurn() % 2), num);
                if (flag == 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cin>>num;
                }
            }
        } else {
            cout << "Please Enter A valid Input!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }

    updateScore(player,s.getScore(player));
}

void yahtzee::playYathzee(){
    Rules r;
    Dice d;
    ScoreBoard s;
    string player1_name;
    string player2_name;

    cout << "Welcome to Yahtzee!" << endl;
    cout << "Please enter the name of Player1: ";
    cin >> player1_name;
    cout << "Please enter the name of Player2: ";
    cin >> player2_name;

    // set player names:
    Player p1(1, player1_name);
    Player p2(2, player2_name);
    s.setNamesOfPlayers(player1_name, player2_name);

    setRounds(15);

    while (gameOn() == 1) {
    	s.print();
    	cout << "Enter R to roll!!" << endl;
    	cin >> c;

    	if (strcmp(c, "R") == 0) {
            int flag = 0;
            d.reset();
    	    d.rollDice();
    	    d.print();
    	    s.print(r.check(s.getScore(), d.getDices(), checkTurn() % 2));
    	    cout << "R to roll again, S to select a score." << endl;
    	    cin >> c;

            while (flag == 0) {
		    if (strcmp(c, "R") == 0) {
                    flag = 1;
                    rollTheDice(r, s, d, 2, checkTurn());
                    selectUpdate(r, s, d, checkTurn() % 2);
                    updateTurn();
                }
                else if (strcmp(c, "S") == 0) {
                    flag = 1;
                    selectUpdate(r, s, d, checkTurn() % 2);
                    updateTurn();
                }
                else {
                    cout << "R to roll again, S to select a score." << endl;
                    cin >> c;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
    	} else {
    	    // empty cin
	    cin.clear();
	    // flush
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    	}
        d.reset();
    }
    cout<<"THE WINNER IS: ";

    if(getWinner() == 0) {
        cout << player1_name << endl;
    }
    else {
        cout << player1_name << endl;
    }
}
