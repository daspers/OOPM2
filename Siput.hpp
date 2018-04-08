#ifndef SIPUT_HPP
#define SIPUT_HPP

#include "BendaAkuarium.hpp"
#include "List.hpp"
#include "Koin.hpp"
#include <cstring>

using namespace std;
class Siput : public BendaAkuarium {
//Kelas siput ialah turunan dari kelas Benda Akuarium yang merupakan benda yang
//mengambil koin koin yang ada pada akuarium
	private :
	  	Posisi pointtujuan;
      string image;
  public :
    //Ctor 
    Siput(Posisi);
    //Cctor
    Siput (const Siput&);
    //Operator overloading =
    Siput& operator=(const Siput&);

  	//getter 
  	Posisi getPointTujuan() const; //Mengembalikan nilai point tujuan
    string getImage() const;
  	
    //setter
  	void setPointTujuan(Posisi); //Mengubah nilai Point Tujuan dari Siput
    void setImage(string);
  	void gerak(); //Prosedur untuk pergerakan dari iput
  	Posisi cariKoinTerdekat(List<Koin>); //Untuk mencari koin terdekat dari posisi siput
  };

#endif
