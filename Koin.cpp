#include "Koin.hpp"

using namespace std;
Koin::Koin(double x, double y, double kecepatan,int nilai) : BendaAkuarium(x, y, 0, kecepatan) {
	this->nilai = nilai;
	image = "koin.png";
}

//Mengembalikan nilai dari sebuah koin
int Koin::getNilai() const{
	return nilai;
}

//Mengembalikan nama file dari image Koin 
string Koin::getImage() const {
	return image;
}

//Mengubah nama file image koin
void Koin::setImage(string i) {
	this->image = i;
}

//Untuk pergerakan dari sebuah koin
void Koin::gerak(){
	if (abs(this->getY() - SCREEN_HEIGHT) > 0.1)
		this->setY(this->getY() + this->getKecepatan() * 0.01);
}