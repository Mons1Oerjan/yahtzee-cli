Abstraction: 

Class Rules only returns a data with updated scores when given current data and data from a dice. No Other object enters this class.

Class ScoreBoard prints the scoreBoard by two different method.
One prints the update scoreBoard which it stores/ modifies and also prints the scoreboard with the possibilities provided by the rules class. Hence it only returns the data and takes data. Noter Class can
access it. 

In a similar manner, the Dice class provides functionality. It keePS track of all the dices and the numbers stored in them. Also it flags the dices the user wants to keep. It only takes input int, to  flag that dice and only returns its stored data to rules which it will use to check for possibilities.

Hence all these three classes work as interfaces that interact with each other and only provide the data needed.

Encapsulation: Bases on the explanation on Abstraction, the same classes can be used for encapsulation. Since all the logical operations are hidden inside each class which is defined by its behaviour on the game.

Inheritance: Printable class is inherited by Scoreboard and Dice.

TODO:: MOVE MAIN TO YATZEEE CREATE H AND CPP FILES AND CREATE A GAMEON CLASS.


Polymorphism: It can be seen in the Yatzee class. In this class all previous named classes are used to provide logic to the game. In other words, in this class all the components come together and work logically.

Good use of pointers and references–Overall quality of the code:
For critical data points we used heap, for data access (objects) we tried to use the stack for efficiency. Since all data manipulation is done through a pipeline proccess: 

dice_data -> rules_data <-scoreboar_data
rules_data->scoreboard_Data
All the above in yatzee class. 

All data was passed in as pointers and only modified when needed. Data modification only occurs on the origin class of the data. 
No extra copies of data were done. 