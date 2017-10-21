/*
 * oggetto.cpp
 *
 *  Created on: 19 ott 2017
 *      Author: turri
 */

#include "oggetto.hpp"



oggetto::oggetto() {
	this->tipooggetto = -1;
	this->value = -1;
	this->x = -1;
	this->y = -1;

}

oggetto::oggetto(int liv, int x, int y){
	this->tipooggetto = randomobject(liv);

	if(this->tipooggetto == 0){

		this->value = 20;

	}else if(this->tipooggetto == 1){

		this->value = 10;

	}else if(this->tipooggetto == 2){

		this->value = -20;

	}else if(this->tipooggetto == 3){

		this->value = 1;

	}else if(this->tipooggetto == 4){

		this->value = 5;
	}

	this->x = x;
	this->y = y;
}

void oggetto::stampaObject (char mappa [45][135]){
	mappa [this->y][this->x] = '?';
}

void oggetto::cancellaObject(char mappa [45][135] ){
	mappa [this->y][this->x] = ' ';
}

bool oggetto::ricercaOgg(int x, int y, int numOggetti, Lista<oggetto> * head, oggetto * result){
	int i;
	int obX, obY;
	for (i = 0; i < numOggetti; i++) {
		oggetto ob1 = getElemetI(i, head);
		obX = ob1.getX();
		obY = ob1.getY();
		if(x == obX && y == obY){
			result = &ob1;
			return true;
		}
	}

	return false;
}

int oggetto::getValue(){
	return this->value;
}

int oggetto::getTipooggetto(){
	return this->tipooggetto;
}

int oggetto::getX(){
	return this->x;
}

int oggetto::getY(){
	return this->y;
}
/*
 * I possibili oggetti sono 5 e vanno da 0 a 4
 * 0- MILK aggiunge 20 Pt. alla salute del giocatore con max 100
 * 1- POZIONE aggiunge 10 Pt. esperienza al giocatore
 * 2- TRAPPOLA toglie 20 di vita al giocatore
 * 3- GEMMA aggiunge una gemma a raccolta del personaggio
 * 4- FORZA  aggiunge 5 Pt. all’attacco del giocatore permanentemente
 */
int oggetto::randomobject(int liv){
	int randomobject;
	if(liv < 2){
		randomobject = rand()%3;
	}else {
		randomobject = rand()%5;
	}

	return randomobject;
}
