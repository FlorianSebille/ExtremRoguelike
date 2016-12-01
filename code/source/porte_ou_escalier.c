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
  do{
    choix = getch();
  }while (choix != KEY_LEFT && choix != KEY_RIGHT);

  switch (choix) {

    case KEY_RIGHT: if (joueur.etat_avant == porte){

              }else if (joueur.etat_avant == uplevel){
                joueur.STAGE = joueur.STAGE + 1;
                srand(time(NULL));
                init_map();
                Placer_uplevel(MAP, mapfenetre);
                Placer_perso(MAP, mapfenetre);
                affichage(MAP,mapfenetre);
              }
              wrefresh(mapfenetre);
              break;
    /*case KEY_LEFT:  mvwprintw(chatfenetre,13,5,"right");
                    mvwprintw(chatfenetre,14,5,"%i",utilisateur);
                    switch(utilisateur){
                      mvwprintw(chatfenetre,15,5,"right");
                      mvwprintw(chatfenetre,16,5,"%i",utilisateur);
                      wrefresh(chatfenetre);
                      case KEY_UP:    MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                                      joueur.etat_avant = MAP[joueur.coordo_x+1][joueur.coordo_y].lieu;
                                      MAP[joueur.coordo_x+1][joueur.coordo_y].lieu = personnage;
                                      joueur.coordo_x++;
                                      wrefresh(mapfenetre);
                                      break;
                      case KEY_DOWN:	MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                                      joueur.etat_avant = MAP[joueur.coordo_x-1][joueur.coordo_y].lieu;
                                      MAP[joueur.coordo_x-1][joueur.coordo_y].lieu = personnage;
                                      joueur.coordo_x--;
                                      wrefresh(mapfenetre);
                                      break;
                      case KEY_LEFT:  MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                                      joueur.etat_avant = MAP[joueur.coordo_x][joueur.coordo_y+1].lieu;
                                      MAP[joueur.coordo_x][joueur.coordo_y+1].lieu = personnage;
                                      joueur.coordo_y++;
                                      wrefresh(mapfenetre);
                                      break;
                      case KEY_RIGHT: MAP[joueur.coordo_x][joueur.coordo_y].lieu = joueur.etat_avant;
                                      joueur.etat_avant = MAP[joueur.coordo_x][joueur.coordo_y-1].lieu;
                                      MAP[joueur.coordo_x][joueur.coordo_y-1].lieu = personnage;
                                      joueur.coordo_y--;
                                      wrefresh(mapfenetre);
                                      break;
                    }
                    while (dep_reussi == 0) {

                    }
                    break;*/
  }
  effacer_fenetre(chatfenetre);
  wrefresh(chatfenetre);
}
