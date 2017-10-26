//============================================================================
// Name        : Gioco.cpp
// Author      : turro
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
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
	srand(time(0));
	int numLivello = 0;
	int truelevel = 0;
	//system("cls");
	Lista<livello> * livelli = NULL;
	livello l1(truelevel);
	l1.stampaLivello();
	livelli = insertCoda(l1,livelli);
	numLivello++;

	while(true){
		int changeLev;
		livello lev = getElemetI(truelevel,livelli);
		input = getch();
		system("cls");
		changeLev = lev.aggiornaMappa(input);
		setElemetI(truelevel,livelli,lev);

		if(changeLev != -1){
			truelevel = changeLev;
			if(changeLev < numLivello){
				livello defaultlev = getElemetI(changeLev,livelli);
				defaultlev.stampaLivello();
				cout << endl;
				cout << "" << changeLev;
			}else{
				livello defaultlev(changeLev);
				livelli = insertCoda(defaultlev,livelli);
				numLivello++;
				defaultlev.stampaLivello();
				cout << endl;
				cout << "" << changeLev;
			}
		}else{
			lev.stampaLivello();
			cout << endl;
			cout << "" << changeLev;
		}

	}
}

