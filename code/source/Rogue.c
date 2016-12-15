/**
 * \file Rogue.c
 * \brief Programme principal du jeu.
 * \author LARDY Anthony
 * \author TROTTIER Arthur
 * \author SEBILLE Florian
 * \version 1.0.1
 */

#include "total.h"
/**
 * \fn int main
 * \fonction principale du jeu qui fait le déroulement de la partie
 */
int main(){
  initscr();
  noecho();
  curs_set(0);
  if(taille_terminal()){

    int startxF, startyF, widthF, heightF;/* Initialisation des variables pour la création de la 1ère fenêtre */
    int startxS, startyS, widthS, heightS;/* Initialisation des variables pour la création de la 2ème fenêtre */
    int startxT, startyT, widthT, heightT;/* Initialisation des variables pour la création de la 3ème fenêtre */

    char utilisateur;

    int compteur = 0;

    cheat = 0;
    nb_deplacement = 0;

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
    init_pair(7, COLOR_RED, COLOR_WHITE);
    init_pair(8, COLOR_GREEN, COLOR_WHITE);
    init_pair(9, COLOR_YELLOW, -1);

    int choix = Ask_Load_Save();
    F_win=create_newwin(heightF,widthF,startyF,startxF,"Profile");
    S_win=create_newwin(heightS,widthS,startyS,startxS,"Map");
    T_win=create_newwin(heightT,widthT,startyT,startxT,"Chat");
    if(choix == 'o'){

        srand(time(NULL));
        joueur.STAGE = 1;
        debut_game(S_win, T_win, F_win);
    }

    affichage(S_win);
    Win_Stat(F_win,widthF);
    ecrire_chat(T_win, 2);

    while(utilisateur != 'q' && utilisateur != 's' && (joueur.etat_avant != arriver || joueur.addcle != 1) && mort != 1 && joueur.HP != 0){

        utilisateur = Depl_perso(T_win);
        combat();
        if(joueur.STAGE > 1 && compteur%1000 == 0 && monstre.HP > 0){
            depl_monstre();
        }
        compteur++;
        affichage(S_win);
        Win_Stat(F_win,widthF);

        if(joueur.etat_avant == porte || joueur.etat_avant == uplevel){
        porte_escalier(T_win, S_win, F_win, utilisateur);
        }
        if((joueur.etat_avant == arriver && joueur.addcle == 1) || joueur.HP == 0){
          choix = fin_game(T_win,S_win,F_win);
          if(choix == 1){
            debut_game(S_win, T_win, F_win);
            affichage(S_win);
            Win_Stat(F_win,widthF);
          }
        }else if(joueur.etat_avant == arriver && joueur.addcle == 0 && joueur.STAGE == 5){
        	int i,j;
        	for(i = 1; i < x; i++){
        		for(j = 1; j < y; j++){
        			if(MAP[i][j].num_salle == nombre_salle-1 && MAP[i][j].lieu == sol){
        				MAP[i][j].lieu = mechant;
        				sleep(1);
                affichage(S_win);
        			}
        		}
        	}
            joueur.HP = 0;
            fin_game(T_win,S_win,F_win);
        }
    }
    if(utilisateur == 's'){
        addsauv();
    }

  }
  endwin();
}
