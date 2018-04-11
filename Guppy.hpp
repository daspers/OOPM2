#ifndef GUPPY_HPP
#define GUPPY_HPP

#include "Ikan.hpp"

using namespace std;

class Guppy : public Ikan {
//Kelas Guppy ialah turunan dari kelas Ikan yang merupakan ikan normal
//dan mempunyai beberapa attribut tambahan dan mempunyai fungsi tambahan
	private :
      	const int waktukeluarkankoin;
        double waktukoin;
        static int makanannaiklevel; //Berapa makanan yang dibutuhkan oleh guppy untuk naik level
        static string daftargambar[3][4]; 
        int level; //Menyimpan level dari guppy
        int jumlahmakanyangdimakan; //Menyimpan jumlah makanan yang telah dimakan oleh guppy
    public :
        //Constructor
        Guppy(double x, double y, double arah, double kecepatan); //Untuk parameter dari Inisialisasi Ikan
        
        //Cctor
        Guppy(const Guppy&); 
        
        //getter
        int getWaktuKeluarkanKoin() const; //Untuk mengembalikan nilai waktu koin turun
        double getWaktuKoin() const; //Untuk mengembalikan nilai waktu produksi
        int getLevel() const; // Untuk mengembalikan nilai level
        int getJumlahMakanYangDimakan() const; //Untuk mengembalikan nilai jumlah makan yang dimakan guppy
        static int getMakananNaikLevel(int); //Untuk mengembalikan nilai level dari guppy

        //operator=
        Guppy& operator=(const Guppy&);

        //setter
        void setLevel(int); //Untuk mengubah nilai level dari guppy
        void setJumlahMakanYangDimakan(int); //Untuk mengbuah nilai jumlah makan yang sudah dimakan guppy
        void setWaktuKoin(double);

    	//method
        bool keluarkanKoinGuppy();
        
        void gerak(); //Pergerakan dari sebuah guppy
        
        int cariMakanGuppy(List<MakananIkan>&);

        void cekLevel();

        void makan(Posisi); //Guppy makan sebuah makanan ikan
};

#endif