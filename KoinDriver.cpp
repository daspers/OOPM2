#include <iostream>
#include "Koin.hpp"

using namespace std;

int main(){
	Koin k(10,0,20,5,1);
	cout<<"Absis dari koin pertama adalah "<< k.getX()<<endl;
	cout<<"Ordinat dari koin pertama adalah "<< k.getY()<<endl;
	cout<<"Kecepatan dari koin pertama adalah "<< k.getKecepatan()<<endl;
	cout<<"Nilai dari koin pertama adalah "<< k.getNilai()<<endl;
	cout<<"Jenis dari koin pertama adalah "<< k.getLevel()<<endl;

	while(abs(k.getY() - SCREEN_HEIGHT) > 0.1){
		k.gerak();
	}
	bool drop = false;
	bool repeat = false;
	do{
		string desicion="";
		cout<<"Apakah koin mau anda jatuhkan?\n";
		cout<<"1) Ya\n";
		cout<<"2) Tidak\n";
		cin>>desicion;
		if(desicion == "Ya"){
			while(abs(k.getY() - SCREEN_HEIGHT) > 0.1){
				k.gerak();
			}			
			drop = true;
			repeat = false;
		}
		else if (desicion == "Tidak"){
			repeat = false;
		}
		else{
			repeat = true;
		}
	}while(repeat);

	if(drop){
		cout<<"Absis dari koin pertama adalah "<< k.getX()<<endl;
		cout<<"Ordinat dari koin pertama adalah "<< k.getY()<<endl;
		cout<<"Yeay Driver selesai"<<endl;
	}
	else{
		cout<<"Kan tidak dijatuhkan jadi drivernya selesai"<<endl;
	}

	return 0;
}
