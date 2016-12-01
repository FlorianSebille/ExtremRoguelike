#include "total.h"

int main(){
  initscr();
  noecho();
  if(taille_terminal()){
    int startxF, startyF, widthF, heightF;
    int startxS, startyS, widthS, heightS;
    int startxT, startyT, widthT, heightT;
    int ligne = 1;
    int utilisateur = 0;

    WINDOW * F_win;
    WINDOW * S_win;
    WINDOW * T_win;

    heightF = 31;   /* Dimensions et Position de la 1ère fenêtre */
    widthF = 30;
    startyF = 2 ;
    startxF = 5 ;

    heightS = 31;   /* Dimensions et Position de la 2ème fenêtre */
    widthS = 90;
    startyS = 2 ;
    startxS = 39 ;

    heightT = 31;    /* Dimensions et Position de la 3ème fenêtre */
    widthT = 36;
    startyT = 2 ;
    startxT = 134 ;

    refresh();
    start_color();
    use_default_colors();
    init_pair(1, COLOR_RED, -1);
  	init_pair(2, COLOR_GREEN, -1);
    init_pair(3, COLOR_BLUE, COLOR_WHITE);
    init_pair(4, COLOR_BLACK, COLOR_WHITE);
    init_pair(5, COLOR_CYAN, COLOR_WHITE);
    init_pair(6, COLOR_WHITE, COLOR_CYAN);
    int choix = Ask_Load_Save();
   if(choix == KEY_LEFT){
        choix = Charger_Sauvegarde();
    }
    if(choix == KEY_RIGHT){
        F_win=create_newwin(heightF,widthF,startyF,startxF,"Profile");
        S_win=create_newwin(heightS,widthS,startyS,startxS,"Map");
        T_win=create_newwin(heightT,widthT,startyT,startxT,"Chat");

        Win_Stat(F_win,widthF);
        wrefresh(F_win);

        srand(time(NULL));
        init_map();
        Placer_uplevel(MAP, S_win);
        Placer_perso(MAP, S_win);
        affichage(MAP,S_win);
    }
    while (utilisateur != 'q') {
      utilisateur = Depl_perso(MAP, &joueur, &ligne,T_win);
      affichage(MAP,S_win);
    }
  }
  endwin();
}
