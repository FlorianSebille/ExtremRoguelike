#include "total.h"

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
  if(posx <= 1 || posx >= x - lg_mur_vert -1) return 0;
  if(posy <= 1 || posy >= y - lg_mur_horiz -1) return 0;
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

void init_room(int num, int nb_salle){                   //fonction qui initialise une salle de taille aléatoire à un endroit aléatoire avec des portes
  int i, j, k, l;
  int posx, posy;
  int lg_mur_horiz, lg_mur_vert;
  int perim_room, pos_door1, pos_door2;
  int compteur = 0;
  lg_mur_horiz = aleat(7,19);
  lg_mur_vert= aleat(10,15);
  posx = aleat(0,x);
  posy = aleat(0,y);
  perim_room = (lg_mur_horiz + lg_mur_vert )* 2;
  pos_door1 = aleat(0,perim_room);
  if(num != 0 && num != nb_salle -1) pos_door2 = aleat(0,perim_room); //on initialise qu'une porte pour la salle de depart et d'arrivée
  else pos_door2 = -1;

   //On vérifie que les portes ne sont pas dans les angles et décalés d'au moins 1

  if(pos_door1 == 0 || pos_door1 == lg_mur_horiz || pos_door1 == perim_room || pos_door1 == 2 * lg_mur_horiz + lg_mur_vert || pos_door1 == lg_mur_horiz + lg_mur_vert){
    if(pos_door1 == 0)pos_door1 = pos_door1 + 1;
    else pos_door1 = pos_door1 -1;
  }

  if(pos_door2 == 0 || pos_door2 == lg_mur_horiz || pos_door2 == perim_room || pos_door2 == 2 * lg_mur_horiz + lg_mur_vert || pos_door2 == lg_mur_horiz + lg_mur_vert){
    if(pos_door2 == 0)pos_door2 = pos_door2 + 1;
    else pos_door2 = pos_door2 -1;
  }

  while(pos_door1 == pos_door2 || pos_door1 == pos_door2 + 1 || pos_door1 == pos_door2 - 1){
    pos_door2 = aleat(0,perim_room);
  }

  //si il y a la place pour une salle

  if(room_possible(lg_mur_horiz, lg_mur_vert, posy, posx)){

    i = posx;
    for(j = posy, k = 0; (k < lg_mur_horiz) && (j < y); j++, k++){   //On place le mur du haut
      if(compteur == pos_door1 || compteur == pos_door2){    // On place la porte de la salle aleatoirement sur l'un des 4 murs en s'assurant que la porte n'est pas dans un angle */
        MAP[i][j].lieu = porte;
      }else{
        MAP[i][j].lieu = mur;
      }
      compteur++;
    }
    for(i = posx, k = 0; (k < lg_mur_vert) && (i < x); i++, k++){     //...de droite
      if(compteur == pos_door1 || compteur == pos_door2){
        MAP[i][j].lieu = porte;
      }else{
        MAP[i][j].lieu = mur;
      }
      compteur++;
    }
    for(j = posy, k = 0; (k <= lg_mur_horiz) && (i < y); j++, k++){   //...du bas
      if(compteur == pos_door1 || compteur == pos_door2){
        MAP[i][j].lieu = porte;
      }else{
        MAP[i][j].lieu = mur;
      }
      compteur++;
    }
    j = posy;
    for(i = posx + 1, k = 0; (k < lg_mur_vert) && (i < x); i++, k++){     //...de gauche
      if(compteur == pos_door1 || compteur == pos_door2){
        MAP[i][j].lieu = porte;
      }else{
        MAP[i][j].lieu = mur;
      }
      compteur++;
    }
    for(j = posy + 1, k = 0; (k < lg_mur_horiz - 1) && (j < y - 1); j++, k++){   //on place le sol dans la salle
      for(i = posx + 1, l = 0; (l < lg_mur_vert - 1) && (i < x - 1); i++, l++){
        MAP[i][j].lieu = sol;
      }
    }
  }else{
    init_room(num, nb_salle);
  }
}
/*
int trouver_porte(int * xA, int * yA){
  for(i = 0; i < x; i++){
    for(j = 0; j < y; j++){
      if(MAP[i][j].lieu == porte && MAP[i][j].position != -1){
        *xA = i;
        *yA = j;
        MAP[i][j].position = -1
        return 0;
      }
    }
  }
}


void relier_2Portes(int x, int y){
  int compteur = 0;
  MAP[x][y].lieu == vide;
  do{
    if(MAP[x][y].lieu == vide){
      MAP[x][y].position = compteur;
      compteur++;
      relier_2Portes(x+1,y);
      relier_2Portes(x-1,y);
      relier_2Portes(x,y+1);
      relier_2Portes(x,y-1);
    }
  }while(MAP[x][y].lieu != porte);
}
*/

void init_map(){                    //fonction qui remplit la map d'un nombre de salle aléatoire
  int nb_salle;
  int i;

  fillmap();
  nb_salle = aleat(3,6);

  for(i = 0; i < nb_salle; i++){
    init_room(i,nb_salle);
  }
}
