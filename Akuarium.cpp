#include "Akuarium.hpp"


//ctor tanpa parameter dengan default size yang akan dideskripsikan dikemudian hari
Akuarium::Akuarium();
//ctor dengan parameter panjang dan lebar
Akuarium::Akuarium(int,int);
//cctor
Akuarium::Akuarium(const Akuarium&);
//dtor
Akuarium::~Akuarium();
//operator overloading untuk assignment
Akuarium& Akuarium::operator=(const Akuarium&);

//Mengembalikan panjang akuarium
int Akuarium::getPanjang() const;
//Mengembalikan lebar akuarium
int Akuarium::getLebar() const;
//Mengembalikan list ikan
List<Ikan*> Akuarium::getListIkan() const;
//Mengembalikan list makanan ikan
List<MakananIkan> Akuarium::getListMakananIkan() const;
//Mengembalikan list koin
List<Koin> Akuarium::getListKoin() const;

//prosedur untuk mengupdate isi dari aquarium
void Akuarium::updateIsi();
//prosedur untuk menggambarkan petak akuarium
void Akuarium::gambarAkuarium();
//prosedur untuk memunculkan benda akuarium secara random
void Akuarium::spawnItem();