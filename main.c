#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"dicegame.h"

int main(int argc, char* argv[])
{
	// Initialize the srand() to start the random generator
	srand((int)time(0));

	// Initialize the player-1 and player-2 scores to 0
	int player1 = 0;
	int player2 = 0;

	// Initialize all other required variables	
	int nRounds;
	DiceRound* rounds;
	int i;
	int curPlayer;

	// Ask the user for the number of rounds to run the game
	printf("Enter the number of rounds: ");
	scanf("%d", &nRounds);

	// Initialize all other required variables	
	rounds = (DiceRound*)malloc(nRounds * sizeof(DiceRound));

	// Check if array created. If not end program, by calling return 1;
	if (rounds == NULL) {
		return 1;
	}

	// Fill the DiceRound array by calling the fillRounds() function
	fillRounds(rounds, nRounds);

	// Determines which player starts
	curPlayer = getRandomNumber(1, 2);
	
	// Call printPlayerInfo() function to print the initial player scores which will be 0
	printPlayerInfo(player1, player2);

	printf("\n");

	for(i=0; i<nRounds; i++)
	{
		printf("\nROUND %d\n--------\n", i+1);
		printf("Player\t: %d\n", curPlayer); // Print current player

	    // Call printRoundInfo() to print the round information
		printRoundInfo(rounds[i]);

		// MAIN GAME LOGIC
		// The part of the code that actually adds or subtracts points from a player depending on which player they are(which is chosen above)

		// IF Player-1 (even player) is the current player and the dice rolled is even 
		if (curPlayer == 1 && rounds[i].dice % 2 == 0) {
			// Current player gains the points, based on the type of the round. The player's turn continues in the next round.
			player1 += getRoundPoints(rounds[i]);
		}
		// IF Player-2 (odd player) is the current player and the dice rolled is odd
		else if (curPlayer == 2 && rounds[i].dice % 2 != 0) {
			// Current player gains the points, based on the type of the round. The player's turn continues in the next round.
			player2 += getRoundPoints(rounds[i]);
		}
		// IF Player-1 (even player) is the current player and the dice rolled is odd 
		else if (curPlayer == 1 && rounds[i].dice % 2 != 0) {
			// THEN Current player incurs penalty of the same amount of points, based on the type of the round (see above). In the next round, the current player is changed to the other player.
			player1 -= getRoundPoints(rounds[i]);
			curPlayer = 2;
		}
		// IF Player-2 (odd player) is the current player and the dice rolled is even
		else {
			// THEN Current player incurs penalty of the same amount of points, based on the type of the round (see above). In the next round, the current player is changed to the other player.
			player2 -= getRoundPoints(rounds[i]);;
			curPlayer = 1;
		}

		// Call printPlayerInfo() to print the player information at the end of the round
		printPlayerInfo(player1, player2);
	}
	printf("\nGAME OVER!!\n");
	// Compare the final points for player-1 and player-2
	// Print the winner as the one with higher points
	if (player1 > player2) {
		printf("P1 Won\n");
	}
	else if (player2 > player1) {
		printf("P2 Won\n");
	}
	else {
		printf("Tie Game!\n");
	}
	
	// Free the dynamically allocated array memory
	free(rounds);

    return 0;
}