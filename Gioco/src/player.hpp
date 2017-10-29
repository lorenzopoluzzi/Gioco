/*
 * player.h
 *
 *  Created on: 18 ott 2017
 *      Author: turri
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

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
    bool getMove (char c, char mappa[45][135]);

    //raccogli oggetto
    void raccolgoOgg(int tipoggetto, int value);

    //vita iniziale
    void getVita(int &life);

    //pinza gemma
    void pickGemma();

    //getters gemma
    void getGemma(int &gemma);

    //cancella il player alla posizione
    void cancellaPlayer( char mappa [45][135]);

    //add vita player
    void addVita(int value);

    //set vita
    void setVita(int hp);

    //add attacco
    void addAttacco(int value);

    //set attacco
    void setAttacco(int value);

    //set livello
    void setLivello(int liv);

    //set esperienza
    void setExp(int exp);

    //set gemme
    void setGemme(int gem);

protected:

    //proprietà del giocatore principale
    int _livello;
    int _esperienza;
    int _attacco;
    int _vita;
    int _gemma;
    char _car;

    //posizione
    int _x;
    int _y;


};



#endif /* PLAYER_HPP_ */
