/*******************************************************
 * Author: Corey Smoot
 * Date: 5/1/2019
 * Description: unit test for the Great Hall card effects
********************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void main() {	
	int seed = 1000;
	struct gameState state;
	struct gameState state_test;
	int numPlayer = 2;
	int curPlayer = 0;
	int k[10] = {adventurer, village, mine, sea_hag, smithy, embargo, minion, cutpurse, tribute, council_room};

	printf("....Test for Great Hall Card....\n");

	initializeGame(numPlayer, k, seed, &state);

	//copy to the test struct
	memcpy(&state_test, &state, sizeof(struct gameState));

	//execute the card
	cardEffect(great_hall, 0, 0, 0, &state, 0, 0);

	curPlayer = whoseTurn(&state_test);

	printf("Test that the card was played\n");
	if (state.playedCardCount == (state_test.playedCardCount + 1)) {
		printf("PASS Great Hall card was played\n");
	}
	else {
		printf("FAIL Great Hall card was not played\n");
	}

	printf("Test that action points were increased\n");
	if (state.numActions == (state_test.numActions + 1)) {
		printf("PASS number of actions has increased\n");
	}
	else {
		printf("FAIL number of actions has not increased\n");
	}

	printf("Test that card was removed from player's hand\n");
	if (state.handCount[curPlayer] == state_test.handCount[curPlayer] - 1) {
		printf("PASS number of cards in hand are correct\n");
	}
	else {
		printf("FAIL number of cards in hand are incorrect\n");
	}

	printf("Test that card was sent to discard pile\n");
	if (state.discardCount[curPlayer] == (state_test.discardCount[curPlayer] + 1)) {
		printf("PASS card was sent to the discard pile\n");
	}
	else {
		printf("FAIL card was not sent to the discard pile\n");
	}
}
