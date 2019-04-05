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
#include "gameInitialisation.h"
#include "gamePrint.h"

int diceRoll();
void clearLine();
void moveTokenUpOrDown(char directionInput, struct square board[][NUM_COLUMNS], int columnInput, int rowInput, struct player players[], int i);
void moveTokenRight(struct square board[][NUM_COLUMNS], int dice, struct player players[], int i);
bool checkToken(struct square board[][NUM_COLUMNS], int dice);



void playGame(unsigned int numPlayers, struct square board[][NUM_COLUMNS], struct player players[]) {

    bool checkForWin = false, directionCheck = false, inputCheck = false, inputCheckRight = false, tokenFound;
    int dice, rowInput, columnInput, columnInputRight;
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

                    if(topColour(board[rowInput][columnInput]) != players[i].playerColour ){
                        printf("Not your counter please try again\n");
                        inputCheck = false;
                    }
                    else if(top(board[rowInput][columnInput]) == ' '){
                        printf("Invalid Input please try again.\n");
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
                if(top(board[dice][columnInputRight]) == ' '){
                    printf("Invalid Input please try again.\n");
                    inputCheckRight = false;
                }

            } while(!inputCheckRight);
            moveTokenRight(board, dice, players, columnInputRight);
            printBoard(board);
            }
            else{
                printf("No token found, turn passed\n");
            }
        }
        }

    }

int diceRoll(){

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

    for(i = 0; (i < NUM_COLUMNS) && (tokenCheck != false); i++){
        tokenCheck = isEmpty(board[dice][i]);
    }
    return tokenCheck;
}
