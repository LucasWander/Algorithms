TARGET = test.out

all: clean test.out run

test.out: testing/main.test.o list.o testing/list.test.o
	g++ -g testing/main.test.o testing/list.test.o list.o -o $(TARGET);

testing/list.test.o: testing/list.test.cpp
	gcc -g -c -o testing/list.test.o testing/list.test.cpp

list.o: list.c
	g++ -g -c -o list.o list.c

testing/main.test.o: testing/main.test.cpp testing/catch.hpp
	g++ -g -c testing/main.test.cpp -o testing/main.test.o

run:
	./$(TARGET)

clean:
	$(RM) $(TARGET)
