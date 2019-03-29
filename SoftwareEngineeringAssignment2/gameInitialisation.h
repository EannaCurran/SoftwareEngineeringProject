/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   gameInitialisation.h
 * Author: John
 *
 * Created on 11 March 2019, 16:13
 */

#ifndef GAMEINITIALISATION_H
#define GAMEINITIALISATION_H

#define NUM_COLUMNS 9


void initializeBoard(struct square board[][NUM_COLUMNS]);

void boardSetup(struct square board[][NUM_COLUMNS], struct player players[], int numPlayers);

int validStartingPosition(struct square board[][NUM_COLUMNS], struct player player, unsigned int columnPositions[]);

#endif /* GAMEINITIALISATION_H */
