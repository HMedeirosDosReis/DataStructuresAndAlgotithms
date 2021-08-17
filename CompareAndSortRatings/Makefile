OPTS= -g -Wall -ansi -pedantic -std=c++17

OBJS = main.o PartiallyFilledArray.o Rating.o

CC = g++ -c $(OPTS) 
LN = g++

rates: $(OBJS)
	$(LN) -o rates $(OBJS)

main.o: main.cpp PartiallyFilledArray.hpp Rating.hpp
	$(CC) main.cpp

PartiallyFilledArray.o: PartiallyFilledArray.cpp PartiallyFilledArray.hpp Rating.hpp
	$(CC) PartiallyFilledArray.cpp

Rating.o: Rating.cpp Rating.hpp 
	$(CC) Rating.cpp


clean:
	/bin/rm -f $(OBJS) rates *~

