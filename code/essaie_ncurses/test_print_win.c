#include <curses.h>
#include <stdlib.h>
#define ENTER 10
#define ESCAPE 27
void init_curses()
{
        initscr();
        start_color();
        init_pair(1,COLOR_WHITE,COLOR_BLUE);
        init_pair(2,COLOR_RED,COLOR_GREEN);
        init_pair(3,COLOR_RED,COLOR_WHITE);
	init_pair(4,COLOR_BLUE,COLOR_YELLOW);
	init_pair(5,COLOR_BLUE,COLOR_CYAN);
	curs_set(0);
        noecho();
        keypad(stdscr,TRUE);
}
void draw_menubar(WINDOW *menubar)
{
        wbkgd(menubar,COLOR_PAIR(5));
        waddstr(menubar,"File");
        wattron(menubar,COLOR_PAIR(3));
        waddstr(menubar,"(F1)");
        wattroff(menubar,COLOR_PAIR(3));
        wmove(menubar,0,10);
        waddstr(menubar,"Edit");
        wattron(menubar,COLOR_PAIR(3));
        waddstr(menubar,"(F2)");
	wmove(menubar,0,20);
        wattroff(menubar,COLOR_PAIR(3));
	waddstr(menubar,"Search");
	wattron(menubar,COLOR_PAIR(3));
	waddstr(menubar,"(F3)");
	wmove(menubar,0,31);
	wattroff(menubar,COLOR_PAIR(3));
        waddstr(menubar,"Cursor ");
	wattron(menubar,COLOR_PAIR(3));
	waddstr(menubar,"(F4)");
	wmove(menubar,0,43);
	wattroff(menubar,COLOR_PAIR(3));
	waddstr(menubar,"Compile");
	wattron(menubar,COLOR_PAIR(3));
	waddstr(menubar,"(F5)");
        wattroff(menubar,COLOR_PAIR(3));
	wmove(menubar,0,56);
	waddstr(menubar,"Help");
	wattron(menubar,COLOR_PAIR(3));
	waddstr(menubar,"(F6)");
        wattroff(menubar,COLOR_PAIR(3));
	wmove(menubar,0,66);
	waddstr(menubar,"Exit");
	wattron(menubar,COLOR_PAIR(3));
	waddstr(menubar,"(F7)");

}
WINDOW **draw_menu(int start_col)
{
        int i;
        WINDOW **items;
        items=(WINDOW **)malloc(9*sizeof(WINDOW *));
	items[0]=newwin(6,19,1,start_col);
        wbkgd(items[0],COLOR_PAIR(2));
    //    box(items[0],ACS_VLINE,ACS_HLINE);
       //wprintw(items[1],"new");

	items[1]=subwin(items[0],1,17,2,start_col+1);
        items[2]=subwin(items[0],1,17,3,start_col+1);
        items[3]=subwin(items[0],1,17,4,start_col+1);
        items[4]=subwin(items[0],1,17,5,start_col+1);
        items[5]=subwin(items[0],1,17,6,start_col+1);
        items[6]=subwin(items[0],1,17,7,start_col+1);
    ///  items[7]=subwin(items[0],1,17,8,start_col+1);
    //    items[8]=subwin(items[0],1,17,9,start_col+1);
///        for (i=1;i<9;i++)

	        wprintw(items[1],"Load",i);
	wprintw(items[2],"New",i);
	wprintw(items[3],"Save");
	wprintw(items[4],"Save as");
	wprintw(items[5],"Printer");
	      /// wprintw(items[],"FILE%d",i);
     /// wprintw(item[1],"File%d",i);
   //     wbkgd(items[1],COLOR_PAIR(1));
        wrefresh(items[0]);
        return items;
}
	WINDOW **draw_menu2(int start_col)
{
	int i;
	WINDOW **items;
	items=(WINDOW**) malloc(9*sizeof(WINDOW*));
	items[0]=newwin(5,19,1,start_col);
	wbkgd(items[0],COLOR_PAIR(2));

	items[1]=subwin(items[0],1,17,2,start_col+1);
	items[2]=subwin(items[0],1,17,3,start_col+1);
	items[3]=subwin(items[0],1,17,4,start_col+1);
	items[4]=subwin(items[0],1,17,5,start_col+1);
	items[5]=subwin(items[0],1,17,6,start_col+1);
	items[6]=subwin(items[0],1,17,7,start_col+1);

	wprintw(items[1],"Find");
	wprintw(items[2],"Find and replace");
	wprintw(items[3],"Repeat last find");
	wprintw(items[4],"Goto line number");
	wrefresh(items[0]);
	return items;
}


	WINDOW **draw_menu1(int start_col)
{

	int i;
	WINDOW **items;
       items=(WINDOW**) malloc(9*sizeof(WINDOW*));
       items[0]=newwin(6,19,1,start_col);
       wbkgd(items[0],COLOR_PAIR(2));

        items[1]=subwin(items[0],1,17,2,start_col+1);
	items[2]=subwin(items[0],1,17,3,start_col+1);
	items[3]=subwin(items[0],1,17,4,start_col+1);
	items[4]=subwin(items[0],1,17,5,start_col+1);
        items[5]=subwin(items[0],1,17,6,start_col+1);
        items[6]=subwin(items[0],1,17,7,start_col+1);

	wprintw(items[1],"Undo");
        wprintw(items[2],"Cut");
	wprintw(items[3],"Copy");
        wprintw(items[4],"Paste");
      	wprintw(items[5],"Delete");
         wrefresh(items[0]);
return items;
}

WINDOW **draw_menu4(int start_col)
 {
       int i;
       WINDOW **items;
       items=(WINDOW**) malloc(9*sizeof(WINDOW*));
       items[0]=newwin(5,19,1,start_col);
       wbkgd(items[0],COLOR_PAIR(2));

        items[1]=subwin(items[0],1,17,2,start_col+1);
        items[2]=subwin(items[0],1,17,2,start_col+1);
        items[3]=subwin(items[0],1,17,4,start_col+1);
	items[4]=subwin(items[0],1,17,4,start_col+1);
       // items[5]=subwi
       (items[0],1,17,4,start_col+1);
//	items[6]=subwin(items[0],1,17,4,start_col+1);
	wprintw(items[2],"C Compiler");
	wprintw(items[4],"C++ Compiler");
	wrefresh(items[0]);

return items;
 }


WINDOW **draw_menu5(int start_col)
{
	int i;
	WINDOW **items;
        items=(WINDOW**) malloc(9*sizeof(WINDOW*));
        items[0]=newwin(4,19,1,start_col);
        wbkgd(items[0],COLOR_PAIR(2));


        items[1]=subwin(items[0],1,17,2,start_col+1);
        items[2]=subwin(items[0],1,17,2,start_col+1);
        items[3]=subwin(items[0],1,17,2,start_col+1);
        items[4]=subwin(items[0],1,17,4,start_col+1);
//	items[5]=subwin(items[0],1,17,4,start_col+1);
 //       items[6]=subwin(items[0],1,17,4,start_col+1);

	wprintw(items[2],"Key words");
//	wprintw(items[4]," perator");
	wprintw(items[4],"Operator");
       // wprintw(items[6],"Help");
	wrefresh(items[0]);

return items;

}

void delete_menu(WINDOW **items,int count)
{
        int i;
        for (i=0;i<count;i++)
                delwin(items[i]);
        free(items);
}
int scroll_menu(WINDOW **items,int count,int menu_start_col)
{
        int key;
        int selected=0;
        while (1) {
                key=getch();
                if (key==KEY_DOWN || key==KEY_UP) {
                        wbkgd(items[selected+1],COLOR_PAIR(2));
                        wnoutrefresh(items[selected+1]);
                        if (key==KEY_DOWN) {
                                selected=(selected+1) % count;
                        } else {
                                selected=(selected+count-1) % count;
                        }
                        wbkgd(items[selected+1],COLOR_PAIR(1));
                        wnoutrefresh(items[selected+1]);
                        doupdate();
                } else if (key==KEY_LEFT || key==KEY_RIGHT) {
                        delete_menu(items,count+1);
                        touchwin(stdscr);
                        refresh();
                        items=draw_menu(60-menu_start_col);
                        return scroll_menu(items,5,60-menu_start_col);
                } else if (key==ESCAPE) {
                        return -1;
                } else if (key==ENTER) {
                        return selected;
                }
        }
}
int main()
{
    int key,t;
    WINDOW *menubar,*messagebar,*window;
    init_curses();
    bkgd(COLOR_PAIR(1));
    window=subwin(stdscr,1,80,24,0);
    wbkgd(window,COLOR_PAIR(4));
    menubar=subwin(stdscr,1,80,0,0);
    messagebar=subwin(stdscr,1,79,23,1);
    draw_menubar(menubar);
    move(2,1);
    printw("Press F1 or F2 to open the menus. ");
    printw("F9 quits.");
  ///  window=newwin(2,68,23,8);
   /// wbkgd(window,COLOR_PAIR(4));
    ///t=wgetch(window);
    refresh();

    do {
        int selected_item;
        WINDOW **menu_items;
        key=getch();
        werase(messagebar);
        wrefresh(messagebar);
        if (key==KEY_F(1))
{
            menu_items=draw_menu(0);
            selected_item=scroll_menu(menu_items,5,0);
            delete_menu(menu_items,9);

	    if (selected_item<0)
                wprintw(messagebar,
	"You haven't selected any item.");
            else
                wprintw(messagebar, "You have selected menu item %d.",selected_item+1);
            touchwin(stdscr);
            refresh();
 }         else if (key==KEY_F(2))
{
            menu_items=draw_menu1(10);
            selected_item=scroll_menu(menu_items,5,10);
            delete_menu(menu_items,9);

	    if (selected_item<0)
                wprintw(messagebar,"You haven't selected any item.");
            else
                wprintw(messagebar, "You have selected menu item %d.",selected_item+1);
           // touchwin(stdscr);
           /// window=newwin(2,68,23,12);
	    ///wbkgd(window,COLOR_PAIR(4));
	   /// t=wgetch(window);
	    touchwin(stdscr);
	    refresh();
}
	else if(key==KEY_F(3))
{
	menu_items=draw_menu2(20);
	selected_item=scroll_menu(menu_items,5,20);
	delete_menu(menu_items,9);

	if(selected_item<0)
	wprintw(messagebar,"don't select any item");
	else
	wprintw(messagebar, "You have select menu item %d",selected_item+1);
	touchwin(stdscr);
	refresh();
}
	else if(key==KEY_F(5))
{
  menu_items=draw_menu4(40);
  selected_item=scroll_menu(menu_items,5,40);
  delete_menu(menu_items,9);

  if(selected_item<0)
  wprintw(messagebar, "No item is selected");
  else
  wprintw(messagebar, "You have selected menu %d",selected_item+1);
  touchwin(stdscr);
  refresh();
}
	else if(key==KEY_F(6))
{
	menu_items=draw_menu5(55);
	selected_item=scroll_menu(menu_items,5,55);
	delete_menu(menu_items,9);

	if(selected_item<0)
	wprintw(messagebar,
	" No item is selected");
	else
	wprintw(messagebar, "You have selected menu %d",selected_item+1);
	touchwin(stdscr);
	refresh();
}

	else if(key==KEY_F(7))
{
 menu_items=draw_menu4(60);
 selected_item=scroll_menu(menu_items,5,60);
 delete_menu(menu_items,9);

 if(selected_item<0)
       wprintw(messagebar, "No item is selected");
 else
	wprintw(messagebar, "You have to select  menu %d",selected_item+1);

 touchwin(stdscr);
 refresh();
}
 } while (key!=KEY_F(9));

    delwin(menubar);
    delwin(messagebar);
    delwin(window);
    endwin();
    return 0;
}



