#include <ncurses.h>

WINDOW * create_newwin(int height, int width, int starty, int startx, char * label);
int taille_terminal();
void ecrire_chat(WINDOW *chatwin,/*int *ligne,*/char phrase[TAILLE]);
