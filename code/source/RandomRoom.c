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
  lg_mur_horiz = aleat(10,15);
  lg_mur_vert= aleat(5,10);
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
        MAP[i][j].num_salle = num;
      }else{
        MAP[i][j].lieu = mur;
        MAP[i][j].num_salle = num;
      }
      compteur++;
    }
    for(i = posx, k = 0; (k < lg_mur_vert) && (i < x); i++, k++){     //...de droite
      if(compteur == pos_door1 || compteur == pos_door2){
        MAP[i][j].lieu = porte;
        MAP[i][j].num_salle = num;
      }else{
        MAP[i][j].lieu = mur;
        MAP[i][j].num_salle = num;
      }
      compteur++;
    }
    for(j = posy, k = 0; (k <= lg_mur_horiz) && (i < y); j++, k++){   //...du bas
      if(compteur == pos_door1 || compteur == pos_door2){
        MAP[i][j].lieu = porte;
        MAP[i][j].num_salle = num;
      }else{
        MAP[i][j].lieu = mur;
        MAP[i][j].num_salle = num;
      }
      compteur++;
    }
    j = posy;
    for(i = posx + 1, k = 0; (k < lg_mur_vert) && (i < x); i++, k++){     //...de gauche
      if(compteur == pos_door1 || compteur == pos_door2){
        MAP[i][j].lieu = porte;
        MAP[i][j].num_salle = num;
      }else{
        MAP[i][j].lieu = mur;
        MAP[i][j].num_salle = num;
      }
      compteur++;
    }
    for(j = posy + 1, k = 0; (k < lg_mur_horiz - 1) && (j < y - 1); j++, k++){   //on place le sol dans la salle
      for(i = posx + 1, l = 0; (l < lg_mur_vert - 1) && (i < x - 1); i++, l++){
        MAP[i][j].lieu = sol;
        MAP[i][j].num_salle = num;
      }
    }
  }else{
    init_room(num, nb_salle);
  }
}

int trouver_porte(int * xA, int * yA){    //fonction qui retourne les coordonnées d'un pointeur et marque la porte comme reliée
  int i,j;
  for(i = 0; i < x; i++){
    for(j = 0; j < y; j++){
      if(MAP[i][j].lieu == porte && MAP[i][j].relie != 1){
        *xA = i;
        *yA = j;
        MAP[i][j].relie = 1;
        return 0;
      }
    }
  }
  return 0;
}

int relier_2Portes(int xA, int yA){
  int num = MAP[xA][yA].num_salle;
  int compteur = 0;
  int l,c;

  init_file();

  if(MAP[xA][yA].lieu != vide && !(MAP[xA][yA].lieu == porte && MAP[xA][yA].num_salle == num))return 0;
  ajouter(xA,yA);

  while(!file_vide()){
    retirer(&l,&c);
    MAP[l][c].position = compteur;
    compteur++;

    if((MAP[l-1][c].lieu == vide || (MAP[l-1][c].lieu == porte && MAP[l-1][c].num_salle == num +1)) && l-1 >= 0)ajouter(l-1,c);
    if((MAP[l+1][c].lieu == vide || (MAP[l+1][c].lieu == porte && MAP[l+1][c].num_salle == num +1)) && l+1 <= x)ajouter(l+1,c);
    if((MAP[l][c-1].lieu == vide || (MAP[l][c-1].lieu == porte && MAP[l][c-1].num_salle == num +1)) && c-1 >= 0)ajouter(l,c-1);
    if((MAP[l][c+1].lieu == vide || (MAP[l][c+1].lieu == porte && MAP[l][c+1].num_salle == num +1)) && l+1 <= y)ajouter(l,c+1);
  }
  return 1;
}


void init_map(){                    //fonction qui remplit la map d'un nombre de salle aléatoire
  int i;


  fillmap();
  nombre_salle = aleat(3,6);

  for(i = 0; i < nombre_salle; i++){
    init_room(i,nombre_salle);
  }

}
