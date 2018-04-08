#ifndef POSISI_HPP
#define POSISI_HPP

class Posisi {
//Kelas Posisi ialah kelas yang menyimpan posisi suatu benda di akuarium
  	private :
      	double x; //Untuk menyimpan kordinat x dari sebuah benda
        double y; //Untuk menyimpan kordinat y dari sebuah benda
    public :
        //Ctor
      	Posisi(); //Menginisiasi nilai x dan y dengan 0 
        Posisi(double x, double y);
        //Menginisiasi nilai x dengan parameter int pertama dan nilai y dengan parameter int kedua
        //cctor
        Posisi(const Posisi& other);
        
        //operator=
        Posisi& operator=(const Posisi& other);

        // sett
        void setX(double x);//Untuk mengubah nilai x dengan sebuah parameter
        void setY(double y);//Untuk menbubah nilai y dengan integer
        
        //getter
        double getX() const; //Untuk mengembalikan nilai x
        double getY() const; //Untuk mengembalikan nilai y
        
        //method
        friend double hitungjarak(Posisi y, Posisi x); //Untuk menghitung jarak dari 2 posisi
};

#endif