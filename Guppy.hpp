#ifndef GUPPY_HPP
#define GUPPY_HPP

#include "Ikan.hpp"
#include "List.hpp"
#include "MakananIkan.hpp"

class Guppy : public Ikan {
//Kelas Guppy ialah turunan dari kelas Ikan yang merupakan ikan normal
//dan mempunyai beberapa attribut tambahan dan mempunyai fungsi tambahan
	private :
      	static const int waktukointurun; //Waktu guppy untuk menghasilkan koin
        static const int* naiklevel; //Berapa makanan yang dibutuhkan oleh guppy untuk naik level
        int waktuproduksi; //Waktu untuk mengetahui apakah Guppy menghasilkan koin atau tidak
        int level; //Menyimpan level dari guppy
        int jumlahmakanyangdimakan; //Menyimpan jumlah makanan yang telah dimakan oleh guppy
        static int jumlahguppy; //Menyimpan banyaknya ikan yang ada pada akuarium
    public :
        //Constructor
    	Guppy(); //Menginisiasi level = 1, jumlahmakanyangdimakan = 0, 
        Guppy(int, int); //Untuk parameter dari Inisialisasi Ikan
        
        //Cctor
        Guppy(const Guppy&); 
        
        //Dtor
        ~Guppy();
        
        //getter
        static int getWaktuKoinTurun(); //Untuk mengembalikan nilai waktu koin turun
        int getWaktuProduksi() const; //Untuk mengembalikan nilai waktu produksi
        int getLevel() const; // Untuk mengembalikan nilai level
        int getJumlahMakanYangDimakan() const; //Untuk mengembalikan nilai jumlah makan yang dimakan guppy
        static int getJumlahGuppy(); //Untuk mengembalikan jumlah guppy yang ada di akuarium
        static int getNaikLevel(int); //Untuk mengembalikan nilai level dari guppy

        //operator=
        Guppy& operator=(const Guppy&);

        //setter
        void setWaktuProduksi(int); //Untuk mengbuah nlai waktu produksi guppy
        void setLevel(int); //Untuk mengubah nilai level dari guppy
        void setJumlahMakanYangDimakan(int); //Untuk mengbuah nilai jumlah makan yang sudah dimakan guppy

    	//method
        void keluarkanCoin(); //Guppy mengeluarkan Koin
        void gerak(); //Pergerakan dari sebuah guppy
        Posisi cariMakanTerdekat(List<MakananIkan>); //Mencari Makanan ikan terdekat dari guppy
        void makan(Posisi); //Guppy makan sebuah makanan ikan
};

#endif