OPTS= -g -Wall -ansi -pedantic -std=c++17

OBJS = main.o Graph.o Connection.o Airports.o

CC = g++ -c $(OPTS) 
LN = g++

rates: $(OBJS)
	$(LN) -o shortest $(OBJS)

main.o: main.cpp Graph.hpp Connection.hpp Airports.hpp
	$(CC) main.cpp

Graph.o: Graph.cpp Graph.hpp Connection.hpp Airports.hpp
	$(CC) Graph.cpp

Connection.o: Connection.cpp Connection.hpp 
	$(CC) Connection.cpp
	
Airports.o: Airports.cpp Airports.hpp 
	$(CC) Airports.cpp

clean:
	/bin/rm -f $(OBJS) shortest *~


