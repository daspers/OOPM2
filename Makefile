# Masukkan semua file cpp Anda
OBJS = Ikan.cpp Posisi.cpp Movement.cpp main.cpp oop.cpp Player.cpp MakananIkan.cpp

CC = g++
COMPILER_FLAGS = -std=c++14 -Wall -O2
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = oopquarium
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
