/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   gamePrint.c
 * Author: John
 *
 * Created on 11 March 2019, 16:18
 */
#include <stdio.h>

#include "defineAssignment2.h"
#include "gamePrint.h"


char printToken(token *t){
    if((*t).colourToken == PINK) return 'P';
    if((*t).colourToken == RED) return 'R';
    if((*t).colourToken == BLU) return 'B';
    if((*t).colourToken == GREEN) return 'G';
    if((*t).colourToken == ORANGE) return 'O';
    if((*t).colourToken == YELLOW) return 'Y';
    return '\0';
}


void printBoard(square board[][NUM_COLUMNS]){
    printf("                THE BOARD\n");
    for(int i =0; i < NUM_ROWS; i++){

        //prints an horizontal line
        printLine();

        //prints the row number
        printf(" %d ", i+1);
        char c[4] = "   \0" ;

        //if the square (i,j) is occupied,
        //c is assigned the initial of the color of the token that occupies the square
        for (int j = 0; j < NUM_COLUMNS; j++){

            if(board[i][j].stack != NULL){
                c[1] = printToken(board[i][j].stack);
            }
            else{
              c[1] = ' ';
            }
            //if the square (i,j) is empty

            //c is assigned 'X' if the square represents an obstacle
            if(board[i][j].type == OBSTACLE){
                    c[0] = '{';
                    c[2] = '}';
                  }
                //c is assigned an empty space otherwise
                else {
                  c[0] = ' ';
                  c[2] = ' ';
                }
        
            printf("|%s ", c);
    }
        printf ("|\n");
    
    printLine();
    //prints the number of the columns at the end of the board
    }
    printf("     1   2   3   4   5   6   7   8   9\n");
}

void printLine(){
  printf("   -------------------------------------\n");
}
