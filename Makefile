CXX=g++
CXXFLAGS=-g -std=c++11 -pedantic -Wno-c++11-extensions

all: clean
	${CXX} ${CXXFLAGS} remove_duplicates.cpp -o ./remove_duplicates.out

clean:
	rm -rf *.o *.out *.dSYM
