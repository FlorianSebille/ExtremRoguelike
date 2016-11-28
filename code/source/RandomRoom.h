#include <ncurses.h>

typedef enum element {vide, mur, sol, porte, couloir} t_element;
typedef struct cellule {t_element lieu; int position;} t_cellule;

int aleat(int min, int max);

void fillmap();

int room_possible (int lg_mur_horiz, int lg_mur_vert, int posy, int posx);

void init_room();

void init_map();
