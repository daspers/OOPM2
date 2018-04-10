#include <iostream>
#include "MakananIkan.hpp"

using namespace std;

int main(){
	double x,y;
	do{
		cout<<"Masukkan absis dari makanan ikan pertama anda:\n";
		cin>>x;
	} while (x<0 || x>853);
	do{
		cout<<"Masukkan ordinat dari makanan ikan pertama anda:\n";
		cin>>y;
	} while (y<0 || y>640);
	MakananIkan yummy1(x,y);
	cout<<"jadi sekarang ada "<<MakananIkan::getBanyakMakananIkan()<<" makanan ikan\n";
	cout<<"Dengan titik absis: "<<x<<endl;
	cout<<"Dan titik ordinat: "<<y<<endl;
	return 0;
}
