/*
 * livello.h
 *
 *  Created on: 18 ott 2017
 *      Author: turri
 */

#ifndef LIVELLO_H_
#define LIVELLO_H_

#include "lista.cpp"
#include "Stanza.h"
#include "mobb.h"
#include "player.h"

int const ALTEZZA = 45;
int const LARGHEZZA = 135;

struct coordinate{
	int x;
	int y;
};

class livello{
	protected:
		char mappa[ALTEZZA][LARGHEZZA];
		int numLivello;
		int numStanze;
		int numMostri;
		Lista<Stanza> * stanze;
		Player giocatore;
		Lista<mostro> * mostri;

	public:
		livello();
		livello(int numLivello);
		void stampaLivello();
		Lista<Stanza> * creazioneStanze(Lista<Stanza> * head);
		void collegamentiPorte();
		void setUpMappa();
		void creazioneGiocatore();
		Lista<mostro> * creazioneMostri(Lista<mostro> * testa);

	void getMappa(char mappa[ALTEZZA][LARGHEZZA]){
		int i,j;
		for(i = 0; i < ALTEZZA; i++){
			for(j = 0; j < LARGHEZZA; j++){
				mappa[i][j] = this->mappa[i][j];
			}
		}
	}

	void setMappa(char mappa[ALTEZZA][LARGHEZZA]){
		int i,j;
		for(i = 0; i < ALTEZZA; i++){
			for(j = 0; j < LARGHEZZA; j++){
				 this->mappa[i][j] = mappa[i][j];
			}
		}
	}
	int getNumLivello() const {
		return numLivello;
	}

	void setNumLivello(int numLivello) {
		this->numLivello = numLivello;
	}

	int getNumStanze() const {
		return numStanze;
	}

	void setNumStanze(int numStanze) {
		this->numStanze = numStanze;
	}

	Lista<Stanza> * getStanze() const {
		return this->stanze;
	}

	void setStanze(Lista<Stanza> * stanze) {
		this->stanze = stanze;
	}
};

int  aggiungiVicino(char mappa[ALTEZZA][LARGHEZZA], Lista<coordinate> * frontiere, coordinate vieneDa [ALTEZZA][LARGHEZZA], int x, int y, int count);
bool controlloPos(char mappa[ALTEZZA][LARGHEZZA], int y, int x);
void collegamenti(char mappa[ALTEZZA][LARGHEZZA], coordinate start, coordinate end);




#endif /* LIVELLO_H_ */
