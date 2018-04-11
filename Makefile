# Masukkan semua file cpp Anda
OBJS = Ikan.cpp Posisi.cpp Movement.cpp MovementDriver.cpp oop.cpp Player.cpp MakananIkan.cpp Koin.cpp Siput.cpp Guppy.cpp Piranha.cpp Akuarium.cpp

CC = g++
COMPILER_FLAGS = -std=c++11 -Wall -O2
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = MovementDriver
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
