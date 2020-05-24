TARGET = list.out

all:
	make clean
	make compile
	make run

compile: list.c main.c
	gcc -o $(TARGET) list.c main.c

run:
	./$(TARGET)

clean:
	$(RM) $(TARGET)