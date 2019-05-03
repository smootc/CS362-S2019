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
	int choice1=

	printf("....Test for Great Hall Card....\n");

	initializeGame(numPlayer, k, seed, state);

	//copy to the test struct
	memcpy(&state_test, &state, sizeof(struct gameState));

	//execute the card
	cardEffect(great_hall, 0, 0, 0, &state, 0, 0);

	curPlayer = whoseTurn(&state_test);

	//Confirm the card was played
	if (state.playedCardCount == (state_test.playedCardCount + 1)) {
		printf("PASS Great Hall card was played\n");
	}
	else {
		printf("FAIL Great Hall card was not played\n");
	}

	//confirm action points were increased from playing card
	if (state.numActions == (state_test.numActions + 1)) {
		printf("PASS number of actions has increased\n");
	}
	else {
		printf("FAIL number of actions has not increased\n");
	}

	//confirm Great Hall was discarded
	if (state.discardCount[curPlayer] == (state_test.discardCount[curPlayer] + 1)) {
		printf("PASS card was sent to the discard pile\n");
	}
	else {
		printf("FAIL card was not sent to the discard pile\n");
	}
}
