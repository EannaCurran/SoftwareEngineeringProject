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

#include "gameInput.h"
#include "defineAssignment2.h"


int gameInput(){
  int numOfPlayers;

  printf("Welcome to Igel Argern");
  printf("Enter the number of players you want to play:");
  return 0;
}

/*Function to clear the stdin buffer in case of overflow chars after recieving input*/
void clearLine(void){
  /*Variables*/
  int temp;

  /*Do while loop to get chars from stdin and store them in temp till a new line*/
  do{

    temp = fgetc(stdin);

  } while (temp != '\n' && temp != EOF);

  return;
