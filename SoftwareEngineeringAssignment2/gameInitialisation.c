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

            //board[i][j].stack = NULL;
            board[i][j].top = -1;
        }
    }
    return;
}

void boardSetup(struct square board[][NUM_COLUMNS], struct player players[], int numPlayers) {

unsigned int cloumn1Positions[6] = {0, 1, 2, 3, 4, 5};

  for (size_t i = 0; i < 4; i++) {
    for (size_t j = 0; j < numPlayers; j++) {
      printf("Player %s please choose where to place your token %d in column\n", players[j].name , i+1 );
    }
  }
}

void validStartingPosition(struct square board[][NUM_COLUMNS], struct player player[], int numPlayers) {
  unsigned int temp, columnPositions[6] = {0,1,2,3,4,5};
  int index;

  for (size_t i = 0; i < 5; i++) {
    index = i;
    for (size_t j = i+1; j < 6; j++) {
        
        //printf("%u=%d  >  %u=%d\n",columnPositions[index],board[columnPositions[index]][0].top,columnPositions[j], board[columnPositions[j]][0].top);
      if (board[columnPositions[index]][0].top > board[columnPositions[j]][0].top) {
        index = j;
        
      }
      
      
    }
    temp = columnPositions[index];
      columnPositions[index] = columnPositions[i];
      columnPositions[i] = temp;
      
      
  }
    printf("\n\n");
      for (size_t i = 0; i < 6; i++) {
        printf("%u\t%d\n", columnPositions[i], board[columnPositions[i]][0].top);
      }
}
