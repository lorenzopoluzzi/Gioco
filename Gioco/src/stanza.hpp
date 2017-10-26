/*
 * stanza.h
 *
 *  Created on: 18 ott 2017
 *      Author: turri
 */

#ifndef STANZA_HPP_
#define STANZA_HPP_

#include <iostream>
using namespace std;


struct porta{
	int x;
	int y;
	bool conect;
};

class Stanza {
protected:
	int x;
	int y;
	int altezza;
	int larghezza;
	porta porte[4];
	int numPorte;
	bool conect;

public:
	Stanza();
	Stanza(int grid);
	void stampaStanza(char  mappa[45][135]);

	int getAltezza() const {
		return altezza;
	}

	void setAltezza(int altezza) {
		this->altezza = altezza;
	}

	int getLarghezza() const {
		return larghezza;
	}

	void setLarghezza(int larghezza) {
		this->larghezza = larghezza;
	}

	int getNumPorte() const {
		return numPorte;
	}

	void setNumPorte(int numPorte) {
		this->numPorte = numPorte;
	}

	void getPorte(porta porte[]){
		int i;
		for(i = 0; i < this->numPorte; i++){
			porte[i] = this->porte[i];
		}
	}
	void setPorte(porta porte[]){
		int i;
		for(i = 0; i < this->numPorte; i++){
			  this->porte[i] = porte[i];
		}
	}
	int getX() const {
		return x;
	}

	void setX(int x) {
		this->x = x;
	}

	int getY() const {
		return y;
	}

	void setY(int y) {
		this->y = y;
	}

	bool getConect() const{
		return conect;
	}

	void setConect(bool conect){
		this->conect = conect;
	}
};




#endif /* STANZA_HPP_ */
