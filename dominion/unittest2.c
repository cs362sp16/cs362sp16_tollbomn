#include "dominion.h"
#include <stdio.h>

int failed = 0;

void myassert(int bool) {
	if (!bool) {
		printf("FAILED ASSERTION.\n");
		failed = 1;
	}

}

int main() {
	struct gameState *g = newGame();
	myassert(g != NULL);
	if (!failed) {
		printf("TEST SUCCESSFULLY COMPLETED\n");
	}
	return 0;
}