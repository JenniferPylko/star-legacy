CPPFLAGS += -g -Wall -W $(INCDIR) -std=c++11 -fPIC
LFLAGS = -shared
CXX = g++
SOURCES = $(wildcard ./src/*.cpp)
OBJECTS = $(patsubst ./src/%.cpp,./src/%.o,$(wildcard ./src/*.cpp))
TARGET = kzqcvm.so

all: $(OBJECTS)
	test -d "./bin/" || mkdir -p "./bin/"
	$(CXX) $(CPPFLAGS) $(OBJECTS) $(LFLAGS) -o ./bin/$(TARGET)
