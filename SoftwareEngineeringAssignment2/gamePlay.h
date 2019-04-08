#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#endif /* GAMEPLAY_H */
#define NUM_COLUMNS 9

void playGame(unsigned int numPlayers, struct square board[][NUM_COLUMNS], struct player players[]);
int diceRoll();
void clearLine2();
void moveTokenUpOrDown(char directionInput, struct square board[][NUM_COLUMNS], int columnInput, int rowInput, struct player players[], int i);
void moveTokenRight(struct square board[][NUM_COLUMNS], int dice, struct player players[]);
