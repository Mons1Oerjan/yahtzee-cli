# To run, enter "make" or "make all"

all: yahtzee

yahtzee: *.cpp
	g++ -std=c++11 *.cpp

clean:
	rm a.out
