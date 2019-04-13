// File containing function prototypes required for stackFunctions.c
// Written by - John O'Donnell

#ifndef STACKFUNCTIONS_H
#define STACKFUNCTIONS_H

// Includes C standard libraries
#include <stdbool.h>

// Includes user created C libraries
#include "defineAssignment2.h"

// Initialises the function push
void push(colour valuePushed, struct square *boardPosition);

// Initialises the function pop
bool pop(struct square *boardPosition);

// Initialises the function top
char top(square boardPosition);

// Initialises the function topColour
colour topColour(square boardPosition);

// Initialises the function isEmpty
bool isEmpty(struct square boardPosition);

// Initialises the function printToken
char printToken(token *t);

#endif /* STACKFUNCTIONS_H */
