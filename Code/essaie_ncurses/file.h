

typedef struct {int ligne; int colonne;} t_coord;
typedef struct elemfile{t_coord nombre; struct elemfile*suivant;} t_elemfile;

t_elemfile*tete;
t_elemfile*queue;



void init_file();
int file_vide(void);
void ajouter(t_coord coord);
void retirer(t_coord*coord);
void queue_file(t_coord*coord);
void file_supprimer();
