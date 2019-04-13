// File containing function prototypes for gamePlay.c
// Written by - John O'Donnell and Eanna Curran

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

// Initialiases the function
int diceRoll();

// Initialises the function moveTokenUpOrDown
void moveTokenUpOrDown(char directionInput, struct square board[][NUM_COLUMNS], int columnInput, int rowInput, struct player players[], int i);

// Initialises the function moveTokenRight
void moveTokenRight(struct square board[][NUM_COLUMNS], int dice, struct player players[], int i);

// Initialises the function checkToken
bool checkToken(square board[][NUM_COLUMNS], int dice);

// Initialises the function checkWinTocken
int checkWinTocken(colour colourCkeck, struct player players[], unsigned int numPlayers);

// Initialises the function chechObstacle
void checkObstacle(square board[][NUM_COLUMNS]);

// Initialises the function playGame
void playGame(unsigned int numPlayers, struct square board[][NUM_COLUMNS], struct player players[]);

#endif /* GAMEPLAY_H */
