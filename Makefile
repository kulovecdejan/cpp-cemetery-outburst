CXX := g++

INCLUDEDIR := src/Include
LIBDIR := src/lib

CXXFLAGS := -I$(INCLUDEDIR) -Wall
LDFLAGS := -L$(LIBDIR) -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

SRCS := $(wildcard *.cpp)
HEADERS := $(wildcard *.hpp)

TARGET := game

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
