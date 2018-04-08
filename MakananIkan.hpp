#ifndef MAKANANIKAN_HPP
#define MAKANANIKAN_HPP

#include <iostream>
#include "BendaAkuarium.hpp"
#include <cstring>
#include <cmath>
#include "oop.hpp"

using namespace std;

#define ARAH_MAKANAN_IKAN 90
#define KEC_MAKANAN_IKAN 10 

class MakananIkan : public BendaAkuarium {
  //Kelas Makanan Ikan ialah turunan dari kelas benda akuarium yang menyimpan 
  //nilai nilai yang dimiliki oleh sebuah makanan ikan
  private :
    static int banyakmakananikan; //Mengembalikan jumlah makanan ikan yang ada pada akuarium
    string image;
  public :
    //Ctor
    MakananIkan(int x);
    MakananIkan();

    //Dtor
    ~MakananIkan();

    void gerak(); //Update attribut ketika makanan ikan bergerak

    void setImage(string x);

    bool operator==(const MakananIkan&);

    bool operator!=(const MakananIkan&);

    string getImage();

    static int getBanyakMakananIkan();
};

#endif
