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
		int numPlayers = 2; //(rand() % 50);
		int seed = (rand() % 5000);

		initializeGame(numPlayers, k, seed, &state);

		printf("....Random Test Adventurer %d of 70....\n", i+1);

		memcpy(&state_test, &state, sizeof(struct gameState));
		
		cardEffect(adventurer, 0, 0, 0, &state, 0, 0);

		currPlayer = whoseTurn(&state_test);

		//check deck count
		if(state_test.deckCount[currPlayer]-1 == state.deckCount[currPlayer]) {
			printf("PASS correct deck count\n");
		}
		else {
			printf("FAIL incorrect deck count\n");
		}

		//check hand count
		if(state.handCount[currPlayer] == state_test.handCount[currPlayer]-1) {
			printf("PASS correct hand count\n");
		}
		else {
			printf("FAIL incorrect hand count\n");
		}

		//check card is in hand
		if(state.hand[currPlayer][state_test.handCount[currPlayer]] != -1) {
			printf("PASS card was added\n");
		}
		else {
			printf("FAIL card was not added\n");
		}

		//card played
		if(state.playedCardCount == state_test.playedCardCount + 2) {
			printf("PASS card was played\n");
		}
		else {
			printf("FAIL card was not played\n");
		}
		
		//discarded after being played
		if(state.discardCount[currPlayer] == state_test.discardCount[currPlayer]) {
			printf("PASS card was discarded\n");
		}
		else {
			printf("FAIL card was not discarded\n");
		}

		//increase in action points
		if(state.numActions == state_test.numActions + 2) {
			printf("PASS action points were added\n");
		}
		else {
			printf("FAIL action points were not added\n");
		}
	}
}
