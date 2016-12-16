all: Beug clean

Beug: Beug_Segmentation.o file.o
	gcc -o Beug Beug_Segmentation.o file.o -lncurses
Beug_Segmentation.o: Beug_Segmentation.c
	gcc -c Beug_Segmentation.c
file.o: file.c
	gcc -c file.c
clean:
	rm *.o
