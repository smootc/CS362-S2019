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
	int i;
	seed = 1000;
	struct gameState state;
	struct gameState state_test;
	int flag = 0;
	int numPlayer = 2;
	int curPlayer = 0;
	int kingdomCards(adventurer, council_room, feast, mine, smithy, baron, gardens, remodel, village, great_hall);
	int result;
	int testCount = 0;
	int stateCount = 0;
	int cardCheck1, cardCheck2;

	printf(".....Test for Smithy Card....\n");

	initializeGame(numPlayer, k, seed, state);

	//copy to the test struct
	memcpy(&state_test, &state, sizeof(struct gameState));

	//execute the card
	cardEffect(smithy, 0, 0, 0, &state, 0, 0);

	curPlayer = whoseTurn(&test);

	//check that two cards were added to the players hand
	if(state.playerCardCount == (state_test.playerCardCount + 2)) {
		printf("PASS player received two cards playing smithy card\n");
	}
	else {
		printf("FAIL player did not receive two cards playing smithy card\n");
	}

	//check that the smithy card was removed
	if(state.discardCount[curPlayer] == state_test.discardCount[curPlayer]) {
		printf("PASS smithy card was sent to discard pile\n");
	}
	else {
		printf("FAIL smithy card was not sent to discard pile\n");
	}

	//confirm the total cards in hand
	if(state.handCount[curPlayer] == (state_test.handCount[curPlayer] - 1)) {
		printf("PASS hand count is correct when calling card Effect\n");
	}
	else {
		printf("FAIL hand count is incorrect when calling card Effect\n");
	}
}
