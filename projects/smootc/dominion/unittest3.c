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
	int cardNum;	//decare variable used as card position
	int costRec;	//will use to hold value returned in call

	printf("....Testing for getCost function....\n");

	//loop through all cards to confirm the value returned was correct
	for(cardNum = 0; cardNum < 27; cardNum++) {
		costRec = getCost(cardNum);

		if(cardNum == 0) {
			if(costRec == 0) {
				printf("PASS when return value for curse is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for curse is %d\n", costRec);
			}
		}

		if(cardNum == 1) {
			if(costRec == 2) {
				printf("PASS when return value for estate is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for estate is %d\n", costRec);
			}
		}

		if(cardNum == 2) {
			if (costRec == 5) {
				printf("PASS when return value for duchy is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for duchy is %d\n", costRec);
			}
		}

		if(cardNum == 3) {
			if(costRec == 8) {
				printf("PASS when return value for province is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for province is %d\n", costRec);
			}
		}

		if(cardNum == 4) {
			if(costRec == 0) {
				printf("PASS when return value for copper is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for copper is %d\n", costRec);
			}
		}

		if(cardNum == 5) {
			if(costRec == 3) {
				printf("PASS when return value for silver is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for silver is %d\n", costRec);
			}
		}

		if(cardNum == 6) {
			if(costRec == 6) {
				printf("PASS when return value for gold is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for gold is %d\n", costRec);
			}
		}
		
		if(cardNum == 7) {
			if(costRec == 6) {
				printf("PASS when return value for adventurer is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for adventurer is %d\n", costRec);
			}
		}

		if(cardNum == 8) {
			if(costRec == 5) {
				printf("PASS when return value for council_room is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for council_room is %d\n", costRec);
			}
		}
		
		if(cardNum == 9) {
			if(costRec == 4) {
				printf("PASS when return value for feast is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for feast is %d\n", costRec);
			}
		}
		
		if(cardNum == 10) {
			if(costRec == 4) {
				printf("PASS when return value for gardens is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for gardens is %d\n", costRec);
			}
		}
		
		if(cardNum == 11) {
			if(costRec == 5) {
				printf("PASS when return value for mine is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for mine is %d\n", costRec);
			}
		}
		
		if(cardNum == 12) {
			if(costRec == 4) {
				printf("PASS when return value for remodel is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for remodel is %d\n", costRec);
			}
		}
		
		if(cardNum == 13) {
			if(costRec == 4) {
				printf("PASS when return value for smithy is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for smithy is %d\n", costRec);
			}
		}
		
		if(cardNum == 14) {
			if(costRec == 3) {
				printf("PASS when return value for village is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for village is %d\n", costRec);
			}
		}
		
		if(cardNum == 15) {
			if(costRec == 4) {
				printf("PASS when return value for baron is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for baron is %d\n", costRec);
			}
		}
		
		if(cardNum == 16) {
			if(costRec == 3) {
				printf("PASS when return value for great_hall is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for great_hall is %d\n", costRec);
			}
		}
		
		if(cardNum == 17) {
			if(costRec == 5) {
				printf("PASS when return value for minion is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for minion is %d\n", costRec);
			}
		}
		
		if(cardNum == 18) {
			if(costRec == 3) {
				printf("PASS when return value for steward is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for steward is %d\n", costRec);
			}
		}
		
		if(cardNum == 19) {
			if(costRec == 5) {
				printf("PASS when return value for tribute is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for tribute is %d\n", costRec);
			}
		}

		if(cardNum == 20) {
			if(costRec == 3) {
				printf("PASS when return value for ambassador is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for ambassador is %d\n", costRec);
			}
		}
		
		if(cardNum == 21) {
			if(costRec == 4) {
				printf("PASS when return value for cutpurse is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for cutpurse is %d\n", costRec);
			}
		}
		
		if(cardNum == 22) {
			if(costRec == 2) {
				printf("PASS when return value for embargo is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for embargo is %d\n", costRec);
			}
		}
		
		if(cardNum == 23) {
			if(costRec == 5) {
				printf("PASS when return value for outpost is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for outpost is %d\n", costRec);
			}
		}
				
		if(cardNum == 24) {
			if(costRec == 4) {
				printf("PASS when return value for salvager is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for salvager is %d\n", costRec);
			}
		}
		
		if(cardNum == 25) {
			if(costRec == 4) {
				printf("PASS when return value for sea_hag is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for sea_hag is %d\n", costRec);
			}
		}
		
		if(cardNum == 26) {
			if(costRec == 4) {
				printf("PASS when return value for treasure_map is %d\n", costRec);
			}
			else {
				printf("FAIL when return value for treasure_map is %d\n", costRec);
			}
		}
	}
}
