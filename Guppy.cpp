#include "Guppy.hpp"

using namespace std;

int Guppy::makanannaiklevel = 5;
string Guppy::daftargambar[3][4] = {{"guppy1kiri.png", "guppy1kanan.png", "guppylapar1kiri.png", "guppylapar1kanan.png"}, {"guppy2kiri.png", "guppy2kanan.png", "guppylapar2kiri.png", "guppylapar2kanan.png"}, {"guppy3kiri.png", "guppy3kanan.png", "guppylapar3kiri.png", "guppylapar3kanan.png"}};


Guppy::Guppy(double x, double y, double arah, double kecepatan) : Ikan(x, y, arah, kecepatan), waktukeluarkankoin(5) {
	level = 1;
	jumlahmakanyangdimakan = 0;
	waktukoin = time_since_start();	
	this->setImage("guppy1kiri.png");
}

Guppy::Guppy(const Guppy& other) : Ikan(other.getX(), other.getY(), other.getArah(), other.getKecepatan()), waktukeluarkankoin(5) {
	level = other.getLevel();
	jumlahmakanyangdimakan = other.getJumlahMakanYangDimakan();
	waktukoin = time_since_start();
}	

int Guppy::getWaktuKeluarkanKoin() const {
	return waktukeluarkankoin;
} //Untuk mengembalikan nilai waktu koin turun

double Guppy::getWaktuKoin() const {
	return waktukoin;
} //Untuk mengembalikan nilai waktu produksi

int Guppy::getLevel() const {
	return level;
} // Untuk mengembalikan nilai level

int Guppy::getJumlahMakanYangDimakan() const {
	return jumlahmakanyangdimakan;
} //Untuk mengembalikan nilai jumlah makan yang dimakan guppy

int Guppy::getMakananNaikLevel(int) {
	return makanannaiklevel;
} //Untuk mengembalikan nilai level dari guppy

//operator=
Guppy& Guppy::operator=(const Guppy& other) {
	this->setX(other.getX());
	this->setY(other.getY());
	this->setArah(other.getArah());
	this->setKecepatan(other.getKecepatan());
	this->setLevel(other.getLevel());	
	this->setJumlahMakanYangDimakan(other.getJumlahMakanYangDimakan());
}

void Guppy::cekLevel() {
	level = min(jumlahmakanyangdimakan/(Guppy::makanannaiklevel) + 1, 3);
}

void Guppy::setLevel(int x) {
	level = x;
} //Untuk mengubah nilai level dari guppy

void Guppy::setJumlahMakanYangDimakan(int x) {
	jumlahmakanyangdimakan = x;
} //Untuk mengbuah nilai jumlah makan yang sudah dimakan guppy

bool Guppy::keluarkanKoinGuppy() {
	double wk = this->getWaktuKoin();
	int wkk = this->getWaktuKeluarkanKoin();
	if (time_since_start() - wk >= wkk) {
		waktukoin = time_since_start();
		return true;
	}
	return false;
}

void Guppy::gerak() {
	this->setArah(atan2(this->getPointTujuan().getY()-this->getY(), this->getPointTujuan().getX()-this->getX()));
    if (this->getArah()*180/PI > -90 && this->getArah()*180/PI < 90) {
        this->setImage(Guppy::daftargambar[this->getLevel()-1][1]);
    } else {
        this->setImage(Guppy::daftargambar[this->getLevel()-1][0]);
    }
    this->setX(this->getX() + this->getKecepatan()*cos(this->getArah())*0.0001);
    this->setY(this->getY() + this->getKecepatan()*sin(this->getArah())*0.0001);
    if (abs(this->getX() - this->getPointTujuan().getX()) < 0.1 && abs(this->getY() - this->getPointTujuan().getY()) < 0.1) {
    	Posisi tujuan(rand()%SCREEN_WIDTH, rand()%SCREEN_HEIGHT);
    	this->setPointTujuan(tujuan);
    }
    if (int(time_since_start()) - int(this->getWaktuMakan()) == this->getTahanKenyang()) {
    	this->setLapar(true);
    }
}

int Guppy::cariMakanGuppy(List<MakananIkan>& listmakananikan) {
	Posisi now(this->getX(), this->getY());
	int terdekat = listmakananikan.cariIndeksTerdekat(now);
	
	if (terdekat != -1) {
		this->setArah(atan2(listmakananikan.getRef(terdekat)->getY() - this->getY(), listmakananikan.getRef(terdekat)->getX() - this->getX()));
		if (this->getArah()*180/PI > -90 && this->getArah()*180/PI < 90) {
        	this->setImage(Guppy::daftargambar[this->getLevel()-1][3]);
	    } else {
        	this->setImage(Guppy::daftargambar[this->getLevel()-1][2]);
	    }
	    this->setX(this->getX() + this->getKecepatan()*cos(this->getArah())*0.0001);
    	this->setY(this->getY() + this->getKecepatan()*sin(this->getArah())*0.0001);
    	if (abs(this->getX() - listmakananikan.getRef(terdekat)->getX()) < 0.1 && abs(this->getY() - listmakananikan.getRef(terdekat)->getY()) < 0.1) {
	        this->setLapar(false);
	        this->setWaktuMakan(time_since_start());
	        jumlahmakanyangdimakan++;
	        this->cekLevel();
	        return terdekat;
	    }
	} else {
		this->setArah(atan2(this->getPointTujuan().getY()-this->getY(), this->getPointTujuan().getX()-this->getX()));
	    if (this->getArah()*180/PI > -90 && this->getArah()*180/PI < 90) {
        	this->setImage(Guppy::daftargambar[this->getLevel()-1][3]);
	    } else {
        	this->setImage(Guppy::daftargambar[this->getLevel()-1][2]);
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

