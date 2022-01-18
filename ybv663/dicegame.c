#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"dicegame.h"

// Generates a random number between min and max inclusive
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// This fills a dynamically allocated DiceRound array called rounds[]
void fillRounds(DiceRound rounds[], int length) {
    for (int i = 0; i < length; ++i) {
        // Assigns the dice member of an element in the rounds[] array with a random number between and including 1 - 6
        rounds[i].dice = getRandomNumber(1, 6);
        // Assigns the points member of an element in the rounds[] array with a random number bewteen and including 1 - 10 but multiplied by 10
        rounds[i].points = 10 * getRandomNumber(1, 10);
        // Assings the RoundType member of an element in the rounds[] array depending on a random number between and including 1 - 10 but the if statement influences the chances
        // of what RoundType enum is used
        // Chance rubric: Regular: 60%, Double: 20%, and Bonus: 20%
        int random = getRandomNumber(1, 10);
        // 20% cahnce of bonus
        if (random < 3) {
            rounds[i].RoundType = BONUS;
        }
        // 20% chance of double
        else if (random < 5 && random > 2) {
            rounds[i].RoundType = DOUBLE;
        }
        // 60% chance of regular
        else {
            rounds[i].RoundType = REGULAR;
        }
    }
}

// Determines how the points in the DiceRound passed to it should be calculated based on the rounds
int getRoundPoints(DiceRound round) {
    // Calulates points for a regular round
    if (round.RoundType == REGULAR) {
        return round.points;
    }
    // Calculates points for a double round
    else if (round.RoundType == DOUBLE) {
        return round.points * 2;
    }
    // Calculates points for a bonus round
    else {
        return 100;
    }
}

// Prints the info for the round passed to it
void printRoundInfo(DiceRound round) {
    // Prints the info for a regular round
    if (round.RoundType == REGULAR) {
        printf("Type\t: REGULAR\nDice\t: %d\nPoints\t: %d\n", round.dice, round.points);
    }
    // Prints the info for a double round
    else if (round.RoundType == DOUBLE) {
        printf("Type\t: DOUBLE\nDice\t: %d\nPoints\t: %d\n", round.dice, round.points);
    }
    // Prints the info for a bonus round
    else {
        printf("Type\t: BONUS\nDice\t: %d\nPoints\t: %d\n", round.dice, round.points);
    }
}

// Prints the info for the players passed into it
void printPlayerInfo(int p1, int p2) {
    printf("P1\t: %d\nP2\t: %d", p1, p2);
}