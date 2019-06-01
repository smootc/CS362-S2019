/**********************************************
 * Author: Corey Smoot
 * Date: 4/29/2019
 * Description: unit test for getCost function
***********************************************/
 
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

	//changed name to council_room - my dominion.c file was refactored to playCouncil_Room
	printf("....Test playCouncil_Room....\n");

	initializeGame(numPlayer, k, seed, &state);

	memcpy(&state_test, &state, sizeof(struct gameState));

	cardEffect(council_room, 0, 0, 0, &state, 0, 0);

	curPlayer = whoseTurn(&state_test);

	printf("Test that player has added 4 cards to hand\n");
	if (state.handCount[curPlayer] == state_test.handCount[curPlayer] + 4) {
		printf("PASS player drew four cards\n");
	}
	else {
		printf("FAIL player did not draw four cards\n");
	}

	printf("Test that number of buys were increased\n");
	if (state.numBuys == state_test.numBuys + 1) {
		printf("PASS player's buys were increased\n");
	}
	else {
		printf("FAIL player's buys were not increased\n");
	}	
}
