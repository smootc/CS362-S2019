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

void main() {
	struct gameState stateA;
	struct gameState stateB;
	struct gameState stateC;
	int supplyPos=2;
	
	stateA.supplyCount[2] = 10;
	stateB.supplyCount[2] = 10;
	stateC.supplyCount[2] = 10;
	stateA.numBuys = 4;
	stateA.coins = 0;
	stateB.numBuys = 2;
	stateB.coins = 15;
	stateC.numBuys = 0;
	stateC.coins = 7;

	printf("....Buy Card Test....\n");

	printf("Test for insufficient coins\n");
	if(buyCard(supplyPos, &stateA) == -1) {
		printf("PASS returned that there were insufficient coins\n");
	}
	else {
		printf("FAIL returned that there were sufficient coins\n");
	}

	printf("Test for sufficient coins scenario\n");
	if(buyCard(supplyPos, &stateB) == 0) {
		printf("PASS returned that there were sufficient coins\n");
	}
	else {
		printf("FAIL returned that there were insufficient coins\n");
	}

	printf("Test for insufficient number of buys available\n");
	if(buyCard(supplyPos, &stateC) == -1) {
		printf("PASS returned that there were insufficient coins\n");
	}
	else {
		printf("FAIL returned that there were sufficient coins\n");
	}
}
