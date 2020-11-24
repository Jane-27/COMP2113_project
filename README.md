# COMP2113_project

## Group 119
XIONG Yingchao 3035446796
YANG Jinghan 3035638789

## Game Description
There are three layers of maps in this game. There are Zuma games between each two layers, and a 357 game is on the last layer. Games are interconnected, and you need to win through your wisdom.

## Features to implement

1. Generation of random game sets or events
    In the zuma game and 357 game (tfs), we use time(NULL) as seed to randomly generate 1) a row of ball in zuma game, 2) the action of the monster in 357 game
    
2. Data structures for storing game status
    Structures and linked list are used.
    In main game (lengend of god and war), we use 2-dimentional array to store the current game status (which is the map) of 3 different levels;
    In the zuma game, we use linked list to store the row of balls left on the table;
    In the 357 game, we use 

3. Dynamic memory management
    In the zuma game, we use linked list to store the game status. Since it can point to any other momory location, and we can know what is the order of a sequence of a row and can insert or delete any several balls innto it.
    
4. File input/output (e.g., for loading/saving game status)
    In the main.cpp(mota game), the input is which direction to go to, and whether to fight with a NPC or not. The output is the map of the level the player is at, and the results after fighting.
    In the zuma.cpp, input is how many balls you want, what color and position to insert the ball. The output is the row of balls left on the table, and finally when player win the game, how many points to get.
    In the 357.cpp, input is how many stones the player wants to take from what group, and the output is monster's actions, what stones are left after the action, and who wins the game

5. Program codes in multiple files
    There are 3 major files: main.cpp, zuma.cpp, tfs.cpp, each of them represents a different game, when the player arrives at a certain location, the main function will call the 2 game functions in different files, and the player will enter into the zuma game or 357 game. 
    
## Compilation and excution
    g++ -pedantic-errors -std=c++11 main.cpp zuma.cpp tfs.cpp -o main
    ./main
