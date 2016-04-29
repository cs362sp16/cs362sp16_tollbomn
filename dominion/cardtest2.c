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
	G.numPlayers = 2;
	G.whoseTurn = 1;
	G.deck[0][0] = copper;
	G.deck[0][1] = copper;
	G.deck[0][2] = copper;
	G.deck[0][3] = copper;
	G.deck[0][4] = copper;
	G.hand[0][0] = smithy;
	G.hand[0][1] = copper;
	G.hand[0][2] = copper;
	G.hand[0][3] = copper;
	G.hand[0][4] = copper;
	G.deckCount[0] = 5;
	G.handCount[0] = 5;
	G.phase = 0;
	G.numActions = 1;
	playCard(0, 0, 0, 0, &G);
	myassert(G.handCount[0] == 7);
	printf("%d \n", G.handCount[0]);
	if (!failed) {
		printf("TEST SUCCESSFUL.\n");
	}
	return 0;
}