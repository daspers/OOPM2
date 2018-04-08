#include "MakananIkan.hpp"

int MakananIkan::banyakmakananikan = 0;

//Ctor
MakananIkan::MakananIkan(int x) : BendaAkuarium(x, 0, 0, 500) {
	MakananIkan::banyakmakananikan++;
	image = "makananikan";
}


void MakananIkan::gerak(){ //Update attribut ketika makanan ikan bergerak
	if(abs(this->getY() - SCREEN_HEIGHT) > 0.1){
		this->setY(this->getY() + 5);
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
