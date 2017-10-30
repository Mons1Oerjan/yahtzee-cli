/*
 * Players class to store name of the players
 */
#include "Player.h"

// Constructor
Player::Player(int id, string name) {
    this->id = id;
    this->name = name;
}

// Destructor
Player::~Player() {

}

string Player::getName() {
    return this->name;
}
