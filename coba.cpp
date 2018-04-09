#include <iostream>
#include <cstring>
#include "List.hpp"
#include "MakananIkan.hpp"
#include "Ikan.hpp"
#include "Posisi.hpp"
#include "Movement.hpp"
#include "BendaAkuarium.hpp"
#include "Guppy.hpp"
#include "oop.hpp"

using namespace std;

int main() {
	List<Ikan*> listofikan;
    Ikan* newguppy = new Guppy(rand()%SCREEN_WIDTH, rand()%SCREEN_HEIGHT, 0, 2000);
	listofikan.add(newguppy);
}