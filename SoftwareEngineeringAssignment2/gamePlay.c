
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "defineAssignment2.h"
#include "stackFunctions.h"
#include "gameInitialisation.h"
#include "gamePrint.h"
#include "gameInput.h"

int diceRoll();

void moveTokenUpOrDown(char directionInput, struct square board[][NUM_COLUMNS], int columnInput, int rowInput, struct player players[], int i);
void moveTokenRight(struct square board[][NUM_COLUMNS], int dice, struct player players[], int i);
bool checkToken(square board[][NUM_COLUMNS], int dice);
int checkWinTocken(colour colourCkeck, struct player players[], unsigned int numPlayers);


void playGame(unsigned int numPlayers, struct square board[][NUM_COLUMNS], struct player players[]) {

  bool checkForWin = false, directionCheck = false, inputCheck = false, inputCheckRight = false, tokenFound;
  int dice, rowInput, columnInput, columnInputRight, winner;
  char directionInput, upDownChoice;;

  while(checkForWin == false){
    for(int i = 0; i < numPlayers; i++){
      printf("Player %d turn\n", i+1);
      dice = diceRoll();
      printf("Player %d rolled %d\n", i+1, dice);

      do{
        printf("Enter Y to move a token you own up or down, else enter N \n");
        scanf("%c" ,&upDownChoice);
        clearLine();

      }while(upDownChoice != 'Y' && upDownChoice != 'N');

      if(upDownChoice == 'Y'){
        do{

          do{
            inputCheck = true;
            printf("Enter the co-ordinate of which of your tokens you would like to move (Enter co-ordinates as:)\n");
            scanf("%d%d", &columnInput, &rowInput);
            clearLine();
          }while((columnInput < 1 || columnInput > 9) && (rowInput < 1 || rowInput > 6));

          rowInput--;
          columnInput--;

          if (isEmpty(board[rowInput][columnInput])) {
            printf("Invalid Input please try again.\n");
            inputCheck = false;
          }

          else if(topColour(board[rowInput][columnInput]) != players[i].playerColour ){
            printf("Not your counter please try again\n");
            inputCheck = false;
          }
          else if (board[rowInput][columnInput].type == OBSTACLE) {
            printf("Sqaure is an obstacle so tokens can't be moved.\n");
            inputCheck = false;
          }

        } while(!inputCheck);

        printf("Do you want to move your token up or down?(U for up, D for Down)\n");
        do{

          directionCheck = true;
          scanf("%c", &directionInput);
          clearLine();

          if(directionInput != 'U' && directionInput != 'D'){
            printf("Invalid input please try again\n");
            directionCheck = false;
          }
          else if(directionInput == 'D' && rowInput == 5){
            printf("Cannot move token down please try again\n");
            directionCheck = false;
          }
          else if(directionInput == 'U' && rowInput == 0){
            printf("Cannot move token up please try again\n");
            directionCheck = false;
          }
        } while(directionCheck != true);
        moveTokenUpOrDown(directionInput, board, columnInput, rowInput, players, i);
        printBoard(board);
      }

      dice--;
      tokenFound = checkToken(board, dice);

      if(!tokenFound){
        do{

          do{
            inputCheckRight = true;
            printf("Enter the column of which of your tokens you would like to move right (Enter co-ordinates as:)\n");
            scanf("%d", &columnInputRight);
            clearLine();
          }while((columnInputRight < 1 || columnInputRight > 8));

          columnInputRight--;

          if(isEmpty(board[dice][columnInputRight])){
            printf("Invalid Input please try again.\n");
            inputCheckRight = false;
          }
          else if (board[dice][columnInputRight].type == OBSTACLE) {
            printf("Sqaure is an obstacle so tokens can't be moved.\n");
            inputCheckRight = false;
          }

        } while(!inputCheckRight);

        moveTokenRight(board, dice, players, columnInputRight);
        printBoard(board);

        if (columnInputRight == 7 && !isEmpty(board[dice][8])) {
          winner = checkWinTocken(topColour(board[dice][8]), players, numPlayers);
          if (winner != -1) {
            checkForWin = true;

            printf("\nThe Winner is %s!\n", players[winner].name);
          }
        }



      }
      else{
        printf("No token found, turn passed\n");
      }
    }
  }
}

int diceRoll(void){

  srand(time(NULL));
  return (rand() % 6) + 1;
}


void moveTokenUpOrDown(char directionInput, struct square board[][NUM_COLUMNS], int columnInput, int rowInput, struct player players[], int i){
  int tokenDirection;

  if(directionInput == 'U'){
    tokenDirection = -1;
  }
  else if(directionInput == 'D'){
    tokenDirection = 1;
  }

  push(players[i].playerColour, &board[rowInput+ tokenDirection][columnInput]);
  pop(&board[rowInput][columnInput]);
}

void moveTokenRight(struct square board[][NUM_COLUMNS], int dice, struct player players[], int columnInputRight){

  push(topColour(board[dice][columnInputRight]), &board[dice][columnInputRight + 1]);
  pop(&board[dice][columnInputRight]);
}

bool checkToken(struct square board[][NUM_COLUMNS], int dice){

  bool tokenCheck = true;
  int i = 0;

  for(i = 0; (i < NUM_COLUMNS - 1) && (tokenCheck != false); i++){
    tokenCheck = isEmpty(board[dice][i]);
  }
  return tokenCheck;
}


int checkWinTocken(colour colourCkeck, struct player players[], unsigned int numPlayers){
  bool playerFound = false;

  for (size_t i = 0; i < numPlayers && playerFound == false; i++) {
    if (colourCkeck == players[i].playerColour) {
      players[i].winCounter++;
      playerFound = true;
    }
  }

  for (size_t i = 0; i < numPlayers; i++) {
    if (players[i].winCounter == 3) {
      return i;
    }
  }
  return -1;

}

void chechObstacle(square board[][NUM_COLUMNS]){

  static int obstacleList[6][2] = {{5,7},{1,6},{3,5},{2,4},{0,3},{4,2}};
  static int numObstacle = 5, clearedColumns = 0;
  bool noTokens = true;

  for (int i = clearedColumns; i < 8; i++) {
    for (size_t j = 0; j < NUM_ROWS && noTokens == true; j++) {
      if (!isEmpty(board[j][i])) {
        noTokens = false;
      }
    }
    if (noTokens == true) {
      clearedColumns = i + 1;
    }

  }
  for (size_t i = numObstacle; i >= 0; i++) {
    if (obstacleList[numObstacle] > clearedColumns ) {
      /* code */
    }
  }

}
