
/**
\file appearance.c
\author Alessandro Petrillo
\version 1.0
\date 2023-01-29
*/

#include <ncurses.h>

/**
\fn void dinosaur1(int y, int x)
\brief questa funzione stampa la prima posizione del dinosauro
\param int y: posizione sull'asse y dei caratteri del dinosauro
\param int x: posizione sull'asse x dei caratteri del dinosauro
\return void: stampa il dinosauro (no return)
*/
void dinosaur1(int y, int x) {
mvprintw(y-4, x, "          e-e  ");
mvprintw(y-3, x, "        /(\\_/)");
mvprintw(y-2, x, ",___.--` /'-` ");
mvprintw(y-1, x, " '-._, )/'");
mvprintw(y, x,   "      \\/");
}

/**
\fn void dinosaur2(int y, int x)
\brief questa funzione stampa la seconda posizione del dinosauro
\param int y: posizione sull'asse y dei caratteri del dinosauro
\param int x: posizione sull'asse x dei caratteri del dinosauro
\return void: stampa il dinosauro (no return)
*/


void dinosaur2(int y, int x) {
mvprintw(y-4, x, "          e-e  ");
mvprintw(y-3, x, "        /(\\_/)");
mvprintw(y-2, x, ",___.--` /'-` ");
mvprintw(y-1, x, " '-._, )/'");
mvprintw(y, x,   "      /\\");
}

/**
\fn void cactus1(int y, int x)
\brief questa funzione stampa un tipo di cactus
\param int y: posizione sull'asse y dei caratteri del cactus
\param int x: posizione sull'asse x dei caratteri del cactus
\return void: stampa il cactus (no return)
*/


void cactus1(int y, int x) {
mvprintw(y-5, x, "    _ ");
mvprintw(y-4, x, " _ ( )   ");
mvprintw(y-3, x, "( \\| | _");
mvprintw(y-2, x, " \\,. |/ )");
mvprintw(y-1, x, "   |  /'");
mvprintw(y, x, "   | |");
}

/**
\fn void cactus2(int y, int x)
\brief questa funzione stampa un tipo di cactus
\param int y: posizione sull'asse y dei caratteri del cactus
\param int x: posizione sull'asse x dei caratteri del cactus
\return void: stampa il cactus (no return)
*/


void cactus2(int y, int x) {
init_pair(5,COLOR_GREEN,COLOR_BLACK);
attron(COLOR_PAIR(5));
mvprintw(y-6, x, "    _");
mvprintw(y-5, x, "   ( ) _");
mvprintw(y-4, x, "  _| |/ )");
mvprintw(y-3, x, " ( \\  /'");
mvprintw(y-2, x, "  \\  |");
mvprintw(y-1, x, "   | |");
mvprintw(y, x, "   | |");
attroff(COLOR_PAIR(5));
}

/**
\fn void sun(int y, int x)
\brief questa funzione stampa il sole
\param int y: posizione sull'asse y dei caratteri del sole
\param int x: posizione sull'asse x dei caratteri del sole
\return void: stampa il sole (no return)
*/


void sun(int y, int x) {
attron(COLOR_PAIR(6));
mvprintw(y-8, x, "      ;   :   ;");
mvprintw(y-7, x, "   .   \\_,!,_/   ,");
mvprintw(y-6, x, "    `.,'     `.,'");
mvprintw(y-5, x, "     /         \\");
mvprintw(y-4, x, "~ -- :         : -- ~");
mvprintw(y-3, x, "     \\         /");
mvprintw(y-2, x, "    ,'`._   _.'`.");
mvprintw(y-1, x, "   '   / `!` \\   `");
mvprintw(y, x, "      ;   :   ;");
attroff(COLOR_PAIR(6));
}

/**
\fn void moon(int y, int x)
\brief questa funzione stampa la luna
\param int y: posizione sull'asse y dei caratteri della luna
\param int x: posizione sull'asse x dei caratteri della luna
\return void: stampa della luna (no return)
*/


void moon(int y, int x) {
attron(COLOR_PAIR(4));
mvprintw(y-8, x, "                      ");
mvprintw(y-7, x, "                      ");
mvprintw(y-6, x, "   _.._               ");
mvprintw(y-5, x, " .' .-'`              ");
mvprintw(y-4, x, "/  /                  ");
mvprintw(y-3, x, "|  |                  ");
mvprintw(y-2, x, "\\  \\                ");
mvprintw(y-1, x, " '._'-._              ");
mvprintw(y, x, "    ```                 ");
attroff(COLOR_PAIR(4));
}

/**
\fn void showLoss(int y, int x)
\brief questa funzione stampa la scritta loss
\param int y: posizione sull'asse y dei caratteri da stampare
\param int x: posizione sull'asse x dei caratteri da stampare
\return void: stampa la scritta loss (no return)
*/


void showLoss(int y, int x) {
mvprintw(y-6, x-15, "88");
mvprintw(y-5, x-15, "88");
mvprintw(y-4, x-15, "88");
mvprintw(y-3, x-15, "88  ,adPPYba,  ,adPPYba, ,adPPYba,");
mvprintw(y-2, x-15, "88 a8\"     \"8a I8[    \"\" I8[    \"\"");
mvprintw(y-1, x-15, "88 8b       d8  `\"Y8ba,   `\"Y8ba, ");
mvprintw(y, x-15, "88 \"8a,   ,a8\" aa    ]8I aa    ]8I");
mvprintw(y+1, x-15, "88  `\"YbbdP\"\'  `\"YbbdP\"\' `\"YbbdP\"\'");
mvprintw(y+3, x-15, "Press 'r' to play again!");
mvprintw(y+4, x-15, "Or 'q' to exit from game.");
}

/**
\fn void showTrex(int y, int x)
\brief questa funzione stampa la scritta trex
\param int y: posizione sull'asse y dei caratteri da stampare
\param int x: posizione sull'asse x dei caratteri da stampare
\return void: stampa la scritta trex (no return)
*/


void showTrex(int x, int y) {
mvprintw(x-7, y-25, "  ,d");
mvprintw(x-6, y-25, "  88");
mvprintw(x-5, y-25, "MM88MMM 8b,dPPYba,  ,adPPYba, 8b,     ,d8");
mvprintw(x-4, y-25, "  88    88P\'   \"Y8 a8P_____88  `Y8, ,8P\' ");
mvprintw(x-3, y-25, "  88    88         8PP\"\"\"\"\"\"\"    )888(  ");
mvprintw(x-2, y-25, "  88,   88         \"8b,   ,aa  ,d8\" \"8b, ");
mvprintw(x-1, y-25, "  \"Y888 88          `\"Ybbd8\"' 8P\'     `Y8");
}

/**
\fn void clearCactus1(int y, int x)
\brief questa funzione cancella il cactus
\param int y: posizione sull'asse y degli spazi da stampare per cancellare il cactus
\param int x: posizione sull'asse x  degli spazi da stampare per cancellare il cactus
\return void: cancella il cactus (no return)
*/

void clearCactus1(int y, int x) {
mvprintw(y-6, x+7, "        ");
mvprintw(y-5, x+8, "           ");
mvprintw(y-4, x+9, "             ");
mvprintw(y-3, x+8, "              ");
mvprintw(y-2, x+9, "                ");
mvprintw(y-1, x+9, "                 ");
mvprintw(y, x+9, "      ");
if (x <= 10) {
mvprintw(y-6, 0, "     ");
mvprintw(y-5, 0, "        ");
mvprintw(y-4, 0, "     ");
mvprintw(y-3, 0, "     ");
mvprintw(y-2, 0, "     ");
mvprintw(y-1, 0, "     ");
mvprintw(y, 0, "    ");
}
}

/**
\fn void cleardinosaurDown(int y, int x)
\brief questa funzione cancella il dinosauro quando salta
\param int y: posizione sull'asse y degli spazi da stampare per cancellare il dinosauro
\param int x: posizione sull'asse x  degli spazi da stampare per cancellare il dinosauro
\return void: cancella il dinosauro (no return)
*/
 

void cleardinosaurDown(int diY, int diX) {
mvprintw(diY+3, diX+10, "              ");
mvprintw(diY+4, diX+8, "              ");
mvprintw(diY+5, diX, "                   ");
mvprintw(diY+6, diX, "                 ");
mvprintw(diY+7, diX, "                ");
}

/**
\fn void cleardinosaurUp(int y, int x)
\brief questa funzione cancella il dinosauro quando non ssalta
\param int y: posizione sull'asse y degli spazi da stampare per cancellare il dinosauro
\param int x: posizione sull'asse x  degli spazi da stampare per cancellare il dinosauro
\return void: cancella il dinosauro (no return)
*/


void cleardinosaurUp(int diY, int diX) {
    mvprintw(diY-7, diX+4, "         ");
mvprintw(diY-8, diX+1, "               ");
mvprintw(diY-9, diX, "             ");
mvprintw(diY-10, diX, "                 ");
mvprintw(diY-11, diX+8, "     ");
}
