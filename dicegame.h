#ifndef DICEGAME_H
#define DICEGAME_H

typedef enum ROUNDTYPE 
{ 
    BONUS, 
    DOUBLE, 
    REGULAR 
} ROUNDTYPE;

typedef struct DiceRound
{
    int dice;
    int points;
    ROUNDTYPE RoundType;
} DiceRound;

int getRandomNumber(int min, int max);
void fillRounds(DiceRound round[], int length);
int getRoundPoints(DiceRound round);
void printRoundInfo(DiceRound round);
void printPlayerInfo(int p1, int p2);

#endif