/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   gamePlay.c
 * Author: John
 *
 * Created on 11 March 2019, 16:18
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "defineAssignment2.h"
#include "stackFunctions.h"


void playGame(unsigned int numPlayers, struct square board[][NUM_COLUMNS], struct player players[]) {

    bool checkForWin = false, directionCheck;
    int dice, rowInput, columnInput;
    char directionInput;

    while(checkForWin == false){
        for(int i = 0; i < numPlayers; i++){
            printf("Player %d turn\n", i+1);
            dice = diceRoll();
            printf("Player %d rolled %d\n", i+1, dice);
            printf("Enter the co-ordinate of which of your tokens you would like to move \n");
            do{
                scanf("%d %d", &rowInput, &columnInput);
                clearLine2();
                if(board[rowInput][columnInput].top != players[i].playerColour){
                    printf("Not your counter please try again\n");
                }
            } while(1 != 1);

            printf("Do you want to move your token up or down?(U for up, D for Down)\n");
            do{
                directionCheck = true;
                scanf("%c", &directionInput);
                clearLine2();
                if(directionInput != 68 && directionInput != 85){
                    printf("Invalid input please try again\n");
                    directionCheck = false;
                }
                else if(directionInput != 68 && rowInput == 6){
                    printf("Cannot move token down please try again\n");
                    directionCheck = false;
                }
                else if(directionInput != 85 && rowInput == 1){
                    printf("Cannot move token up please try again\n");
                    directionCheck = false;
                }
            } while(directionCheck = false);
            printf("Token has been moved\n");
        }
        checkForWin = true;
    }
}

int diceRoll(){

    srand(time(NULL));
    return (rand() % 5) + 1;
}

void clearLine2(){
  /*Variables*/
  int temp;

  /*Do while loop to get chars from stdin and store them in temp till a new line*/
  do{

    temp = fgetc(stdin);

  } while (temp != '\n' && temp != EOF);
}
