// File containing the functions to Initialises the game
// Written by - John O'Donnell

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


// Declares the function boardSetup which lets each user place their tokens in
// The first column before the game starts
void boardSetup(struct square board[][NUM_COLUMNS], struct player players[], int numPlayers) {

  // Creates variables
  int numValidPossitions, selectedRow;
  bool validPositionSelected;

  // Loops though for each token each player has
  for (size_t i = 1; i <= 4; i++) {

    // Loops through for each player in the game
    for (size_t j = 0; j < numPlayers; j++) {
      unsigned int column1Positions[6] = {0, 1, 2, 3, 4, 5};

      // Calls function validStartPosition to return which rows the current
      // Player can place their tokens on
      numValidPossitions = validStartingPosition(board, players[j], column1Positions);
      printf("\nPlayer %s please choose where to place your token %u in column:\n", players[j].name , i );

      // Executes loop until the user inputs a valid row for their token
      do {

        // Resets ValidPositionSelected to false
        validPositionSelected = false;

        // Prints the valid row positions to the user
        printf("The valid position are rows:");

        // Loop through each vaild positions
        for (size_t k = 0; k <= numValidPossitions; k++) {
          printf(" %u", column1Positions[k] + 1);
        }

        printf(".\n");

        // Gets user input for which row they want to place their token in
        scanf("%d", &selectedRow);

        // Calls clearLine to empty stdin buffer so not to have value run into next scanf
        clearLine();

        // Decroment selectedRow
        selectedRow--;

        // Loops through each valid row to check if the user inputted a valid row
        for (size_t k = 0; k <= numValidPossitions && validPositionSelected != true; k++) {

          // If the user has inputted a valid row position, validPositionSelected
          // Is set to true so loop can be broken
          if (selectedRow == column1Positions[k]) {
            validPositionSelected = true;
          }
        }

        // If the user hasn't inputted a valid row position, they are told
        // So and stay within the loop to input a new value
        if (validPositionSelected == false) {
          printf("Invalid position to place token! Please try again.\n\n");
        }

      } while(validPositionSelected != true);

      // Calls function push which pushes the current users token to the row they inputted
      push(players[j].playerColour, &board[selectedRow][0]);

      // Prints the updated board
      printBoard(board);
    }
  }
}

// validStartingPosition sorts the list of posible postions in 1st column inorder to return valid postions
int validStartingPosition(struct square board[][NUM_COLUMNS], struct player player, unsigned int columnPositions[]) {
  // Declare variables
  unsigned int temp;
  int index, validPositionCounter = 0;

  //For loop to sort the positions by smallest stack using selection sort algorithm
  for (size_t i = 0; i < 5; i++) {
    // Sets index equal to i
    index = i;

    //Loop through positions
    for (size_t j = i+1; j < 6; j++) {

      //If index position is greater than position j, index = j
      if (board[columnPositions[index]][0].numStack > board[columnPositions[j]][0].numStack) {
        index = j;
      }
    }

    // Swap the index position with i position
    temp = columnPositions[index];
    columnPositions[index] = columnPositions[i];
    columnPositions[i] = temp;

  }

  //Loops through to find how many from the start of the array have the same number of tokens in their stack
  for (size_t i = 1; i < 6 && board[columnPositions[i]][0].numStack == board[columnPositions[i-1]][0].numStack; i++) {

    // Set validPositionCounter equal to the position where numStack are the same
    validPositionCounter = i;
  }


  //Loops through each valid position to check that the top token doesnt belong to the player if it does send to end of the valid positions and decroment validPositionCounter
  for (size_t i = 0; i <= validPositionCounter && validPositionCounter != -1; i++) {

    //If the stack is not empty and the top token belongs to player
    if ( !isEmpty( board[columnPositions[i]][0]) && board[columnPositions[i]][0].stack->colourToken == player.playerColour) {

      //Swap last valid position with current position
      temp = columnPositions[validPositionCounter];
      columnPositions[validPositionCounter] = columnPositions[i];
      columnPositions[i] = temp;

      // Decroment validPositionCounter and i
      validPositionCounter--;
      i--;
    }
  }

  return validPositionCounter;
}
