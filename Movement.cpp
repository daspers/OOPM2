#include<iostream>
#include"Movement.hpp"

using namespace std;

Movement::Movement(){
    arah = 0;
    kecepatan = 0;
}

//Menginisiasi nilai arah = x, dan kecepatan = y
Movement::Movement(double input_arah, double input_kecepatan){
    arah = input_arah;
    kecepatan = input_kecepatan;
}

Movement::Movement(const Movement& x) {
	this->arah = x.arah;
	this->kecepatan = x.kecepatan;
}

Movement::~Movement() {
	
}

//setter
//Untuk mengubah arah dari benda
void Movement::setArah(double a){
    arah = a;
}

//Untuk mengubah kecepatan dari benda
void Movement::setKecepatan(double k){
    kecepatan = k;
} 

//getter
//Untuk mengembalikan nilai arah dari benda
double Movement::getArah() const{
    return arah;
}
// Untuk mengembalikan nilai kecepatan dari benda
double Movement::getKecepatan() const{
    return kecepatan;
}