/******************************************
 * Author: Corey Smoot
 * Date: 4/29/2019
 * Description: test on whoseTurn function
*******************************************/

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
	struct gameState state2;
	state1.whoseTurn = 1;
	state2.whoseTurn = 2;

	//simple test for returning the correct whoseTurn value of the
	//gameState struct passed
	printf("Test for whoseTurn as 1\n");
	if (whoseTurn(&state1) == 1) {
		printf("PASS when test contains %d as whoseTurn", state1.whoseTurn);
	}
	else {
		printf("FAIL when test contains %d as whoseTurn", state1.whoseTurn);
	}

	printf("Test for whoseTurn as 2\n");
	if (whoseTurn(&state2) == 2) {
		printf("PASS when test contains %d as whoseTurn", state2.whoseTurn);
	}
	else {
		printf("FAIL when test contains %d as whoseTurn", state2.whoseTurn);
	}
}
