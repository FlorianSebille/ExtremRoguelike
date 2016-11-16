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


	heightF = (int) LINES * 0.85;
	widthF = (int) COLS * 0.12;
	startyF = 2 ;	/* Dimensions et Position de la 1ère fenêtre */
	startxF = (int) COLS * 0.03 ;

  heightS = (int) LINES * 0.85;
	widthS = (int) COLS * 0.6;
	startyS = 2 ;	/* Dimensions et Position de la 2ème fenêtre */
	startxS = (int) COLS * 0.17 ;

  heightT = (int) LINES * 0.85;
	widthT = (int) COLS * 0.12;
	startyT = 2 ;	/* Dimensions et Position de la 3ème fenêtre */
	startxT = (int) COLS * 0.795 ;

	printw("Press q to exit\n");
  printw("Nombre de lignes: %i, Nombre de colonnes: %i\n",LINES,COLS);
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
