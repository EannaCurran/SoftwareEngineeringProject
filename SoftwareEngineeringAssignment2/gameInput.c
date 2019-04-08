#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

#include "gameInput.h"
#include "defineAssignment2.h"
#include "gameInput.h"

// Declares the function gameInput which receives the user input before the start of the game
int gameInput(player players[]){
    
    // Creates variables
    int numOfPlayers;
    char playerColour;
    bool validColourInput = true;

     // Prompts user to input number of users
    printf("Welcome to Igel Argern\n");
    printf("Enter the number of players you want to play (2 - 6 players only).\n");

    // Do while loop to scan in the number of players, stays in loop if an invalid number of players is inputted
     do {
         
        // Receives the input for the number of players
         scanf("%d", &numOfPlayers);
      
         // Calls clearLine to empty stdin buffer so not to have value run into next scanf
         clearLine();

        // If the user has inputted an invalid number of players the are told and the player is kept in the loop
        if(numOfPlayers > 6 || numOfPlayers < 2){
            printf("Invalid input please try again.\n");
        }
    } while(numOfPlayers > 6 || numOfPlayers < 2);
    
    // Loops through each player
    for(size_t i = 0; i < numOfPlayers; i++){
        
        printf("\nEnter player %u name.\n", i+1);
        
        // Receives user input for their own name
        scanf("%19[^\n]s", players[i].name);
        
        // Calls clearLine to empty stdin buffer so not to have value run into next scanf
        clearLine();
        
        // initializes the players win counter to 0
        players[i].winCounter = 0;
        
        printf("Which colour token does player %u want?\n(R=Red, G=Green, B=Blue, Y=Yellow, P=Pink, O=Orange)\n", i+1);
        
        // Do while loop to scan in which colour token the player wants=, stays in the loop if the user 
        // Selects a token that has already been taken by another player
        do {
            
            // Resets validColourInput to true
            validColourInput = true;
            
            // Receives the players input for which colour token that want  
            scanf("%c", &playerColour);
            
            // Calls clearLine to empty stdin buffer so not to have value run into next scanf
            clearLine();
            
            // Switch statement to set playersColour to the colour that they have inputted
            switch(playerColour) {
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
            
            // Loops through each players colour that has already been inputted
            for(size_t j = 0; j < i;j++) {
                
                // Checks if the current user has the same colour as a previous player, if they have 
                // the player is told and validColourInput is set to false so the player can input a new colour
                if(players[i].playerColour == players[j].playerColour){
                    printf("Colour has already been selected please try again!\n");
                    validColourInput = false;
                    break;
                }
            }
        } while(validColourInput != true);

    }
    // Returns the number of players in the game to main
    return numOfPlayers;
}

// Declares the function clearLine which clears the stdin buffer in case of overflow chars after recieving input*/
void clearLine(void) {
    
    // Creates variables
    int temp;

    // Do while loop to get chars from stdin and store them in temp till a new line
    do {
        temp = fgetc(stdin);
    } while (temp != '\n' && temp != EOF);
}
