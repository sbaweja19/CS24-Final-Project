#Makefile 

CXX_FLAG = --std=c++11 -g

all: runMovies #tests

runMovies: main.o movies.o utility.o
	g++ $(CXX_FLAG) -o runMovies main.o movies.o utility.o

#tests: tests.o movies.o
#	g++ $(CXX_FLAG) -o tests movies.o tests.o

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp 

#tests.o: tests.cpp
#	g++ -c $(CXX_FLAG) tests.cpp

movies.o: movies.cpp
	g++ -c $(CXX_FLAG) movies.cpp

utility.o: utility.cpp
	g++ -c $(CXX_FLAG) utility.cpp

clean:
	rm -f *.o
