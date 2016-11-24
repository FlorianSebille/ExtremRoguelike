/* test pour savoir si le terminal est assez grand
pour pouvoir jouer sinon redimansionner quitter et
relancer*/
#include <ncurses.h>

int taille_terminal(){

  if(LINES < 36 && COLS < 179){
    endwin();
    printf("votre terminal est trop petit\n");
    printf("il fait %i colones et %i lignes\n",COLS,LINES);
    printf("veuillez le redimansionner pour avoir au moin\n");
    printf("180 colones et 37 lignes et relancer\n");
    return 0;
  }else{
    return 1;
  }

}
