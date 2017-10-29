//============================================================================
// Name        : Gioco.cpp
// Author      : turro
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include "conio.h"
#include <time.h>

#include "livello.hpp"
using namespace std;

int main() {
	char input;
	bool fine = false;
	bool vittoria = false;
	srand(time(0));
	int numLivello = 0;
	int truelevel = 0;
	system("cls");
	Lista<livello> * livelli = NULL;
	livello l1(truelevel);
	l1.stampaLivello();
	livelli = insertCoda(l1,livelli);
	numLivello++;
	Player g1;
	int liv;
	int hp;
	int exp;
	int gemme;
	int attack;

	while(!fine){
		int changeLev;
		livello lev = getElemetI(truelevel,livelli);
		input = getch();
		system("cls");
		changeLev = lev.aggiornaMappa(input);
		setElemetI(truelevel,livelli,lev);
		lev.getPlayer().getAttacco(attack);
		lev.getPlayer().getVita(hp);
		lev.getPlayer().getEsperienza(exp);
		lev.getPlayer().getGemma(gemme);
		lev.getPlayer().getLivello(liv);

		if(gemme == 10){
			fine = true;
			vittoria = true;
		}
		if(hp <= 0){
			fine = true;
		}
		if(!fine){
			if(changeLev != -1){
				truelevel = changeLev;
				if(changeLev < numLivello){
					livello defaultlev = getElemetI(changeLev,livelli);
					defaultlev.setPlayer(hp,attack,gemme,exp,liv);
					setElemetI(changeLev,livelli,defaultlev);
					defaultlev.stampaLivello();
				}else{
					livello defaultlev(changeLev);
					defaultlev.setPlayer(hp,attack,gemme,exp,liv);
					livelli = insertCoda(defaultlev,livelli);
					numLivello++;
					defaultlev.stampaLivello();
				}
			}else{
				lev.stampaLivello();
			}
		}
	}

	return 0;
}

