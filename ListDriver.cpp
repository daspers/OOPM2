#include "List.hpp"
#include "MakananIkan.hpp"
#include <iostream>
#include <cstdio>

void print( List<int>& a){
	for(int i=0;i<a.getSize();i++){
		cout<<a.get(i)<<endl;
	}
}

int main(){
	List<int> a;
	cout <<"---------List Int---------\n";
	cout<<"List kosong(1/0) : "<<a.isEmpty()<<endl; 
	cout <<"mengisi List dengan : angka random sebanyak 20 buah\n";
	for(int i=0;i<20;i++)
		a.add(rand() % 1000000);
	cout<<"ukuran list : "<<a.getSize()<<endl;
	cout<<"isi list : \n";
	print(a);
	cout<<"Hapus elemen pertama\n";
	a.delFirst();
	cout<<"ukuran list : "<<a.getSize()<<endl;
	cout<<"isi list : \n";
	print(a);
	cout<<"Hapus elemen terakhir\n";
	a.delLast();
	cout<<"ukuran list : "<<a.getSize()<<endl;
	cout<<"isi list : \n";
	print(a);
	cout<<"Hapus elemen dengan indeks ke-10\n";
	a.removeIdx(10);
	cout<<"ukuran list : "<<a.getSize()<<endl;
	cout<<"isi list : \n";
	print(a);
	cout<<"indeks nilai 520059 di list : "<<a.find(520059)<<endl;
	cout<<"apakah nilai 101121 di list : "<<a.find(101121)<<endl;
	cout<<"menambahkan 1 didepan list";
	a.addFirst(1);
	cout<<"ukuran list : "<<a.getSize()<<endl;
	cout<<"isi list : \n";
	print(a);
	return 0;
}