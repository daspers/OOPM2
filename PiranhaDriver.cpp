#include <iostream>
#include "Piranha.hpp"

using namespace std;

int main(){
	double x,y;
	do{
		cout<<"Pilih absis ikan piranha:\n";
		cin>>x;
	} while (x<0 || x>853);
	do{
		cout<<"Pilih ordinat ikan piranha:\n";
		cin>>y;
	} while (y<0 || y>640);
	Piranha p1(x,y,0,4000);
	cout<<"Mau tambah Piranha lagi ngga?(y/n)\n";
	char sol;
	do{
		cin>>sol;
	}while(!(sol=='y'||sol=='n'));
	Piranha p2 = p1;
	cout<<"Absis dari piranha pertama adalah "<<p1.getX()<<endl;
	cout<<"Ordinat dari piranha pertama adalah "<<p1.getY()<<endl;
	if(sol=='y'){
		cout<<"Absis dari piranha kedua adalah "<<p2.getX()<<endl;
		cout<<"Ordinat dari piranha kedua adalah "<<p2.getY()<<endl;
	}
	cout<<endl;
	cout<<"Yeay driver piranha selesai\n";
	return 0;
}
