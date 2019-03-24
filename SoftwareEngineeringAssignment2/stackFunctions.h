/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   stackFunctions.h
 * Author: John
 *
 * Created on 14 March 2019, 16:39
 */

#ifndef STACKFUNCTIONS_H
#define STACKFUNCTIONS_H

#include <stdbool.h>

bool push(char valuePushed, struct square *boardPosition);

void pop(struct square *boardPosition);

char top(square boardPosition);

bool isEmpty(struct square boardPosition);

char printToken(token *t);

bool charToToken(char valueToConvert, token *t);


#endif /* STACKFUNCTIONS_H */
