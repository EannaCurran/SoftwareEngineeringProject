// File containing definitions for variables 
// Written by - John O'Donnell and Eanna Curran

#ifndef DEFINEASSIGNMENT2_H
#define DEFINEASSIGNMENT2_H

// Number of rows of the board
#define NUM_ROWS 6
// Number of columns of the board
#define NUM_COLUMNS 9


// Types of squares
enum stype{
    NORMAL, OBSTACLE 
  };

// Colours of tokens
enum colour {
    RED, BLUE, GREEN, YELLOW, PINK, ORANGE
};


// Defines a token. 
// Note each token can be associated with a color
typedef struct token{
   enum colour colourToken;    
}token;

// Defines a square of the board.
typedef struct square{
    // A square can be a NORMAL or an OBSTACLE square
     enum stype type;
     // the stack of tokens that can be placed on the board square
     token * stack;      
}square;

// Defines each players information
typedef struct player{
    // Name of player
    char name[20];
    //Players token colour
    enum colour playerColour;
    
}player; 


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* DEFINEASSIGNMENT2_H */

