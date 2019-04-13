/*This program plays the 2- 6 player game Igel Ärgern
Written by John O'Donnell and Eanna Curran*/

// Includes C standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

// Includes user created C libraries
#include "defineAssignment2.h"
#include "stackFunctions.h"
#include "gameInput.h"
#include "gameInitialisation.h"
#include "gamePrint.h"
#include "gamePlay.h"


int main(void){

  // Creates an array which stores the information of each player in the game
  player players[6];
  // Creates an array which stores information for each square in the game board
  square board[NUM_ROWS][NUM_COLUMNS];

  // Calls the gameInput function to request the player inputs information about each player and returns the number of players in the game
  unsigned int numPlayers = gameInput(players);

  // Calls the initializeBoard function to initialize the board to its starting state
  initializeBoard(board);

  // Calls the printBoard function to print the board in its starting state
  printBoard(board);

  // Calls the boardSetup function to let the players set up the board before the game begins
  boardSetup(board, players, numPlayers);

  // Calls the playGame function to play through the game until a player wins
  playGame(numPlayers, board, players);

  return 0;
}
