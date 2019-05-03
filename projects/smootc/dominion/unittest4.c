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

void main() {
	struct gameState state1;
	state1->supplyCount[province] = 0;
	struct gameState state2;
	state2->supplyCount[province] = 2;
	struct gameState state3;
	state3->supplyCount[province] = 2;

	int i;
	for(i=0; i < 25; i++) {
		state1->supplyCount[i] = 3;
	}

	for(i=0; i < 25; i++) {
		if(i != 3) {
			state2->supplyCount[i] = 0;
		}
	}

	for(i=0; i < 25; i++) {
		state3->supplyCount[i] = 3;
	}

	printf("Test for game ending when no more province cards\n");
	if(isGameOver(state1) == 1) {
		printf("PASS when total province is %d\n", state1->supplyCount[province]);
	}
	else {
		printf("FAIL when total province is %d\n", state1->supplyCount[province]);
	}

	printf("Test for game ending when there are 3+ supply piles at 0\n");
	if(isGameOver(state2) == 1) {
		printf("PASS when 3 or more supply piles are empty\n");
	}
	else {
		printf("FAIL when 3 or more supply piles are empty\n");
	}

	printf("Test for game ending when no supply piles are empty and province total greater than 0\n");
	if(isGameOver(state3) == 0) {
		printf("PASS when supply piles and province are not empty\n");
	}
	else {
		printf("FAIL when supply piles and province are not empty\n");
	}
}
