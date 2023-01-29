// build with "gcc main.c game.c menu.c appearance.c -lncurses -o dino.exe
/** 
	\file main.c
	\author Pognant Carlo
	\version 1.0
	\date 2023-01-29
*/
#include <ncurses.h>
#include <stdio.h>
#include "menu.h"
#include "minunit.h"

/**
	\fn int main(int argc, char **argv)
	\brief Funzione principale del programma Questa funzione gestisce l'avvio del programma e la sua modalità di esecuzione
	Se viene specificato il comando '-test', verranno eseguiti tutti i test del programma 		
	utilizzando la libreria minunit.h
	Altrimenti verrà avviato il menu principale del gioco usando la libreria ncurses
	\param int argc: Numero di argomenti passati al programma
	\param int **argv: Array di argomenti pasati al programma
	\return int: Fa tornare o 1 se il gioco non è terminato oppure 0 se il gioco è terminato
*/

int main(int argc, char **argv) {
	// Run tests (if the -test command argument has been specified)
	int testsResult = run_all_tests(argc, argv);
	if(testsResult > 0)
		return testsResult != 0;
	
	// Normal star
	initscr();
	start_color();
	curs_set(FALSE);
	startMenu();
	endwin();

    return 0;
}
