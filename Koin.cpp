#include "Koin.hpp"

using namespace std;

string Koin::daftargambar[4] = {"koin1.png", "koin2.png", "koin3.png", "koin4.png"};

Koin::Koin(double x, double y, double kecepatan,int nilai, int i) : BendaAkuarium(x, y, 0, kecepatan), level(i) {
	this->nilai = nilai;
	image = daftargambar[i-1];
}

//Mengembalikan nilai dari sebuah koin
int Koin::getNilai() const{
	return nilai;
}

//Mengembalikan nama file dari image Koin 
string Koin::getImage() const {
	return image;
}

int Koin::getLevel() const {
	return level;
}

//Mengubah nama file image koin
void Koin::setImage(string i) {
	this->image = i;
}

//Untuk pergerakan dari sebuah koin
void Koin::gerak(){
	if (abs(this->getY() - SCREEN_HEIGHT - 20) > 0.1)
		this->setY(this->getY() + this->getKecepatan() * 0.01);
}