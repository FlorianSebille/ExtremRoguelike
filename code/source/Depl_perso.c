#include "total.h"

void test_depl(

void Depl_perso(t_celulle MAP[N][M]){
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
			if(test_depl(c){
				MAP[x+1][y];
				joueur.x+1
			}
			break;
			case KEY_DOWN:
			if(test_depl(c){
				MAP[x-1][y];
				joueur.x-1
			}
			break;
			case KEY_LEFT:
			if(test_depl(c){
				MAP[x][y-1];
				joueur.y-1
			}
			break;
			case KEY_RIGHT:
			if(test_depl(c){
				MAP[x][y+1];
				joueur.y+1
			}
			break;
		}
	}
}