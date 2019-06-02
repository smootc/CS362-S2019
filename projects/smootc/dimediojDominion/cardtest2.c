/*****************************************************
 * Author: Corey Smoot
 * Date: 5/1/2019
 * Description: unit test for the smithy card effects
******************************************************/

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

	printf(".....Test for Smithy Card....\n");

	initializeGame(numPlayer, k, seed, &state);

	//copy to the test struct
	memcpy(&state_test, &state, sizeof(struct gameState));

	//execute the card
	cardEffect(smithy, 0, 0, 0, &state, 0, 0);

	curPlayer = whoseTurn(&state_test);
	
	//adding 2 to account for discarded smithy
	printf("Test for player gaining two cards\n");
	if(state.playedCardCount == (state_test.playedCardCount + 2)) {
		printf("PASS card added three cards to hand\n");
	}
	else {
		printf("FAIL card did not add three cards\n %d   %d\n", state.playedCardCount, state_test.playedCardCount);
	}

	printf("Test for card being sent to discard pile\n");
	if(state.discardCount[curPlayer] == state_test.discardCount[curPlayer]) {
		printf("PASS card went to discard pile\n");
	}
	else {
		printf("FAIL card was not sent to discard pile\n");
	}

	printf("Test for correct hand count of the current player\n");
	if(state.handCount[curPlayer] == (state_test.handCount[curPlayer] + 2)) {
		printf("PASS hand count correct\n");
	}
	else {
		printf("FAIL hand count is incorrect\n %d   %d\n", state.handCount[curPlayer], state_test.handCount[curPlayer]);
	}
}
