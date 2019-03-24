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
  playGame();

<<<<<<< HEAD
  /*Testing stack
  char testChar;
  do {
    printf("Please enter char to be pushed\n" );
    scanf("%c",&testChar );
  } while(!push(testChar, &board[0][0]));
=======
>>>>>>> 22094772b0db5dbb46e05882e02c65e5be931c5e


<<<<<<< HEAD
printf("%c\n",top(board[0][0]));
printBoard(board);
=======
  //Testing stack
  while(!push(YELLOW, &board[0][0]));

  printBoard(board);

  printf("%c\n",top(board[0][0]));
>>>>>>> 22094772b0db5dbb46e05882e02c65e5be931c5e

  pop(&board[0][0]);
  printBoard(board);


<<<<<<< HEAD
   * */
=======
  board[0][0].top = 1;
  board[1][0].top = 7;
  board[2][0].top = 3;
  board[3][0].top = 4;
  board[4][0].top = 6;
  board[5][0].top = 2;

  validStartingPosition(board, players, numPlayers);
>>>>>>> 22094772b0db5dbb46e05882e02c65e5be931c5e
  return 0;
}
