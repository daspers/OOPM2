#ifndef PLAYER_HPP
#define PLAYER_HPP

//Kelas Player adalah kelas yang digunakan untuk pemain yang akan memainkan game ini dengan atribut berupa jumlah koin yang digunakan juga sebagai score

class Player {
    private :
        int jumlahkoin;
        int banyaktelur;
    public :
        //ctor
        Player();
        //ctor player dengan koin dan banyak telur yang didefenisikan
        Player(int, int);
    
        //Mengembalikan jumlah koin dari pemain
        int getJumlahKoin() const;
        
        //Mengubah nilai koin dari pemain
        void tambahKoin(int);
        
        //Mengembalikan banyak telur dari pemain
        int getBanyakTelur() const;
        
        //Mengubah banyak telur dari pemain
        void tambahTelur();

        int getKoin() const;
};
#endif