BINARY_SEARCH: main.o search.o
	gcc build/main.o build/search.o -o build/BINARY_SEARCH

main.o: main.c
	gcc -c main.c -o build/main.o

search.o: search.c search.h
	gcc -c search.c -o build/search.o
