CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

unittest1: unittest1.c dominion.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c dominion.o
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)

unittest4: unittest4.c dominion.o
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)

cardtest1: cardtest1.c dominion.o
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)

results.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	./unittest1 >> results.out
	echo "GCOV AFTER 1 TEST" >> results.out
	gcov dominion.c >> results.out
	./unittest2 >> results.out
	echo "GCOV AFTER 2 TESTS" >> results.out
	gcov dominion.c >> results.out
	./unittest3 >> results.out
	echo "GCOV AFTER 3 TESTS" >> results.out
	gcov dominion.c >> results.out
	./unittest4 >> results.out
	echo "GCOV AFTER 4 TESTS" >> results.out
	gcov dominion.c >> results.out
	./cardtest1 >> results.out
	echo "GCOV AFTER 5 TESTS" >> results.out
	gcov dominion.c >> results.out
	./cardtest2 >> results.out
	echo "GCOV AFTER 6 TESTS" >> results.out
	gcov dominion.c >> results.out
	./cardtest3 >> results.out
	echo "GCOV AFTER 7 TESTS" >> results.out
	gcov dominion.c >> results.out
	./cardtest4 >> results.out
	echo "GCOV AFTER 8 TESTS" >> results.out
	gcov dominion.c >> results.out

all: playdom player

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
