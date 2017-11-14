#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "yahtzee.h"
#include <string.h>
#include <cstring>
using namespace std;

int main() {
    // initialize objects:
    yahtzee* game = new yahtzee(2);
    game->playYathzee();

	return 0;
}
