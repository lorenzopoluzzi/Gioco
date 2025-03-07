/*
 * mobb.cpp
 *
 *  Created on: 18 ott 2017
 *      Author: turri
 */


#include "mobb.hpp"



//inizializzo le caratteristiche dei mobb
mostro::mostro(){
	this->atck = -1;
	this->life = -1;
	this->tipomobb = -1;
	this->vivo = false;
	this->x = -1;
	this->y = -1;
	this->vista = -1;
	this->car = ' ';
}

mostro::mostro (int liv, int x, int y) {

    this->tipomobb = randomobb (liv);

        if (tipomobb==0) {

            this->atck = 10 + (liv*2);
            this->life = 25 + (liv*5);
            this->vista = 3;


        }

        else if (tipomobb==1) {

            this->atck = 15 + (liv*2);
            this->life = 35 + (liv*5);
            this->vista = 4;

        }

        else  if (tipomobb==2) {

            this->atck = 25 + (liv*2);
            this->life = 50 + (liv*5);
            this->vista = 5;

        }

        this->vivo = true;          //se true � vivo

        this->car = ' ';
        this->x = x;
        this->y = y;

    }

int mostro::randomobb (int liv) {

    int randomobb;

        if (liv<3){

            randomobb=(rand()%2);      //� 0 o 1 perch� resto divisione per 2
        }

        else if (liv >= 3 && liv < 7) {


            randomobb=(rand()%2)+1;

        }

        else {

            randomobb= 2;

        }
    return randomobb;
}


bool mostro::setvita (int atckpl) {

    this->life= this->life - atckpl;

    if (this->life <= 0) {

    	this->vivo = false;

        return true;
    }

    else {

    	return false;

    }

}


int mostro::getvita () {

    return (this->life);

}


int mostro::getattacco () {

    return (this->atck);

}

void mostro::setpos (int ics ,int ipsilon ) {

    x= ics;
    y= ipsilon;

}

int mostro::getposx () {
    return (this->x);
}

int mostro::getposy () {
    return (this->y);
}

bool mostro::getVivo(){
	return(this->vivo);
}

int mostro::getVista(){
	return(this->vista);
}

void mostro::stampamobb (char mappa[45][135]) {

    if (tipomobb == 0) {

        mappa[y][x] = 'V';

    } else if (tipomobb == 1) {

        mappa[y][x] = 'W';

    } else if (tipomobb == 2) {

        mappa[y][x] = 'X';

    }
}

void mostro::cancellaMobb( char mappa [45][135]){
	mappa[y][x] = this->car;
}

void mostro::movemobb (bool moodmobb, bool sopra, bool sotto, bool destra, bool sinistra, char mappa[45][135] )  {
	int x,y;
	//activemobb move si muove segue il player
    if (moodmobb == true ) {
    	if(sopra){
    		this->car = mappa[this->y-1][this->x];
    		x = this->x;
    		y = this->y-1;
    		this->setpos(x,y);

    	}else if(sotto){
    		this->car = mappa[this->y+1][this->x];
    		x = this->x;
    		y = this->y+1;
    		this->setpos(x,y);
    	}else if(destra){
    		this->car = mappa[this->y][this->x+1];
    		x = this->x+1;
    		y = this->y;
    		this->setpos(x,y);
    	}else if(sinistra){
    		this->car = mappa[this->y][this->x-1];
    		x = this->x-1;
    		y = this->y;
    		this->setpos(x,y);
    	}

    }
    //passivemobb move si muove in modo random
    else {
    	bool isMove = false;
    	int random;
    	while(!isMove){
    		random = rand()%4;
    		//move top
    		if(random == 0 && sopra){
    			this->car = mappa[this->y-1][this->x];
    			x = this->x;
    			y = this->y-1;
    			this->setpos(x,y);
    			isMove = true;
    		}
    		//move bottom
    		else if(random == 1 && sotto){
    			this->car = mappa[this->y+1][this->x];
    			x = this->x;
				y = this->y+1;
				this->setpos(x,y);
				isMove = true;
    		}
    		//move right
    		else if(random == 2 && destra){
    			this->car = mappa[this->y][this->x+1];
    			x = this->x+1;
				y = this->y;
				this->setpos(x,y);
				isMove = true;
    		}
    		//move left
    		else if(random == 3 && sinistra){
    			this->car = mappa[this->y][this->x-1];
    			x = this->x-1;
				y = this->y;
				this->setpos(x,y);
				isMove = true;
    		}
    	}

    }


}

bool mostro::ricercamobb(int x, int y){
	int i = 0;
	int xpl,ypl;
	bool result = false;
	while(!result && i<4){
		if(i == 0){
			ypl = y;
			xpl = x - 1;
		}else if(i == 1){
			ypl = y;
			xpl = x + 1;
		}else if(i == 2){
			xpl = x;
			ypl = y - 1;
		}else if(i == 3){
			xpl = x;
			ypl = y + 1;
		}
		if(xpl == this->x && ypl == this->y){
				result = true;
		}
		i++;
	}

	return result;
}

bool mostro::dropGemma(int liv){
	bool drop = false;
	int random = rand()%10 + liv/2;
	if(random >=7){
		drop = true;
	}
	return drop;
}
