CC = g++
CFLAGS = -Wall -g  -pthread -std=c++11

main: server.cpp client.cpp
	mkdir -p build
	$(CC) $(CFLAGS) -c server.cpp -o build/server.o
	$(CC) $(CFLAGS) build/server.o -o build/server
	$(CC) $(CFLAGS) -c client.cpp -o build/client.o
	$(CC) $(CFLAGS) build/client.o -o build/client
	clear
clean:
	rm -f build/server.o build/server build/client.o build/client
