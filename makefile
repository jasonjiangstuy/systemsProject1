all: main.o songslibrary.o songslist.o
	gcc -o a.out main.o songslibrary.o songslist.o

main.o: main.c songslibrary.h songslist.h
	gcc -c main.c songslibrary.c songslist.c

run: a.out
	./a.out
