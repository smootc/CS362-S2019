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

	printf("....Test for Adventure Card....\n");

	initializeGame(numPlayer, k, seed, state);
	
	//copy to the test struct
	memcpy(&state_test, &state, sizeof(struct gameState));

	//execute the card
	cardEffect(adventurer, 0, 0, 0, &state, 0, 0);

	curPlayer = whoseTurn(&state_test);

	//check if the card was discarded
	if(state_test.discardCount[curPlayer] == state.discardCount[curPlayer]) {
		printf("PASS adventurer was discarded\n");
	}
	else {
		printf("FAIL adventurer was not discarded\n");
	}

	//check that 2 treasure cards were added
	for(i = 0; i < state_test.hand[curPlayer]; i++) {
		cardCheck1 = state_test.hand[curPlayer][i];
		if (cardCheck1 == copper || cardCheck1 == silver || cardCheck1 == gold) {
			testCount++;
		}
	}

	for (i=0; i < state.hand[curPlayer]; i++) {
		cardCheck2 = state.hand[curPlayer][i];
		if (cardCheck2 == copper || cardCheck2 == silver || cardCheck2 == gold) {
			stateCount++;
		}	
	}
	
	if ((cardCheck2 - cardCheck1) > 0 || (cardCheck2 - cardCheck1) < 3) {
		printf("PASS, %d more treasure cards were drawn\n", (cardCheck2 - cardCheck1));
	}
	else {
		printf("FAIL, %d more treasure cards were drawn\n", (cardCheck2 - cardCHeck1));
	}
}
