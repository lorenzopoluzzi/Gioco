/*
 * mobb.cpp
 *
 *  Created on: 18 ott 2017
 *      Author: turri
 */


#include "mobb.h"



//inizializzo le caratteristiche dei mobb
mostro::mostro(){
	this->atck = -1;
	this->life = -1;
	this->tipomobb = -1;
	this->vivo = false;
	this->x = -1;
	this->y = -1;
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

        this->vivo = true;          //se true è vivo

        this->x = x;
        this->y = y;

    }

int mostro::randomobb (int liv) {

    int randomobb;

        if (liv<3){

            randomobb=(rand()%2);      //è 0 o 1 perchè resto divisione per 2
        }

        else if (3<= liv <7) {


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

        this->life= false;
        return false;
    }

    else {return true;} ;

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
	mappa[y][x] = ' ';
}

void mostro::movemobb (bool moodmobb, bool sopra, bool sotto, bool destra, bool sinistra )  {
	int x,y;
	//activemobb move si muove segue il player
    if (moodmobb == true ) {
    	if(sopra){
    		x = this->x;
			y = this->y-1;
			this->setpos(x,y);

    	}else if(sotto){
    		x = this->x;
			y = this->y+1;
			this->setpos(x,y);
    	}else if(destra){
    		x = this->x+1;
			y = this->y;
			this->setpos(x,y);
    	}else if(sinistra){
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
    			x = this->x;
    			y = this->y-1;
    			this->setpos(x,y);
    			isMove = true;
    		}
    		//move bottom
    		else if(random == 1 && sotto){
    			x = this->x;
				y = this->y+1;
				this->setpos(x,y);
				isMove = true;
    		}
    		//move right
    		else if(random == 2 && destra){
    			x = this->x+1;
				y = this->y;
				this->setpos(x,y);
				isMove = true;
    		}
    		//move left
    		else if(random == 3 && sinistra){
    			x = this->x-1;
				y = this->y;
				this->setpos(x,y);
				isMove = true;
    		}
    	}

    };


}



