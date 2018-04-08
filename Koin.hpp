#ifndef KOIN_HPP
#define KOIN_HPP

#include "BendaAkuarium.hpp"

class Koin : public BendaAkuarium {
//Kelas koin ialah kelas turunan dari benda akuarium yang mempunyai atribut nilai dari koin tersebut
	private : 
  	const int nilai; //Menyimpan nilai dari suatu koin
    static int jumlahkoin; //Menyimpan banyaknya coin dari
  public :
  	//getter
  	static int getJumlahKoin(); //Mengembalikan nilai jumlah koin
  	int getNilai(); //Mengembalikan nilai dari sebuah koin

  	void gerak(); //Untuk pergerakan dari sebuah koin
};

#endif