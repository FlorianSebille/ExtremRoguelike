
/**
 * \file total.h
 * \brief fichier contenant tous les entêtes des fonctions utilent pour le jeu.
 * \author TROTIIER Arthur
 * \author LARDY Anthony
 * \author SEBILLE Florian
 * \version 1.0.1
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>

int nombre_salle;
int deplacement;
int stage_cle;
int stage_medikit;
int nb_deplacement;
int mort;
int q;
int f;
int cheat;
int type_mort;


/**
 * \enum t_element
 * \brief Type énumeration pour les cellules.
 *
 * t_element est un type enum qui sert à définir ce qu'une cellule contient par exemple
 * un mur, le sol, le joueur etc.
 */
typedef enum {vide, mur, sol, porte, couloir, personnage, uplevel, arriver, cle, food, piege, medikit, mechant} t_element;

/**
 * \struct t_cellule
 * \brief Type de la matrice qui sert à jouer.
 *
 * t_cellule est une structure qui sert à stocker les différents éléments utile a la gestion d'une partie
 * par exemple les différents objets du jeu tel que le medikit ou la nourriture et bien les monstres,
 * elle sert aussi à faire le lien entre les salles.
 */

typedef struct {t_element lieu; int position; int relie; int xb;int yb;int num_salle;int presence;} t_cellule;

/**
 * \struct t_joueur
 * \brief Type du joueur.
 *
 * t_joueur est une structure contenant tous les éléments utiles concernant le joueur tel que ses points de vie
 * ou sa nourriture, son niveau. Elle sert aussi à stocker le nom du joueur son étage ou même sa salle.
 */
typedef struct {char nom[20];int coordo_x;int coordo_y;t_element etat_avant;int addcle;int STAGE;int SALLE;int LEVEL;int EXP;int HP;int ATT;int DEF;int FOOD;} t_joueur;

/**
 * \var t_joueur joueur
 * \brief variable joueur de type t_joueur.
 *
 * la variable joueur contient les différentes données du joueur points de vie, points d'attaques,
 * la nouriture, ses coordonnées etc.
 */
t_joueur joueur;

/**
 * \struct t_monstre
 * \brief type des monstres.
 *
 * t_monstre est une structure qui sert à stocker les différents éléments utiles concernant les monstres
 * comme leurs coordonnées, leurs niveaux.
 */
typedef struct {int coordo_x;int coordo_y;int salle;int EXP;int HP;int ATT;int DEF;} t_monstre;

/**
 * \var t_monstre monstre
 * \brief variable monstre de type t_monstres.
 *
 * la variable monstre contient les différentes données des monstres points de vie, points d'attaques etc.
 */
t_monstre monstre;

#define x 29
#define y 88
t_cellule MAP[x][y];


//dans le fichier GenWindows.c
WINDOW * create_newwin(int height, int width, int starty, int startx, char * label);
void destroy_win(WINDOW *local_win);

//dans le fichier test_taille_terminal.c
int taille_terminal();

//int addsauv(WINDOW *centerwin);

//dans le fichier RandomRoom.c
int aleat(int min, int max);

void fillmap();

int room_possible (int lg_mur_horiz, int lg_mur_vert, int posy, int posx);

void init_room(int num, int nb_salle);

int trouver_porte(int * xA, int * yA, int salle);

int relier_2Portes(int xA, int yA);

void positionzero();

void init_map();

//dans le fichier Affichage.c
void affichage(WINDOW *fenetre);

void Win_Stat(WINDOW *fenetre, int widthF);

void effacer_ligne(WINDOW *chatwin, int ligne_effacer);

void effacer_fenetre(WINDOW *chatwin);

void ecrire_chat(WINDOW *chatwin,int position_perso);

//dans le fichier placer_element.c
int Placer_uplevel();

int Placer_perso();

int Placer_cle();

int Placer_monstre();

int Placer_medikit();

int Placer_piege();

int Placer_food();


//dans le fichier Depl_perso.c
int test_depl(int c);

int Depl_perso(WINDOW *fenetre);

//dans le fichier porte_ou_escalier.c
void porte_escalier(WINDOW *chatfenetre,WINDOW *mapfenetre, WINDOW *statfenetre, int utilisateur);

//dans le fichier Ask_Load_Save.c
int Ask_Load_Save();

//dans le fichier Charger_Sauvegarde.c
int Charger_Sauvegarde(WINDOW *fenetre);

void addsauv();

//dans le fichier debut_partie.c
void debut_game(WINDOW *S_win, WINDOW *T_win);

//dans le fichier fin_de_la_partie.c
int fin_game(WINDOW *chat_Win,WINDOW *map_Win,WINDOW *stat_Win);

//dans le fichier monstre.c
void depl_monstre();

//dans le fichier combat.c
void combat();

//dans le fichier file.c

/**
 * \struct t_coord
 * \brief Type qui donne les coordonnés d'un objet ou d'un élément.
 *
 * t_coord est une structure qui contient la ligne et la colonne d'un élément.
 * il est utilisé pour donner la coordonnée d'un élément de la matrice.
 */
typedef struct {int ligne; int colonne;} t_coord;

/**
 * \struct t_elemfile
 * \brief Type des éléments de la file.
 *
 * t_elemfile est une structure contenant une valeur de type t_coord et l'élément suivant.
 */

/**
  * \struct elemfile
  * \brief Nom de la structure pour t_elemfile.
  *
  * t_elemfile est une structure contenant une valeur de type t_coord et l'élément suivant.
  */
typedef struct elemfile{t_coord nombre; struct elemfile*suivant;} t_elemfile;

t_elemfile*tete;
t_elemfile*queue;

void init_file();

int file_vide(void);

void ajouter(t_coord coord);

void retirer(t_coord*coord);

void queue_file(t_coord*coord);

void file_supprimer();
