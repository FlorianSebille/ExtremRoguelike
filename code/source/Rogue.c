#include "total.h"

int main(){
  initscr();
  noecho();
  if(taille_terminal()){
    int startxF, startyF, widthF, heightF;
    int startxS, startyS, widthS, heightS;
    int startxT, startyT, widthT, heightT;
    int ligne = 1;
    char utilisateur;
    int compteur = 0;
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
    init_pair(9, COLOR_YELLOW, COLOR_BLACK);

    int choix = Ask_Load_Save();
    
    F_win=create_newwin(heightF,widthF,startyF,startxF,"Profile");
    S_win=create_newwin(heightS,widthS,startyS,startxS,"Map");
    T_win=create_newwin(heightT,widthT,startyT,startxT,"Chat");
    if(choix == KEY_RIGHT){

        srand(time(NULL));
        joueur.STAGE = 1;
        init_map(S_win);
        Placer_uplevel(S_win);
        Placer_perso(S_win);
        Placer_food(S_win);
        stage_cle = aleat(2,5);
        stage_medikit = aleat(2,5);
        joueur.SALLE = 1;
        joueur.LEVEL = 1;
        joueur.EXP = 1;
        joueur.HP = 200;
        joueur.ATT = 5;
        joueur.DEF = 12;
        joueur.FOOD = 10;
        ecrire_chat(T_win, 2);
    }
        affichage(S_win);
        Win_Stat(F_win,widthF);
    while(utilisateur != 'q' && utilisateur != 's' && (joueur.etat_avant != arriver || joueur.addcle != 1) && mort != 1 && joueur.HP != 0){
        utilisateur = Depl_perso(T_win);
        if(joueur.STAGE > 1 && (compteur%900) == 0 && monstre.HP > 0){
            depl_monstre(S_win);
            combat();
        }
        compteur++;    
        wrefresh(F_win);
        affichage(S_win);
        Win_Stat(F_win,widthF);
        if(joueur.etat_avant == porte || joueur.etat_avant == uplevel){
        porte_escalier(T_win, S_win, utilisateur);
        }
        if((joueur.etat_avant == arriver && joueur.addcle == 1) || mort == 1 || joueur.HP == 0){
          choix = fin_game(T_win,S_win,F_win);
          if(choix == 1){
            S_win=create_newwin(heightS,widthS,startyS,startxS,"Map");
            srand(time(NULL));
            joueur.STAGE = 1;
            init_map(S_win);
            Placer_uplevel(S_win);
            Placer_perso(S_win);
            Placer_piege(S_win);
            Placer_food(S_win);
            stage_cle = aleat(2,5);
            stage_medikit = aleat(2,5);
            joueur.SALLE = 1;
            joueur.LEVEL = 1;
            joueur.EXP = 1;
            joueur.HP = 20;
            joueur.ATT = 5;
            joueur.DEF = 12;
            joueur.FOOD = 10;
            joueur.addcle = 0;
            ecrire_chat(T_win, 2);
          }
        }else if(joueur.etat_avant == arriver && joueur.addcle == 0){
        	int i,j;
        	for(i = 0; i < x; i++){
        		for(j = 0; j < y; j++){
        			if(joueur.SALLE == MAP[i][j].num_salle && MAP[i][j].lieu == sol){
        				MAP[i][j].lieu = mechant;
        				sleep(1);
        			}
        		}
        	}
        }
    }
    if(utilisateur == 's'){
        addsauv();
    }

  }
  endwin();
}
