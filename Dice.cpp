#include "Dice.h"
/*
Class Dice stores the numbers of 5 diffrent dices. iNHERITS FROM printable
*/
Dice::Dice(){ // constructor
	dices = new int*[5];
	for(int i =0; i<5; i++){
		dices[i]=new int[2];
		dices[i][0]=0;
		dices[i][1]=1;
	}
}

Dice::~Dice(){} // deconstructor

void Dice::rollDice(){ // roll the dices that the user would like to roll.
	for(int i=0; i<5; i++){
		if(dices[i][1]==1){ // checks for roll flag store at [i][1]
			dices[i][0]= rand() % 6 + 1; // assignes random number
		}
	}
}

/*
Flags the dice to prevent rolling. User inputs the index
*/
void Dice::reserveDice(int index){
	dices[index][1]=0; // flags ir
}
/*
Resets all dices to be roll after each roll
*/
void Dice::reset(){
	for(int i=0; i<5; i++){
		dices[i][1]= 1;
	}
}

/*
Returns Dices
*/
int** Dice::getDices(){
	return dices;
}

/*
Prints the dices
*/
void Dice::print(){
	for (int i=0; i<5; i++){
		cout<<"DICE "<<(i+1)<<": "<<dices[i][0]<<endl;
	}
}