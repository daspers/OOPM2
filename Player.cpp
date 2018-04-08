#include <iostream>
#include"Player.hpp"

using namespace std;
//Kelas Player adalah kelas yang digunakan untuk pemain yang akan memainkan game ini dengan atribut berupa jumlah koin yang digunakan juga sebagai score

//ctor
Player::Player(){
	jumlahkoin = 1000;
	banyaktelur = 0;
}
//ctor player dengan koin yang didefenisikan
Player::Player(int koin, int telur){
	jumlahkoin = koin;
	banyaktelur = telur;
}

//Mengembalikan Jumlah koin dari pemain
int Player::getJumlahKoin() const{
	return jumlahkoin;
}
//Mengubah nilai koin dari pemain
void Player::tambahKoin(int koin){
	jumlahkoin+=koin;
}

void Player::setKoin(int x) {
	jumlahkoin = x;
}

//Mengembalikan banyak telur dari pemain
int Player::getBanyakTelur() const{
	return banyaktelur;
}

//Mengubah banyak telur dari pemain
void Player::tambahTelur(){
	if(getJumlahKoin() > 50){
		banyaktelur++;
	}
}

int Player::getKoin() const {
	return jumlahkoin;
}
