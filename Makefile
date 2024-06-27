all:
	g++ -Isrc/Include -Lsrc/lib -o game *.cpp *.hpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -Wall