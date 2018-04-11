#include "Siput.hpp"

Siput::Siput() : BendaAkuarium(rand()%SCREEN_WIDTH, SCREEN_HEIGHT, 0,500) {
  pointtujuan.setX(rand()%SCREEN_WIDTH);
  pointtujuan.setY(rand()%SCREEN_HEIGHT);
  image = "siputkanan.png";
}

Siput::Siput(double x, double y, double a, double kecepatan):BendaAkuarium(x, y, a, kecepatan){
  pointtujuan.setX(rand()%SCREEN_WIDTH);
  pointtujuan.setY(rand()%SCREEN_HEIGHT);
  image = "siputkanan.png";
}

Siput::Siput (const Siput& other): BendaAkuarium(other.getX(), other.getY(), other.getArah(), other.getKecepatan()){
  this->pointtujuan = other.pointtujuan;
  this->image = other.image;
}

Siput& Siput::operator=(const Siput& other){
  this->pointtujuan= other.pointtujuan; 
  this->setImage(other.getImage());
  this->setX(other.getX());
  this->setY(other.getY());
  this->setArah(other.getArah());
  this->setKecepatan(other.getKecepatan());
  return *this;
}

//geter poin tujuan siput
Posisi Siput::getPointTujuan() const{
  return pointtujuan;
}

//mengembalikan nama file gambar koin
string Siput::getImage() const{
  return image;
}

// setter poin tujuan siput
void Siput::setPointTujuan(Posisi point){
  pointtujuan= point;
}

// setter nama file image koin
 void Siput::setImage(string i){
    this->image = i;
 }

//implementasi method gerak siput
void Siput::gerak(){
      bool kanansiput = true;

      if ((pointtujuan.getX()-this->getX())>0) {
          kanansiput = true;
          image = "siputkanan.png";
      } else {
          kanansiput = false;
          image = "siputkiri.png";
      }
      if ((kanansiput) && (this->getX() != SCREEN_WIDTH) && (abs(this->getX()-pointtujuan.getX())>0.1))
        this->setX(this->getX() + this->getKecepatan()*0.0001);
      else if ((this->getX()!= 0) && (abs(this->getX()-pointtujuan.getX())>0.1))
        this->setX(this->getX() - this->getKecepatan()*0.0001);
} 

//Untuk mencari koin terdekat dari posisi siput
int Siput::cariKoin(List<Koin>& listkoin){
  bool kanansiput = true;
  bool ketemudasar = false;
  int terdekat = -1;

  Posisi tujuan(this->getX(), this->getY());

  Posisi now(this->getX(), this->getY());

  for(int i = 0; i < listkoin.getSize() && !ketemudasar; i++) {
    if (abs(listkoin.getRef(i)->getY() - SCREEN_HEIGHT-20) < 1) {
      ketemudasar = true;
    }
  }

  if (ketemudasar) {
    tujuan.setX(99999);
    tujuan.setY(SCREEN_HEIGHT);
    for(int i = 0; i < listkoin.getSize(); i++) {
      if (abs(listkoin.getRef(i)->getY() - SCREEN_HEIGHT - 20) < 1) {
        if (abs(now.getX() - listkoin.getRef(i)->getX()) < abs(now.getX() - tujuan.getX())) {
          terdekat = i;
          tujuan.setX(listkoin.getRef(i)->getX());
        }
      }   
    }
  } else {
    tujuan.setX(this->getX());
    tujuan.setY(0);
    for(int i = 0; i < listkoin.getSize(); i++) {
      if (listkoin.getRef(i)->getY() > tujuan.getY()) {
        terdekat = i;
        tujuan.setX(listkoin.getRef(i)->getX());
        tujuan.setY(listkoin.getRef(i)->getY());
      }
    }
  }

  if (terdekat != -1) {
    this->setArah(atan2(listkoin.getRef(terdekat)->getY() - this->getY(), listkoin.getRef(terdekat)->getX() - this->getX()));
    if (this->getArah()*180/PI > -90 && this->getArah()*180/PI < 90) {
          image = "siputkanan.png";
          kanansiput = true;
      } else {
          image = "siputkiri.png";
          kanansiput = false;
      }
      if ((kanansiput) && (this->getX() != SCREEN_WIDTH) && (abs(this->getX()-listkoin.getRef(terdekat)->getX())>0.1))
        this->setX(this->getX() + this->getKecepatan()*0.0001);
      else if ((this->getX()!= 0) && (abs(this->getX()-listkoin.getRef(terdekat)->getX())>0.1))
        this->setX(this->getX() - this->getKecepatan()*0.0001);
      if (abs(this->getX() - listkoin.getRef(terdekat)->getX()) < 0.1 && abs(listkoin.getRef(terdekat)->getY() - SCREEN_HEIGHT-20) < 1) {
          return terdekat;
      }
  }

  return -1;
}
