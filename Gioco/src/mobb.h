/*
 * mobb.h
 *
 *  Created on: 18 ott 2017
 *      Author: turri
 */

#ifndef MOBB_H_
#define MOBB_H_

#include <iostream>
using namespace std;

class mostro {

public:
	mostro();
    mostro(int liv, int x, int y);
    void caratteristiche  ( int atck, int life);
    bool setvita (int atckpl);
    int getvita ();
    int getattacco ();
    void setpos (int x, int y);
    int getposx ();
    int getposy ();
    bool getVivo();
    int getVista();
    void stampamobb (char mappa[][135]);
    void cancellaMobb( char mappa [45][135]);
    void movemobb (bool moodmobb, bool sopra, bool sotto, bool destra, bool sinistra );

private:

    bool vivo ;
    int randomobb (int liv);
    int tipomobb;


    //proprietà del mobb

    int atck ;
    int life ;
    int vista;
    //posizione

    int x;
    int y;

};






#endif /* MOBB_H_ */
