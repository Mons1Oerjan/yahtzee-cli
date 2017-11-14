# CSCI 3132 Group Project: Yahtzee

Yahtzee text-based console I/O game in c++

## Compile
- Run `make` or `make all`

## Run Program
- Run `./a.out`

## Software Description
### Abstraction
All these three classes below work as interfaces that interact with each other and only provide the data needed.

#### Rules
The `Rules` class only returns data with updated scores when given current data and data from a dice. No other object enters this class.

#### ScoreBoard
The `ScoreBoard` class prints the scoreBoard by two different methods.
One prints the updated scoreBoard which stores / updates the scores. The other method prints the scoreboard with the possibilities provided by the `Rules` class. Hence it only returns the data and takes data. No other class can access it.

#### Dice
In a similar manner, the `Dice` class provides functionality. It keeps track of all the dices and the numbers stored in them. It also flags the dices the user wants to keep. It only takes input int, flags that dice and returns its stored data to `Rules` which it will use to check for possibilities.

### Encapsulation
Based on the explanation of Abstraction, the same classes are using encapsulation. All the logical operations are hidden inside each class which is defined by the behaviour in the game.

### Inheritance
The `Printable` class is inherited by `Scoreboard` and `Dice`.
Yahtzee class inherits from game class that keeps track of the total score and turns remaining. It also flags when the game is over.

### Polymorphism
This can be seen in the Yahtzee class. In this class all previous named classes are used to provide logic to the game. In other words, in this class all the components come together and work logically.

### Use of Pointers and References
- For critical data points we used the `heap`.
- for data access (objects) we use the `stack` for efficiency. Since all data manipulation is done through a pipeline process in the `Yahtzee` class:

dice_data -> rules_data <- scoreboard_data
rules_data -> scoreboard_data

- All data was passed in as pointers and only modified when needed. Data modification only occurs on the original class of the data.
- No extra copies of data are being created.
