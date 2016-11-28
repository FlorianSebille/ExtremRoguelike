#include "total.h"

int test_depl(MAP,int c,t_joueur* joueur){
		switch(c){
			case KEY_UP:
				if(MAP[joueur.x+1][joueur.y] == mur){
				}else{
					return 1;
				}
			case KEY_DOWN:
				if(MAP[joueur.x-1][joueur.y] == mur){
				}else{
					return 1;
				}
			case KEY_LEFT:
				if(MAP[joueur.x][joueur.y-1] == mur){
				}else{
					return 1;
				}
			case KEY_RIGHT:
				if(MAP[joueur.x][joueur.y+1] == mur){
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
				if(test_depl(MAP[joueur.x][joueur.y],c){
					MAP[joueur.x+1][joueur.y].lieu = personnage;
					MAP[joueur.x][joueur.y].lieu = sol;
					joueur.x+1;
				}
				break;
			case KEY_DOWN:
				if(test_depl(MAP[joueur.x][joueur.y],c){
					MAP[joueur.x-1][joueur.y].lieu = personnage;
					MAP[joueur.x][joueur.y].lieu = sol;
					joueur.x-1;
				}
				break;
			case KEY_LEFT:
				if(test_depl(MAP[x][y],c){
					MAP[joueur.x][joueur.y-1].lieu = personnage;
					MAP[joueur.x][joueur.y].lieu = sol;
					joueur.y-1;
				}
				break;
			case KEY_RIGHT:
				if(test_depl(MAP[joueur.x][joueur.y],c){
					MAP[joueur.x][joueur.y+1].lieu = personnage;
					MAP[joueur.x][joueur.y].lieu = sol;
					joueur.y+1;
				}
				break;
		}
	}
}
	
