

#ifndef STACKFUNCTIONS_H
#define STACKFUNCTIONS_H

#include <stdbool.h>
#include "defineAssignment2.h"

bool push(colour valuePushed, struct square *boardPosition);

bool pop(struct square *boardPosition);

char top(square boardPosition);

bool isEmpty(struct square boardPosition);

char printToken(token *t);

bool charToToken(char valueToConvert, token *t);


#endif /* STACKFUNCTIONS_H */
