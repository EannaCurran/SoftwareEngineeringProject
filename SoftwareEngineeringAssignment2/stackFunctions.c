#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "defineAssignment2.h"
#include "stackFunctions.h"


/*The Push function takes a colour value to be pushed and a pointer square on the board and pushes the value to the top of the stack
returns true if sucessful*/
void push(colour valuePushed, struct square *boardPosition){
  token *tempPrtr = malloc(sizeof(token));

  if (tempPrtr == Null) {
    tempPrtr->nextToken = boardPosition->stack;
    boardPosition->stack = tempPrtr;
    tempPrtr->colourToken = valuePushed;
    return;
  }
  /*Else stack is full print error return false*/
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
    token tempPrtr = boardPosition->stack;
    boardPosition->stack = *tempPrtr;
    free(tempPrtr);
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
    return printToken(&boardPosition.stack->colourToken);
  }
  /*Else stack is empty so retuRn ' '*/
  else return ' ';
}

colour topColour(square boardPosition){
  /*If the stack is not empty*/
  if (!isEmpty(boardPosition)) {
    /*Calls the printToken function to convert the colour of the token to char then returns that char*/
    return boardPosition.stack->colourToken;
  }
}

/*The isEmpty function checks if the stack of a square is empty
return true if empty*/
bool isEmpty(struct square boardPosition){
  /*If top == -1 then stack is empty return true*/
  if(boardPosition.stack == Null){
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

bool charToToken(char valueToConvert, token *t){

  switch (valueToConvert) {
    case 'P':
    t->colourToken = PINK;
    return true;
    break;

    case 'R':
    t->colourToken = RED;
    return true;
    break;

    case 'B':
    t->colourToken = BLUE;
    return true;
    break;

    case 'G':
    t->colourToken = GREEN;
    return true;
    break;

    case 'O':
    t->colourToken = ORANGE;
    return true;
    break;

    case 'Y':
    t->colourToken = YELLOW;
    return true;
    break;

    default:
    printf("Invalid input try again\n");
    return false;
    break;
  }
}
