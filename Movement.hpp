#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

class Movement {
//Kelas Movement ialah kelas yang mengatur pergerakan dari sebuah benda, yang mempunyai 
//nilai kecepatan dan arah
	private :
  	double arah; //Arah gerak dari sebuah benda yang berisi sudut
    double kecepatan; //Kecepatan dari sebuah benda
  public :
	//Ctor
    Movement(); //Menginisiasi nilai arah = 0 dan kecepatan = 0
    Movement(double, double); //Menginisiasi nilai arah = x, dan kecepatan = y
    
    //Cctor    
    Movement(const Movement&); 
    
    //Dtor
    ~Movement();
    
    //operator=
    Movement& operator=(const Movement&);

    //setter
    void setArah(double); //Untuk mengubah arah dari benda
    void setKecepatan(double); //Untuk mengubah kecepatan dari benda
    
    //getter
    double getArah() const; //Untuk mengembalikan nilai arah dari benda
    double getKecepatan() const;// Untuk mengembalikan nilai kecepatan dari benda
};

#endif