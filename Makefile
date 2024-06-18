all:
	g++ -Isrc/Include -Lsrc/lib -o game main.cpp game.cpp game.hpp -lmingw32 -lSDL2main -lSDL2