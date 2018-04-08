#ifndef KOIN_HPP
#define KOIN_HPP

#include <iostream>
#include <string.h>
#include "BendaAkuarium.hpp"
#include "oop.hpp"

using namespace std;

class Koin : public BendaAkuarium {
	//Kelas koin ialah kelas turunan dari benda akuarium yang mempunyai atribut nilai dari koin tersebut
	private : 
		int nilai; //Menyimpan nilai dari suatu koin
		static int jumlahkoin; //Menyimpan banyaknya coin di aquarium
		string image;
	public :
		//CTOR
		Koin(double x, double, double,int);
		//cctor
	//	Koin(const Koin&);
		//operator overloading assignment
		//Koin& operator=(const Koin&);

		//getter
		//static int getJumlahKoin(); //Mengembalikan nilai jumlah koin
		int getNilai() const; //Mengembalikan nilai dari sebuah koin
		void setNilai(int);//Mengubah nilai dari suatu koin
		void gerak(); //Untuk pergerakan dari sebuah koin
		string getImage() const;
		void setImage(string);
};

#endif
