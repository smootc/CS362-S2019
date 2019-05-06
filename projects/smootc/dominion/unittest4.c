/**************************************************
 * Author: Corey Smoot
 * Date: 4/29/2019
 * Description: 
****************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
	int seed = 1000;
	struct gameState state;
	struct gameState state_test;
	int numPlayer = 2;
	int curPlayer = 0;
	int k[10] = {adventurer, village, mine, sea_hag, smithy, embargo, minion, cutpurse, tribute, council_room};
	
	printf("....Test playVillage....\n");

	initializeGame(numPlayer, k, seed, &state);

	memcpy(&state_test, &state, sizeof(struct gameState));

	playVillage(0, 0, &state);

	curPlayer = whoseTurn(&state_test);

	printf("Test that the player drew a card\n");
	if (state.handCount[curPlayer] == state_test.handCount[curPlayer]) {
		printf("PASS player drew a card\n");
	}
	else {
		printf("FAIL player did not draw a card\n");
	}

	printf("Test that number of of actions increased by 2\n");
	if (state.numActions == state_test.numActions + 2) {
		printf("PASS nuber of actions was increased by 2\n");
	}
	else {
		printf("FAIL number of actions did not increase by 2\n");
	}

	printf("Test that card was moved to discard pile\n");
	if (state.discardCount[curPlayer] == state_test.discardCount[curPlayer] + 1) {
		printf("PASS village card was placed into discard pile\n");
	}
	else {
		printf("FAIL village card was not placed in discard pile\n");
	}	
}
