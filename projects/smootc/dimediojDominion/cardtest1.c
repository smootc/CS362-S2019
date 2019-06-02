/*************************************************
 * Author: Corey Smoot
 * Date: 4/30/2019
 * Description: unit test for the adventure card
**************************************************/

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

	printf("....Test for Adventure Card....\n");

	initializeGame(numPlayer, k, seed, &state);
	
	//copy to the test struct
	memcpy(&state_test, &state, sizeof(struct gameState));

	//execute the card
	cardEffect(adventurer, 0, 0, 0, &state, 0, 0);

	curPlayer = whoseTurn(&state_test);

	printf("Test if the card was discarded\n");
	if(state_test.discardCount[curPlayer] + 1 == state.discardCount[curPlayer]) {
		printf("PASS adventurer was discarded\n");
	}
	else {
		printf("FAIL adventurer was not discarded\n");
	}

	
	//confirm number of cards in hand
	printf("Test for correct number of cards in hand\n");
	if(state.handCount[curPlayer] == state_test.handCount[curPlayer] + 2) {
		printf("PASS correct deck amount after execution\n");
	}
	else {
		printf("FAIL incorrect deck amount after execution\n %d   %d", state.handCount[curPlayer], state_test.handCount[curPlayer]);
	}
	
}
