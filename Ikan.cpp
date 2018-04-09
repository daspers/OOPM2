#include "Ikan.hpp"

int Ikan::banyakikan = 0;

Ikan::Ikan(double x, double y, double arah, double kecepatan) : BendaAkuarium(x, y, arah, kecepatan), tahankenyang(5), hunger(10) {
	lapar = false;
	waktumakan = 0;
	banyakikan++;
	image = "ikankiri.gif";
	waktumakan = time_since_start();
}

Ikan::Ikan(const Ikan& other) : BendaAkuarium(other.getX(), other.getY(), other.getArah(), other.getKecepatan()), tahankenyang(5), hunger(10) {
	this->lapar = other.getLapar();
	this->waktumakan = other.getWaktuMakan();
}

Ikan& Ikan::operator=(const Ikan& other) {
	this->setX(other.getX());
	this->setY(other.getY());
	this->setArah(other.getArah());
	this->setKecepatan(other.getKecepatan());
}

//cctor
// Ikan::Ikan(const Ikan&);

//dtor
// Ikan::~Ikan();

//operator overloading untuk assignment
// Ikan& Ikan::operator=(const Ikan&);

//Mengembalikan koin yang diproduksi oleh ikan
// Koin Ikan::getProduksi() const {
// 	return this.produksi;
// }

//Mengembalikan kondisi ikan lapar menjadi true else false
bool Ikan::getLapar() const {
	return this->lapar;
}

//Mengembalikan waktu yang dibutuhkan sampai mencapai kondisi harus memakan/lapar
int Ikan::getTahanKenyang() const {
	return this->tahankenyang;
}

//Mengembalikan banyak kali ikan makan yang digunakan untuk mengupdate level ikan kedepannya
int Ikan::getWaktuMakan() const {
	return this->waktumakan;
}

//Mengembalikan waktu yang dibutuhkan sampai mati karena kelaparan
int Ikan::getHunger() const {
	return this->hunger;
}

//Mengembalikan nilai point tujuan sebuah ikan
Posisi Ikan::getPointTujuan() const {
	return this->pointtujuan;
}

//Mengembalikan type ikan apakah guppy atau piranha
string Ikan::getType() const {
	return this->type;
}

string Ikan::getImage() const {
    return image;
}

//prosedur untuk mengubah produksi koin dari ikan
// void Ikan::setProduksi(Koin x) {
// 	produksi = x;
// }

//prosedur untuk mengubah kondisi lapar dari ikan
void Ikan::setLapar(bool x) {
	lapar = x;
}

//prosedur untuk mengubah waktu makan dari ikan
void Ikan::setWaktuMakan(int x) {
	waktumakan = x;
}

//Prosedur untuk mengubah point tujuan dari ikan
void Ikan::setPointTujuan(Posisi x) {
	pointtujuan = x;
}

void Ikan::setImage(string x){
    image = x;
}

//virtual method untuk gerak ikan
void Ikan::gerak() {
    this->setArah(atan2(pointtujuan.getY()-this->getY(), pointtujuan.getX()-this->getX()));
    if (this->getArah()*180/PI > -90 && this->getArah()*180/PI < 90) {
        image = "ikankanan.png";
    } else {
        image = "ikankiri.gif";
    }
    this->setX(this->getX() + this->getKecepatan()*cos(this->getArah())*0.0001);
    this->setY(this->getY() + this->getKecepatan()*sin(this->getArah())*0.0001);
    if (abs(this->getX() - pointtujuan.getX()) < 0.1 && abs(this->getY() - pointtujuan.getY()) < 0.1) {
        pointtujuan.setX(rand()%SCREEN_WIDTH);
        pointtujuan.setY(rand()%SCREEN_HEIGHT);
    }
    if (int(time_since_start()) - int(waktumakan) == tahankenyang) {
    	lapar = true;
    }
}

bool Ikan::mati() {
	if (time_since_start() - this->getWaktuMakan() - this->getTahanKenyang() >= this->getHunger()) {
		return true;
	}
	return false;
}

bool Ikan::keluarkanKoinGuppy(){};

int Ikan::getLevel() const{};

int Ikan::cariMakanGuppy(List<MakananIkan>& listmakananikan){}

//virtual method untuk ikan makan
// void Ikan::makan();