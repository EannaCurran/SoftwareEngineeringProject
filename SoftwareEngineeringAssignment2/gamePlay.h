/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   gamePlay.h
 * Author: John
 *
 * Created on 11 March 2019, 16:18
 */

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

int diceRoll();
void moveTokenUpOrDown(char directionInput, struct square board[][NUM_COLUMNS], int columnInput, int rowInput, struct player players[], int i);
void moveTokenRight(struct square board[][NUM_COLUMNS], int dice, struct player players[], int i);
bool checkToken(square board[][NUM_COLUMNS], int dice);
int checkWinTocken(colour colourCkeck, struct player players[], unsigned int numPlayers);
void chechObstacle(square board[][NUM_COLUMNS]);




#endif /* GAMEPLAY_H */
