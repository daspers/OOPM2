#include "Akuarium.hpp"

//ctor tanpa parameter dengan default size yang akan dideskripsikan dikemudian hari
Akuarium::Akuarium() : tinggi(0), lebar(0) {
}

//ctor dengan parameter panjang dan lebar
Akuarium::Akuarium(int x,int y) : lebar(x), tinggi(y) {
}

//cctor
Akuarium::Akuarium(const Akuarium& other) : lebar(other.getLebar()), tinggi(other.getTinggi()) {

}

//dtor
Akuarium::~Akuarium() {}

//operator overloading untuk assignment
Akuarium& Akuarium::operator=(const Akuarium&) {}

//Mengembalikan panjang akuarium
int Akuarium::getTinggi() const {
	return tinggi;
}

//Mengembalikan lebar akuarium
int Akuarium::getLebar() const {
	return lebar;
}

//Mengembalikan list ikan
List<Ikan*> Akuarium::getListIkan() const {
	return ikan;
}

// //Mengembalikan list makanan ikan
// List<MakananIkan> Akuarium::getListMakananIkan() const {
// 	return makananikan;
// }

// //Mengembalikan list koin
// List<Koin> Akuarium::getListKoin() const {
// 	return koin;
// }

// //prosedur untuk mengupdate isi dari aquarium
// void Akuarium::updateIsi();
// //prosedur untuk menggambarkan petak akuarium
// void Akuarium::gambarAkuarium();
// //prosedur untuk memunculkan benda akuarium secara random
// void Akuarium::spawnItem();