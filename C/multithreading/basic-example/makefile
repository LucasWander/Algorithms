TARGET = thread.out

all:
	make clean
	make compile
	make run

compile: main.c
	gcc -o $(TARGET) main.c -lpthread

run:
	./$(TARGET)

clean:
	$(RM) $(TARGET)
