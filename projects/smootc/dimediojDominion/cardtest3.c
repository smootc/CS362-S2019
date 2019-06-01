/**************************************************
 * Author: Corey Smoot
 * Date: 5/1/2019
 * Description: Unit test for village card effects
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

	printf("....Test for Village Card....\n");

	initializeGame(numPlayer, k, seed, &state);

	//copy to the test struct
	memcpy(&state_test, &state, sizeof(struct gameState));

	//execute the village card
	cardEffect(village, 0,0,0, &state, 0, 0);
	
	curPlayer = whoseTurn(&state_test);

	printf("Test for player drawing a card\n");
	if(state.playedCardCount == (state_test.playedCardCount + 1)) {
		printf("PASS playing village card resulted in drawing another card\n");
	}
	else {
		printf("FAIL playing village card did not result in drawing a card\n");
	}

	printf("Test for 2 added action points\n");
	if(state.numActions == (state_test.numActions + 2)) {
		printf("PASS added 2 action points\n");
	}
	else {
		printf("FAIL did not add 2 action points\n");
	}

	//confirm the village card was discarded
	printf("Test that the card was sent to the discard pile\n");
	if(state.discardCount[curPlayer] == state_test.discardCount[curPlayer]) {
		printf("PASS village card was discarded\n");
	}
	else {
		printf("FAIL village card was not discarded\n");
	}
}
