#include "total.h"

void porte_escalier(WINDOW *chatfenetre,WINDOW *mapfenetre, int utilisateur){

  int choix = 0;
  int dep_reussi = 0;

  cbreak();
	keypad(stdscr,TRUE);
  timeout(0);

  if (joueur.etat_avant == porte){
    mvwprintw(chatfenetre,5,1,"voulez vous changer de salle ?");
    wattron(chatfenetre, COLOR_PAIR(2));
    mvwprintw(chatfenetre,7,1,"oui: appuier sur o");
    wattroff(chatfenetre,COLOR_PAIR(2));
    wattron(chatfenetre, COLOR_PAIR(1));
    mvwprintw(chatfenetre,9,1,"non: appuier sur n");
    wattroff(chatfenetre,COLOR_PAIR(1));
  }else if (joueur.etat_avant == uplevel){
    mvwprintw(chatfenetre,5,1,"voulez vous changer de stage ?");
    wattron(chatfenetre, COLOR_PAIR(2));
    mvwprintw(chatfenetre,7,1,"oui: appuier sur o");
    wattroff(chatfenetre,COLOR_PAIR(2));
    wattron(chatfenetre, COLOR_PAIR(1));
    mvwprintw(chatfenetre,9,1,"non: appuier sur n");
    wattroff(chatfenetre,COLOR_PAIR(1));
  }
  wrefresh(chatfenetre);
  int i = 0;
  do{
    choix = getch();
  }while (choix != 'n' && choix != 'o' && choix != '9');

  switch (choix) {

    case 'o': if (joueur.etat_avant == porte){

                      MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                      int temp_coordo_x = MAP[joueur.coordo_x][joueur.coordo_y].xb;
                      int temp_coordo_y = MAP[joueur.coordo_x][joueur.coordo_y].yb;
                      joueur.coordo_x = temp_coordo_x;
                      joueur.coordo_y = temp_coordo_y;
                      joueur.etat_avant = MAP[joueur.coordo_x][joueur.coordo_y].lieu;
                      MAP[joueur.coordo_x][joueur.coordo_y].lieu = personnage;

                      if(joueur.etat_avant == porte && MAP[joueur.coordo_x][joueur.coordo_y+1].lieu == sol){
                        MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                        joueur.coordo_y++;
                        joueur.etat_avant = MAP[joueur.coordo_x][joueur.coordo_y].lieu;
                        MAP[joueur.coordo_x][joueur.coordo_y].lieu = personnage;
                      }else if(joueur.etat_avant == porte && MAP[joueur.coordo_x][joueur.coordo_y-1].lieu == sol){
                        MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                        joueur.coordo_y--;
                        joueur.etat_avant = MAP[joueur.coordo_x][joueur.coordo_y].lieu;
                        MAP[joueur.coordo_x][joueur.coordo_y].lieu = personnage;
                      }else if(joueur.etat_avant == porte && MAP[joueur.coordo_x+1][joueur.coordo_y].lieu == sol){
                        MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                        joueur.coordo_x++;
                        joueur.etat_avant = MAP[joueur.coordo_x][joueur.coordo_y].lieu;
                        MAP[joueur.coordo_x][joueur.coordo_y].lieu = personnage;
                      }else if(joueur.etat_avant == porte && MAP[joueur.coordo_x-1][joueur.coordo_y].lieu == sol){
                        MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                        joueur.coordo_x--;
                        joueur.etat_avant = MAP[joueur.coordo_x][joueur.coordo_y].lieu;
                        MAP[joueur.coordo_x][joueur.coordo_y].lieu = personnage;
                      }
                      joueur.SALLE = MAP[joueur.coordo_x][joueur.coordo_y].num_salle+1;
                    }else if (joueur.etat_avant == uplevel){
                      joueur.STAGE = joueur.STAGE + 1;
                      debut_game(mapfenetre, chatfenetre);
                      if(stage_cle == joueur.STAGE){
                        Placer_cle();
                      }
                      if (stage_medikit == joueur.STAGE) {
                        Placer_medikit();
                      }
                    }
                    affichage(mapfenetre);
                    wrefresh(mapfenetre);
                    break;
    case 'n':
                    switch(deplacement){
                      case 5: MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                              joueur.etat_avant = MAP[joueur.coordo_x+1][joueur.coordo_y].lieu;
                              MAP[joueur.coordo_x+1][joueur.coordo_y].lieu = personnage;
                              joueur.coordo_x++;
                              break;
                      case 2:	MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                              joueur.etat_avant = MAP[joueur.coordo_x-1][joueur.coordo_y].lieu;
                              MAP[joueur.coordo_x-1][joueur.coordo_y].lieu = personnage;
                              joueur.coordo_x--;
                              break;
                      case 1: MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                              joueur.etat_avant = MAP[joueur.coordo_x][joueur.coordo_y+1].lieu;
                              MAP[joueur.coordo_x][joueur.coordo_y+1].lieu = personnage;
                              joueur.coordo_y++;
                              break;
                      case 3: MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                              joueur.etat_avant = MAP[joueur.coordo_x][joueur.coordo_y-1].lieu;
                              MAP[joueur.coordo_x][joueur.coordo_y-1].lieu = personnage;
                              joueur.coordo_y--;
                              break;
                    }
                    affichage(mapfenetre);
                    wrefresh(mapfenetre);
                    break;

    case '9':
                    if(choix == '9' && joueur.SALLE == 1 && joueur.STAGE == 1){
                      joueur.addcle = 1;
                      joueur.etat_avant = arriver;
                      break;
                    }else porte_escalier(chatfenetre, mapfenetre, utilisateur); break;
  }
  ecrire_chat(chatfenetre, MAP[joueur.coordo_x][joueur.coordo_y].lieu);
}
