/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: John
 *
 * Created on 08 March 2019, 12:24
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

#include "defineAssignment2.h"
#include "gameInput.h"
#include "gameInitialisation.h"
#include "gamePrint.h"
#include "gamePlay.h"

int main(void){
  player players[6];
  square board[NUM_ROWS][NUM_COLUMNS];

<<<<<<< HEAD
  int numPlayers = gameInput(players);
  initializeBoard(board);
=======
  unsigned int numPlayers = gameInput(players);
  initialize_board(board);
>>>>>>> 2af1cbc4cc690f40ff89621c38df39bc0811b9e2

  printBoard(board);


  return 0;
}
