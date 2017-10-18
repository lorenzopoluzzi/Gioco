/*
 * player.c
 *
 *  Created on: 18 ott 2017
 *      Author: Omar Serrah
 */

#include "player.h"

//inizializzo la posizione del giocatore a zero
Player::Player() {
    _x = 5;
    _y = 10;
    _livello = 0;
    _esperienza = 0;
    _attacco = 20;
    _vita = 100;
    _gemma = 0;
    }

//stampa a schermo
void Player::stampaGiocatore (char mappa [45][135]){
    mappa [_y][_x] = 'P';
}
// setta la vita del giocatore
void Player::getVita (int &life) {
    life = _vita;
}

// setta la posizione del giocatore
void Player::setPosizione (int x, int y) {
    _x = x;
    _y = y;
}

//ottieni gemma
void Player::pickGemma (){
    _gemma = _gemma +1;
}

//getters gemma
void Player::getGemma(int &gemma) {
    gemma = _gemma;
}

//perdere vita
void Player::vieniColpito(int attacco) {
        _vita -= attacco;
    }

//esperienza
void Player::addEsperienza (int esperienza) {
    _esperienza += esperienza;
    //Level UP
    while (_esperienza >= 100) {
        printf("Level UP! \n");
         _esperienza -= 100;
         _attacco += 10;
         _vita = 100;
         _livello ++;
     }
}

//tu colpisci
void Player::getAttacco(int &attacco) {
    attacco = _attacco;
}

//esperienza
void Player::getEsperienza(int &esperienza) {
    esperienza = _esperienza;
}
//esperienza
void Player::getLivello(int &livello) {
    livello = _livello;
}

//prende la posizione usando variabili
void Player::getPosizione (int &x, int &y) {
    x = _x;
    y = _y;
}

//movimenti del player
void Player::getMove (char c) {
    if (c == 'w')
        this->_y = this->_y-1;

    if ( c == 's')
        this->_y = this->_y+1;

    if ( c == 'a')
        this->_x = this->_x-1;

    if ( c == 'd')
        this->_y = this->_x+1;
}

