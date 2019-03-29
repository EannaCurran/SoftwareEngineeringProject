/*This program plays the 2- 6 player game Igel Ärgern
Written by John O'Donnell and Eanna Curran*/

/*Including Stardard C Libarys*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

/*Including User Created C Libarys*/
#include "defineAssignment2.h"
#include "stackFunctions.h"
#include "gameInput.h"
#include "gameInitialisation.h"
#include "gamePrint.h"
#include "gamePlay.h"


int main(void){
  /*Variables*/
  player players[6];/*An array storing the information on the player for the game*/
  square board[NUM_ROWS][NUM_COLUMNS];/*Array of the squares on the board storing infromation on each square*/

  /*Calls the gameInput function to request player input on players and return number of players*/
  unsigned int numPlayers = gameInput(players);

  /*Calls the initializeBoard function to initialize the board to its starting state*/
  initializeBoard(board);

  /*Calls the printBoard function to print the board in its starting state*/
  printBoard(board);

  boardSetup(board, players, numPlayers);

  playGame(numPlayers, board, players);

  printBoard(board);


>>>>>>> 5e37adc3b85a7c36e7f99db97519edc700c8e44c
  return 0;
}
