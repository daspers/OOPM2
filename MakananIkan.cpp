#include "MakananIkan.hpp"

int MakananIkan::banyakmakananikan = 0;

MakananIkan::MakananIkan() : BendaAkuarium(0, 0, 0, 500) {
	MakananIkan::banyakmakananikan++;
}


MakananIkan::~MakananIkan() {
}

//Ctor
MakananIkan::MakananIkan(double x, double y) : BendaAkuarium(x, y, 0, 500) {
	MakananIkan::banyakmakananikan++;
	image = "makananikan";
}

void MakananIkan::gerak(){ //Update attribut ketika makanan ikan bergerak
	if(abs(this->getY() - SCREEN_HEIGHT) > 0.1){
		this->setY(this->getY() + 0.1);
	}
}

void MakananIkan::setImage(string x) {
	image = x;
}

string MakananIkan::getImage() {
	return image;
}

int MakananIkan::getBanyakMakananIkan() {
	return MakananIkan::banyakmakananikan;
}

bool MakananIkan::operator==(const MakananIkan& other) {
	return (this->getX() == other.getX() && this->getY() == other.getY());
}

bool MakananIkan::operator!=(const MakananIkan& other) {
	return (this->getX() != other.getX() || this->getY() != other.getY());
}
