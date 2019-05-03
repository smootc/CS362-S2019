/*****************************************************
 * Author: Corey Smoot
 * Date: 4/29/2018
 * Description: Test functionality of buyCard function 
*****************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void main(int argc, char** argv) {
	struct gameState state1;
	struct gameState state2;
	struct gameState state3;
	int supplyPos=2;

	//test buyCard function
	
	state1.numBuys = 1;
	state1.coins = 4;
	state2.numBuys = 1;
	state2.coins = 5;
	state3.numBuys = 0;
	state3.coins = 12;

	printf("Test for insufficient coins\n");
	if(buyCard(supplyPos, &state1) == -1) {
		printf("PASS when testing %d coins\n", state1.coins);
	}
	else {
		printf("FAIL when testing %d coins\n", state1.coins);
	}

	printf("Test for sufficient coins scenario\n");
	if(buyCard(supplyPos, &state2) == 0) {
		printf("PASS when testing %d coins\n", state2.coins);
	}
	else {
		printf("FAIL when testing %d coins\n", state2.coins);
	}

	printf("Test for insufficient number of buys available\n", state3.coins);
	if(buyCard(supplyPos, &state3) == -1) {
		printf("PASS when testing %d numBuys\n", state3.numBuys);
	}
	else {
		printf("FAIL when testing %d numBuys\n", state3.numBuys);
	}

	printf("END OF BUYCARD TEST\n");
	
}
