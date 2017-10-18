/*
 * player.h
 *
 *  Created on: 18 ott 2017
 *      Author: turri
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
using namespace std;


class Player {
public:

    Player();

    //stampa a schermo il giocatore
    void stampaGiocatore (char mappa [45][135]);

    //setters
    void setPosizione (int x, int y);

    //getta esperienza
    void getEsperienza (int &esperienza);

    //getta livello
    void getLivello (int &livello);

    //collezziona esperienza
    void addEsperienza(int esperienza);

    //getters
    void getPosizione (int &x, int &y);

    //perdi vita
    void vieniColpito (int attacco);

    //tu colpisci
    void getAttacco (int &attacco);

    //tu muovi
    void getMove (char c);

    //vita iniziale
    void getVita(int &life);

    //pinza gemma
    void pickGemma();

    //getters gemma
    void getGemma(int &gemma);

protected:

    //proprietà del giocatore principale
    int _livello;
    int _esperienza;
    int _attacco;
    int _vita;
    int _gemma;

    //posizione
    int _x;
    int _y;


};



#endif /* PLAYER_H_ */
