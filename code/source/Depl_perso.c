#include "total.h"

int test_depl(t_celulle MAP[N][M],int c){
		switch(c){
			case KEY_UP:
			if(MAP[x+1][y] == mur){
			}else{
				return 1;
			}
			case KEY_DOWN:
			if(MAP[x-1][y] == mur){
			}else{
				return 1;
			}
			case KEY_LEFT:
			if(MAP[x][y-1] == mur){
			}else{
				return 1;
			}
			case KEY_RIGHT:
			if(MAP[x][y+1] == mur){
			}else{
				return 1;
			}
		}
}

void Depl_perso(t_celulle MAP[N][M],t_joueur joueur){
	//typedef struct joueur {char "nom";int x;int y;int STAGE;int LEVEL;int EXP;int HP;int ATT;int DEF;int FOOD} t_joueur;
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
			if(test_depl(MAP[x][y],c){
				MAP[x+1][y];
				joueur.x+1
			}
			break;
			case KEY_DOWN:
			if(test_depl(MAP[x][y],c){
				MAP[x-1][y];
				joueur.x-1
			}
			break;
			case KEY_LEFT:
			if(test_depl(MAP[x][y],c){
				MAP[x][y-1];
				joueur.y-1
			}
			break;
			case KEY_RIGHT:
			if(test_depl(MAP[x][y],c){
				MAP[x][y+1];
				joueur.y+1
			}
			break;
		}
	}
}