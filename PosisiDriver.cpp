#include <iostream>
#include <cmath>
#include "Posisi.hpp"

using namespace std;

int main(){
	Posisi P;
	Posisi Q(4,3);
	cout<<"Absis P:"<<P.getX()<<", Ordinat P:"<<P.getY()<<endl;
	cout<<"Absis Q:"<<Q.getX()<<", Ordinat Q: "<<Q.getY()<<endl;
	cout<<"Jarak dari P dan Q adalah "<< hitungjarak(P,Q) << " satuan";
	return 0;
}
