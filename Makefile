all: mites_and_stars

mites_and_stars: main.o universe.o mite.o node.o star.o cthulu.o
	g++  -o bin/mites_and_stars obj/main.o obj/universe.o obj/mite.o obj/node.o obj/star.o obj/cthulu.o -pthread

main.o: src/main.cpp
	g++  -c -g -std=c++11 -o obj/main.o src/main.cpp -lpthread

universe.o: src/universe.cpp
	g++  -c -g -std=c++11 -o obj/universe.o src/universe.cpp -lpthread

mite.o: src/mite.cpp
	g++  -c -g -std=c++11 -o obj/mite.o src/mite.cpp -lpthread

node.o: src/node.cpp
	g++  -c -g -std=c++11 -o obj/node.o src/node.cpp -lpthread

star.o: src/star.cpp
	g++ -c -g -std=c++11 -o obj/star.o src/star.cpp -lpthread

cthulu.o: src/cthulu.cpp
	g++  -c -g -std=c++11 -o obj/cthulu.o src/cthulu.cpp -lpthread

clean:
	rm obj/*.o  bin/*

install: 
	cp bin/mites_and_stars /usr/local/bin
