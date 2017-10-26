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

		this->value = 20;

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

bool oggetto::ricercaOgg(int x, int y){
	int i = 0;
	int xpl,ypl;
	bool result = false;
	while(!result && i<4){
		if(i == 0){
			ypl = y;
			xpl = x - 1;
		}else if(i == 1){
			ypl = y;
			xpl = x + 1;
		}else if(i == 2){
			xpl = x;
			ypl = y - 1;
		}else if(i == 3){
			xpl = x;
			ypl = y + 1;
		}
		if(xpl == this->x && ypl == this->y){
				result = true;
		}
		i++;
	}

	return result;

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
