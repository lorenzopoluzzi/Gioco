/*
 * oggetto.hpp
 *
 *  Created on: 19 ott 2017
 *      Author: turri
 */

#ifndef OGGETTO_HPP_
#define OGGETTO_HPP_

#include <iostream>
#include "lista.cpp"
using namespace std;


class oggetto {



public:
	oggetto();
	oggetto(int liv, int x, int y);
    void stampaObject (char mappa[][135]);
    void cancellaObject( char mappa [][135]);
    bool ricercaOgg(int x, int y);
    int getX();
    int getY();
    int getValue();
    int getTipooggetto();


protected:
	int tipooggetto;
	int value;
	int x;
	int y;

private:
	int randomobject (int liv);
};



#endif /* OGGETTO_HPP_ */
