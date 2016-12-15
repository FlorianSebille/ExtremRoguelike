
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


/**
 * \enum t_element
 * \brief type enumeration pour les cellules.
 *
 * t_element est un type enum qui sert a définir ce qu'une cellule contient par exemple
 * un mur, le sol, le joueur etc.
 */
typedef enum {vide, mur, sol, porte, couloir, personnage, uplevel, arriver, cle, food, piege, medikit, mechant} t_element;

/**
 * \struct t_cellule
 * \brief type de la matrice qui se sert jouer.
 *
 * t_cellule est une structure qui sert à stocker les differents element utile a la gestion d'une partie
 * par exemple les different objets du jeu tel que le medikit ou la nouriture et bien les monstre
 * elle sert aussi a faire le lien entre les salle.
 */

typedef struct {t_element lieu; int position; int relie; int xb;int yb;int num_salle;int presence;} t_cellule;

/**
 * \struct t_joueur
 * \brief type du joueur.
 *
 * t_joueur est une structure contenant tout les element utile consernant le joueur tel que son niveau de vie
 * ou sa nouriture, son niveau. Elle sert aussi a stocker le nom du joueur son etage ou meme sa salle.
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
 * t_monstre est une structure qui sert à stocker les differents element utile consernant les monstres
 * comme leurs coordonnés, leurs niveaux.
 */
typedef struct {int coordo_x;int coordo_y;int salle;int EXP;int HP;int ATT;int DEF;} t_monstre;

/**
 * \var t_monstre monstre
 * \brief variable monstre de type t_monstres.
 *
 * la variable monstre contient les différentes données des monstres points de vie, points d'attaques etc.
 */
t_monstre monstre;

#define x 30
#define y 89
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
int Charger_Sauvegarde();

void addsauv();

void debut_game(WINDOW *S_win, WINDOW *T_win, WINDOW *F_win);

int fin_game(WINDOW *chat_Win,WINDOW *map_Win,WINDOW *stat_Win);

//dans le fichier monstre.c
void init_presence();

int calcul_presence(int ligne, int colonne);

void depl_monstre();

//dans le fichier combat.c
void combat();

//dans le fichier file.c

/**
 * \struct t_coord
 * \brief type qui donne les coordonnés d'un objet ou d'un element.
 *
 * t_coord est une structure qui contient la ligne et la colonne d'un element.
 * il est utiliser pour donner la coordonné d'un element de la matrice.
 */
typedef struct {int ligne; int colonne;} t_coord;

/**
 * \struct t_elemfile
 * \brief type des element de la fille.
 *
 * t_elemfile est une structure contenant et l'element suivant.
 */

/**
  * \struct elemfile
  * \brief nom de la structure pour t_elemfile.
  *
  * t_elemfile est une structure contenant et l'element suivant.
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
