#include "total.h"

int Ask_Load_Save(){
	int startxSave, startySave, widthSave, heightSave;
	int startxStart, startyStart, widthStart, heightStart;
	WINDOW *Save_Win;
	WINDOW *Start_Win;
	cbreak();
	keypad(stdscr,TRUE);
	timeout(0);
	int choix;
	heightSave = 10;
	widthSave = 60;
	startxSave = 50;
	startySave = 15;
	heightStart = 34;
	widthStart = 170;
	startxStart = 2;
	startyStart = 2;
	Start_Win=create_newwin(heightStart,widthStart,startyStart,startxStart,"Roguelike");
	mvwprintw(Start_Win,10,110,"					     ,-.");
	mvwprintw(Start_Win,10,110,"			___,---.__          /'|`\          __,---,___");
	mvwprintw(Start_Win,10,110,"	             ,-'    \`    `-.____,-'  |  `-.____,-'    //    `-.");
	mvwprintw(Start_Win,10,110,"		   ,'        |           ~'\     /`~           |        `.");
	mvwprintw(Start_Win,10,110,"		  /      ___//              `. ,'          ,  , \___      \");
	mvwprintw(Start_Win,10,110,"             |    ,-'   `-.__   _         |        ,    __,-'   `-.    |");
	mvwprintw(Start_Win,10,110,"		 |   /          /\_  `   .    |    ,      _/\          \   |");
	mvwprintw(Start_Win,10,110,"		 \  |           \ \`-.___ \   |   / ___,-'/ /           |  /");
	mvwprintw(Start_Win,10,110,"		  \  \           | `._   `\\  |  //'   _,' |           /  /");
	mvwprintw(Start_Win,10,110,"		   `-.\         /'  _ `---'' , . ``---' _  `\         /,-'");
	mvwprintw(Start_Win,10,110,"		      ``       /     \    ,='/ \`=.    /     \       ''");
	mvwprintw(Start_Win,10,110,"			      |__   /|\_,--.,-.--,--._/|\   __|");
	mvwprintw(Start_Win,10,110,"			      /  `./  \\`\ |  |  | /,//' \,'  \");
	mvwprintw(Start_Win,10,110,"			     /   /     ||--+--|--+-/-|     \   \");
	mvwprintw(Start_Win,10,110,"			    |   |     /'\_\_\ | /_/_/`\     |   |");
	mvwprintw(Start_Win,10,110,"			     \   \__, \_     `~'     _/ .__/   /");
	mvwprintw(Start_Win,10,110,"			      `-._,-'   `-._______,-'   `-._,-'*/");
		
	Save_Win=create_newwin(heightSave,widthSave,startySave,startxSave,"Sauvegarde");
	mvwprintw(Save_Win,2,2,"Voulez vous charger une partie sauvegardée ?");
	mvwprintw(Save_Win,6,widthSave*0.05,"LEFTWARDS ARROW: Oui");
	mvwprintw(Save_Win,6,widthSave*0.60,"RIGHTWARDS ARROW: Non");
	wrefresh(Save_Win);
	wrefresh(Start_Win);
	do{
		choix = getch();
	}while(choix != KEY_RIGHT && choix != KEY_LEFT);
	effacer_fenetre(Save_Win);
	wborder(Save_Win, ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ');
	wrefresh(Save_Win);
	delwin(Save_Win);
	return choix;
}

/*


					     ,-.
			___,---.__          /'|`\          __,---,___
	             ,-'    \`    `-.____,-'  |  `-.____,-'    //    `-.
		   ,'        |           ~'\     /`~           |        `.
		  /      ___//              `. ,'          ,  , \___      \
                 |    ,-'   `-.__   _         |        ,    __,-'   `-.    |
		 |   /          /\_  `   .    |    ,      _/\          \   |
		 \  |           \ \`-.___ \   |   / ___,-'/ /           |  /
		  \  \           | `._   `\\  |  //'   _,' |           /  /
		   `-.\         /'  _ `---'' , . ``---' _  `\         /,-'
		      ``       /     \    ,='/ \`=.    /     \       ''
			      |__   /|\_,--.,-.--,--._/|\   __|
			      /  `./  \\`\ |  |  | /,//' \,'  \
			     /   /     ||--+--|--+-/-|     \   \
			    |   |     /'\_\_\ | /_/_/`\     |   |
			     \   \__, \_     `~'     _/ .__/   /
			      `-._,-'   `-._______,-'   `-._,-'*/
