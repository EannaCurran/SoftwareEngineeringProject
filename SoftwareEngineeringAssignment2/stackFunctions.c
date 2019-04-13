// File containing functions required for the stacks in the program
// Written by - John O'Donnell

// Includes C standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Includes user created C libraries
#include "defineAssignment2.h"
#include "stackFunctions.h"


/*The Push function takes a colour value to be pushed and a pointer square on the board and pushes the value to the top of the stack*/
void push(colour valuePushed, struct square *boardPosition){
  /*Declares variables*/
  token *tempPrtr = malloc(sizeof(token)); // malloc to size of token

  // If the pointer is not set to NULL
  if (tempPrtr != NULL) {

    //Set the nextToken pointer of tempPrtr to first pointer of the stack
    tempPrtr->nextToken = boardPosition->stack;

    // Then set the first pointer of the stack to tempPrtr
    boardPosition->stack = tempPrtr;

    // Set the colour to the token to valuePushed
    tempPrtr->colourToken = valuePushed;

    //increase the counter for number of tokens on the stack
    boardPosition->numStack++;

    return;
  }

  /*Else not enough merory and an error has occured so exit the program*/
  else{

    fprintf(stderr, "ERROR Not enough memory to add to stack!\nProgram closing.\n");
    exit(EXIT_FAILURE);

  }
}

/*The pop function takes in a pointer to a square on the board and pops the top value from the stack
returns true if sucessful*/
bool pop(struct square *boardPosition){

  /*If stack is not empty*/
  if (!isEmpty(*boardPosition)) {

    // Decalres a pointer and set to first pointer of the stack
    token *tempPrtr = boardPosition->stack;

    // Set the first pointer of the stack to the nextToken of tempPrtr
    boardPosition->stack = tempPrtr->nextToken;

    // Free tempPrtr
    free(tempPrtr);

    // Reduce number of tokens on the stacks
    boardPosition->numStack--;

    return true;
  }

  /*Else the stack is empty print Error and return false*/
  else{
    printf("ERROR Stack is empty!\n");
    return false;
  }
}

/*The top function returns the top value from the stack of the square in its char form*/
char top(square boardPosition){

  /*If the stack is not empty*/
  if (!isEmpty(boardPosition)) {

    /*Calls the printToken function to convert the colour of the token to char then returns that char*/
    return printToken(boardPosition.stack);
  }

  /*Else stack is empty so return ' '*/
  else return ' ';
}

// topColour takes in a boardPosition and return the top token as a colour enum
colour topColour(square boardPosition){

  /*If the stack is not empty*/
  if (!isEmpty(boardPosition)) {

    /*Returns the top colour from the stack*/
    return boardPosition.stack->colourToken;
  }
}

/*The isEmpty function checks if the stack of a square is empty
return true if empty*/
bool isEmpty(struct square boardPosition){

  /*If first stack point equal Null then stack is empty return true*/
  if(boardPosition.stack == NULL){
    return true;
  }

  /*Else stack is not empty return false*/
  else {return false;}
}

/*The printToken function converts the colour of a token to a printable char*/
char printToken(token *t){

  /*If the token colour then return corosponding char*/
  if((*t).colourToken == PINK) return 'P';
  if((*t).colourToken == RED) return 'R';
  if((*t).colourToken == BLUE) return 'B';
  if((*t).colourToken == GREEN) return 'G';
  if((*t).colourToken == ORANGE) return 'O';
  if((*t).colourToken == YELLOW) return 'Y';

  return '\0';
}
