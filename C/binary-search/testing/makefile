BINARY_SEARCH_TEST: search.o main.test.o tests.o
	g++ ./testing/build/main.test.o ./testing/build/search.o ./testing/build/search.test.o -o ./testing/build/BINARY_SEARCH_TEST

tests.o: testing/search.test.cpp
	g++ -c testing/search.test.cpp -o testing/build/search.test.o

search.o: search.c
	g++ -c search.c -o testing/build/search.o

main.test.o: testing/main.test.cpp
	g++ -c testing/main.test.cpp -o testing/build/main.test.o
