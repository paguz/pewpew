SRC_DIR = src
CC=g++
CFLAGS= -Wall -g -std=c++14 $(shell sdl2-config --cflags)
LDFLAGS= $(shell sdl2-config --libs) -lSDL2_image -lSDL_image
SOURCES =$(wildcard $(SRC_DIR)/*.cpp)
TARGET = pew
OBJS = $(SOURCES:.cpp=.o)
.PHONY:$(TARGET)
$(TARGET): 
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) $(LDFLAGS) 

clean:
	$(RM) $(OBJS)
