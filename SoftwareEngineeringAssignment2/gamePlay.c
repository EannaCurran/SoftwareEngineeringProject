// File containing functions required to play the the game
// Written by - John O'Donnell and Eanna Curran

// Includes C standard libraries
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Includes user created C libraries
#include "defineAssignment2.h"
#include "gamePlay.h"
#include "stackFunctions.h"
#include "gameInitialisation.h"
#include "gamePrint.h"
#include "gameInput.h"


// Declares function playGame which players through a game of Igel Argern
void playGame(unsigned int numPlayers, struct square board[][NUM_COLUMNS], struct player players[]) {

  // Creates variables
  bool checkForWin = false, directionCheck = false, inputCheck = false, inputCheckRight = false, tokenFound;
  int dice, rowInput, columnInput, columnInputRight, winner;
  char directionInput, upDownChoice;;

  // Continues to play each round until checkForWin is set to true
  while(checkForWin == false){

    // Loops for each players turn during a round
    for(int i = 0; i < numPlayers && checkForWin == false; i++){

      // Displays the dice roll for that players turn
      printf("\nPlayer %s turn\n", players[i].name);
      //Calls dice roll to get random number between 1 - 6
      dice = diceRoll();
      printf("Player %s rolled %d\n", players[i].name, dice);


      // Do while loop to scan if the player wants to move one of their tokens
      // Up or down until the player inputs Y or N
      do{

        // Scans in the players input
        printf("\nEnter Y to move a token you own up or down, else enter N: \n");
        scanf("%c" ,&upDownChoice);
        clearLine();

      }while(upDownChoice != 'Y' && upDownChoice != 'N');

      // Checks if the user has indicated that the want to move a token up
      // Or down the board
      if(upDownChoice == 'Y'){

        // Do while loop which continues until a valid token of the current player is moved
        do{

          // Do while loop to scan until the player inputs a co-ordinate which is on the board
          do{

            // Resets input check to true
            inputCheck = true;

            // Scans in the players input for co-ordinates
            printf("\nEnter the co-ordinate of which of your tokens you would like to move: \n(Enter co-ordinates as: column row)\n");
            scanf("%d%d", &columnInput, &rowInput);

            // Calls clearLine to empty stdin buffer so not to have value run into next scanf
            clearLine();

          }while((columnInput < 1 || columnInput > 9) && (rowInput < 1 || rowInput > 6));

          // Decreases rowInput and columnInput by 1
          rowInput--;
          columnInput--;

          // Checks if the player has inputted a board co-ordinate with no token,
          // If so inputCheck is set to false
          if (isEmpty(board[rowInput][columnInput])) {

            printf("Invalid Input please try again.\n");
            inputCheck = false;

          }

          // Checks if the player has inputted a board co-ordinate with is not their token,
          // If so inputCheck is set to false
          else if(topColour(board[rowInput][columnInput]) != players[i].playerColour ){

            printf("Not your counter please try again\n");
            inputCheck = false;

          }

          // Checks if the player has inputted a board co-ordinate with an obstacle,
          // If so inputCheck is set to false
          else if (board[rowInput][columnInput].type == OBSTACLE) {

            printf("Sqaure is an obstacle so tokens can't be moved.\n");
            inputCheck = false;

          }

        } while(!inputCheck);


        // Do while loop to receive the players input for a valid direction
        // They want to move a token
        do{

          // Resets directionCheck to true
          directionCheck = true;

          printf("\nDo you want to move your token up or down?\n(U for up, D for Down)\n");

          // Gets the players input for which direction they want a token
          scanf("%c", &directionInput);
          clearLine();

          // Checks if the player has inputted an invalid input,
          // If so  directionCheck is set to false
          if(directionInput != 'U' && directionInput != 'D'){

            printf("Invalid input please try again\n");
            directionCheck = false;

          }

          // Checks if the player has inputted to move a token down in row 6,
          // If so  directionCheck is set to false
          else if(directionInput == 'D' && rowInput == 5){

            printf("Cannot move token down please try again\n");
            directionCheck = false;

          }

          // Checks if the player has inputted to move a token up in row 1,
          // If so  directionCheck is set to false
          else if(directionInput == 'U' && rowInput == 0){

            printf("Cannot move token up please try again\n");
            directionCheck = false;

          }

        } while(directionCheck != true);


        // Calls function to move the token up or down
        moveTokenUpOrDown(directionInput, board, columnInput, rowInput, players, i);

        // Calls function to print the board
        printBoard(board);
      }

      // Decrease the value of dice by 1
      dice--;

      // Stores boolean value of the call checkToken to check if there are any
      // Tokens in the row indicated by the dice roll
      tokenFound = checkToken(board, dice);

      // Checks if there is a token the player can be moved right,
      // Otherwise the turn is passed
      if(!tokenFound){

        // Do while loop which continues until the player inputs a valid
        // Column to move a token forward
        do{

          // Do while loop that loops until the player inputs a column
          // Which is on the board
          do{

            // Resets inputCheckRight to true
            inputCheckRight = true;

            // Receives the players input for the column position
            // Which is on the board
            printf("\nEnter the column of which of your tokens you would like to move right:\n");
            scanf("%d", &columnInputRight);
            clearLine();
          }while((columnInputRight < 1 || columnInputRight > 8));

          // Decreases columnInputRight by 1
          columnInputRight--;

          // Checks if the user has inputted an empty co-ordinate,
          // If so inputCheckRight is set to false
          if(isEmpty(board[dice][columnInputRight])){
            printf("Invalid Input please try again.\n");
            inputCheckRight = false;
          }

          // Checks if the user has inputted a co-ordinate with contains an obstacle,
          // If so inputCheckRight is set to false
          else if (board[dice][columnInputRight].type == OBSTACLE) {

            printf("Sqaure is an obstacle so tokens can't be moved.\n");
            inputCheckRight = false;

          }

        } while(!inputCheckRight);

        // Moves the a valid token forward
        moveTokenRight(board, dice, players, columnInputRight);

        // Removes obstacle object from the board if possible
        checkObstacle(board);
        printBoard(board);


        // Checks if the player has has moved a token into the last column,
        // If so checkWinToken function is called
        if (columnInputRight == 7 && !isEmpty(board[dice][8])) {

          // Calls checkWinToken which returns a plays name if they have
          // 3 tokens in the last column, returns -1 otherwise
          winner = checkWinTocken(topColour(board[dice][8]), players, numPlayers);

          // Checks if a player has won, if so checkForWin is set
          // To true and the winning players name is printed
          if (winner != -1) {

            checkForWin = true;
            printf("\nThe Winner is %s!\n", players[winner].name);

          }
        }
      }

      // Passes turn if no token can be moved in the row of the dice roll
      else{
        printf("No token found, turn passed.\n");
      }

    }
  }
  return;
}

// Decalares function diceRool which generates and retrurns a random number between 1 and 6
int diceRoll(void){

  srand(time(NULL));
  return (rand() % 6) + 1;
}


// Decalres function moveTokenUpOrDown which moves a token up or down to a different stack
void moveTokenUpOrDown(char directionInput, struct square board[][NUM_COLUMNS], int columnInput, int rowInput, struct player players[], int i){

  // Declaring variable
  int tokenDirection;

  // If the player has indicated they want to move the token up,
  // tokenDirection is set to -1
  if(directionInput == 'U'){

    tokenDirection = -1;

  }

  // If the player has indicated they want to move the token down,
  // tokenDirection is set to 1
  else if(directionInput == 'D'){

    tokenDirection = 1;

  }

  // Calls function push to move a token onto a different stack
  push(players[i].playerColour, &board[rowInput+ tokenDirection][columnInput]);

  // Calls function pop to remove a tokon from its original stack
  pop(&board[rowInput][columnInput]);

  return;
}

// Declares function moveToken right which moves a token to the stack to the right of itself
void moveTokenRight(struct square board[][NUM_COLUMNS], int dice, struct player players[], int columnInputRight){

  // Calls function push to move a token onto a different stack
  push(topColour(board[dice][columnInputRight]), &board[dice][columnInputRight + 1]);

  // Calls function pop to remove a tokon from its original stack
  pop(&board[dice][columnInputRight]);

  return;
}

// checkToken if there are tokens which can be moved forward
bool checkToken(struct square board[][NUM_COLUMNS], int dice){
  // tokenCheck is set to true
  bool tokenCheck = true;

  // Loop through columns 1 - 8 until a moveble token is found
  for(int i = 0; (i < NUM_COLUMNS - 1) && (tokenCheck != false); i++){

    // If the position is an obstacle or the position is empty
    if (board[dice][i].type == OBSTACLE || isEmpty(board[dice][i])) {

      // tokenCheck is set true
      tokenCheck == true;
    }

    // Else tokenCheck set to false
    else{tokenCheck = false;}

  }

  // Return tokenCheck
  return tokenCheck;
}


// checkWinTocken checks which player owns the token moved to final column and increase their winCounter
int checkWinTocken(colour colourCkeck, struct player players[], unsigned int numPlayers){
  // Create variables
  bool playerFound = false;

  // Loops through players until the correct player is found
  for (size_t i = 0; i < numPlayers && playerFound == false; i++) {

    // If the playerColour equal to token colour
    if (colourCkeck == players[i].playerColour) {

      // increase player winCounter and set playerFound to true
      players[i].winCounter++;
      playerFound = true;

    }
  }

  // Loop through to check if any player has reached winCounter of 3
  for (size_t i = 0; i < numPlayers; i++) {

    //If player winCounter equal to 3
    if (players[i].winCounter == 3) {

      // Return player position in the array
      return i;
    }
  }

  // Else return -1
  return -1;
}


// checkObstacle checks to see if obstacles should be removed and set to normal
void checkObstacle(square board[][NUM_COLUMNS]){

  // Declares static variables
  static int obstacleList[6][2] = {{4,2},{0,3},{2,4},{3,5},{1,6},{5,7}};
  static int numObstacle = 0, clearedColumns = 0;

  // Declares variables
  bool noTokens = true, moreObstacles = true;
  int newNumObstacle = 0;
  unsigned int j = 0;

  // Loops through columns starting from previous cleared columns
  for (int i = clearedColumns; i < 8 && noTokens == true; i++) {

    // Loops through rows to find if there are tokens in the column
    for (size_t j = 0; j < NUM_ROWS && noTokens == true; j++) {

      // If stack is empty
      if (!isEmpty(board[j][i])) {

        // Set noTokens to false
        noTokens = false;
      }
    }

    //If noTokens is true then set clearedColumns to column + 1
    if (noTokens == true) {
      clearedColumns = i + 1;
    }

  }

  // Loops until no more obstacle need to be removed
  do{

    // If the obstacle is in a column less than the cleared columns
    if (obstacleList[j][1] <= clearedColumns ) {

      // set newNumObstacle to j + 1
      newNumObstacle = j + 1;
    }

    // Else moreObstacles is set to false
    else {moreObstacles = false;}

    //Incroment j
    j++;

  }while(moreObstacles && j < 6);

  // Loops through and set all the obstacles less than newNumObstacle to normal
  for (size_t i = numObstacle; i < newNumObstacle && i < 6; i++) {

    board[obstacleList[i][0]][obstacleList[i][1]].type = NORMAL;

  }

  // If newNumObstacle is not 0 set numObstacle to newNumObstacle
  if (newNumObstacle != 0) {

    numObstacle = newNumObstacle;

  }

  return;
}
