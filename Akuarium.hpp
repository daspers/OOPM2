#ifndef AKUARIUM_HPP
#define AKUARIUM_HPP

#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include "Ikan.hpp"
#include "List.hpp"
#include "Player.hpp"
#include "MakananIkan.hpp"
#include "Koin.hpp"
#include "Siput.hpp"
#include "Guppy.hpp"
#include "Piranha.hpp"

using namespace std;

//Kelas Akuarium adalah kelas yang mempunyai relasi has-a yang mana mempunyai atribut berupa objek-objek yang ada

class Akuarium{
	private:
  		const int tinggi, lebar; //Ukuran dari akuarium
    	List<Ikan*> ikan; //Menyimpan ikan yang ada pada akuarium
    	List<MakananIkan> makananikan; //Menyimpan makanan ikan yang ada pada akuarium
  		List<Koin> koin; //Menyimpan koin yang ada pada akuarium
    	Siput siput; //Menyimpan siput yang ada pada akuarium
	public:
		//ctor tanpa parameter dengan default size yang akan dideskripsikan dikemudian hari
	  	Akuarium();
		//ctor dengan parameter tinggi dan lebar
	    Akuarium(int,int);
		//cctor
	    Akuarium(const Akuarium&);
	    //dtor
		~Akuarium();
		//operator overloading untuk assignment
		Akuarium& operator=(const Akuarium&);
	    
	    //Mengembalikan tinggi akuarium
		int getTinggi() const;
		//Mengembalikan lebar akuarium
	    int getLebar() const;
		
		//Mengembalikan list ikan
	    List<Ikan*>& getListIkan();
		
		//Mengembalikan list makanan ikan
	    List<MakananIkan>& getListMakananIkan();
	    
	    //Mengembalikan list koin
		List<Koin>& getListKoin();
	   	
		Siput& getSiput();

		void tambahikan(Ikan*);

		void tambahmakananikan(MakananIkan);

		void tambahkoin(Koin);

		void gerak();

		void gambarAkuarium(Player, bool);
};


#endif