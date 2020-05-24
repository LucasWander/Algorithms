TARGET = test.out

all: clean test.out run

test.out: testing/main.test.o list.o testing/list.test.o
	g++ testing/main.test.o testing/list.test.o list.o -o $(TARGET);

testing/list.test.o: testing/list.test.cpp 
	gcc -c -o testing/list.test.o testing/list.test.cpp

list.o: list.c 
	g++ -c -o list.o list.c 

testing/main.test.o: testing/main.test.cpp testing/catch.hpp
	g++ -c testing/main.test.cpp -o testing/main.test.o

run:
	./$(TARGET)

clean:
	$(RM) $(TARGET)