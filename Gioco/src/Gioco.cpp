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
#include <time.h>

#include "livello.hpp"
using namespace std;

int main() {
	string input;
	srand(time(0));
	int i = 0;

	//system("cls");
	livello l1(i);
	l1.stampaLivello();

	while(true)
	{
		input = getch();
		i++;
		system("cls");
		livello l1(i);
		l1.stampaLivello();

	}
}
