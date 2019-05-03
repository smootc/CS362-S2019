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

	printf("....Test for Village Card....\n");

	initializeGame(numPlayer, k, seed, state);

	//copy to the test struct
	memcpy(&state_test, &state, sizeof(struct gameState));

	//execute the village card
	cardEffect(village, 0,0,0, &state, 0, 0);
	
	curPlayer = whoseTurn(&state_test);

	//check the card cound confirming that a card was drawn
	if(state.playedCardCount == (state_test.playedCardCount + 1)) {
		printf("PASS playing village card resulted in drawing another card\n");
	}
	else {
		printf("FAIL playing village card did not result in drawing a card\n");
	}

	//check that action points were added
	if(state.playedCardCount == (state_test.playedCardCount + 2)) {
		printf("PASS playing village card added 2 action points\n");
	}
	else {
		printf("FAIL playing village card added 2 action points\n");
	}

	//confirm the village card was discarded
	if(state.discardCount[curPlayer] == state_test.discardCount[curPlayer]) {
		printf("PASS village card was discarded\n");
	}
	else {
		printf("FAIL village card was not discarded\n");
	}
}
