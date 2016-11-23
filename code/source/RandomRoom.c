#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#define x 31
#define y 90



typedef enum element {vide, mur, sol} t_element;
typedef struct cellule {t_element lieu; int position;} t_cellule;
t_cellule MAP[x][y];


int aleat(int min, int max){         //fonction qui retourne un nombre aléatoire entre 2 bornes
    return (rand() % (max - min + 1)) + min;
}

void fillmap(){                     //fonction qui remplit la map à l'état vide
  int i, j;
  for(i = 0; i < x; i++){
    for(j = 0; j < y; j++){
      MAP[i][j].lieu = vide;
      MAP[i][j].position = 0;
    }
  }
}

int room_possible (int lg_mur_horiz, int lg_mur_vert, int posy, int posx){    //fonction qui renvoit 1 si la creation d'une salle est possible
  int i, j, k;
  i = posx;
  if(posx == 0 || posx >= x - lg_mur_vert) return 0;
  if(posy == 0 || posy >= y - lg_mur_horiz) return 0;
  for(j = posy, k = 0; (k < lg_mur_horiz) && (j < y); j++, k++){
    if(MAP[i][j].lieu == 1) return 0;
  }
  for(i = posx, k = 0; (k < lg_mur_vert) && (i < x); i++, k++){
    if(MAP[i][j].lieu == 1) return 0;
  }
  for(j = posy, k = 0; (k < lg_mur_horiz) && (i < y); j++, k++){
    if(MAP[i][j].lieu == 1) return 0;
  }
  j = posy;
  for(i = posx, k = 0; (k < lg_mur_vert) && (i < x); i++, k++){
    if(MAP[i][j].lieu == 1) return 0;
  }
  return 1;
}

void init_room(){                   //fonction qui initialise une salle de taille aléatoire à un endroit aléatoire.
  int i, j, k, l;
  int posx, posy, lg_mur_horiz, lg_mur_vert;
  lg_mur_horiz = aleat(7,19);
  lg_mur_vert= aleat(5,9);
  posx = aleat(0,x);
  posy = aleat(0,y);

  if(room_possible(lg_mur_horiz, lg_mur_vert, posy, posx)){         //si il y a la place pour une salle

    i = posx;
    for(j = posy, k = 0; (k < lg_mur_horiz) && (j < y); j++, k++){   //On place le mur du haut
      MAP[i][j].lieu = mur;
      MAP[i][j].position = 1;
    }
    for(i = posx, k = 0; (k < lg_mur_vert) && (i < x); i++, k++){     //...de droite
      MAP[i][j].lieu = mur;
      MAP[i][j].position = 1;
    }
    for(j = posy, k = 0; (k <= lg_mur_horiz) && (i < y); j++, k++){   //...du bas
      MAP[i][j].lieu = mur;
      MAP[i][j].position = 1;
    }
    j = posy;
    for(i = posx, k = 0; (k < lg_mur_vert) && (i < x); i++, k++){     //...de gauche
      MAP[i][j].lieu = mur;
      MAP[i][j].position = 1;
    }

    for(j = posy + 1, k = 0; (k < lg_mur_horiz - 1) && (j < y - 1); j++, k++){   //on place le sol dans la salle
      for(i = posx + 1, l = 0; (l < lg_mur_vert - 1) && (i < x - 1); i++, l++){
        MAP[i][j].lieu = sol;
        MAP[i][j].position = 2;
      }
    }
  }else{
    init_room();
  }
}

void init_map(){                    //fonction qui remplit la map d'un nombre de salle aléatoire
  int nb_salle;
  int i;

  fillmap();
  nb_salle = aleat(3,6);

  for(i = 0; i < nb_salle; i++){
    init_room();
  }
}

int main(){
  srand(time(NULL));
  int i,j;

  fillmap();
  init_map();

  for(i = 0; i < x; i++){
    for(j = 0; j < y; j++){
      if(MAP[i][j].lieu != vide) printf("%i",MAP[i][j].position);
      else printf(" ");
    }
    printf("\n");
  }
}
