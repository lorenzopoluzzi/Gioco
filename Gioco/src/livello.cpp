/*
 * livello.cpp
 *
 *  Created on: 18 ott 2017
 *      Author: turri
 */


#include "livello.hpp"

livello::livello(){
	this->numLivello = -1;
	this->numStanze = -1;
	this->stanze = NULL;
	this->mostri = NULL;
	this->numMostri = -1;
	this->numOggetti = -1;
	this->oggetti = NULL;
	this->viewdestra = 0;
	this->viewsinistra = 0;
	this->viewsopra = 0;
	this->viewsotto = 0;
}

livello::livello(int numLivello){
	this->numLivello = numLivello;
	Lista<Stanza> * head = NULL;
	this->numStanze = this->numLivello + 2;
	if(this->numStanze > 9){
		this->numStanze = 9;
	}
	setUpMappa();
	this->stanze = this->creazioneStanze(head);
	collegamentiPorte();
	creazioneGiocatore();
	Lista<mostro> * testa = NULL;
	this->numMostri = 0;
	this->mostri = this->creazioneMostri(testa);
	this->numOggetti = (this->numLivello/2) +1;
	Lista<oggetto> * fronte = NULL;
	this->oggetti = this->creazioneOggetti(fronte);
	creazioneScale();
	this->viewdestra = 6;
	this->viewsinistra = -6;
	this->viewsotto = 6;
	this->viewsopra = -6;
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
	int liv,exp,hp,atck,xpl,ypl,gem;
	int minX,maX,minY,maxY;
	this->giocatore.getLivello(liv);
	this->giocatore.getEsperienza(exp);
	this->giocatore.getVita(hp);
	this->giocatore.getAttacco(atck);
	this->giocatore.getPosizione(xpl,ypl);
	this->giocatore.getGemma(gem);
	Stanza s = getElemetI(0,this->stanze);
	int plxIn = s.getX()+1;
	int plyIn = s.getY()+1;
	minX = plxIn + this->viewsinistra;
	if(minX < 0){
		minX = 0;
	}
	maX = plxIn + this->viewdestra;
	if(maX >= 135){
		maX = 134;
	}
	minY = plyIn + this->viewsopra;
	if(minY < 0){
		minY = 0;
	}
	maxY = plyIn + this->viewsotto;
	if(maxY >= 45){
		maxY = 44;
	}
	for (y = 0; y < 45; y++) {
		if(y >= minY && y <= maxY){
			for (x = 0; x < 135; x++) {
				if(x >= minX && x <= maX){
					cout << this->mappa[y][x];
				}else{
					cout << '\0';
				}

			}
		}else{
			for (x = 0; x < 135; x++) {
				cout << '\0';
			}
		}
		if(y == 1){
			cout << " __          ___    ____    ______   ";
		}else if(y == 2){
			cout << "/\\ \\       /'___`\\ /\\  _`\\ /\\__  _\\  ";
		}else if(y == 3){
			cout << "\\ \\ \\     /\\_\\ /\\ \\\\ \\ \\_\\ \\/_/\\ \\/  ";
		}else if(y == 4){
			cout << " \\ \\ \\    \\/_/// /__\\ \\ ,__/  \\ \\ \\  ";
		}else if(y == 5){
			cout << "  \\ \\ \\___   // /_\\ \\\\ \\ \\/    \\ \\ \\ ";
		}else if(y == 6){
			cout << "   \\ \\____| /\\______/ \\ \\_\\     \\ \\_\\ ";
		}else if(y == 7){
			cout << "    \\/___/  \\/_____/   \\/_/      \\/_/ ";
		}else if(y == 9){
			cout << "TARGET -> To win you have to collect 10 gems";
		}else if(y == 11){
			cout << "LEVEL GAME -> "<< this->numLivello+1;
		}
		else if(y == 13){
			while(x < 181){
				cout << "-";
				x++;
			}

		}
		else if(y == 14){
			cout << " |                  LEGEND";
			x = 162;
			while(x < 181){
				cout << " ";
				x++;
			}
			cout << "|";
		}else if(y == 15){
			cout << " |";
			x = 138;
			while(x < 181){
				cout << " ";
				x++;
			}
			cout << "|";
		}else if(y == 16){
			cout << " |         # - WALLS      + - DOORS/PATH";
			x = 176;
			while(x < 181){
				cout << " ";
				x++;
			}
			cout << "|";
		}else if(y == 17){
			cout << " |         O - TRAP-DOORS (LOWER LEVEL)";
			x = 175;
			while(x < 181){
				cout << " ";
				x++;
			}
			cout << "|";
		}else if(y == 18){
			cout << " |         H - STAIRS (HIGHER LEVEL)";
			x = 172;
			while(x < 181){
				cout << " ";
				x++;
			}
			cout << "|";
		}else if(y == 19){
			cout << " |         P - PLAYER      V - MOB 1";
			x = 172;
			while(x < 181){
				cout << " ";
				x++;
			}
			cout << "|";
		}else if(y == 20){
			cout << " |         W - MOB 2       X - MOB 3";
			x = 172;
			while(x < 181){
				cout << " ";
				x++;
			}
			cout << "|";
		}else if(y == 21){
			cout << " | ? - RANDOM OBJECT(HP,ATTACK,TRAP,GEM,EXP)";
			x = 180;
			while(x < 181){
				cout << " ";
				x++;
			}
			cout << "|";
		}else if(y == 22){
			cout << " |";
			x = 138;
			while(x < 181){
				cout << " ";
				x++;
			}
			cout << "|";
		}else if(y == 23){
			cout << " |                  COMAND";
			x = 162;
			while(x < 181){
				cout << " ";
				x++;
			}
			cout << "|";
		}else if(y == 24){
			cout << " |";
			x = 138;
			while(x < 181){
				cout << " ";
				x++;
			}
			cout << "|";
		}else if(y == 25){
			cout << " |       W - MOVE UP        S - MOVE DOWN";
			x = 177;
			while(x < 181){
				cout << " ";
				x++;
			}
			cout << "|";
		}else if(y == 26){
			cout << " |       A - MOVE LEFT      D - MOVE RIGHT";
			x = 178;
			while(x < 181){
				cout << " ";
				x++;
			}
			cout << "|";
		}else if(y == 27){
			cout << " |       J - ATTACK         L - PICK OBJECT";
			x = 179;
			while(x < 181){
				cout << " ";
				x++;
			}
			cout << "|";
		}else if(y == 28){
			cout << " |  K - GOING UP/DOWN STAIRS (LEVEL UP/DOWN) ";
			cout << "|";
		}else if(y == 29){
			while(x < 181){
				cout << "-";
				x++;
			}
		}




		cout << endl;
	}
	cout << "LEVEL -> "<< liv+1 << " EXP -> "<< exp << " HP -> "<< hp <<" ATTACK -> "<< atck <<" GEMS -> "<< gem <<"     POSITION PLAYER -> [" << xpl <<"," << ypl <<"] " ;
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
	if(x >= 0 && x < 135){
		if(y >= 0 && y < 45){
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
				if (temp == ' ' || temp == '+'){
					return true;
				}else{
					return false;
				}
			}
		}else {
			return false;
		}
	}else{
		return false;
	}
}

bool livello::findPlayer(coordinate player, coordinate mobb, int vista,bool &sopra,bool &sotto,bool &destra,bool &sinistra){
	int distanzaRigha = abs(mobb.x - player.x);
	int distanzaCol = abs(mobb.y - player.y);
	sopra = false;
	sotto = false;
	destra = false;
	sinistra = false;
	//righa controllo se è visibile
	if(distanzaRigha <= vista && distanzaCol <= vista){
		//destra
		if((abs((mobb.x+1) - player.x) < distanzaRigha) && checkPos(mobb.x+1,mobb.y,false)){
			destra = true;
			return true;
		}
		//sinistra
		if((abs((mobb.x-1) - player.x) < distanzaRigha) && checkPos(mobb.x-1,mobb.y,false)){
			sinistra = true;
			return true;
		}

		//sotto
		if((abs((mobb.y+1) - player.y) < distanzaCol) && checkPos(mobb.x,mobb.y+1,false)){
			sotto = true;
			return true;
		}
		//sopra
		if((abs((mobb.y-1) - player.y) < distanzaCol) && checkPos(mobb.x,mobb.y-1,false)){
			sopra = true;
			return true;
		}

		return true;

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
void livello::setPosGiocatore(){
	Stanza s = getElemetI(0,this->stanze);
	this->giocatore.setPosizione(s.getX()+1,s.getY()+1);
	int x,y;
	this->giocatore.getPosizione(x,y);
	this->mappa[y][x] = 'P';
}

Player livello::getPlayer(){
	return this->giocatore;
}

void livello::setPlayer(int hp, int attack, int gem, int exp, int liv){

	this->giocatore.setVita(hp);
	this->giocatore.setAttacco(attack);
	this->giocatore.setExp(exp);
	this->giocatore.setGemme(gem);
	this->giocatore.setLivello(liv);

}

int livello::aggiornaMappa(char input){
	//aggiornamento poszione dei mostri
	int i,j;
	int plx,ply;
	this->giocatore.getPosizione(plx,ply);
	bool sopra = false;
	bool sotto = false;
	bool destra = false;
	bool sinistra = false;
	bool isActive;
	bool flag = false;
	bool find = false;
	int atkpl;
	this->giocatore.getAttacco(atkpl);
	oggetto ogg;
	mostro mob;
	coordinate coplayer;
	coordinate comostro;
	if(input == 'l') {
		for(j=0; (j < this->numOggetti) && !find ; j++){
			ogg = getElemetI(j,this->oggetti);
			find = ogg.ricercaOgg(plx, ply);
			if(find){
				ogg.cancellaObject(this->mappa);
				this->giocatore.raccolgoOgg(ogg.getTipooggetto(), ogg.getValue());
				this->oggetti = deleteI(j,this->oggetti);
				this->numOggetti--;
			}
		}

	}else if(input == 'k'){
		int indice;
		find = ricercaScale(plx,ply,indice);
		if(find){
			return this->scale[indice].liv;
		}

	}else if(input == 'j'){
		for(j=0; (j < this->numMostri) && !find ; j++){
			mob = getElemetI(j,this->mostri);
			find = mob.ricercamobb(plx, ply);
			if(find){
				if(mob.setvita(atkpl)){
					this->giocatore.addEsperienza(mob.getattacco()+(this->numLivello*5));
					if(mob.dropGemma(this->numLivello)){
						this->giocatore.pickGemma();
					}
					mob.cancellaMobb(this->mappa);
					this->mostri = deleteI(j,this->mostri);
					this->numMostri--;

				}else {
					setElemetI(j,this->mostri,mob);
					this->giocatore.vieniColpito(mob.getattacco());


				}

			}
		}
	}else {
		this->giocatore.cancellaPlayer(this->mappa);
		flag = this->giocatore.getMove(input, this->mappa);
		this->visibleMappa();
		this->giocatore.stampaGiocatore(this->mappa);
	}

	if(flag){
		for(i = 0; i < this->numMostri; i++){
			mostro mostro = getElemetI(i,this->mostri);
			comostro.x = mostro.getposx();
			comostro.y = mostro.getposy();
			this->giocatore.getPosizione(plx,ply);
			coplayer.x = plx;
			coplayer.y = ply;
			mostro.cancellaMobb(this->mappa);
			isActive = findPlayer(coplayer, comostro, mostro.getVista(),sopra,sotto,destra,sinistra);
			if(!isActive){
				sopra = checkPos(mostro.getposx(),mostro.getposy()-1,true);
				sotto = checkPos(mostro.getposx(),mostro.getposy()+1,true);
				destra = checkPos(mostro.getposx()+1,mostro.getposy(),true);
				sinistra = checkPos(mostro.getposx()-1,mostro.getposy(),true);
			}
			mostro.movemobb(isActive, sopra, sotto, destra, sinistra, this->mappa);
			setElemetI(i,this->mostri,mostro);
			mostro.stampamobb(this->mappa);


		}
	}
	return -1;
}

void livello::creazioneGiocatore(){
	Stanza s = getElemetI(0,this->stanze);
	this->giocatore.setPosizione(s.getX()+1,s.getY()+1);
	this->giocatore.stampaGiocatore(this->mappa);
}

Lista<mostro> * livello::creazioneMostri(Lista<mostro> * testa){
	int x,y;
	int numstanza;
	Stanza s;
	for(numstanza = 1; numstanza < this->numStanze; numstanza++){
		if(numstanza < this->numLivello){
			s = getElemetI(numstanza,this->stanze);
			x = (rand() % (s.getLarghezza() - 2)) + s.getX() + 1;
			y = (rand() % (s.getAltezza() - 2)) + s.getY() + 1;
			mostro mostro(numLivello, x , y);
			mostro.stampamobb(this->mappa);
			testa = insertCoda(mostro,testa);
			this->numMostri++;
		}
		else if(rand()%2){
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

void livello::creazioneScale(){
	int x,y;
	int i = 0;
	bool correct;

	while(i < 2){
		if(i==0){
			Stanza s = getElemetI(this->numStanze-1, this->stanze);
			x = (rand() % (s.getLarghezza() - 2)) + s.getX() + 1;
			y = (rand() % (s.getAltezza() - 2)) + s.getY() + 1;
			correct = this->checkPos(x,y,true);
			if(correct){
				this->scale[i].x = x;
				this->scale[i].y = y;
				this->scale[i].liv = this->numLivello+1;
				this->mappa[y][x] = 'H';
				if(this->numLivello == 0){
					i = 2;
				}else{
					i++;
				}
			}

		}else if(this->numLivello != 0){
			Stanza s = getElemetI(0, this->stanze);
			x = (rand() % (s.getLarghezza() - 2)) + s.getX() + 1;
			y = (rand() % (s.getAltezza() - 2)) + s.getY() + 1;
			correct = this->checkPos(x,y,true);
			if(correct){
				this->scale[i].x = x;
				this->scale[i].y = y;
				this->scale[i].liv = this->numLivello-1;
				this->mappa[y][x] = 'O';
				i++;

			}
		}

	}
}

bool livello::ricercaScale(int x,int y, int &indice){
	bool result = false;
	int i = 0;
	int j = 0;
	int xpl;
	int ypl;
	while (!result && i < 2 ){
		indice = i;
		j = 0;
		while(!result && j < 4){
			xpl = x;
			ypl = y;

			if(j == 0){
				xpl = x - 1;
			}else if(j == 1){
				xpl = x + 1;
			}else if(j == 2){
				ypl = y - 1;
			}else if(j == 3){
				ypl = y + 1;
			}
			if(this->scale[i].x == xpl && this->scale[i].y == ypl){
				result = true;
			}
			j++;
		}
		i++;
	}
	return result;
}

void livello::visibleMappa(){
	Stanza s = getElemetI(0,this->stanze);
	int plxIn = s.getX()+1;
	int plyIn = s.getY()+1;
	int xpl,ypl;
	this->giocatore.getPosizione(xpl,ypl);
	int distanzaRigha = xpl - plxIn;
	int distanzaCol = ypl - plyIn;

	if(distanzaRigha < 0){
		distanzaRigha = distanzaRigha -6;
		if(distanzaRigha < this->viewsinistra){
			this->viewsinistra = distanzaRigha;
		}
	}else{
		distanzaRigha = distanzaRigha +6;
		if(distanzaRigha > this->viewdestra){
			this->viewdestra = distanzaRigha;
		}
	}

	if(distanzaCol < 0){
		distanzaCol = distanzaCol -6;
		if(distanzaCol < this->viewsopra){
			this->viewsopra = distanzaCol;
		}
	}else{
		distanzaCol = distanzaCol +6;
		if(distanzaCol > this->viewsotto){
			this->viewsotto = distanzaCol;
		}
	}

}


