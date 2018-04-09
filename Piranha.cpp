#include "Piranha.hpp"

string Piranha::daftargambar[4] = {"piranhakiri.png", "piranhakanan.png", "piranhalaparkiri.png", "piranhalaparkanan.png"};

//public :
using namespace std;

//ctor memanggil ctor Ikan dan menambah jumlahpiranha
Piranha::Piranha(double x, double y, double arah, double kecepatan): Ikan(x, y, arah, kecepatan, "Piranha"), waktukeluarkankoin(5) {
	this->setImage("piranhakiri.png");
	this->setLapar(false);
}

//cctor mengkopi piranha
Piranha::Piranha(const Piranha& other): Ikan(other.getX(), other.getY(), other.getArah(), other.getKecepatan(), other.getType()), waktukeluarkankoin(5) {
	 this->waktukoin = time_since_start();
}

//dtor mengubah jumlah piranha
//Piranha::~Piranha(){

//}

//operator overloading =
Piranha& Piranha::operator=(const Piranha& other){
	this->setX(other.getX());
	this->setY(other.getY());
	this->setArah(other.getArah());
	this->setKecepatan(other.getKecepatan());
}

//getter
 int Piranha::getWaktuKeluarkanKoin() const{
 	return waktukeluarkankoin;
 } //Untuk mengembalikan nilai waktu koin turun
 double Piranha::getWaktuKoin() const{
 	return waktukoin;
 } //Untuk mengembalikan nilai waktu produksi

//method
//Fungsi yang menambahkan koin ke List<Koin>
bool Piranha::keluarkanCoinPiranha(List<Koin>& listkoi){
	double wk = this->getWaktuKoin();
	int wkk = this->getWaktuKeluarkanKoin();
	if (time_since_start() - wk >= wkk) {
		waktukoin = time_since_start();
		return true;
	}
	return false;
} 

//Fungsi yang membuat ikan bergerak ke suatu tempat
void Piranha::gerak(){
	this->setArah(atan2(this->getPointTujuan().getY()-this->getY(), this->getPointTujuan().getX()-this->getX()));
    if (this->getArah()*180/PI > -90 && this->getArah()*180/PI < 90) {
        this->setImage(Piranha::daftargambar[1]);
    } else {
        this->setImage(Piranha::daftargambar[0]);
    }
    this->setX(this->getX() + this->getKecepatan()*cos(this->getArah())*0.0001);
    this->setY(this->getY() + this->getKecepatan()*sin(this->getArah())*0.0001);
    if (abs(this->getX() - this->getPointTujuan().getX()) < 0.1 && abs(this->getY() - this->getPointTujuan().getY()) < 0.1) {
    	Posisi tujuan(rand()%SCREEN_WIDTH, rand()%SCREEN_HEIGHT);
    	this->setPointTujuan(tujuan);
    }
    if (int(time_since_start() - this->getWaktuMakan()) == this->getTahanKenyang()) {
    	this->setLapar(true);
    }
}

//Fungsi yang mencari ikan yang bisa dimakan dari List<Ikan>
//dan mengembalikkan posisi makanan yang bisa dimakan terdekat
//jika tidak ada makanan di radius akan mengembalikkan (-1, -1)
int Piranha::cariIkanTerdekat(List<Ikan*>& listikan){

	double min = 99999999999;
	int terdekat = -1;

	Posisi now(this->getX(), this->getY());

	for(int i = 0; i < listikan.getSize(); i++) {
		if (listikan.get(i)->getType()=="Guppy") {
			Posisi a(listikan.get(i)->getX(), listikan.get(i)->getY());
			if (min > hitungjarak(a, now)) {
				terdekat = i;
				min = hitungjarak(a, now);
			}
		}
	}

	if (terdekat != -1) {
		this->setArah(atan2(listikan.get(terdekat)->getY() - this->getY(), listikan.get(terdekat)->getX() - this->getX()));
		if (this->getArah()*180/PI > -90 && this->getArah()*180/PI < 90) {
        	this->setImage(Piranha::daftargambar[3]);
	    } else {
        	this->setImage(Piranha::daftargambar[2]);
	    }
	    this->setX(this->getX() + this->getKecepatan()*cos(this->getArah())*0.0001);
    	this->setY(this->getY() + this->getKecepatan()*sin(this->getArah())*0.0001);
    	if (abs(this->getX() - listikan.get(terdekat)->getX()) < 0.1 && abs(this->getY() - listikan.get(terdekat)->getY()) < 0.1) {
	        this->setLapar(false);
	        this->setWaktuMakan(time_since_start());
	        return terdekat;
	    }
	} else {
		this->setArah(atan2(this->getPointTujuan().getY()-this->getY(), this->getPointTujuan().getX()-this->getX()));
	    if (this->getArah()*180/PI > -90 && this->getArah()*180/PI < 90) {
        	this->setImage(Piranha::daftargambar[3]);
	    } else {
        	this->setImage(Piranha::daftargambar[2]);
	    }
	    this->setX(this->getX() + this->getKecepatan()*cos(this->getArah())*0.0001);
	    this->setY(this->getY() + this->getKecepatan()*sin(this->getArah())*0.0001);
	    if (abs(this->getX() - this->getPointTujuan().getX()) < 0.1 && abs(this->getY() - this->getPointTujuan().getY()) < 0.1) {
	        Posisi tujuan(rand()%SCREEN_WIDTH, rand()%SCREEN_HEIGHT);
    		this->setPointTujuan(tujuan);
	    }
	}

	return -1;
}
