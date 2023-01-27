#ifndef MENU_H
#define MENU_H
/**
	\fn struct user
	\brief E' la struttura che conterrà i dati che verrano inseriti dal utente.
	\param char name[20] è la stringa nella quale verrà inserito il nome dell'utente.
	\param char lastName[20] è la stringa nella quale verrà inserito il cognome dell'utente.
	\param char age[3]è la stringa nella quale verrà inserita l'età dell'utente.
*/
struct user {
	char name[20];
	char lastName[20];
	char age[3];
};
/**
		\fn void startMenu()
		\brief Questa funzione contiene i parametri nei quali l'utente inserirà i dati.
		
*/
void startMenu();
/**
		\fn void endGame(int score, int highScore, int diY, int diX, struct user firstUser)
		\brief In questa funzione In questa funzione il gioco finisce o ricomincia.
		\param int score è una varibile  con la quale compararemo il punteggio più alto.
		\param int highScore è la variabile che conterra il punteggio più alto.
		\param int diY è la posizione del dinosaurio sull'asse Y.
		\param int diX è la posizione del dinosaurio sull'asse X.
		\param struct user firstUser è la struttura nella quale ci sono i dati dell'utante.
		
*/
void endGame(int score, int highScore, int diY, int diX, struct user firstUser);

#endif

