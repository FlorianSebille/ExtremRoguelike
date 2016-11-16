#include <ncurses.h>


/*fonction qui génère une fenêtre*/

WINDOW * create_newwin(int height, int width, int starty, int startx)
{
  WINDOW *local_win;

	local_win = newwin(height, width, starty, startx); /* newwin() créer la fenêtre */
  wborder(local_win, '*', '*', '*','*','*','*','*','*'); /* Création des bordures */
	wrefresh(local_win);		/* Affiche la fenêtre*/

	return local_win; /* Renvoi la fenêtre */
}

/* Fonction qui génère les fenêtres necessaires à notre RogueLike */

int GenWindow()
{

  WINDOW * F_win;
  WINDOW * S_win;
  WINDOW * T_win;


	int startxF, startyF, widthF, heightF;
  int startxS, startyS, widthS, heightS;
  int startxT, startyT, widthT, heightT;

	char ch;

	initscr();			/* On démarre le mode ncurses 		*/

	heightF = 50;
	widthF = 35;
	startyF = 2 ;	/* Dimensions et Position de la 1ère fenêtre */
	startxF = 10 ;

  heightS = 50;
	widthS = 180;
	startyS = 2 ;	/* Dimensions et Position de la 2ème fenêtre */
	startxS = 50 ;

  heightT = 50;
	widthT = 35;
	startyT = 2 ;	/* Dimensions et Position de la 3ème fenêtre */
	startxT = 235 ;

	printw("Press q to exit\n");
  refresh();
  F_win=create_newwin(heightF,widthF,startyF,startxF);
  S_win=create_newwin(heightS,widthS,startyS,startxS);
  T_win=create_newwin(heightT,widthT,startyT,startxT);
  while((ch = getch()) != 'q'){                         /* Tant que l'on appuie pas sur q */
    F_win=create_newwin(heightF,widthF,startyF,startxF);
    S_win=create_newwin(heightS,widthS,startyS,startxS);
    T_win=create_newwin(heightT,widthT,startyT,startxT);
  }

  endwin(); /* On revient à l'état initial du terminal */
  return 0;
}
