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
    
    bool checkForWin = false;
    int dice;
    
    while(checkForWin == false){
        for(int i = 0; i < numPlayers; i++){
            printf("Player %d turn\n", i+1);
            dice = diceRoll();
            printf("Player %d rolled %d\n", i+1, dice);
        }
        checkForWin = true;
    }
}

int diceRoll(){
    srand(time(NULL));
    return (rand() % 5) + 1;
}