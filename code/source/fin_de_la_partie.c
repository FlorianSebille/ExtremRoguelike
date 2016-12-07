#include "total.h"

int fin_game(WINDOW *chat_Win,WINDOW *map_Win,WINDOW *stat_Win){
	int startx, starty, width, height;
	WINDOW *fin_Win;
	WINDOW *rejouer_Win;
	cbreak();
	keypad(stdscr,TRUE);
	timeout(0);
	int choix;
	height = 15;
	width = 90;
	startx = 39;
	starty = 2;
	effacer_fenetre(chat_Win);
  effacer_fenetre(map_Win);
	wborder(map_Win, ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ');
	wrefresh(map_Win);
	delwin(map_Win);
	fin_Win=create_newwin(height,width,starty,startx,"FIN");
	if(joueur.etat_avant == arriver && joueur.addcle == 1){
		mvwprintw(fin_Win,3,16,"         _  _  _       _ _     ______                    " );
    mvwprintw(fin_Win,4,16,"	(_)(_)(_)     | | |   (______)                   " );
    mvwprintw(fin_Win,5,16,"	 _  _  _ _____| | |    _     _ ___  ____  _____  " );
    mvwprintw(fin_Win,6,16," 	| || || | ___ | | |   | |   | / _ \\|  _ \\| ___ | " );
    mvwprintw(fin_Win,7,16," 	| || || | ____| | |   | |__/ / |_| | | | | ____| " );
    mvwprintw(fin_Win,8,16," 	\\______/|_____)\\_)_)  |_____/ \\___/|_| |_|_____)  " );
		mvwprintw(fin_Win,11,24,"Vous avez reussi a atteindre l'arriver avec la clé");


		mvwprintw(chat_Win,4,1,"				     OOOOOOO						 ");
		mvwprintw(chat_Win,5,1,"	       OOOOOOOOOOOOOOO				 ");
	  mvwprintw(chat_Win,6,1,"      OOOO  OOOOOOOOO  OOOO			 ");
    mvwprintw(chat_Win,7,1,"    OOOO      OOOOO      OOOO		 ");
    mvwprintw(chat_Win,8,1,"  OOOOOO  #   OOOOO  #   OOOOOO	 ");
    mvwprintw(chat_Win,9,1," OOOOOOOO    OOOOOOO    OOOOOOOO ");
    mvwprintw(chat_Win,10,1,"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
    mvwprintw(chat_Win,11,1,"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
    mvwprintw(chat_Win,12,1,"OO  OOOOOOOOOOOOOOOOOOOOOOOOO  OO");
		mvwprintw(chat_Win,13,1," OO  OOOOOOOOOOOOOOOOOOOOOOO  OO ");
    mvwprintw(chat_Win,14,1,"  OO   OOOOOOOOOOOOOOOOOOOO  OO	 ");
    mvwprintw(chat_Win,15,1,"   OOO    OOOOOOOOOOOOOOO   OO	 ");
	  mvwprintw(chat_Win,16,1,"     OOOO   OOOOOOOOO   OOOO		 ");
		mvwprintw(chat_Win,17,1,"        OOOO         OOOO				 ");
		mvwprintw(chat_Win,18,1,"		        OOOOOOOO					   ");

	}else if(mort == 1 || joueur.HP == 0){

		mvwprintw(fin_Win,3,16,"  _______                      _______                    " );
    mvwprintw(fin_Win,4,16," (_______)                    (_______)                   " );
    mvwprintw(fin_Win,5,16,"  _   ___ _____ ____  _____    _     _ _   _ _____  ____  " );
    mvwprintw(fin_Win,6,16," | | (_  (____ |    \\| ___ |  | |   | | | | | ___ |/ ___) " );
    mvwprintw(fin_Win,7,16," | |___) / ___ | | | | ____|  | |___| |\\ V /| ____| |     " );
    mvwprintw(fin_Win,8,16," \\______/\\_____|_|_|_|_____)   \\_____/  \\_/ |_____)_|      " );

		mvwprintw(fin_Win,11,27,"Dommage, il semblerait que vous etes mort");

		mvwprintw(chat_Win,4,5,"           uuuuuuu");
		mvwprintw(chat_Win,5,5,"      uu$$$$$$$$$$$uu");
		mvwprintw(chat_Win,6,5,"   uu$$$$$$$$$$$$$$$$$uu");
		mvwprintw(chat_Win,7,5,"  u$$$$$$$$$$$$$$$$$$$$$u");
		mvwprintw(chat_Win,8,5," u$$$$$$$$$$$$$$$$$$$$$$$u");
		mvwprintw(chat_Win,9,5,"u$$$$$$$$$$$$$$$$$$$$$$$$$u");
		mvwprintw(chat_Win,10,5,"u$$$$$$$$$$$$$$$$$$$$$$$$$u");
		mvwprintw(chat_Win,11,5,"u$$$$$$     $$$     $$$$$$u");
		mvwprintw(chat_Win,12,5," $$$$       u$u       $$$$");
		mvwprintw(chat_Win,13,5," $$$u       u$u       u$$$");
		mvwprintw(chat_Win,14,5," $$$u      u$$$u      u$$$");
		mvwprintw(chat_Win,15,5,"   $$$$uu$$$   $$$uu$$$$");
		mvwprintw(chat_Win,16,5,"    $$$$$$$     $$$$$$$ ");
		mvwprintw(chat_Win,17,5,"     u$$$$$$$u$$$$$$$u");
		mvwprintw(chat_Win,18,5,"      u$ $ $ $ $ $ $u");
		mvwprintw(chat_Win,19,5,"      $$u$ $ $ $ $u$$");
		mvwprintw(chat_Win,20,5,"       $$$$$u$u$u$$$");
		mvwprintw(chat_Win,21,5,"         $$$$$$$$$");
		mvwprintw(chat_Win,22,5,"           $$$$$");
	}
	wrefresh(fin_Win);
	wrefresh(chat_Win);
	height = 15;
	width = 90;
	startx = 39;
	starty = 18;
	rejouer_Win=create_newwin(height,width,starty,startx,"REJOUER");
	mvwprintw(rejouer_Win,4,30,"voulez vous rejouer ou quitter");
	mvwprintw(rejouer_Win,9,17,"LEFTWARDS ARROW: QUITTER");
	mvwprintw(rejouer_Win,9,52,"RIGHTWARDS ARROW: REJOUER");
	wrefresh(rejouer_Win);
	do{
		choix = getch();
	}while(choix != KEY_RIGHT && choix != KEY_LEFT);
	if(choix == KEY_RIGHT){
    effacer_fenetre(stat_Win);
    effacer_fenetre(chat_Win);
    effacer_fenetre(rejouer_Win);
		wborder(rejouer_Win, ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ');
		wrefresh(rejouer_Win);
		delwin(rejouer_Win);
		effacer_fenetre(fin_Win);
		wborder(fin_Win, ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ');
		wrefresh(fin_Win);
		delwin(fin_Win);
		mort = 0;
		height = 31;
    width = 90;
    starty = 2 ;
    startx = 39 ;
		map_Win=create_newwin(height,width,starty,startx,"Map");
	}
  if(choix == KEY_RIGHT){
    return 1;
  }else return 0;
}
