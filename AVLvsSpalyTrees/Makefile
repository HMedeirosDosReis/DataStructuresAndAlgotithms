OPTS= -g -Wall -ansi -pedantic -std=c++17

OBJS = main.o AVLTree.o AVLNode.o SplayNode.o SplayTree.o SoccerTeam.o

CC = g++ -c $(OPTS) 
LN = g++

trees: $(OBJS)
	$(LN) -o trees $(OBJS)

main.o: main.cpp AVLTree.hpp AVLNode.hpp SoccerTeam.hpp SplayNode.hpp SplayNode.hpp
	$(CC) main.cpp

AVLTree.o: AVLTree.cpp AVLTree.hpp AVLNode.hpp SoccerTeam.hpp
	$(CC) AVLTree.cpp

AVLNode.o: AVLNode.cpp AVLNode.hpp SoccerTeam.hpp
	$(CC) AVLNode.cpp

SplayNode.o: SplayNode.cpp SplayNode.hpp SoccerTeam.hpp
	$(CC) SplayNode.cpp
	
SplayTree.o: SplayTree.cpp SplayNode.hpp SoccerTeam.hpp
	$(CC) SplayTree.cpp
	
SoccerTeam.o: SoccerTeam.hpp SoccerTeam.cpp
	$(CC) SoccerTeam.cpp


clean:
	/bin/rm -f $(OBJS) AVLtest *~

