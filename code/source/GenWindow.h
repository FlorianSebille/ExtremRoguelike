#include <ncurses.h>
#define TAILLE 100

WINDOW * create_newwin(int height, int width, int starty, int startx, char * label);
int taille_terminal();
void ecrire_chat(WINDOW *chatwin,/*int *ligne,*/char phrase[TAILLE]);
