/*
 * livello.cpp
 *
 *  Created on: 18 ott 2017
 *      Author: turri
 */


#include "Livello.h"


livello::livello(){
	this->numLivello = -1;
	this->numStanze = -1;
	this->stanze = NULL;
	this->mostri = NULL;
	this->numMostri = -1;
}

livello::livello(int numLivello){
	this->numLivello = numLivello;
	Lista<Stanza> * head = NULL;
	this->numStanze = this->numLivello + 2;
	setUpMappa();
	this->stanze = this->creazioneStanze(head);
	collegamentiPorte();
	creazioneGiocatore();
	Lista<mostro> * testa = NULL;
	this->mostri = this->creazioneMostri(testa);
}


Lista<Stanza> * livello::creazioneStanze(Lista<Stanza> * head){
		int count;
		int i;
		int grid;
		bool griglia[9];
		for(i = 0; i < 9 ; i++){
			griglia[i] = false;
		}
		for (count = 0; count < this->numStanze; count++) {
			grid = rand() % 9;
			if(!griglia[grid]){
				Stanza s(grid);
				head = insertCoda(s,head);
				s.stampaStanza(this->mappa);
				griglia[grid] = true;
			}else{
				count--;
			}
		}
		return head;
}

void livello::stampaLivello(){
	int y,x;
	for (y = 0; y < 45; y++) {
		for (x = 0; x < 135; x++) {
			cout << this->mappa[y][x];
		}
		cout << endl;
	}
}

void livello::collegamentiPorte(){
	int i, j;
	int randomRoom, randomDoor;
	int count;
	bool collegamento = false;
	if(this->numStanze == 2){
		Stanza s = getElemetI(0,this->stanze);
		Stanza random = getElemetI(1,this->stanze);
		porta porte1[4];
		s.getPorte(porte1);
		porta porte2[4];
		random.getPorte(porte2);
		coordinate start,end;
		start.x = porte2[0].x;
		start.y = porte2[0].y;
		end.x = porte1[0].x;
		end.y = porte1[0].y;
		collegamenti(this->mappa, start, end);
		porte2[0].conect = true;
		porte1[0].conect = true;
		s.setPorte(porte1);
		random.setPorte(porte2);
	}else{
	for (i = 0; i < this->numStanze; i++){
		Stanza s = getElemetI(i,this->stanze);
		for (j = 0; j < s.getNumPorte() ; ++j) {
			porta porte1[4];
			s.getPorte(porte1);
			if(!porte1[j].conect){
				count = 0;
				collegamento = false;
				while(count < 2 && !collegamento){
					randomRoom = rand() % this->numStanze;
					Stanza random = getElemetI(randomRoom,this->stanze);
					randomDoor = rand() % random.getNumPorte();
					porta porte2[4];
					random.getPorte(porte2);
					if(!porte2[randomDoor].conect && randomRoom != i){
						coordinate start,end;
						start.x = porte2[randomDoor].x;
						start.y = porte2[randomDoor].y;
						end.x = porte1[j].x;
						end.y = porte1[j].y;
						collegamenti(this->mappa, start, end);
						porte2[randomDoor].conect = true;
						porte1[j].conect = true;
						s.setPorte(porte1);
						random.setPorte(porte2);
						setElemetI(randomRoom,this->stanze,random);
						setElemetI(i,this->stanze,s);
						collegamento = true;
					}else{
						count++;
					}
				}
			}
		}

		}
	}
}

bool livello::checkPos(int x, int y, bool flag){
	char temp = this->mappa[y][x];
	if(flag){
		if (temp == '+' || temp == '#' ){
			return false;
		}else{
			return true;
		}
	}else{
		if (temp == '#' && temp == '\0' ){
			return false;
		}else{
			return true;
		}
	}

}

bool livello::findPlayer(coordinate player, coordinate mobb, int vista,bool &sopra,bool &sotto,bool &destra,bool &sinistra){
	int distanzaRigha = abs(mobb.x - player.x);
	int distanzaCol = abs(mobb.y - player.y);
	//righa controllo se è visibile
	if(distanzaRigha <= vista){
		//sinistra
		if(abs(((mobb.x-1) - player.x) < distanzaRigha) && checkPos(mobb.x-1,mobb.y,false)){
			sinistra = true;
			return true;
		}
		//destra
		else if(abs(((mobb.x+1) - player.x) < distanzaRigha) && checkPos(mobb.x+1,mobb.y,false)){
			destra = true;
			return true;
		}
	}
	//colonna controllo se è visibile
	else if(distanzaCol <= vista){
		//sotto
		if(abs(((mobb.y+1) - player.y) < distanzaCol) && checkPos(mobb.x,mobb.y+1,false)){
			sotto = true;
			return true;
		}
		//sopra
		else if(abs(((mobb.y-1) - player.y) < distanzaCol) && checkPos(mobb.x,mobb.y-1,false)){
			sopra = true;
			return true;
		}

	}else{
		return false;
	}
}

void livello::setUpMappa(){
	int x, y;
	for (y = 0; y < 45; y++) {
		for (x = 0; x < 135; x++) {
			this->mappa[y][x] = '\0';
		}
	}
}

void livello::aggiornaMappa(char input){
	//aggiornamento poszione dei mostri
	int i;
	int x,y;
	int xmobb,ymobb;
	bool sopra, sotto, destra, sinistra;
	bool isActive;
	coordinate coplayer;
	coordinate comostro;

	for(i = 0; i < this->numMostri; i++){
		mostro mostro = getElemetI(i,this->mostri);
		if(mostro.getVivo()){
			comostro.x = mostro.getposx();
			comostro.y = mostro.getposy();
			mostro.cancellaMobb(this->mappa);
			isActive = findPlayer(coplayer, comostro, mostro.getVista(),sopra,sotto,destra,sinistra);
			if(!isActive){
				sopra = checkPos(mostro.getposx(),mostro.getposy()-1,true);
				sotto = checkPos(mostro.getposx(),mostro.getposy()+1,true);
				destra = checkPos(mostro.getposx()+1,mostro.getposy(),true);
				sinistra = checkPos(mostro.getposx()-1,mostro.getposy(),true);
			}
			mostro.movemobb(isActive, sopra, sotto, destra, sinistra);
			setElemetI(i,this->mostri,mostro);
			mostro.stampamobb(this->mappa);

		}
	}
}

void livello::creazioneGiocatore(){
	Stanza s = getElemetI(0,this->stanze);
	this->giocatore.setPosizione(s.getX()+1,s.getY()+1);
	int x,y;
	this->giocatore.stampaGiocatore(this->mappa);
}

Lista<mostro> * livello::creazioneMostri(Lista<mostro> * testa){
	int x,y;
	int numstanza;
	Stanza s;
	for(numstanza = 1; numstanza < this->numStanze; numstanza++){
		if(numstanza<this->numLivello || rand()%2){
			s = getElemetI(numstanza,this->stanze);
			x = (rand() % (s.getLarghezza() - 2)) + s.getX() + 1;
			y = (rand() % (s.getAltezza() - 2)) + s.getY() + 1;
			mostro mostro(numLivello, x , y);
			mostro.stampamobb(this->mappa);
			testa = insertCoda(mostro,testa);
			this->numMostri++;
		}
	}
	return testa;

}

