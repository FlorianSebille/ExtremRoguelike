#include <stdio.h>
#include <string.h>
#include <math.h>
#include <curses.h>
#include <stdlib.h>
#include <ncurses.h>
#define TAILLE 100
typedef struct joueur {char nom;int x;int y;int STAGE;int LEVEL;int EXP;int HP;int ATT;int DEF;int FOOD;} t_joueur;
typedef enum element {vide, mur, sol} t_element;
typedef struct cellule {t_element lieu; int position;} t_cellule;
t_joueur perso;


//dans le fichier GenWindows.c
WINDOW * create_newwin(int height, int width, int starty, int startx, char * label);
void destroy_win(WINDOW *local_win);

//dans le fichier test_taille_terminal.c
int taille_terminal();

//dans le fichier chat.c
void ecrire_chat(WINDOW *chatwin,int *ligne,int position_perso);

int addsauv(WINDOW *centerwin);

void Win_Stat(WINDOW *F_winn, int widthF);

//dans le fichier RandomRoom.c
int aleat(int min, int max);

void fillmap();

int room_possible (int lg_mur_horiz, int lg_mur_vert, int posy, int posx);

void init_room();

void init_map();
