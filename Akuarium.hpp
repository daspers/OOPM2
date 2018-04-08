#ifndef AKUARIUM_HPP
#define AKUARIUM_HPP

#include "List.hpp"
#include "Ikan.hpp"
#include "MakananIkan.hpp"
#include "Koin.hpp"
#include "Siput.hpp"
#include "BendaAkuarium.hpp"

//Kelas Akuarium adalah kelas yang mempunyai relasi has-a yang mana mempunyai atribut berupa objek-objek yang ada

class Akuarium{
	private:
  		const int panjang, lebar; //Ukuran dari akuarium
    	List<Ikan> ikan; //Menyimpan ikan yang ada pada akuarium
    	List<MakananIkan> makananikan; //Menyimpan makanan ikan yang ada pada akuarium
  		List<Koin> koin; //Menyimpan koin yang ada pada akuarium
    	Siput siput; //Menyimpan siput yang ada pada akuarium
    
	public:
		//ctor tanpa parameter dengan default size yang akan dideskripsikan dikemudian hari
	  	Akuarium();
		//ctor dengan parameter panjang dan lebar
	    Akuarium(int,int);
		//cctor
	    Akuarium(const Akuarium&);
	    //dtor
		~Akuarium();
		//operator overloading untuk assignment
		Akuarium& operator=(const Akuarium&);
	    
	    //Mengembalikan panjang akuarium
		int getPanjang() const;
		//Mengembalikan lebar akuarium
	    int getLebar() const;
		//Mengembalikan list ikan
	    List<Ikan> getListIkan() const;
		//Mengembalikan list makanan ikan
	    List<MakananIkan> getListMakananIkan() const;
	    //Mengembalikan list koin
		List<Koin> getListKoin() const;
	    
		//prosedur untuk mengupdate isi dari aquarium
	    void updateIsi();
		//prosedur untuk menggambarkan petak akuarium
	    void gambarAkuarium();
		//prosedur untuk memunculkan benda akuarium secara random
	    void spawnItem();
};

#endif