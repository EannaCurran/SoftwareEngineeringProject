/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   gameInput.c
 * Author: John
 *
 * Created on 11 March 2019, 16:04
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include "defineAssignment2.h"

// Function to receive user input
int gameInput(struct player players[6]){
  int numOfPlayers;

  printf("Welcome to Igel Argern\n");
  printf("Enter the number of players you want to play (2 - 6 players only:\n");
  do{
    scanf("%d", &numOfPlayers);
    clearLine();
    if(numOfPlayers > 6 || numOfPlayers < 2){
        printf("Invalid input please try again.\n");
    }
  }while(numOfPlayers > 6 || numOfPlayers < 2);
}

/*Function to clear the stdin buffer in case of overflow chars after recieving input*/
void clearLine(){
  /*Variables*/
  int temp;

  /*Do while loop to get chars from stdin and store them in temp till a new line*/
  do{

    temp = fgetc(stdin);

  } while (temp != '\n' && temp != EOF);
}
