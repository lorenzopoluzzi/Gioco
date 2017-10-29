/*
 * player.c
 *
 *  Created on: 18 ott 2017
 *      Author: Omar Serrah
 */

#include "player.hpp"

//inizializzo la posizione del giocatore a zero
Player::Player() {
    _x = 5;
    _y = 10;
    _livello = 0;
    _esperienza = 0;
    _attacco = 20;
    _vita = 100;
    _gemma = 0;
    _car = ' ';
}

//stampa a schermo
void Player::stampaGiocatore (char mappa [45][135]){
    mappa [_y][_x] = 'P';
}
// ghetta la vita del giocatore
void Player::getVita (int &life) {
    life = _vita;
}

void Player::addVita(int value){
	this->_vita += value;
	if(this->_vita > 100){
		this->_vita = 100;
	}
}

void Player::setVita(int hp){
	this->_vita = hp;
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
//setters gemma
void Player::setGemme(int gem){
	this->_gemma = gem;
}
//perdere vita
void Player::vieniColpito(int attacco) {
        this->_vita -= attacco;
 }

//esperienza
void Player::addEsperienza (int esperienza) {
    _esperienza += esperienza;
    //Level UP
    while (_esperienza >= 100) {
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
void Player::setExp(int exp){
	this->_esperienza = exp;
}
//livello
void Player::getLivello(int &livello) {
    livello = _livello;
}

void Player::setLivello(int liv){
	this->_livello = liv;
}
//prende la posizione usando variabili
void Player::getPosizione (int &x, int &y) {
    x = _x;
    y = _y;
}

void Player::addAttacco(int value){
	_attacco += value;
}

void Player::setAttacco(int value){
	this->_attacco = value;
}
//movimenti del player
bool Player::getMove (char c, char mappa[45][135]) {
    if ( c == 'w') {
    	if(_y-1 >= 0){
    		if(mappa[_y-1][_x]==' ' || mappa[_y-1][_x]=='+') {
    			this->_car = mappa[_y-1][_x];
    			this->_y = this->_y-1;
    			return true;
    		} else {
    			return false;
    		}
    	}else{
    		return false;
    	}
	}
    if ( c == 's') {
    	if(_y+1 < 45){
    		if(mappa[_y+1][_x]==' ' || mappa[_y+1][_x]=='+') {
    			this->_car = mappa[_y+1][_x];
    			this->_y = this->_y+1;
    			return true;
    		} else {
    			return false;
    		}
    	}else{
    		return false;
    	}
	}
    if ( c == 'a') {
    	if(_x-1 >=0){
			if(mappa[_y][_x-1]==' ' || mappa[_y][_x-1]=='+') {
				this->_car = mappa[_y][_x-1];
				this->_x = this->_x-1;
				return true;
			} else {
				return false;
			}
    	}else{
    		return false;
    	}
	}
    if ( c == 'd') {
    	if(_x+1 < 135){
    		if(mappa[_y][_x+1]==' ' || mappa[_y][_x+1]=='+') {
    			this->_car = mappa[_y][_x+1];
    			this->_x = this->_x+1;
    			return true;
    		} else {
    			return false;
    		}
    	}else{
    		return false;
    	}
    }
    return false;
}

void Player::raccolgoOgg(int tipoggetto, int value){
	if(tipoggetto == 0){
		addVita(value);
	}else if(tipoggetto == 1){
		addEsperienza(value);
	}else if(tipoggetto == 2){
		vieniColpito(value);
	}else if(tipoggetto == 3){
		pickGemma();
	}else if(tipoggetto == 4){
		addAttacco(value);
	}
}

void Player::cancellaPlayer( char mappa [45][135]){
	mappa[_y][_x] = this->_car;
}
