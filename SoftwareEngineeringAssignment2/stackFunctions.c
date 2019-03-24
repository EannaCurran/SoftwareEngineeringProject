#include <stdio.h>
#include <stdbool.h>

#include "defineAssignment2.h"
#include "stackFunctions.h"



bool push(char valuePushed, struct square *boardPosition){
    
if (boardPosition->top < 24) {
  
  if (charToToken(valuePushed, &boardPosition->stack[boardPosition->top + 1] )) {
    boardPosition->top++;

    return true;
  }
}
  else{
    printf("ERROR stack is full\n" );
    return false;
  }

  return false;
}

void pop(struct square *boardPosition){
  if (!isEmpty(*boardPosition)) {
    boardPosition->top--;

  }
  else{
    printf("ERROR Stack is empty!\n");
  }
  return;
}

char top(square boardPosition){
  if (!isEmpty(boardPosition)) {
    return printToken(&boardPosition.stack[boardPosition.top]);
  }
  else return ' ';

}

bool isEmpty(struct square boardPosition){
  if(boardPosition.top == -1){
      return true;
    }
   else {return false;}
}

char printToken(token *t){
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
