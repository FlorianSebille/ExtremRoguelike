#include <stdio.h>
#include <string.h>
#include <math.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>
#define TAILLE 100
int nombre_salle;

typedef struct joueur {char nom;int coordo_x;int coordo_y;int etat_avant;int STAGE;int SALLE;int LEVEL;int EXP;int HP;int ATT;int DEF;int FOOD;} t_joueur;
t_joueur joueur;

typedef enum element {vide, mur, sol, porte, couloir, personnage, uplevel} t_element;

typedef struct cellule {t_element lieu; int position; int relie; int num_salle;} t_cellule;

#define x 30
#define y 89
t_cellule MAP[x][y];


//dans le fichier GenWindows.c
WINDOW * create_newwin(int height, int width, int starty, int startx, char * label);
void destroy_win(WINDOW *local_win);

//dans le fichier test_taille_terminal.c
int taille_terminal();

//dans le fichier chat.c
void effacer_ligne(WINDOW *chatwin, int ligne_effacer);

void effacer_fenetre(WINDOW *chatwin);

void ecrire_chat(WINDOW *chatwin,int position_perso);

//int addsauv(WINDOW *centerwin);

void Win_Stat(WINDOW *F_winn, int widthF);

//dans le fichier RandomRoom.c
int aleat(int min, int max);

void fillmap();

int room_possible (int lg_mur_horiz, int lg_mur_vert, int posy, int posx);

void init_room();

int trouver_porte(int * xA, int * yA);

int relier_2Portes(int xA, int yA);

void init_map();

void affichage(t_cellule MAP [x] [y], WINDOW *fenetre);

int Placer_uplevel(t_cellule MAP [x] [y], WINDOW *fenetre);

int Placer_perso(t_cellule MAP [x] [y], WINDOW *fenetre);

int test_depl(t_cellule MAP [x] [y], int c,t_joueur joueur);

int Depl_perso(t_cellule MAP [x] [y],t_joueur *joueur,int *ligne, WINDOW *fenetre);

int Ask_Load_Save();

int Charger_Sauvegarde();

/* Dimensions et Position de la 1ère fenêtre
const int startxF = 5;
const int startyF = 2;
const int widthF = 30;
const int heightF = 31;

Dimensions et Position de la 2ème fenêtre
const int startxS = 39;
const int startyS = 2;
const int widthS = 90;
const int heightS = 31;

Dimensions et Position de la 3ème fenêtre
const int startxT = 134;
const int startyT = 2;
const int widthT = 36;
const int heightT = 31;

WINDOW * F_win;
WINDOW * S_win;
WINDOW * T_win;*/

//dans le fichier file.c

typedef struct coord{int ligne; int colonne;} t_colonne;

typedef struct elemfile{t_colonne nombre; struct elemfile*suivant;} t_elemfile;

t_elemfile*tete;
t_elemfile*queue;

void init_file();

int file_vide(void);

void ajouter(int l, int c);

void retirer(int*l, int*c);

void queue_file(int*l, int*c);
