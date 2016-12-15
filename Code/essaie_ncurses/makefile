all: exe clean

exe: test_ncurses.o
	gcc -o exe test_ncurses.o -lncurses
test_ncurses.o: test_ncurses.c
	gcc -c test_ncurses.c -lncurses

clean:
	rm *.o
