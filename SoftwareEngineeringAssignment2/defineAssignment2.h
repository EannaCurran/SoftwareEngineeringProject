/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   defineAssignment2.h
 * Author: John
 *
 * Created on 11 March 2019, 14:40
 */

#ifndef DEFINEASSIGNMENT2_H
#define DEFINEASSIGNMENT2_H

//number of rows of the board
#define NUM_ROWS 6
//number of columns of the board
#define NUM_COLUMNS 9


//types of squares
enum stype{
    NORMAL, OBSTACLE 
  };

//colours of tokens
enum colour {
    RED, BLU, GREEN, YELLOW, PINK, ORANGE
};


//defines a token. 
//Note each token can be associated with a color
typedef struct token{
   enum colour colourPlayer;    
}token;

//Defines a square of the board.
typedef struct square{
    //A square can be a NORMAL or an OBSTACLE square
     enum stype type;
     //the stack of tokens that can be placed on the board square
     token * stack;      
}square;


typedef struct player{
    
    
}player; 


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* DEFINEASSIGNMENT2_H */

