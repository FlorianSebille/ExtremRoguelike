#include "total.h"

int test_depl(MAP,int c,t_joueur* joueur){
		switch(c){
			case KEY_UP:
				if(MAP[joueur.positionx+1][joueur.positiony] == mur){
				}else{
					return 1;
				}
			case KEY_DOWN:
				if(MAP[joueur.positionx-1][joueur.positiony] == mur){
				}else{
					return 1;
				}
			case KEY_LEFT:
				if(MAP[joueur.positionx][joueur.positiony-1] == mur){
				}else{
					return 1;
				}
			case KEY_RIGHT:
				if(MAP[joueur.positionx][joueur.positiony+1] == mur){
				}else{
					return 1;
				}
		}
}

void Depl_perso(MAP,t_joueur* joueur){
	initscr();
	noecho();
	cbreak();
	keypad(stdscr,TRUE);
   	timeout(0);
   	int c;
	c = getch();
	if(c!=ERR){
		switch(c){
			case KEY_UP:
				if(test_depl(MAP[joueur.positionx][joueur.positiony],c){
					MAP[joueur.positionx+1][joueur.positiony].lieu = personnage;
					MAP[joueur.positionx][joueur.positiony].lieu = sol;
					joueur.positionx+1;
				}
				break;
			case KEY_DOWN:
				if(test_depl(MAP[joueur.positionx][joueur.positiony],c){
					MAP[joueur.positionx-1][joueur.positiony].lieu = personnage;
					MAP[joueur.positionx][joueur.positiony].lieu = sol;
					joueur.positionx-1;
				}
				break;
			case KEY_LEFT:
				if(test_depl(MAP[x][y],c){
					MAP[joueur.positionx][joueur.positiony-1].lieu = personnage;
					MAP[joueur.positionx][joueur.positiony].lieu = sol;
					joueur.positiony-1;
				}
				break;
			case KEY_RIGHT:
				if(test_depl(MAP[joueur.positionx][joueur.positiony],c){
					MAP[joueur.positionx][joueur.positiony+1].lieu = personnage;
					MAP[joueur.positionx][joueur.positiony].lieu = sol;
					joueur.positiony+1;
				}
				break;
		}
	}
}
	
