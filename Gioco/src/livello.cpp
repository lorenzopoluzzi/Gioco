/*
 * livello.cpp
 *
 *  Created on: 18 ott 2017
 *      Author: turri
 */


#include "Livello.hpp"


livello::livello(){
	this->numLivello = -1;
	this->numStanze = -1;
	this->stanze = NULL;
	this->mostri = NULL;
	this->numMostri = -1;
	this->numOggetti = -1;
	this->oggetti = NULL;
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
	this->numOggetti = (this->numLivello/2) +1;
	Lista<oggetto> * fronte = NULL;
	this->oggetti = this->creazioneOggetti(fronte);
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
	for (i = 0; i < this->numStanze; i++){
		Stanza s = getElemetI(i,this->stanze);
		for (j = 0; j < s.getNumPorte() ; ++j) {
			porta porte1[4];
			s.getPorte(porte1);
			if(!porte1[j].conect){
				count = 0;
				collegamento = false;
				while(!s.getConect() || (count < 3 && !collegamento)){
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
						if(random.getNumPorte() != 1){
							porte2[randomDoor].conect = true;
						}
						if(s.getNumPorte() != 1){
							porte1[j].conect = true;
						}
						s.setPorte(porte1);
						random.setPorte(porte2);
						s.setConect(true);
						random.setConect(true);
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

bool livello::checkPos(int x, int y, bool flag){
	char temp = this->mappa[y][x];
	//situazione statica o di creazione
	if(flag){
		if (temp != ' '){
			return false;
		}else{
			return true;
		}
	}
	//situazione di movimento o inseguimento
	else {
		if (temp != ' ' || temp != '+'){
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

	}
		return false;

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
		if(rand()%2){
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

Lista<oggetto> * livello::creazioneOggetti(Lista<oggetto> * fronte){
	int x,y;
	int count;
	int numstanza;
	bool correct;
	Stanza s;
	for(count = 0; count < this->numOggetti; count++){
		numstanza = rand()%this->numStanze;
		s = getElemetI(numstanza,this->stanze);
		x = (rand() % (s.getLarghezza() - 2)) + s.getX() + 1;
		y = (rand() % (s.getAltezza() - 2)) + s.getY() + 1;
		correct = this->checkPos(x,y,true);
		if(correct){
			oggetto oggetto(numLivello, x , y);
			oggetto.stampaObject(this->mappa);
			fronte = insertCoda(oggetto,fronte);
		}else{
			count--;
		}
	}
	return fronte;
}

