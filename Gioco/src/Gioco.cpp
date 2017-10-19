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
#include <conio.h>
#include "Livello.h"
#include <time.h>
using namespace std;

int main() {
	char input;
	srand(time(NULL));


	system("cls");
	livello l1(4);
	l1.stampaLivello();

	while(true)
	{
		input = getch();

		system("cls");
		l1.aggiornaMappa('1');
		l1.stampaLivello();
	}
}
