#include "MakananIkan.hpp"

MakananIkan::MakananIkan() : BendaAkuarium(0, 0, 0, 500) {
}


MakananIkan::~MakananIkan() {
}

MakananIkan::MakananIkan(double x, double y) : BendaAkuarium(x, y, 0, 500) {
	image = "makananikan";
}

void MakananIkan::gerak(){
	if(abs(this->getY() - SCREEN_HEIGHT - 70) > 0.1){
		this->setY(this->getY() + 0.1);
	}
}

void MakananIkan::setImage(string x) {
	image = x;
}

string MakananIkan::getImage() {
	return image;
}

bool MakananIkan::operator==(const MakananIkan& other) {
	return (this->getX() == other.getX() && this->getY() == other.getY());
}

bool MakananIkan::operator!=(const MakananIkan& other) {
	return (this->getX() != other.getX() || this->getY() != other.getY());
}