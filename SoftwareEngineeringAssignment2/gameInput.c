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

#include "gameInput.h"
#include "defineAssignment2.h"
#include "gameInput.h"

// Function to receive user input
int gameInput(player players[]){
  int numOfPlayers;
  char playerColour;
  bool validColourInput = true;

  printf("Welcome to Igel Argern\n");
  printf("Enter the number of players you want to play (2 - 6 players only).\n");

  do {
    scanf("%d", &numOfPlayers);
    clearLine();
    if(numOfPlayers > 6 || numOfPlayers < 2){
        printf("Invalid input please try again.\n");
    }
  } while(numOfPlayers > 6 || numOfPlayers < 2);

  for(size_t i = 0; i < numOfPlayers; i++){
      printf("\nEnter player %u name.\n", i+1);
      // Scanning up to new line line character
      scanf("%19[^\n]s", players[i].name);
      clearLine();
      printf("Which colour token does player %u want?\n(R=Red, G=Green, B=Blue, Y=Yellow, P=Pink, O=Orange)\n", i+1);

      do {
        validColourInput = true;
        scanf("%c", &playerColour);
        clearLine();
        switch(playerColour){
            case 'R':
                players[i].playerColour = RED;
                break;
            case 'G':
                players[i].playerColour = GREEN;
                break;
            case 'B':
                players[i].playerColour = BLUE;
                break;
            case 'Y':
                players[i].playerColour = YELLOW;
                break;
            case 'P':
                players[i].playerColour = PINK;
                break;
            case 'O':
                players[i].playerColour = ORANGE;
                break;
            default:
                printf("Invalid Input please try again!\n");
                validColourInput = false;
            }
        for(size_t j = 0; j < i;j++){
            if(players[i].playerColour == players[j].playerColour){
                printf("Colour has already been selected please try again!\n");
                validColourInput = false;
                break;
            }
        }
      } while(validColourInput != true);

    }
    return numOfPlayers;
}

/*Function to clear the stdin buffer in case of overflow chars after recieving input*/
void clearLine(void){
  /*Variables*/
  int temp;

  /*Do while loop to get chars from stdin and store them in temp till a new line*/
  do{

    temp = fgetc(stdin);

  } while (temp != '\n' && temp != EOF);
}
