#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#include "menu.h"
#include "game.h"
#include "appearance.h"

/**
		\fn void startMenu()
		\brief Questa funzione contiene i parametri nei quali l'utente inserirà i dati.
		\return void: La funzione viene eseguita in loop quando viene chiamata
*/

void startMenu() {
	struct user firstUser;
	int highScore;
    // Read high score.
	FILE *highScoreFile;
	highScoreFile = fopen("./highScore.txt", "r");
	fscanf(highScoreFile, "%d", &highScore);
	fclose(highScoreFile);
	int maxX = getmaxx(stdscr)/2;
	int maxY = getmaxy(stdscr)/2;
	init_pair(3,COLOR_GREEN,COLOR_BLACK);
	attron(COLOR_PAIR(3));
	showTrex(maxY, maxX);
	attroff(COLOR_PAIR(3));
    
	mvprintw(maxY+1, maxX-28, "Write inputs and press Enter to start the Game.");
   	mvprintw(maxY+2, maxX-26, "When you had prize, fire it with 'k' key!");
	mvprintw(maxY+3, maxX-21, "You can jump with space key!");
	mvprintw(maxY+4, maxX-15, "Name: ");
	getstr(firstUser.name);
	mvprintw(maxY+5, maxX-15, "Last name: ");
	getstr(firstUser.lastName);
	mvprintw(maxY+6, maxX-15, "Age: ");
	getstr(firstUser.age);
	noecho();
	startEngine(highScore, firstUser);
}

/**
		\fn void endGame(int score, int highScore, int diY, int diX, struct user firstUser)
		\brief In questa funzione il gioco finisce o ricomincia.
		\param int score: Punteggio attuale.
		\param int highScore: è la variabile che conterra il punteggio più alto.
		\param int diY: conterrà la posizione del dinosaurio sull'asse Y.
		\param int diX: conterrà la posizione del dinosaurio sull'asse X.
		\param struct user firstUser: è la struttura nella quale ci sono i dati dell'utente.
		\return void: La funzione viene eseguita in loop quando viene chiamata
*/

void endGame(int score, int highScore, int diY, int diX, struct user firstUser) {
	nodelay(stdscr, FALSE);
	init_pair(2,COLOR_RED,COLOR_BLACK);
    // Save
	if (score > highScore) {
		highScore = score;
		FILE *highScoreFile;
		highScoreFile = fopen("./highScore.txt", "w");
		fprintf(highScoreFile, "%d", highScore);
		fclose(highScoreFile);
	}
	int maxX = getmaxx(stdscr)/2;
	int maxY = getmaxy(stdscr)/2;
	attron(COLOR_PAIR(2));
	showLoss(maxY, maxX);
	mvprintw(diY-4, diX, "          X-X ");
	mvprintw(diY, diX, "      ||");
	char keyToExit = getch();
    // Exit or restart
	
	if (keyToExit == 'r') {
		attroff(COLOR_PAIR(2));
		startEngine(highScore, firstUser);
	}
	else if (keyToExit == 'q') {
		return;
	}
	else {
		endGame(score, highScore, diY, diX, firstUser);
	}
}


