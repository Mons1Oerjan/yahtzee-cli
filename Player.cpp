#include "Player.h"

/*
Players class to store name of the platers
*/
// Constructor takes two strings as id and name
Player::Player(int id, string name) {
    this->id = id;
    this->name = name;
}

// Destructor
Player::~Player() {

}
// returns name
string Player::getName() {
    return this->name;
}
