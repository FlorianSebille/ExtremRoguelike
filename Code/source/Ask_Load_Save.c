/**
 * \file Ask_Load_Save.c
 * \brief Programme gérant l'affichage de la fenêtre de début de partie
 * \author LARDY Anthony
 * \author SEBILLE Florian
 * \version 1.0.1
 */


#include "total.h"


/**
  * \brief Affichage de la fenêtre de début de partie
  * \fn int Ask_Load_Save()
  * \return choix du joueur
  */
int Ask_Load_Save(){
	int startxSave, startySave, widthSave, heightSave;
	int startxStart, startyStart, widthStart, heightStart;
	int startxRules, startyRules, widthRules, heightRules;
	WINDOW *Save_Win;
	WINDOW *Start_Win;
	WINDOW *Rules_Win;
	cbreak();
	keypad(stdscr,TRUE);
	int choix;
	int i = 0;
	char choix_pseudo;
	heightSave = 10;
	widthSave = 60;
	startxSave = 50;
	startySave = 15;
	heightStart = 33;
	widthStart = 173;
	startxStart = 1;
	startyStart = 1;
	heightRules = 18;
	widthRules = 40;
	startxRules = 5;
	startyRules = 11;
	Start_Win=create_newwin(heightStart,widthStart,startyStart,startxStart,"Roguelike");  /* Création de la fenêtre Roguelike */
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
	mvwprintw(Start_Win,3,55," ______                         _  _ _ ");
	mvwprintw(Start_Win,4,55,"(_____ \\                       | |(_) | ");
	mvwprintw(Start_Win,5,55," _____) )___   ____ _   _ _____| | _| |  _ _____ ");
	mvwprintw(Start_Win,6,55,"|  __  // _ \\ / _  | | | | ___ | || | |_/ ) ___ |");
	mvwprintw(Start_Win,7,55,"| |  \\ \\ |_| ( (_| | |_| | ____| || |  _ (| ____|");
	mvwprintw(Start_Win,8,55,"|_|   |_\\___/ \\___ |____/|_____)\\_)_|_| \\_)_____)");
	mvwprintw(Start_Win,9,55,"             (_____|                             ");
	Rules_Win=create_newwin(heightRules,widthRules,startyRules,startxRules,"Règles");	/* Création de la fenêtre contenant les règles */
	mvwprintw(Rules_Win,2,2,"Cher Joueur,");
	mvwprintw(Rules_Win,3,2,"afin de profiter au maximum de");
	mvwprintw(Rules_Win,4,2,"l'expérience de jeu, nous te");
	mvwprintw(Rules_Win,5,2,"demandons de ne pas effectuer toutes");
	mvwprintw(Rules_Win,6,2,"actions qui seraient contraire au");
	mvwprintw(Rules_Win,7,2,"mode d'utilisation normal.");
	mvwprintw(Rules_Win,10,2,"Au cours de ton aventure, tu");
	mvwprintw(Rules_Win,11,2,"évolueras dans une tour formée de");
	mvwprintw(Rules_Win,12,2,"plusieurs étages, tu devras braver");
	mvwprintw(Rules_Win,13,2,"tous les dangers afin de t'emparer");
	mvwprintw(Rules_Win,14,2,"de la clé et gravir tous les étages");
	mvwprintw(Rules_Win,15,2,"pour ne pas finir en tas d'os.");
	Save_Win=create_newwin(heightSave,widthSave,startySave,startxSave,"Sauvegarde");	/* Création de la fenêtre demandant de charger une partie */
	mvwprintw(Save_Win,2,2,"Voulez vous charger une partie sauvegardée ?");
	mvwprintw(Save_Win,6,19,"o : Oui");
	mvwprintw(Save_Win,6,widthSave*0.60,"n : Non");
	wrefresh(Save_Win);
	wrefresh(Rules_Win);
	wrefresh(Start_Win);
	do{
		choix = getch();
	}while(choix != 'n' && choix != 'o'&& choix != 'p');
    if(choix == 'n'){ /* Une nouvelle partie va être crée */
			echo();
			effacer_fenetre(Save_Win);
			mvwprintw(Save_Win,2,2,"Veuillez saisir votre pseudo pour la partie");
			mvwprintw(Save_Win,6,3,"pseudo : ");
			mvwprintw(Save_Win,8,26,"appuyer sur entrer pour valider");
			move(21,62);
			wrefresh(Save_Win);
			getnstr(joueur.nom, 20);
			noecho();
			choix = 'o';
	}else if(choix == 'o'){		/* Une partie sauvegardée va être chargée */
		effacer_fenetre(Save_Win);
		int g = Charger_Sauvegarde(Save_Win);
		if(g == 'o'){
			echo();
			effacer_fenetre(Save_Win);
			mvwprintw(Save_Win,2,2,"veuillez saisir votre pseudo pour la partie");
			mvwprintw(Save_Win,6,3,"pseudo : ");
			mvwprintw(Save_Win,8,26,"appuyer sur entrer pour valider");
			move(21,62);
			wrefresh(Save_Win);
			getnstr(joueur.nom, 20);
			noecho();
			choix = 'o';
		}else choix = 'n';
	}else if(choix == 'p'){
		cheat = 1;
		effacer_fenetre(Save_Win);
		echo();
		effacer_fenetre(Save_Win);
		mvwprintw(Save_Win,2,2,"Veuillez saisir votre pseudo pour la partie");
		mvwprintw(Save_Win,6,3,"pseudo : ");
		mvwprintw(Save_Win,8,26,"appuyer sur entrer pour valider");
		move(21,62);
		wrefresh(Save_Win);
		getnstr(joueur.nom, 20);
		noecho();

		choix = 'o';
		}else choix = 'n';


	effacer_fenetre(Save_Win);
	effacer_fenetre(Rules_Win);
	effacer_fenetre(Start_Win);
	wborder(Rules_Win, ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ');
	wborder(Save_Win, ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ');
	wrefresh(Save_Win);
	wrefresh(Rules_Win);
	wrefresh(Start_Win);
	delwin(Save_Win);
	delwin(Rules_Win);
	return choix;
}
