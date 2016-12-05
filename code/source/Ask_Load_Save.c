#include "total.h"

int Ask_Load_Save(){
	int startxSave, startySave, widthSave, heightSave;
	int startxStart, startyStart, widthStart, heightStart;
	int startxRules, startyRules, widthRules, heightRules;
	WINDOW *Save_Win;
	WINDOW *Start_Win;
	WINDOW *Rules_Win;
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
	heightRules = 22;
	widthRules = 30;
	startxRules = 10;
	startyRules = 10;
	Start_Win=create_newwin(heightStart,widthStart,startyStart,startxStart,"Roguelike");
	mvwprintw(Start_Win,10,138,",-.");
	mvwprintw(Start_Win,11,118,"___,---.__         /'|`\\          __,---,___" );
	mvwprintw(Start_Win,12,115,",-'    \\`    `-.____,-' |  `-.____,-'    //    `-." );
	mvwprintw(Start_Win,13,112,",'        |           ~'\\     /`~           |        `." );
	mvwprintw(Start_Win,14,111,"/      ___//              `. ,'          ,  , \\___      \\" );
	mvwprintw(Start_Win,15,110,"|    ,-'   `-.__   _         |        ,    __,-'   `-.    |");
	mvwprintw(Start_Win,16,110,"|   /          /\\_  `   .    |    ,      _/\\          \\   |");
	mvwprintw(Start_Win,17,110,"\\  |           \\ \\`-.___ \\   |   / ___,-'/ /           |  /");
	mvwprintw(Start_Win,18,111,"\\  \\           | `._    `\\  |  /'    _,'  |           /  /");
	mvwprintw(Start_Win,19,112,"`-.\\         /'  _ `---'' , . ``---' _   `\\         /,-'");
	mvwprintw(Start_Win,20,115,"``       /     \\    ,='/ \\`=.    /      \\       ''");
	mvwprintw(Start_Win,21,123,"|__   /|\\_,--.,-.--,--._/|\\   __|");
	mvwprintw(Start_Win,22,123,"/  `./  \\\\`\\ |  |  | /,//' \\,'  \\");
	mvwprintw(Start_Win,23,122,"/   /     ||--+--|--+-/-|    \\    \\");
	mvwprintw(Start_Win,24,121,"|   |     /'\\_\\_\\ | /_/_/`\\    |   |");
	mvwprintw(Start_Win,25,121,"\\   \\__,  \\_     `~'     _/ .__/   /");
	mvwprintw(Start_Win,26,122,"`-._,-'    `-._______,-'   `-._,-'");		
	Rules_Win=create_newwin(heightRules,widthRules,startyRules,startxRules,"Rules");

	Save_Win=create_newwin(heightSave,widthSave,startySave,startxSave,"Sauvegarde");
	mvwprintw(Save_Win,2,2,"Voulez vous charger une partie sauvegardée ?");
	mvwprintw(Save_Win,6,widthSave*0.05,"LEFTWARDS ARROW: Oui");
	mvwprintw(Save_Win,6,widthSave*0.60,"RIGHTWARDS ARROW: Non");
	wrefresh(Save_Win);
	wrefresh(Rules_Win);
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