/* test pour savoir si le terminal est assez grand
pour pouvoir jouer sinon redimansionner quitter et
relancer*/
#include <ncurses.h>

int taille_terminal(){

  if(LINES < 33 && COLS < 140){
    endwin();
    printf("votre terminal est trop petit\n");
    printf("veuillez le redimansionner\n");
    printf("et relancer\n");
    return 0;
  }else{
    return 1;
  }

}
