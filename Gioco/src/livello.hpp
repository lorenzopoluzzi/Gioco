/*
 * livello.h
 *
 *  Created on: 18 ott 2017
 *      Author: turri
 */

#ifndef LIVELLO_HPP_
#define LIVELLO_HPP_

#include "mobb.hpp"
#include "player.hpp"
#include "stanza.hpp"
#include "oggetto.hpp"
#include <cmath>
#include "lista.hpp"



int const ALTEZZA = 45;
int const LARGHEZZA = 135;

struct coordinate{
	int x;
	int y;
};
struct scala{
	int x;
	int y;
	int liv;
};
class livello{
	protected:
		char mappa[ALTEZZA][LARGHEZZA];
		int numLivello;
		int numStanze;
		int numMostri;
		int numOggetti;
		int viewdestra;
		int viewsinistra;
		int viewsotto;
		int viewsopra;
		Lista<Stanza> * stanze;
		Player giocatore;
		Lista<mostro> * mostri;
		Lista<oggetto> * oggetti;
		scala scale[2];

	public:
		livello();
		livello(int numLivello);
		void stampaLivello();
		Lista<Stanza> * creazioneStanze(Lista<Stanza> * head);
		void collegamentiPorte();
		void setUpMappa();
		void creazioneGiocatore();
		Lista<mostro> * creazioneMostri(Lista<mostro> * testa);
		Lista<oggetto> * creazioneOggetti(Lista<oggetto> * fronte);
		int aggiornaMappa(char input);
		void setPosGiocatore();
		Player getPlayer();
		void setPlayer(int hp, int attack, int gem, int exp, int liv);
		void creazioneScale();


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

	private:
	bool checkPos(int x, int y, bool flag);
	bool findPlayer(coordinate player, coordinate mobb, int vista,bool &sopra,bool &sotto,bool &destra,bool &sinistra);
	bool ricercaScale(int x,int y, int &indice);
	void visibleMappa();
};

int  aggiungiVicino(char mappa[ALTEZZA][LARGHEZZA], Lista<coordinate> * frontiere, coordinate vieneDa [ALTEZZA][LARGHEZZA], int x, int y, int count);
bool controlloPos(char mappa[ALTEZZA][LARGHEZZA], int y, int x);
void collegamenti(char mappa[ALTEZZA][LARGHEZZA], coordinate start, coordinate end);




#endif /* LIVELLO_HPP_ */
