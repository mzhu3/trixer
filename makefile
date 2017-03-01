OBJECTS= main.o matrix.o display.o draw.o
CFLAGS= -Wall
CC= gcc

main: $(OBJECTS)
	$(CC) -o main $(OBJECTS)

main.o: main.c matrix.h matrix.c
	$(CC) -c main.c

matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c

display.o: display.c display.h ml6.h
	$(CC) $(CFLAGS) -c display.c

draw.o: draw.c draw.h ml6.h matrix.h
	$(CC) $(CFLAGS) -c draw.c

run: main
	./main

clean:
	rm *.o *~
