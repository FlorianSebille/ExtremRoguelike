#include <ncurses.h>
#define TAILLE 100

//dans le fichier GenWindows.c
WINDOW * create_newwin(int height, int width, int starty, int startx, char * label);
void destroy_win(WINDOW *local_win);

//dans le fichier test_taille_terminal.c
int taille_terminal();

//dans le fichier chat.c
void ecrire_chat(WINDOW *chatwin,int *ligne,int position_perso);

int addsauv(WINDOW *centerwin);
