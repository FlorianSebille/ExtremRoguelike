#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#define x 31
#define y 90



typedef enum element {vide, mur, sol, porte, couloir} t_element;
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
    if(MAP[i][j].lieu == 1 || MAP[i+1][j].lieu == 1 || MAP[i-1][j].lieu == 1) return 0;
  }
  for(i = posx, k = 0; (k < lg_mur_vert) && (i < x); i++, k++){
    if(MAP[i][j].lieu == 1 || MAP[i][j+1].lieu == 1 || MAP[i][j-1].lieu == 1) return 0;
  }
  for(j = posy, k = 0; (k < lg_mur_horiz) && (i < y); j++, k++){
    if(MAP[i][j].lieu == 1 || MAP[i+1][j].lieu == 1 || MAP[i-1][j].lieu == 1) return 0;
  }
  j = posy;
  for(i = posx, k = 0; (k < lg_mur_vert) && (i < x); i++, k++){
    if(MAP[i][j].lieu == 1 || MAP[i][j+1].lieu == 1 || MAP[i][j-1].lieu == 1) return 0;
  }
  return 1;
}

void init_room(){                   //fonction qui initialise une salle de taille aléatoire à un endroit aléatoire.
  int i, j, k, l;
  int posx, posy;
  int lg_mur_horiz, lg_mur_vert;
  int perim_room, pos_door;
  int compteur = 0;
  lg_mur_horiz = aleat(7,19);
  lg_mur_vert= aleat(5,9);
  posx = aleat(0,x);
  posy = aleat(0,y);
  perim_room = (lg_mur_horiz + lg_mur_vert )* 2;
  pos_door = aleat(0,perim_room);

   //si la porte est dans un angle on la décale d'1.

  if(pos_door == 0 || pos_door == lg_mur_horiz || pos_door == perim_room || pos_door == 2 * lg_mur_horiz + lg_mur_vert || pos_door == lg_mur_horiz + lg_mur_vert){
    if(pos_door == 0)pos_door = pos_door + 1;
    else pos_door = pos_door -1;
  }

  //si il y a la place pour une salle

  if(room_possible(lg_mur_horiz, lg_mur_vert, posy, posx)){

    i = posx;
    for(j = posy, k = 0; (k < lg_mur_horiz) && (j < y); j++, k++){   //On place le mur du haut
      if(compteur == pos_door){    // On place la porte de la salle aleatoirement sur l'un des 4 murs en s'assurant que la porte n'est pas dans un angle */
        MAP[i][j].lieu = porte;
        MAP[i][j].position = 3;
      }else{
        MAP[i][j].lieu = mur;
        MAP[i][j].position = 1;
      }
      compteur++;
    }
    for(i = posx, k = 0; (k < lg_mur_vert) && (i < x); i++, k++){     //...de droite
      if(compteur == pos_door){
        MAP[i][j].lieu = porte;
        MAP[i][j].position = 3;
      }else{
        MAP[i][j].lieu = mur;
        MAP[i][j].position = 1;
      }
      compteur++;
    }
    for(j = posy, k = 0; (k <= lg_mur_horiz) && (i < y); j++, k++){   //...du bas
      if(compteur == pos_door){
        MAP[i][j].lieu = porte;
        MAP[i][j].position = 3;
      }else{
        MAP[i][j].lieu = mur;
        MAP[i][j].position = 1;
      }
      compteur++;
    }
    j = posy;
    for(i = posx + 1, k = 0; (k < lg_mur_vert) && (i < x); i++, k++){     //...de gauche
      if(compteur == pos_door){
        MAP[i][j].lieu = porte;
        MAP[i][j].position = 3;
      }else{
        MAP[i][j].lieu = mur;
        MAP[i][j].position = 1;
      }
      compteur++;
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

void relier_2Portes(int xA, int yA, int xB, int yB){
  int relie = 0;

  do{
    if(xA < xB){                                        //si la porte A se situe au-dessus de la porte B
      if(MAP[xA+1][yA] == vide){                              //si l'espace est libre on descend
        xA = xA + 1;
        MAP[xA][yA].lieu = couloir;
      }else if(MAP[xA][yA+1] == vide){                        //sinon si l'espace à droite est libre on va à droite
        yA = yA + 1;
        MAP[xA][yA].lieu = couloir;
      }else if(MAP[xA][yA-1] == vide){                        //sinon si l'espace à gauche est libre on va à gauche
        yA = yA - 1;
        MAP[xA][yA].lieu = couloir;
      }else{                                                  //sinon on monte
        xA = xA - 1;
        MAP[xA][yA];
      }
    }else if(xA > xB){                                    //sinon si la porte A se situe en dessous de la porte B
      if(MAP[xA - 1][yA] == vide){                            //si l'espace est libre on monte
        xA = xA - 1;
        MAP[xA][yA].lieu = couloir;
      }else if(MAP[xA][yA+1] == vide){                        //sinon si l'espace à droite est libre on va à droite
        yA = yA + 1;
        MAP[xA][yA].lieu = couloir;
      }else if(MAP[xA][yA-1] == vide){                        //sinon si l'espace à gauche est libre on va à gauche
        yA = yA - 1;
        MAP[xA][yA].lieu = couloir;
      }else{                                                  //sinon on descend
        xA = xA + 1;
        MAP[xA][yA];
      }
    }else{                                                 //sinon c'est que la porte A se situe à la même hauteur que la porte B

    }

  }while(relie == 0)


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
      if(MAP[i][j].lieu == vide) printf(" ");
      else if(MAP[i][j].lieu == porte) printf(".");
      else printf("%i",MAP[i][j].position);
    }
    printf("\n");
  }
}
