#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int failed = 0;

void myassert(int bool) {
	if (!bool) {
		printf("FAILED ASSERTION.\n");
		failed = 1;
	}

}

int main (int argc, char** argv) {
  struct gameState G;
  struct gameState *p = &G;
  int i, j, k;
  int handsize, decksize, discardsize;

  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

  printf ("Running test on: Council Room.\n");
  for (i = 0; i < 250; i++) { //run 250 tests
	  failed = 0;
	  initializeGame(2, k, atoi(argv[1]), p);
	  //populate player 1's hand, deck, and discard with random cards.
	  handsize = floor(Random * (MAX_HAND - 4));
	  G.handCount[0] = handsize;
	  for (j = 0; j < handsize; j++) {
		  G.hand[0][j] = floor(Random() * 27);
	  }
	  decksize = floor(Random * (MAX_DECK));
	  G.deckCount[0] = decksize;
	  for (j = 0; j < decksize; j++) {
		  G.deck[0][j] = floor(Random() * 27);
	  }
	  discardsize = floor(Random * (MAX_DECK));
	  G.discardCount[0] = discardsize;
	  for (j = 0; j < discardsize; j++) {
		  G.discard[0][j] = floor(Random() * 27);
	  }
	  G.hand[0][0] = village; //place desired card
	  playCard(0, -1, -1, -1, p); //play card
	  printf("Checking handcount\n");
	  myassert(G.handCount(0) == handsize);
	  printf("Checking actions\n");
	  myassert(G.numActions[0] == 2);
	  printf("Checking card discarded\n");
	  myassert(G.discard[0][discardsize(0)] == village);
	  if (!failed) {
		  printf("TEST %d SUCCESSFULLY COMPLETED\n", i);
	  }

  }
  
  
  return 0;
}
