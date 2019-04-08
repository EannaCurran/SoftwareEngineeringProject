// Includes C standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

// Includes user created C libraries
#include "defineAssignment2.h"
#include "stackFunctions.h"
#include "gameInitialisation.h"
#include "gamePrint.h"
#include "gameInput.h"

// Declares the function initializeBoard which sets up the board at the start of the game
void initializeBoard(struct square board[][NUM_COLUMNS]) {
    
    // Loops through each row on the board
    for (int i =0; i< NUM_ROWS; i++) {
        
        // Loops through each column on the board
        for(int j =0; j < NUM_COLUMNS; j++) {

            // Creates an obstacle tile at positions (0,3), (1,6), (2,4), (3,5), (4,2) and (5,7)
            if((i == 0 && j==3) || (i == 1 && j == 6) || (i ==2 && j ==4) || (i == 3 && j ==5) || (i==4 && j==2) || (i==5 && j==7)) {
                board[i][j].type = OBSTACLE;
            }
            
            // Creates a normal tile at every other position
            else {
                board[i][j].type = NORMAL;
            }
        
        // Initializes the stack at the current tile
        board[i][j].stack = NULL;
        board[i][j].numStack = -1;
        }
    }
}

// Declares the function boardSetup which lets each user place their tokens in the first column before the game starts
void boardSetup(struct square board[][NUM_COLUMNS], struct player players[], int numPlayers) {
    
    // Creates variables
    unsigned int column1Positions[6] = {0, 1, 2, 3, 4, 5};
    int numValidPossitions, selectedRow;
    bool validPositionSelected;
    
    // Loops though for each token each player has
    for (size_t i = 1; i <= 4; i++) {
        
        // Loops through for each player in the game
        for (size_t j = 0; j < numPlayers; j++) {
            
            // Calls function validStartPosition to return which rows the current player can place their tokens on
            numValidPossitions = validStartingPosition(board, players[j], column1Positions);
            printf("\nPlayer %s please choose where to place your token %u in column\n", players[j].name , i );
            
            // Executes loop until the user inputs a valid row for their token
            do {
                
                // Resets ValidPositionSelected to false
                validPositionSelected = false;
                
                // Prints the valid row positions to the user
                printf("The valid position are rows:");
                
                for (size_t k = 0; k <= numValidPossitions; k++) {
                    printf(" %u", column1Positions[k]+1);
                }
                
                printf(".\n");
                
                // Gets user input for which row they want to place their token in
                scanf("%d", &selectedRow);
                clearLine();
                selectedRow--;
                
                // Loops through each valid row to check if the user inputted a valid row 
                for (size_t k = 0; k <= numValidPossitions && validPositionSelected != true; k++) {
                    
                    // If the user has inputted a valid row position, validPositionSelected is set to true so loop can be broken
                    if (selectedRow == column1Positions[k]) {
                        validPositionSelected = true;
                    }
                }
                
                // If the user hasn't inputted a valid row position, they are told and stay within the loop to input a new value
                if (validPositionSelected == false) {
                    printf("Invalid position to place token! Please try again.\n");
                }
            } while(validPositionSelected != true);
        
        // Calls function push which pushes the current users token to the row they inputted 
        push(players[j].playerColour, &board[selectedRow][0]);
        
        // Prints the updated board
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
