//private :
//static int jumlahpiranha;
//public :

//ctor memanggil ctor Ikan dan menambah jumlahpiranha
Piranha::Piranha(double x, double y, double arah, double kecepatan): Ikan(x, y, arah, kecepatan, "Piranha"), waktukeluarkankoin(5) {
	waktukoin = time_since_start();	
	this->setImage("piranhakiri.png");
}

//cctor mengkopi piranha
Piranha(const Piranha& other): Ikan(other.getX(), other.getY(), other.getArah(), other.getKecepatan(), other.getType()), waktukeluarkankoin(5) {
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
        this->setImage(Piranha::daftargambar[2]);
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

//Fungsi yang mencari ikan yang bisa dimakan dari List<Ikan>
//dan mengembalikkan posisi makanan yang bisa dimakan terdekat
//jika tidak ada makanan di radius akan mengembalikkan (-1, -1)
Posisi Piranha::cariIkanTerdekat(const List<Ikan*>& listikan){

	double min = 99999999999;
	int indeksmin = -1;

	Posisi now(this->getX(), this->getY());

	for(int i = 0; i < listikan.getSize(); i++) {
		if (listikan.get(i)->getType()="Guppy")
			Posisi a(listikan.get(i)->getX(), listikan.get(i)->getY());
		if (min > hitungjarak(a, x)) {
			indeksmin = i;
			min = hitungjarak(a, x);
		}
	}
	
	if (terdekat != -1) {
		this->setArah(atan2(listikan.getRef(indeksmin)->getY() - this->getY(), listikan.getRef(indeksmin)->getX() - this->getX()));
		if (this->getArah()*180/PI > -90 && this->getArah()*180/PI < 90) {
        	this->setImage(Piranha::daftargambar[1]);
	    } else {
        	this->setImage(Piranha::daftargambar[2]);
	    }
	    this->setX(this->getX() + this->getKecepatan()*cos(this->getArah())*0.0001);
    	this->setY(this->getY() + this->getKecepatan()*sin(this->getArah())*0.0001);
    	if (abs(this->getX() - listikan.getRef(indeksmin)->getX()) < 0.1 && abs(this->getY() - listikan.getRef(indeksmin)->getY()) < 0.1) {
	        this->setLapar(false);
	        this->setWaktuMakan(time_since_start());
	        return terdekat;
	    }
	} else {
		this->setArah(atan2(this->getPointTujuan().getY()-this->getY(), this->getPointTujuan().getX()-this->getX()));
	    if (this->getArah()*180/PI > -90 && this->getArah()*180/PI < 90) {
        	this->setImage(Piranha::daftargambar[this->getLevel()-1][3]);
	    } else {
        	this->setImage(Piranha::daftargambar[this->getLevel()-1][2]);
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
