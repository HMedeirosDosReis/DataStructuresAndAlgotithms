DEBUG = -g
OPTS = $(DEBUG) -Wall -ansi -pedantic -std=c++17

CC=g++ $(OPTS) -c
LN=g++

OBJS = main.o Term.o Token.o Polynomial.o

proj2: $(OBJS)
	$(LN) -o proj2 $(OBJS)

main.o: main.cpp Term.hpp Token.hpp Polynomial.hpp MyStack.hpp
	$(CC) main.cpp

Polynomial.o: Polynomial.cpp Polynomial.hpp Term.hpp
	$(CC) Polynomial.cpp

Term.o: Term.cpp Term.hpp Token.hpp
	$(CC) Term.cpp

Token.o: Token.cpp Token.hpp
	$(CC) Token.cpp


clean:
	/bin/rm -rf $(OBJS) proj2


