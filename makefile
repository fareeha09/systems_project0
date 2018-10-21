all: main.o linkedlist.o music_library.o
	gcc -o test main.o linkedlist.o music_library.o

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c

music_library.o: music_library.c music_library.h
	gcc -c music_library.c

main.o: main.c music_library.h linkedlist.h
	gcc -c main.c

run:
	./test
