/*
 * stanza.cpp
 *
 *  Created on: 18 ott 2017
 *      Author: turri
 */

#include "Stanza.h"


Stanza::Stanza() {
	this->x = -1;
	this->y = -1;
	this->altezza = -1;
	this->larghezza = -1;
	this->numPorte = -1;
}
Stanza::Stanza(int grid) {
	// TODO Auto-generated constructor stub
	int i;
	bool sopra = false;
	bool sotto = false;
	bool destra = false;
	bool sinistra = false;
	this->numPorte = (rand() % 4) +1; /* il numero di porte va da 1 a 4 */
	if(grid == 0){
		this->x = 0;
		this->y = 0;
	}else if(grid == 1){
		this->x = 33;
		this->y = 0;
	}else if(grid == 2){
		this->x = 66;
		this->y = 0;
	}else if(grid == 3){
		this->x = 0;
		this->y = 15;
	}else if(grid == 4){
		this->x = 33;
		this->y = 15;
	}else if(grid == 5){
		this->x = 66;
		this->y = 15;
	}else if(grid == 6){
		this->x = 0;
		this->y = 30;
	}else if(grid == 7){
		this->x = 33;
		this->y = 30;
	}else if(grid == 8){
		this->x = 66;
		this->y = 30;
	}

	this->altezza = rand() % 6 + 4; /* altezza massima 9 */
	this->larghezza = rand() % 14 + 4; /* larghezza massima 17 */

	/* spostamento/padding */
	this->x += rand() % (30 - this->larghezza) + 1;
	this->y += rand() % (10 - this->altezza) +1;

	for (i = 0; i < this->numPorte; i++) {

		this->porte[i].conect = false;

		bool assegnato = false;
		while (!assegnato){
			int posizione = rand() % 4;
			if(posizione == 0 && !sopra){
				this->porte[i].x = rand() % (this->larghezza - 2) + this->x + 1;
				this->porte[i].y = this->y;
				sopra = true;
				assegnato = true;
			}else if(posizione == 1 && !sotto){
				this->porte[i].y = this->y + this->altezza -1;
				this->porte[i].x = rand() % (this->larghezza - 2) + this->x + 1;
				sotto = true;
				assegnato = true;
			}else if(posizione == 2 && !destra){
				this->porte[i].y = rand() % (this->altezza - 2) + this->y + 1;
				this->porte[i].x = this->x + this->larghezza -1;
				destra = true;
				assegnato = true;
			}else if(posizione == 3 && !sinistra){
				this->porte[i].y = rand() % (this->altezza - 2) + this->y+1;
				this->porte[i].x = this->x;
				sinistra = true;
				assegnato = true;
			}
		}

		}
}

void Stanza::stampaStanza(char  mappa[45][135]){
	int x;
	int y;

	for (x = this->x; x < (this->x+this->larghezza); x++) {
		mappa[this->y][x] = '#';
		mappa[this->y + this->altezza-1][x] = '#';
	}
	for (y = this->y+1; y < (this->y+this->altezza) -1; y++) {
		mappa[y][this->x] = '#';
		mappa[y][this->x + this->larghezza -1] = '#';

		for (x = this->x+1; x < this->x + this->larghezza -1; x++) {
			mappa[y][x] = ' ';
		}
	}
	int k;
	for (k = 0; k < this->numPorte; k++) {
		mappa[this->porte[k].y][this->porte[k].x] = '+';
	}


}

