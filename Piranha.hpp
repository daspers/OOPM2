#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include <iostream>
#include <cstring>
#include "Ikan.hpp"
#include "List.hpp"

class Piranha : public Ikan {
//Kelas piranha merupakan derived class dari ikan yang pada dasarnya dapat bergerak dan makan. 
//Kelas ini memiliki atribut statik jumlahpiranha untuk mengembalikan jumlah objek  piranha
	private :
        static string daftargambar[4]; 
	public :
		//ctor memanggil ctor Ikan dan menambah jumlahpiranha
		Piranha(double x, double y, double arah, double kecepatan);
		
		//cctor mengkopi piranha
		Piranha(const Piranha&);
		
		//operator overloading =
		Piranha& operator=(const Piranha&);
		
		//Fungsi yang membuat ikan bergerak ke suatu tempat
		void gerak();
		
		//Fungsi yang mencari ikan yang bisa dimakan dari List<Ikan>
		//dan mengembalikkan posisi makanan yang bisa dimakan terdekat
		//jika tidak ada makanan di radius akan mengembalikkan (-1, -1)
		int cariIkanTerdekat(List<Ikan*>&);
		
		//Fungsi yang mengembalikkan
		void makan(List<Ikan>&, Ikan&);
};

#endif
