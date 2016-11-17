#include <ncurses.h>
#include <time.h>
#include <stdlib.h>

const char * car = "#";
const char * wall_h = "-";
const char * wall_v = "|";
const char * angle = "+";

getmaxyx(S_win,row,col);
typedef enum element {sol, mur, vide} t_element;
typedef struct cellule {t_element lieu, int position;} t_cellule;
t_cellule MAP[row][col];

int aleat(int min, int max){
    return rand()%(max-min) +min;
}


void fillmap(){   //fonction qui remplit la map à l'état vide
  int row, col, i, j;
  for(i = 0; i < col; i++){
    for(j = 0; j < row; j++){
      MAP[i][j].lieu = vide;
      MAP[i][j].position = 0;
    }
  }
}


void init_room(){     //fonction qui initialise une salle de taille aléatoire à un endroit aléatoire (mur, sol..)
  int row, col, i, j;
  int k = 0;
  int nb_salle, lg_mur, posx, posy, lg_mur_horiz, lg_mur_vert;
  lg_mur_horiz = aleat(10,20);
  lg_mur_vert= aleat(10,20);
  posx = aleat(0,row);
  posy = aleat(0,col);

  j = posy;
  for(i = posx; i < lg_mur_horiz; i++){   //On place le mur du haut
  MAP[i][j].lieu = mur;
  MAP[i][j].position = 0;
  }
  for(j = posy; j < lg_mur_vert; j--){     //...de droite
  MAP[i][j].lieu = mur;
  MAP[i][j].position = 0;
  }
  for(i = posx; i < lg_mur_horiz; i--){   //...du bas
  MAP[i][j].lieu = mur;
  MAP[i][j].position = 0;
  }
  for(j = posy; j < lg_mur_vert; j++){     //...de gauche
  MAP[i][j].lieu = mur;
  MAP[i][j].position = 0;
  }

  for(i = posx + 1; i < lg_mur_horiz - 1; i++){   //on place le sol dans la salle
    for(j = posy - 1; j < lg_mur_vert - 1; j++){
      MAP[i][j].lieu = sol;
      MAP[i][j].position = 0;
    }
  }


}
