// File containing functions required to print the board
// Written by - John O'Donnell

// Includes C standard libraries
#include <stdio.h>

// Includes user created C libraries
#include "defineAssignment2.h"
#include "gamePrint.h"
#include "stackFunctions.h"
#include "gameInitialisation.h"


// Declares the function printBoard which prints the board of the game as it changes throughout the game
void printBoard(square board[][NUM_COLUMNS]) {

    // Prints the top of the bard
    printf("\n                THE BOARD\n");

    printLine();

    // Loops through each row
    for(int i =0; i < NUM_ROWS; i++) {

        // Prints the number of each row at the side of the board
        printf(" %d ", i+1);

        // Creates a string to represent a tile on the board
        char c[4] = "   \0" ;

        // Loops through each column in each row
        for (int j = 0; j < NUM_COLUMNS; j++) {


            // If the tile (i,j) is occupied, c[1] is assigned to show the color of the token that occupies that tile
            if(!isEmpty(board[i][j])) {
                c[1] = printToken(board[i][j].stack);
            }

            // If the tile (i,j) is empty then c[1] is displayed as a tile with no token in it
            else {
              c[1] = ' ';
            }

            // If the tile (i,j) is an obstacle tile, c[0] and c[2] are assigned to show the obstacle characters in that tile
            if(board[i][j].type == OBSTACLE){
                c[0] = '{';
                c[2] = '}';
            }

            // Otherwise c[0] and c[2] are assigned as empty space
            else {
                c[0] = ' ';
                c[2] = ' ';
            }

            printf("|%s", c);
        }

    printf ("|\n");
    printLine();
    }

    // Prints the number of each column at the bottom of the board
    printf("     1   2   3   4   5   6   7   8   9\n");
}

// Declares the function printLine which prints a line of the game board to separate each row
void printLine() {
  printf("   -------------------------------------\n");
}
