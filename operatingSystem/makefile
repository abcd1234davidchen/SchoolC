CC = g++
CFLAGS = -Wall -g

main: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o
	$(CC) $(CFLAGS) main.o -o main	
	
exec: main
	./main

clean:
	rm -f main.o main
