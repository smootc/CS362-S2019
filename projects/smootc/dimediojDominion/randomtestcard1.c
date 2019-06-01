#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

void main() {
	int currPlayer=0;
	struct gameState state, state_test;
	int k[10] = {adventurer, village, mine, sea_hag, smithy, embargo, minion, cutpurse, tribute, council_room};

	for(int i = 0; i < 70; i++) {
		int numPlayers = (rand() % 5);
		int seed = (rand() % 1000);

		initializeGame(numPlayers, k, seed, &state);

		printf("....Random Test Village %d of 70....\n", i+1);

		memcpy(&state_test, &state, sizeof(struct gameState));
		
		cardEffect(village, 0, 0, 0, &state, 0, 0);

		currPlayer = whoseTurn(&state_test);

		//check card in hand
		if(state.hand[currPlayer][state_test.handCount[currPlayer]-1] != -1) {
			printf("PASS card was added\n");
		}
		else {
			printf("FAIL card was not added\n");
		}

		//check that card was played
		if(state.playedCardCount == state_test.playedCardCount + 1) {
			printf("PASS card was played\n");
		}
		else {
			printf("FAIL card was not played\n");
		}

		//check action points
		if(state.numActions == state_test.numActions + 2) {
			printf("PASS 2 action points were added\n");
		}
		else {
			printf("FAIL 2 action points were not added\n");
		}

		//check card as discarded
		if(state.discardCount[currPlayer] == state_test.discardCount[currPlayer]) {
			printf("PASS card was discarded\n");
		}
		else {
			printf("FAIL card was not discarded\n");
		}
	}
}
