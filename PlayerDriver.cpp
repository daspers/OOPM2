#include<iostream>
#include"Player.hpp"

using namespace std;

int main(){
	Player Harry(10000, 1);
	Player Habibi = Harry;
	Player Tony;
	Habibi.tambahKoin(200);
	Harry.tambahTelur();
	Tony.tambahTelur();
	Tony.tambahTelur();
	Tony.tambahTelur();
	cout<<"Jumlah Koin Harry: "<<Harry.getJumlahKoin()<<", Jumlah Telur Harry: "<<Harry.getBanyakTelur()<<endl;
	cout<<"Jumlah Koin Habibi: "<<Habibi.getJumlahKoin()<<", Jumlah Telur Habibi: "<<Habibi.getBanyakTelur()<<endl;
	cout<<"Jumlah Koin Tony: "<<Tony.getJumlahKoin()<<", Jumlah Telur Tony: "<<Tony.getBanyakTelur()<<endl;
	return 0;
}
