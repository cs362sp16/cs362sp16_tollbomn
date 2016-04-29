#include "dominion.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>

int failed = 0;

void myassert(int bool) {
	if (!bool) {
		printf("FAILED ASSERTION.\n");
		failed = 1;
	}

}

int main() {
	struct gameState G;
	struct gameState *p = &G;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };
	initializeGame(2, k, 1, p);
	myassert(supplyCount(village, &G) == 10);
	if (!failed) {
		printf("TEST SUCCESSFULLY COMPLETED\n");
	}
	return 0;
}