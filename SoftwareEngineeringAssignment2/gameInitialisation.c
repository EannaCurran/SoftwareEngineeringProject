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
 

void initialize_board(struct square board[][NUM_COLUMNS]){

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
        }
    }
    return;
}
