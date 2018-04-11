#include <iostream>
#include "Siput.hpp"

using namespace std;

int main(){
	double sx,sy,px,py;
	cout<< "masukkan absis dari siput pertama: \n";
	cin>>sx;
	do{
		cout<< "masukkan ordinat dari siput pertama: \n";
		cin>>sy;
	} while (sy!=640);
	Siput s1(sx, sy, 0 , 50);
	Siput s2 = s1;
	cout<<"Siput pertama berada pada koordinat ("<<s1.getX()<<","<<s1.getY()<<")\n";
	cout<<"Siput kedua yang berasal dari cctor berada pada koordinat ("<<s2.getX()<<","<<s2.getY()<<")\n";
	
	cout<< "masukkan absis dari titik tujuan: \n";
	cin>>px;
	cout<< "masukkan ordinat dari titik tujuan: \n";
	cin>>py;


	Posisi pointtujuan(px,py);
	cout<<"Point tujuan berada pada koordinat ("<<pointtujuan.getX()<<","<<pointtujuan.getY()<<")\n";
	s1.setPointTujuan(pointtujuan);
	bool kanansiput;
	if ((pointtujuan.getX()-s1.getX())>0) {
        kanansiput = true;
        cout<<"Siput perlu bergerak ke kanan\n";
    } else {
	    kanansiput = false;
	    cout<<"Siput perlu bergerak ke kiri\n";
	}
	cout<<endl;
	while(abs(s1.getX()-pointtujuan.getX())>0.1){
		s1.gerak();
	}
	cout<<"Siput pertama setelah ke titik tujuan berada pada koordinat ("<<s1.getX()<<","<<s1.getY()<<")\n";

}
