#include <iostream>
#include <cmath>
#include "Posisi.hpp"

using namespace std;

//Ctor
//Menginisiasi nilai x dan y dengan 0
Posisi::Posisi(){
    x = 0;
    y = 0;
}
//Menginisiasi nilai x dengan parameter int pertama dan nilai y dengan parameter int kedua
Posisi::Posisi(double x, double y) {
    this->x = x;
    this->y = y;
} 

Posisi::Posisi(const Posisi& other) {
	this->x = other.getX();
	this->y = other.getY();
}

Posisi& Posisi::operator=(const Posisi& other) {
	this->x = other.x;
	this->y = other.y;

	return *this;
}


// set
//Untuk mengubah nilai x dengan sebuah parameter
void Posisi::setX(double temp){
    x = temp;
}
//Untuk menbubah nilai y dengan integer
void Posisi::setY(double temp){
    y = temp;
}

//getter
//Untuk mengembalikan nilai x
double Posisi::getX() const{
    return x;
}
//Untuk mengembalikan nilai y
double Posisi::getY() const{
    return y;
}

//method
//Untuk menghitung jarak dari 2 posisi
double hitungjarak(Posisi p1, Posisi p2){
    return sqrt( pow(p1.getX()-p2.getX(), 2) + pow(p1.getY()-p2.getY(), 2) );
}