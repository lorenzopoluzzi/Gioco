/*
 * utility.cpp
 *
 *  Created on: 18 ott 2017
 *      Author: turri
 */

#include "livello.hpp"


int aggiungiVicino(char  mappa[ALTEZZA][LARGHEZZA], Lista<coordinate> * frontiere, coordinate vieneDa [ALTEZZA][LARGHEZZA], int x, int y, int count){
	coordinate coord;

	if (y > 0 && vieneDa[y - 1][x].y < 0 && controlloPos(mappa, y - 1, x)){
			coord.x = x;
			coord.y = y - 1;
			frontiere = insertCoda(coord, frontiere);
	        count++;
	        vieneDa[y - 1][x].y = y;
	        vieneDa[y - 1][x].x = x;
	}
	if (y < (ALTEZZA - 1) && vieneDa[y + 1][x].y < 0 && controlloPos(mappa, y + 1, x)){
		coord.x = x;
		coord.y = y + 1;
		frontiere = insertCoda(coord, frontiere);
		count++;
		vieneDa[y + 1][x].y = y;
		vieneDa[y + 1][x].x = x;

	}
	if (x < (LARGHEZZA - 1) && vieneDa[y][x + 1].y < 0 && controlloPos(mappa, y, x + 1)){
		coord.x = x + 1;
		coord.y = y;
		frontiere = insertCoda(coord, frontiere);
		count++;
		vieneDa[y][x + 1].y = y;
		vieneDa[y][x + 1].x = x;
	}

	// west
	if (x > 0 && vieneDa[y][x - 1].y < 0 && controlloPos(mappa, y, x - 1)){
		coord.x = x - 1;
		coord.y = y;
		frontiere = insertCoda(coord, frontiere);
		count++;
		vieneDa[y][x - 1].y = y;
		vieneDa[y][x - 1].x = x;
	}

	    return count;
}

bool controlloPos(char  mappa[ALTEZZA][LARGHEZZA], int y, int x){
	char temp = mappa[y][x];
	if (temp == ' ' || temp == '#' ){
		return false;
	}else{
		return true;
	}
}

void collegamenti(char  mappa[ALTEZZA][LARGHEZZA], coordinate start, coordinate end){

	int i, j;
	int x, y;
	int tempY;
	int frontiereIndice = 0;
	int frontiereCount = 0;
	bool flag = false;

	Lista<coordinate> * frontiere = NULL;
	coordinate vieneDa [ALTEZZA][LARGHEZZA];

	for (i = 0; i < ALTEZZA; i++){
		for(j = 0; j < LARGHEZZA; j++){
			vieneDa[i][j].x = -1;
			vieneDa[i][j].y = -1;
		}
	}

	vieneDa[start.y][start.x].x = -9;
	vieneDa[start.y][start.x].y = -9;

	frontiere = insertCoda(start, frontiere);
	frontiereCount++;

	 while (frontiereIndice < frontiereCount && !flag){
		 x = getElemetI(frontiereIndice, frontiere).x;
		 y = getElemetI(frontiereIndice, frontiere).y;

		 frontiereIndice++;
		 if(y == end.y && x == end.x){
			 flag = true;
		 }else{
			 frontiereCount = aggiungiVicino(mappa, frontiere, vieneDa, x, y, frontiereCount);
		 }

	 }
		 y = end.y;
		 x = end.x;

		 while (y != start.y || x != start.x)
		 {
			 tempY = y;
			 y = vieneDa[tempY][x].y;
			 x = vieneDa[tempY][x].x;
			 mappa[y][x] = '+';
		 }
		 cancellaLista(frontiere);
}

