
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

int diceRoll();
void moveTokenUpOrDown(char directionInput, struct square board[][NUM_COLUMNS], int columnInput, int rowInput, struct player players[], int i);
void moveTokenRight(struct square board[][NUM_COLUMNS], int dice, struct player players[], int i);
bool checkToken(square board[][NUM_COLUMNS], int dice);
int checkWinTocken(colour colourCkeck, struct player players[], unsigned int numPlayers);
void chechObstacle(square board[][NUM_COLUMNS]);



#endif /* GAMEPLAY_H */
