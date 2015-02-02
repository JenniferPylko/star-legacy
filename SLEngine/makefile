INCDIR = -I/usr/include/freetype2
CPPFLAGS += -g -Wall -W $(INCDIR) -std=c++11
LFLAGS = -lSLMINX -lfreetype
CXX = g++
SOURCES = $(wildcard ./src/*.cpp)
OBJECTS = $(patsubst ./src/%.cpp,./src/%.o,$(wildcard ./src/*.cpp))
TARGET = SLMain

all: $(OBJECTS)
	test -d "./bin/" || mkdir -p "./bin/"
	$(CXX) $(CPPFLAGS) $(OBJECTS) $(LFLAGS) -o ./bin/$(TARGET)
