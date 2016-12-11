#include "total.h"

/**
 * \fn void debut_game(WINDOW *S_win, WINDOW *T_win)
 * \brief Fonction qui nitialise la map et place les différents elements.
 *
 * \param S_win contenant la map.
 * \param T_win contenant la map.
 */
void debut_game(WINDOW *S_win, WINDOW *T_win){
  init_map(S_win);
  Placer_uplevel(S_win);
  Placer_perso(S_win);
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
  ecrire_chat(T_win, 2);
}
