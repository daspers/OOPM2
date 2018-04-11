#include <iostream>
#include "Movement.hpp"

using namespace std;

int main(){
	Movement m1;
	Movement m2(2, 10);
	Movement m3 = m2;
	cout<<"arah gerakan pertama: "<<m1.getArah()<<", kecepatan gerakan pertama: "<<m1.getKecepatan()<<endl;
	cout<<"arah gerakan kedua: "<<m2.getArah()<<", kecepatan gerakan kedua: "<<m2.getKecepatan()<<endl;
	cout<<"arah gerakan ketiga: "<<m3.getArah()<<", kecepatan gerakan ketiga: "<<m3.getKecepatan()<<endl;
}
