#include "Siput.hpp"

Siput::Siput(Posisi point,double x, double y, double a, double kecepatan):BendaAkuarium(x, y, a, kecepatan){
  pointtujuan= point;
  image = "Siput.jpg";
}

Siput::Siput (const Siput& other): BendaAkuarium(other.getX(), other.getY(), other.getArah(), other.getKecepatan()){
  this->pointtujuan = other.pointtujuan;
  this->image = other.image;
}

Siput Siput::operator=(const Siput& other){
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
 void setImage(string i){
    this->image = i;
 }

//implementasi method gerak siput
void Siput::gerak(){
      bool kanansiput = true;
      double a;

      if ((pointtujuan.x-this->getX())>0) {
          kanansiput = true;
      } else {
          kanansiput = false;
      }
      if ((kanansiput) && (this!= SCREEN_WIDTH) && (abs(this->getX()-pointtujuan.x)>0.1))
        this->setX(this->getX() + this->getKecepatan()*0.0001);
      else if ((this->getX()!= 0) && (abs(this->getX()-pointtujuan.x)>0.1))
        this->setX(this->getX() - this->getKecepatan()*0.0001);
} 

//Untuk mencari koin terdekat dari posisi siput
Posisi Siput::cariKoinTerdekat(List<Koin> listkoin){
  Posisi now(this->getX(), this->getY());

  int terdekat = listkoin.cariIndeksTerdekat(now);
  
  if (terdekat != -1) {
    this->setArah(atan2(listkoin.getRef(terdekat)->getY() - this->getY(), listkoin.getRef(terdekat)->getX() - this->getX()));
    if (this->getArah()*180/PI > -90 && this->getArah()*180/PI < 90) {
          image = "siputkanan.jpg";
      } else {
          image = "siputkiri.jpg";
      }
      if ((kanansiput) && (this!= SCREEN_WIDTH) && (abs(this->getX()-listkoin.getRef(terdekat)->getX())>0.1))
        this->setX(this->getX() + this->getKecepatan()*0.0001);
      else if ((this->getX()!= 0) && (abs(this->getX()-listkoin.getRef(terdekat)->getX())>0.1))
        this->setX(this->getX() - this->getKecepatan()*0.0001);
      if (abs(this->getX() - listkoin.getRef(terdekat)->getX()) < 0.1 && abs(this->getY() - listkoin.getRef(terdekat)->getY()) < 0.1) {
          return terdekat;
      }
  } else {
    this->setArah(atan2(pointtujuan.getY()-this->getY(), pointtujuan.getX()-this->getX()));
      if (this->getArah()*180/PI > -90 && this->getArah()*180/PI < 90) {
          image = "siputkanan.jpg";
      } else {
          image = "siputkiri.jpg";
      }
      if ((kanansiput) && (this!= SCREEN_WIDTH) && (abs(this->getX()-pointtujuan.x)>0.1))
        this->setX(this->getX() + this->getKecepatan()*0.0001);
      else if ((this->getX()!= 0) && (abs(this->getX()-pointtujuan.x)>0.1))
        this->setX(this->getX() - this->getKecepatan()*0.0001);
  }
  return -1;
}
