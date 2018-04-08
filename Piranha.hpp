#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include "Ikan.hpp"
#include "List.hpp"

class Piranha : public Ikan {
//Kelas piranha merupakan derived class dari ikan yang pada dasarnya dapat bergerak dan makan. 
//Kelas ini memiliki atribut statik jumlahpiranha untuk mengembalikan jumlah objek  piranha
	private :
		static int jumlahpiranha;
	public :
		//ctor memanggil ctor Ikan dan menambah jumlahpiranha
		Piranha();
		//cctor mengkopi piranha
		Piranha(const Piranha&);
		//dtor mengubah jumlah piranha
		~Piranha();

		//method
		//Fungsi yang menambahkan koin ke List<Koin>
		void keluarkanCoin(List<Koin>&);
		//Fungsi yang membuat ikan bergerak ke suatu tempat
		void gerak();
		//Fungsi yang mencari ikan yang bisa dimakan dari List<Ikan>
		//dan mengembalikkan posisi makanan yang bisa dimakan terdekat
		//jika tidak ada makanan di radius akan mengembalikkan (-1, -1)
		Posisi cariIkanTerdekat(const List<Ikan>&);
		//Fungsi yang mengembalikkan
		void makan(List<Ikan>&, Ikan&);
};

#endif