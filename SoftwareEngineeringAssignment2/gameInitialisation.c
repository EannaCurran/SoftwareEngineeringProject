/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   gameInitialisation.c
* Author: John
*
* Created on 11 March 2019, 16:13
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include "defineAssignment2.h"
#include "stackFunctions.h"
#include "gameInitialisation.h"
#include "gamePrint.h"
#include "gameInput.h"


void initializeBoard(struct square board[][NUM_COLUMNS]){

  for (int i =0; i< NUM_ROWS; i++){

    for(int j =0; j < NUM_COLUMNS; j++){


      //creates an obstacle square at positions (0,3), (1,6), (2,4), (3,5), (4,2) and (5,7)
      if((i == 0 && j==3) || (i == 1 && j == 6) || (i ==2 && j ==4) || (i == 3 && j ==5) || (i==4 && j==2) || (i==5 && j==7)){
        board[i][j].type = OBSTACLE;
      }
      else{
        //creates a normal square otherwise
        board[i][j].type = NORMAL;
      }

      board[i][j].stack = NULL;
      board[i][j].numStack = -1;
    }
  }
  return;
}

void boardSetup(struct square board[][NUM_COLUMNS], struct player players[], int numPlayers) {

  unsigned int column1Positions[6] = {0, 1, 2, 3, 4, 5};
  int numValidPossitions, selectedRow;
  bool validPositionSelected;

  for (size_t i = 1; i <= 4; i++) {
    for (size_t j = 0; j < numPlayers; j++) {
      printf("Player %s please choose where to place your token %d in column\n", players[j].name , i );

      numValidPossitions = validStartingPosition(board, players[j], column1Positions);

        do{
          validPositionSelected = false;

          printf("\nPlayer %s please choose where to place your token %u in column\nThe valid position are rows:", players[j].name , i );

          for (size_t k = 0; k <= numValidPossitions; k++) {
            printf(" %u", column1Positions[k]+1);
          }
          printf(".\n");

          scanf("%d", &selectedRow);
          clearLine();
          selectedRow--;

          for (size_t k = 0; k <= numValidPossitions && validPositionSelected != true; k++) {
            if (selectedRow == column1Positions[k]) {
              validPositionSelected = true;
            }
          }

          if (validPositionSelected == false) {
            printf("Invalid position to place token! Try again.\n");
          }
        }while(validPositionSelected != true);

      push(players[j].playerColour, &board[selectedRow][0]);

      printBoard(board);
    }
  }
}

int validStartingPosition(struct square board[][NUM_COLUMNS], struct player player, unsigned int columnPositions[]) {
  unsigned int temp;
  int index, validPositionCounter = 0;

  for (size_t i = 0; i < 5; i++) {
    index = i;
    for (size_t j = i+1; j < 6; j++) {

      if (board[columnPositions[index]][0].numStack > board[columnPositions[j]][0].numStack) {
        index = j;
      }
    }

    temp = columnPositions[index];
    columnPositions[index] = columnPositions[i];
    columnPositions[i] = temp;

  }


  for (size_t i = 1; i < 6 && board[columnPositions[i]][0].numStack == board[columnPositions[i-1]][0].numStack; i++) {
    validPositionCounter = i;
  }


  for (size_t i = 0; i <= validPositionCounter && validPositionCounter != -1; i++) {
    if ( !isEmpty( board[columnPositions[i]][0]) && board[columnPositions[i]][0].stack->colourToken == player.playerColour) {
      temp = columnPositions[validPositionCounter];
      columnPositions[validPositionCounter] = columnPositions[i];
      columnPositions[i] = temp;

      validPositionCounter--;
      i--;
    }

  }
  return validPositionCounter;
}
