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
int deplacement;
int stage_cle;
int stage_medikit;
int nb_deplacement;
int mort;
int q;
int f;


/**
 * \enum t_element
 * \brief type enumeration pour les cellules.
 *
 * t_element est un type enum qui sert a définir ce qu'une cellule contient par exemple
 * un mur, le sol, le joueur etc.
 */
typedef enum element {vide, mur, sol, porte, couloir, personnage, uplevel, arriver, cle, food, piege, medikit, mechant} t_element;

/**
 * \struct t_cellule
 * \brief type de la matrice qui se sert jouer.
 *
 * t_cellule est une structure qui sert à stocker les differents element utile a la gestion d'une partie
 * par exemple les different objets du jeu tel que le medikit ou la nouriture et bien les monstre
 * elle sert aussi a faire le lien entre les salle.
 */

typedef struct cellule {t_element lieu; int position; int relie; int xb;int yb;int num_salle;int presence;} t_cellule;

/**
 * \struct t_joueur
 * \brief type du joueur.
 *
 * t_joueur est une structure contenant tout les element utile consernant le joueur tel que son niveau de vie
 * ou sa nouriture, son niveau. Elle sert aussi a stocker le nom du joueur son etage ou meme sa salle.
 */
typedef struct joueur {char nom[20];int coordo_x;int coordo_y;t_element etat_avant;int addcle;int STAGE;int SALLE;int LEVEL;int EXP;int HP;int ATT;int DEF;int FOOD;} t_joueur;
t_joueur joueur;

/**
 * \struct t_monstre
 * \brief type des monstres.
 *
 * t_monstre est une structure qui sert à stocker les differents element utile consernant les monstres
 * comme leurs coordonnés, leurs niveaux.
 */
typedef struct monstre {int coordo_x;int coordo_y;int salle;int EXP;int HP;int ATT;int DEF;} t_monstre;
t_monstre monstre;

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

void init_room(int num, int nb_salle);

int trouver_porte(int * xA, int * yA, int salle);

int relier_2Portes(int xA, int yA);

void positionzero();

void init_map(WINDOW *fenetre);

//dans le fichier affichage_Swin.c
void affichage(WINDOW *fenetre);

//dans le fichier placer_element.c
int Placer_uplevel(WINDOW *fenetre);

int Placer_perso(WINDOW *fenetre);

int Placer_cle(WINDOW *fenetre);

int Placer_monstre();

int Placer_medikit(WINDOW *fenetre);

int Placer_piege(WINDOW *fenetre);

int Placer_food(WINDOW *fenetre);


//dans le fichier Depl_perso.c
int test_depl(int c);

int Depl_perso(WINDOW *fenetre);

//dans le fichier porte_ou_escalier.c
void porte_escalier(WINDOW *chatfenetre,WINDOW *mapfenetre, int utilisateur);

//dans le fichier Ask_Load_Save.c
int Ask_Load_Save();

//dans le fichier Charger_Sauvegarde.c
int Charger_Sauvegarde();

void addsauv();

void debut_game(WINDOW *S_win, WINDOW *T_win);

int fin_game(WINDOW *chat_Win,WINDOW *map_Win,WINDOW *stat_Win);

//dans le fichier monstre.c
void init_presence(WINDOW *fenetre);

int calcul_presence(int ligne, int colonne);

void depl_monstre(WINDOW *fenetre);

//dans le fichier combat.c
void combat();

//dans le fichier file.c

typedef struct coord{int ligne; int colonne;} t_coord;

typedef struct elemfile{t_coord nombre; struct elemfile*suivant;} t_elemfile;

t_elemfile*tete;
t_elemfile*queue;

void init_file();

int file_vide(void);

void ajouter(t_coord coord);

void retirer(t_coord*coord);

void queue_file(t_coord*coord);

void file_supprimer();
