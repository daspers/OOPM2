#ifndef KOIN_HPP
#define KOIN_HPP

#include "BendaAkuarium.hpp"
#include <iostream>
#include "oop.hpp"
#include <cmath>

using namespace std;

class Koin : public BendaAkuarium {
//Kelas koin ialah kelas turunan dari benda akuarium yang mempunyai atribut nilai dari koin tersebut
	private : 
  		int nilai; //Menyimpan nilai dari suatu koin
  		string image;
  		const int level;
  		static string daftargambar[4];
  	public :
		//Constructor
		Koin(double, double, double,int, int);
		//getter
		int getNilai() const; //Mengembalikan nilai dari sebuah koin
		int getLevel() const;

		string getImage() const;

		void setImage(string i);

		void gerak(); //Untuk pergerakan dari sebuah koin
};

#endif
