#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

class Player {
    private:
        int id;
        string name;
    public:
        Player(int id, string name);
        ~Player();
        string getName();
};

#endif
