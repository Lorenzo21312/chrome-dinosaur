
/** 
	\file game.c
	\author Lorenzo Boggiatto
	\version 1.0
	\date 2023-01-29
*/

#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#include "menu.h"
#include "game.h"
#include "appearance.h"
#include "minunit.h"

// Check if the game is going to be finished in this turn of loop

/**
	\fn int checkGame(int y, int x, int diY, int diX)
	\brief Questa funzione controlla se il gioco è terminato
	\param int y: Posizione sull'asse y del cactus
	\param int x: Posizione sull'asse x del cactus
	\param int diY: Posizione sull'asse y del dinosauro
	\param int diX: Posizione sull'asse x del dinosauro
	\return int: Fa tornare o 1 se il gioco non è terminato oppure 0 se il gioco è terminato
	
*/
int checkGame(int y, int x, int diY, int diX) {
	if (diY == y) {
		if (abs((diX+14)-x) <= 4) {
			return 0;
		}
	}
	return 1;
}

// Make game faster

/**
	\fn int computeTime(int delayTime) 
	\brief Questa funzione fa aumentare la velocità del gioco
	\param int delayTime: velocità del gioco
	\return int: la velocità con cui va riprodotto il gioco
*/
int computeTime(int delayTime) {
	if (delayTime >= 250000) {
		delayTime -= 1000;
	}
	else if (delayTime >= 200000) {
		delayTime -= 600;
	}
	else {
		delayTime -= 200;
	}
	return delayTime;
}

// Which dinosaur should be printed

/**
	\fn void showdinosaur(int diY, int diX)
	\brief Questa funzione serve a far vedere le due prospettive del dinosauro
	\param int diY: Posizione sull asse y
	\param int diX: Posizione sull asse x
	\return void: La funzione continua in loop facendo sembrare che il dinosauro si muova (no return)
*/

void showdinosaur(int diY, int diX) {
	static int counter = 0;
	if (counter == 0) {
		dinosaur1(diY, diX);
		counter++;
	}
	else {
		dinosaur2(diY, diX);
		counter--;
	}
}

// Give user the prize

/**
	\fn int computePrize(int score, int usedPrize)
	\brief Questa funzione serve per dare il "prize" all'utente
	\param int score: Punteggio attuale
	\param int usedPrize: Volte in cui è stato utilizzato il prize
	\return int: Fa ritornare il prize a 1 oppure lo fa tornare a 0 
*/

int computePrize(int score, int usedPrize) {
	if (score >= 20 && score <= 40 && usedPrize == 0) {
		return 1;
	}
	else if (score >= 60 && score <= 80 && usedPrize <= 1) {
		return 1;
	}
	else if (score >= 100 && score <= 120 && usedPrize <= 2) {
		return 1;
	}	
	return 0;
}

// The main engine!



/**
	\fn void startEngine(int highScore, struct user firstUser)
	\brief Questa funzione serve per far funzionare il gioco
	\param int highScore: Punteggio massimo raggiunto dall'utente
	\param struct user firstUser: Dati inseriti dall'utente nel menu
	\return void: Esegue il programma in loop fino a quando la funzione "checkGame" non restituisce 0 (no return)
*/

void startEngine(int highScore, struct user firstUser) {
    srand(time(NULL));
	int x, y, diX=5, prize=0, usedPrize=0, score=0, delayTime = 300000
    , gameStatus=1, cactusNum=0;
	int maxX=getmaxx(stdscr);
	x = maxX-20;
	y = getmaxy(stdscr)-6;
	int diY = y;
	int arrowX=(diX+15), arrowY=(diY-3);
	char userInput;
	int jumping=-1;
    bool fire=FALSE;
    clear();
	nodelay(stdscr, TRUE);
  	init_pair(1,COLOR_WHITE,COLOR_BLACK);
	init_pair(4,COLOR_BLUE,COLOR_BLACK);
	init_pair(5,COLOR_GREEN,COLOR_BLACK);
	init_pair(6,COLOR_YELLOW,COLOR_BLACK);
	while (gameStatus == 1) {
		userInput = getch();
		// Show day or night
		if((score/50)%2 != 0) {
			moon(10, (maxX/2)-10);
		}
		else {
			attron(COLOR_PAIR(1));
			sun(10, (maxX/2)-10);			
		}
		// clear arrow
		if (fire) {
			mvprintw(arrowY, arrowX-2, " ");
		}

		score++;
        // Show informations
		mvprintw(1, 6, "%s %s %s", firstUser.name, firstUser.lastName, firstUser.age);
		mvprintw(1, getmaxx(stdscr)-9, "%d:%d", highScore, score);
		// Use prize to destroy cactus
		prize = computePrize(score, usedPrize);
		mvprintw(3, 6, "Prize: %d    ", prize);
		if (prize == 1) {
			if (userInput == 'k') {
				usedPrize++;
				fire = TRUE;
			}
		}
		if (fire) {
			mvprintw(arrowY, arrowX, "*");
			arrowX += 2;
		}
		if ((x+4)-arrowX <= 1 && fire) {
			clearCactus1(y, x-1);
			mvprintw(arrowY, arrowX-2, " ");
			x = getmaxx(stdscr)-20;
			fire = FALSE;
			arrowX = diX+15;
		}
		// ----------
		box(stdscr, ACS_VLINE, ACS_HLINE);
		//for clearing screen
		cleardinosaurUp(diY, diX);
		if (x <= 7) {
			x = getmaxx(stdscr)-20;
            cactusNum = rand() % 2;
		}
        // if input is equal to ' ' then jump
		if (userInput == ' ' && jumping<0) {
			diY -= 7;
			jumping = 3;
		}
		showdinosaur(diY, diX);
		if (userInput == ' ') {
			cleardinosaurDown(diY, diX);		
		}
		if (x-diX <= 7) {
			x -= 10;
		}
        if (cactusNum == 0) {
        	cactus1(y, x);
		}
		else {
			cactus2(y, x);
		}
		if (x-diX <= 7) {
			x += 10;
		}
		gameStatus = checkGame(y, x, diY, diX);
        // Bring back dinosaur
		jumping--;
		if (jumping==0) {
			diY += 7;
		}
		mvhline(y+1, 1, '-', getmaxx(stdscr)-3);
        refresh();
        clearCactus1(y, x);
		refresh();
        usleep(delayTime);
        x -= 7;
        delayTime = computeTime(delayTime);
		userInput = 'q';
	}

	endGame(score, highScore, diY, diX, firstUser);
	attroff(COLOR_PAIR(1));
}



//
// START of tests section
//

// sample variables to be tested
int foo = 4;
int bar = 5;

// init tests vars
int tests_run = 0;
int tests_passed = 0;



// sample test function checkGame

void test_checkGame() {

	int oracolo = 0;
	mu_assert("ERRORE: Non ritorna 0 (Test 1)", checkGame(3,17,3,5) == oracolo);
	mu_assert("ERRORE: Non ritorna 0 (Test 2)", checkGame(0,14,0,4) == oracolo);
	mu_assert("ERRORE: Non ritorna 0 (Test 3)", checkGame(-10,11,-10,0) == oracolo);
	mu_assert("ERRORE: Non ritorna 0 (Test 4)", checkGame(11,0,11,-14) == oracolo);
	mu_assert("ERRORE: Non ritorna 0 (Test 5)", checkGame(8,20,8,7) == oracolo);
	
	oracolo = 1;
	mu_assert("ERRORE: Non ritorna 1 (Test 6)", checkGame(9,3,9,11) == oracolo);
	mu_assert("ERRORE: Non ritorna 1 (Test 7)", checkGame(1,35,1,4) == oracolo);
	mu_assert("ERRORE: Non ritorna 1 (Test 8)", checkGame(5,17,7,3) == oracolo);
	mu_assert("ERRORE: Non ritorna 1 (Test 9)", checkGame(-3,14,3,0) == oracolo);
	mu_assert("ERRORE: Non ritorna 1 (Test 10)", checkGame(12,14,2,1) == oracolo);
}



// sample test function computeTime

void test_fake2() {
	int oracolo = 3;
	mu_assert("ERRORE, 1+1 non fa 2!", 3 == oracolo);
}






// sample test function computePrize

void test_computePrize() {

	int oracolo = 0;
	mu_assert("ERRORE: Non ritorna 0 (Test 1)", computePrize(23,1) == oracolo);
	mu_assert("ERRORE: Non ritorna 0 (Test 2)", computePrize(63,2) == oracolo);
	mu_assert("ERRORE: Non ritorna 0 (Test 3)", computePrize(101,4) == oracolo);
	mu_assert("ERRORE: Non ritorna 0 (Test 4)", computePrize(200,1) == oracolo);
	mu_assert("ERRORE: Non ritorna 0 (Test 5)", computePrize(10,1) == oracolo);
	
	oracolo = 1;
	mu_assert("ERRORE: Non ritorna 1 (Test 6)", computePrize(24,0) == oracolo);
	mu_assert("ERRORE: Non ritorna 1 (Test 7)", computePrize(61,1) == oracolo);
	mu_assert("ERRORE: Non ritorna 1 (Test 8)", computePrize(104,1) == oracolo);
	mu_assert("ERRORE: Non ritorna 1 (Test 9)", computePrize(20,0) == oracolo);
	mu_assert("ERRORE: Non deve ritornare 1 (Test 10)", computePrize(63,3) != oracolo);
}



// sample random test 

/**
	\fn static char * test_foo()
	\brief Questa funzione serve per far eseguire dei test
*/

static char * test_foo() {
    mu_assert("error, foo != 7", foo == 7);
}



// sample random test

/**
	\fn static char * test_bar()
	\brief Questa funzione serve per far eseguire dei test
*/

static char * test_bar() {
    mu_assert("error, bar != 5", bar == 5);
}





// put all tests here

/**
	\fn void all_tests()
	\brief Questa funzione serve per far eseguire dei test
*/

void all_tests() {
	mu_run_test(test_foo);
	mu_run_test(test_bar);
	mu_run_test(test_checkGame);
	mu_run_test(test_fake2);
	mu_run_test(test_computePrize);
}

// call this to run all tests

/**
	\fn int run_all_tests(int argc, char **argv)
	\brief Questa funzione serve per far eseguire dei test
	\param int argc: Numero di stringhe
	\param char **argv: array di stringhe
	\return int: Restituisce il valore di test eseguiti ed il valore dei test passati
*/

int run_all_tests(int argc, char **argv) {
	if(argc<2 || strcmp(argv[1],"-test")!=0) {
		return -1;
	}
	
	printf("--- RUNNING TESTS ---\n");
    all_tests();
	printf("--- SUMMARY ---\n");
    printf("Total number of tests: %d\n", tests_run);
	printf("Tests passed: %d\n", tests_passed);
	return tests_run-tests_passed;
}
//
// END of tests section
//
