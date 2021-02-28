DEBUG = -g
OPTS = $(DEBUG) -Wall -ansi -pedantic

CC=g++ $(OPTS) -c
LN=g++

OBJS = main.o Term.o Token.o 

proj1: $(OBJS)
	$(LN) -o proj1 $(OBJS)

main.o: main.cpp Term.hpp Token.hpp 
	$(CC) main.cpp

Term.o: Term.cpp Term.hpp Token.hpp
	$(CC) Term.cpp

Token.o: Token.cpp Token.hpp
	$(CC) Token.cpp


clean:
	/bin/rm -rf $(OBJS) proj1


