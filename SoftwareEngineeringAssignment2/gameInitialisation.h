// File containing the function prototypes for gameInitialisation.c
// Written by - John O'Donnell

#ifndef GAMEINITIALISATION_H
#define GAMEINITIALISATION_H

#define NUM_COLUMNS 9

// Initialises the function initializeBoard
void initializeBoard(struct square board[][NUM_COLUMNS]);

// Initialises the function boardSetup
void boardSetup(struct square board[][NUM_COLUMNS], struct player players[], int numPlayers);

// Initialises the function validStartingPosition
int validStartingPosition(struct square board[][NUM_COLUMNS], struct player player, unsigned int columnPositions[]);

#endif /* GAMEINITIALISATION_H */
