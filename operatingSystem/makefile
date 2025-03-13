CC = g++
CFLAGS = -Wall -g

main: main.cpp
	mkdir -p build
	$(CC) $(CFLAGS) -c main.cpp -o build/main.o
	$(CC) $(CFLAGS) build/main.o -o build/main	
	
exec: build/main
	./build/main

clean:
	rm -f build/main.o build/main
