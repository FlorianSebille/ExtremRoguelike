#include "total.h"

void combat(){
	if(MAP[monstre.coordo_x][monstre.coordo_y+1].lieu == personnage || (monstre.coordo_x == joueur.coordo_x && monstre.coordo_y+1 == joueur.coordo_y)){
		/*monstre.HP = monstre.HP - (2*joueur.ATT-log(monstre.DEF));
		joueur.HP = joueur.HP - (monstre.ATT-log(joueur.DEF));*/
		joueur.HP = 0;
	}else if(MAP[monstre.coordo_x][monstre.coordo_y-1].lieu == personnage || (monstre.coordo_x == joueur.coordo_x && monstre.coordo_y-1 == joueur.coordo_y)){
		/*monstre.HP = monstre.HP - (2*joueur.ATT-log(monstre.DEF));
		joueur.HP = joueur.HP - (monstre.ATT-log(joueur.DEF));*/
		joueur.HP = 0;
	}else if(MAP[monstre.coordo_x+1][monstre.coordo_y-1].lieu == personnage || (monstre.coordo_x+1 == joueur.coordo_x && monstre.coordo_y-1 == joueur.coordo_y)){
		/*monstre.HP = monstre.HP - (joueur.ATT-log(monstre.DEF));
		joueur.HP = joueur.HP - (monstre.ATT-log(joueur.DEF));	*/	
		joueur.HP = 0;
	}else if(MAP[monstre.coordo_x+1][monstre.coordo_y].lieu == personnage || (monstre.coordo_x+1 == joueur.coordo_x && monstre.coordo_y == joueur.coordo_y)){
		/*monstre.HP = monstre.HP - (2*joueur.ATT-log(monstre.DEF));
		joueur.HP = joueur.HP - (monstre.ATT-log(joueur.DEF));	*/	
		joueur.HP = 0;
	}else if(MAP[monstre.coordo_x+1][monstre.coordo_y+1].lieu == personnage || (monstre.coordo_x+1 == joueur.coordo_x && monstre.coordo_y+1 == joueur.coordo_y)){
		/*monstre.HP = monstre.HP - (joueur.ATT-log(monstre.DEF));
		joueur.HP = joueur.HP - (monstre.ATT-log(joueur.DEF));	*/	
		joueur.HP = 0;
	}else if(MAP[monstre.coordo_x-1][monstre.coordo_y-1].lieu == personnage || (monstre.coordo_x-1 == joueur.coordo_x && monstre.coordo_y-1 == joueur.coordo_y)){
	/*	monstre.HP = monstre.HP - (joueur.ATT-log(monstre.DEF));
		joueur.HP = joueur.HP - (monstre.ATT-log(joueur.DEF));	*/	
		joueur.HP = 0;
	}else if(MAP[monstre.coordo_x-1][monstre.coordo_y].lieu == personnage || (monstre.coordo_x-1 == joueur.coordo_x && monstre.coordo_y == joueur.coordo_y)){
		/*monstre.HP = monstre.HP - (2*joueur.ATT-log(monstre.DEF));
		joueur.HP = joueur.HP - (monstre.ATT-log(joueur.DEF));	*/
		joueur.HP = 0;	
	}else if(MAP[monstre.coordo_x-1][monstre.coordo_y+1].lieu == personnage || (monstre.coordo_x-1 == joueur.coordo_x && monstre.coordo_y+1 == joueur.coordo_y)){
		/*monstre.HP = monstre.HP - (joueur.ATT-log(monstre.DEF));
		joueur.HP = joueur.HP - (monstre.ATT-log(joueur.DEF));*/
		joueur.HP = 0;
	}
	if(joueur.HP < 0){
		joueur.HP = 0;
	}
}
