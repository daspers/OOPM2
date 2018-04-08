#ifndef SIPUT_HPP
#define SIPUT_HPP

#include "BendaAkuarium.hpp"
#include "List.hpp"
#include "Koin.hpp"

class Siput : public BendaAkuarium {
//Kelas siput ialah turunan dari kelas Benda Akuarium yang merupakan benda yang
//mengambil koin koin yang ada pada akuarium
	private :
	  	const int radiuskoin; //Radius apakah koin dapat diambil atau tidak
	  	Posisi PointTujuan;
  public :
  	//getter 
  	Posisi getPointTujuan(); //Mengembalikan nilai point tujuan
  	int getRadiusKoin(); //Mengembalikan nilai Radius Koin dari siput

  	//setter
  	void setPointTujuan(Posisi); //Mengubah nilai Point Tujuan dari Siput

  	void gerak(); //Prosedur untuk pergerakan dari iput
    Posisi cariKoinTerdekat(List<Koin>); //Untuk mencari koin terdekat dari posisi siput
    void ambilKoin(Koin); //Untuk mengambil suatu koin yang sudan mendekati radius dari siput
};

#endif