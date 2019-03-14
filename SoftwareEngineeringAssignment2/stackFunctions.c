#include <stdio.h>
#include <stdbool.h>

#include "defineAssignment2.h"
#include "stackFunctions.h"

void push(char valuePushed, struct square *boardPosition){

if (*boardPosition->top < 24) {
  *boardPosition->top++;
  *boardPosition->stack[*boardPosition->top] = valuePushed;
}
  else{
    printf("ERROR stack is full\n" );
  }

  return;
}

void pop(struct square *boardPosition){
  if (!isEmpty(*boardPosition) {
    *boardPosition->top--;
  }
  else{
    printf("ERROR Stack is empty!\n");
  }
  return;
}

char top(struct square boardPosition){
  if (!isEmpty(boardPosition)) {
    return boardPosition.stack[boardPosition.top];
  }
  else {return ' ';}

}

bool isEmpty(struct square boardPosition){
  if(boardPosition.top == -1){
      return true;
    }
   else {return false;}
}
