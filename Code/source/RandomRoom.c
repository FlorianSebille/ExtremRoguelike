/**
 * \file RandomRoom.c
 * \brief Programme regroupant les fonctions qui génèrent les principales structures du jeu
 * \author TROTTIER Arthur
 * \version 1.0.1
 */

#include "total.h"

/**
 * \fn int aleat(int min, int max)
 * \brief fonction qui retourne un nombre aléatoire entre 2 bornes
 * \param min valeur minimum possible
 * \param max valeur maximum possible
 */
int aleat(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

/**
 * \fn void fillmap()
 * \brief fonction qui met la carte (matrice) à l'état 0
 */
void fillmap(){

  int i, j;
  for(i = 0; i < x; i++){
    for(j = 0; j < y; j++){
      MAP[i][j].lieu = vide;
      MAP[i][j].position = 0;
      MAP[i][j].relie = 0;
    }
  }
}

/**
 * \fn int room_possible (int lg_mur_horiz, int lg_mur_vert, int posy, int posx)
 * \brief fonction qui parcourt la matrice pour vérifier si la construction d'une salle est possible
 * \param lg_mur_horiz longueur des murs horizontaux
 * \param lg_mur_vert longueur des murs verticaux
 * \param posy numero de la colonne ou débute la salle
 * \param posy numero de la ligne ou débute la salle
 */
int room_possible (int lg_mur_horiz, int lg_mur_vert, int posy, int posx){
  int i = posx;
  int j,k,l;
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
/**
 * \fn void init_room(int num, int nb_salle)
 * \brief fonction qui consruit une salle numérotée avec 1 ou 2 portes en fonction de ce numéro
 * \param num numéro de la salle à construire
 * \param nb_salle nombre de salle total de la carte
 */
void init_room(int num, int nb_salle){

  int i, j, k, l;
  int posx, posy;
  int lg_mur_horiz, lg_mur_vert;
  int perim_room, pos_door1, pos_door2;
  int compteur = 0;
  lg_mur_horiz = aleat(10,20);
  lg_mur_vert= aleat(5,10);
  posx = aleat(0,x);
  posy = aleat(0,y);
  perim_room = (lg_mur_horiz + lg_mur_vert )* 2;
  pos_door1 = aleat(0,perim_room);
  if(num != 0 && num != nb_salle -1) pos_door2 = aleat(0,perim_room); /* On initialise qu'une porte pour la salle de depart et d'arrivée */
  else pos_door2 = -1;

   /* On vérifie que les portes ne sont pas dans les angles et écartés d'au moins 1 entre elles */

  if(pos_door1 == 0 || pos_door1 == lg_mur_horiz || pos_door1 == perim_room || pos_door1 == 2 * lg_mur_horiz + lg_mur_vert || pos_door1 == lg_mur_horiz + lg_mur_vert){
    if(pos_door1 == 0)pos_door1 = pos_door1 + 1;
    else pos_door1 = pos_door1 - 1;
  }

  if(pos_door2 == 0 || pos_door2 == lg_mur_horiz || pos_door2 == perim_room || pos_door2 == 2 * lg_mur_horiz + lg_mur_vert || pos_door2 == lg_mur_horiz + lg_mur_vert){
    if(pos_door2 == 0)pos_door2 = pos_door2 + 1;
    else pos_door2 = pos_door2 - 1;
  }

  while(pos_door1 == pos_door2 || pos_door1 == pos_door2 + 1 || pos_door1 == pos_door2 - 1){
    pos_door2 = aleat(0,perim_room);
  }

  /* Si il y a la place pour une salle, alors on la construit */

  if(room_possible(lg_mur_horiz, lg_mur_vert, posy, posx)){

    i = posx;
    for(j = posy, k = 0; (k < lg_mur_horiz) && (j < y); j++, k++){   /* On place le mur du haut */
      if(compteur == pos_door1 || compteur == pos_door2){    /* On place les portes de la salle aleatoirement */
        MAP[i][j].lieu = porte;
        MAP[i][j].num_salle = num;
      }else{
        MAP[i][j].lieu = mur;
        MAP[i][j].num_salle = num;
      }
      compteur++;
    }
    for(i = posx, k = 0; (k < lg_mur_vert) && (i < x); i++, k++){     /* On place le mur de droite */
      if(compteur == pos_door1 || compteur == pos_door2){
        MAP[i][j].lieu = porte;
        MAP[i][j].num_salle = num;
      }else{
        MAP[i][j].lieu = mur;
        MAP[i][j].num_salle = num;
      }
      compteur++;
    }
    for(j = posy, k = 0; (k <= lg_mur_horiz) && (i < y); j++, k++){   /* On place le mur du bas */
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
    for(i = posx + 1, k = 0; (k < lg_mur_vert) && (i < x); i++, k++){     /* On place le mur de gauche */
      if(compteur == pos_door1 || compteur == pos_door2){
        MAP[i][j].lieu = porte;
        MAP[i][j].num_salle = num;
      }else{
        MAP[i][j].lieu = mur;
        MAP[i][j].num_salle = num;
      }
      compteur++;
    }
    for(j = posy + 1, k = 0; (k < lg_mur_horiz - 1) && (j < y - 1); j++, k++){   /* On place le sol à l'intérieur de la salle */
      for(i = posx + 1, l = 0; (l < lg_mur_vert - 1) && (i < x - 1); i++, l++){
          MAP[i][j].lieu = sol;
          MAP[i][j].num_salle = num;
      }
    }
  }else{
    init_room(num, nb_salle);
  }
}

/**
 * \fn int trouver_porte(int * xA, int * yA, int salle)
 * \brief fonction qui met à jour les coordonnées de la prochaine porte à relier
 * \param xA numéro de ligne de la porte à relier
 * \param yA numéro de colonne de la porte à relier
 * \param salle numéro de la salle où se situe actuellement le reliage de porte
 */

int trouver_porte(int * xA, int * yA, int salle){
  int i,j;
  for(i = 0; i < x; i++){
    for(j = 0; j < y; j++){
      if(MAP[i][j].num_salle == salle && MAP[i][j].lieu == porte && MAP[i][j].relie != 1){
        *xA = i;
        *yA = j;
        MAP[i][j].relie = 1;
        return 1;
      }
    }
  }
  return 0;
}

/**
 * \fn int relier_2Portes(int xA, int yA)
 * \brief fonction qui relie une porte d'une salle à la porte de la salle suivante
 * \param xA numéro de ligne de la porte à relier
 * \param yA numéro de colonne de la porte à relier
 */
int relier_2Portes(int xA, int yA){

  t_coord MaPos;
  int num = MAP[xA][yA].num_salle;
  int compteur;
  int l,c;
  int check = 1;

  init_file();      /* Utilisation d'une file qui utilise le système de flood & fill pour trouver le chemin le plus court */

  MaPos.ligne = xA;
  MaPos.colonne = yA;
  MAP[xA][yA].position = 0;
  ajouter(MaPos);
  int prop = 0, propmem = -1;

  while(MAP[MaPos.ligne][MaPos.colonne].lieu != porte || MAP[MaPos.ligne][MaPos.colonne].num_salle != num + 1 || MAP[MaPos.ligne][MaPos.colonne].relie == 1){
    l = MaPos.ligne;
    c = MaPos.colonne;
    compteur = MAP[l][c].position + 1;
    propmem = prop;
    prop = compteur;

    if( l-1 >= 0 && MAP[l-1][c].position == 0 && ((MAP[l-1][c].lieu == vide || MAP[l-1][c].lieu == couloir) || (MAP[l-1][c].lieu == porte && MAP[l-1][c].num_salle == num +1))){
      MaPos.ligne = l-1;
      MaPos.colonne = c;
      MAP[l-1][c].position = compteur;
      ajouter(MaPos);
    }if( l+1 < x && MAP[l+1][c].position == 0 && ((MAP[l+1][c].lieu == vide || MAP[l+1][c].lieu == couloir) || (MAP[l+1][c].lieu == porte && MAP[l+1][c].num_salle == num +1))){
      MaPos.ligne = l+1;
      MaPos.colonne = c;
      MAP[l+1][c].position = compteur;
      ajouter(MaPos);
    }if( c-1 >= 0 && MAP[l][c-1].position == 0 && ((MAP[l][c-1].lieu == vide || MAP[l][c-1].lieu == couloir) || (MAP[l][c-1].lieu == porte && MAP[l][c-1].num_salle == num +1))){
      MaPos.ligne = l;
      MaPos.colonne = c-1;
      MAP[l][c-1].position = compteur;
      ajouter(MaPos);
    }if( c+1 < y && MAP[l][c+1].position == 0 && ((MAP[l][c+1].lieu == vide || MAP[l][c+1].lieu == couloir) || (MAP[l][c+1].lieu == porte && MAP[l][c+1].num_salle == num +1))){
      MaPos.ligne = l;
      MaPos.colonne = c+1;
      MAP[l][c+1].position = compteur;
      ajouter(MaPos);
    }
    retirer(&MaPos);
  }
    MAP[xA][yA].xb = MaPos.ligne; /* Mise à jour des coordonnées de la porte A et B mutuellement reliées entres elles */
    MAP[xA][yA].yb = MaPos.colonne;

    MAP[MaPos.ligne][MaPos.colonne].xb = xA;
    MAP[MaPos.ligne][MaPos.colonne].yb = yA;

    l = MaPos.ligne;
    c = MaPos.colonne;
    MAP[l][c].relie = 1;

    while(MAP[l][c].position != 1){     /* Lorsque la porte que l'on cherche est trouvée, on fait le chemin inverse pour arriver jusqu'a elle */
      if(MAP[l][c+1].position == MAP[l][c].position - 1){
        c++;
      }else if(MAP[l-1][c].position == MAP[l][c].position - 1){
        l--;
      }else if(MAP[l+1][c].position == MAP[l][c].position - 1){
        l++;
      }else if(MAP[l][c-1].position == MAP[l][c].position - 1){
        c--;
      }
      MAP[l][c].lieu = couloir;
    }
    MAP[l][c].lieu = couloir;
    file_supprimer();
    return 1;
}

/**
 * \void positionzero
 * \brief fonction qui met à zéro le paramètre position de la carte (matrice)
 */
void positionzero(){
  int i, j;
  for(i=0;i<x;i++){
    for(j=0;j<y;j++){
      MAP[i][j].position = 0;
    }
  }
}

/**
 * \fn void init_map
 * \brief fonction qui initialise une carte totalement aléatoire constituée de salles reliées par des couloirs
 */
void init_map(){
  int * xB;
  int * yB;
  int ligne, colonne;
  int i;
  xB = &ligne;
  yB = &colonne;

  fillmap();                          /* On initialise la map à vide */

  if(joueur.STAGE != 1){
    nombre_salle = nombre_salle + 1;
  }else nombre_salle = aleat(3,5);

  for(i = 0; i < nombre_salle; i++){  /* On remplit la carte d'un nombre de salle aléatoire */
    init_room(i,nombre_salle);
  }
  for(i = 0; i < nombre_salle - 1; i++){  /* On relie les salles entres elles */
    positionzero();
    trouver_porte(xB,yB,i);
    relier_2Portes(ligne,colonne);
  }
  if(joueur.STAGE > 1){ /* Si l'on ne se situe pas au premier étage alors on place dans les salles des monstres (fonction se situant dans Placer_element.c) */
      Placer_monstre();
  }
  Placer_piege(); /* On place pour finir des pièges dans les salles (fonction se situant dans Placer_element.c) */

}
