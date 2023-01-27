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
	/**
		\fn int maxX, int maxY
		\brief Queste due variabili conterranno i valori degli assi X Y.
		\param La varibile maxX conterra i valori del asse X.
		\param La variabile maxY conterra i valori del asse Y.
	*/
	init_pair(3,COLOR_GREEN,COLOR_BLACK);
	attron(COLOR_PAIR(3));
	showTrex(maxY, maxX);
	attroff(COLOR_PAIR(3));
    
	mvprintw(maxY+1, maxX-28, "Write inputs and press Enter to start the Game.");
    mvprintw(maxY+2, maxX-26, "When you had prize, fire it with 'k' key!");
	mvprintw(maxY+3, maxX-21, "You can jump with space key!");
	mvprintw(maxY+4, maxX-15, "Name: ");
	/**
		\fn getstr(firstUser.name), getstr(firstUser.lastName), getstr(firstUser.age) 
		\brief Questa funzione richiede una stringa come input.
		\param getstr(firstUser.name) richiederà il nome del giocatore e l'inserirà nella struttura.
		\param getstr(firstUser.lastName) richiederà il cognome del giocatore e l'inserirà nella struttura.
		\param getstr(firstUser.age) richiederà l'età del giocatore e l'inserirà nella struttura.
	*/
	getstr(firstUser.name);
	mvprintw(maxY+5, maxX-15, "Last name: ");
	getstr(firstUser.lastName);
	mvprintw(maxY+6, maxX-15, "Age: ");
	getstr(firstUser.age);
	/**
		\fn noecho()
		\brief Questa funzione controlla se i caratteri digitati dall'utente vengono ripetuti dalla funzione getstr() mentre vengono digitati
	*/
	noecho();
	startEngine(highScore, firstUser);
}
/**
		\fn void endGame(int score, int highScore, int diY, int diX, struct user firstUser)
		\brief In questa funzione In questa funzione il gioco finisce o ricomincia.
		\param int score è una varibile  con la quale compararemo il punteggio più alto.
		\param int highScore è la variabile che conterra il punteggio più alto.
		\param int diY conterrà la posizione del dinosaurio sull'asse Y.
		\param int diX conterrà la posizione del dinosaurio sull'asse X.
		\param struct user firstUser è la struttura nella quale ci sono i dati dell'utante.
		
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
	/**
		\fn keyToExit
		\brief In questa variabile verra inserito "r" per restart il gioco e "q" per finire il gioco.
	*/
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


