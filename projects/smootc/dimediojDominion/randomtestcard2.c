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
        	printf("....Random Test Great Hall %d of 70....\n", i+1);
		
		//seg fault occurs if set higher than 5
		int numPlayers = (rand() % 5);

		int seed = (rand() % 1000);

		initializeGame(numPlayers, k, seed, &state);
		
		memcpy(&state_test, &state, sizeof(struct gameState));
		
		cardEffect(great_hall, 0, 0, 0, &state, 0, 0);
		
		currPlayer = whoseTurn(&state_test);

		//check that player received an action point
		if(state.numActions == state_test.numActions + 1) {
			printf("PASS an action point was added\n");
		}
		else {
			printf("FAIL 1 action point was not added\n");
		}

		//check card was added
		if(state.hand[currPlayer][state_test.handCount[currPlayer]-1] != -1) {
			printf("PASS card was added to hand\n");
		}
		else {
			printf("FAIL card was not added\n");
		}

		//check cards were added and removed
		if(state.playedCardCount == state_test.playedCardCount+2) {
			printf("PASS card was played\n");
		}
		else {
			printf("FAIL card was not played\n");
		}

		//check card was discarded
		if(state.discardCount[currPlayer] == state_test.discardCount[currPlayer] + 1) {
			printf("PASS card was discarded\n");
		}
		else {
			printf("FAIL card was not discarded\n");
		}
	}
	printf("\n");
}
