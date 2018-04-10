
#include <iostream>
#include <math.h>
#include <sstream>
#include "List.h"
#include "Ikan.hpp"
#include "Guppy.hpp"

using namespace std;

int main(){
    double gx,gy;

    cout<< "Masukkan absis dari ikan guppy : (0-640) \n";
    cin>>gx;

    cout<< "Masukkan ordinat dari siput guppy : (0-853) \n"
    cin>>gy;

    //test ctor
    Guppy guppy(gx, gy, 0, 50);
    //test cctor
    Guppy guppycopy(guppy);
    cout<<" Ikan guppy copy telah dibuat dengan x= "<< guppycopy.getX()<< " dan y="<< guppycopy.getY()<<endl;
   
    guppy.keluarkanKoinGuppy();
    //test getter
    cout<< "Waktu keluarkan koin : "<< guppy.getWaktuKeluarkanKoin() << endl;
    cout<< "Range waktu koin keluar :"<< guppy.getWaktuKoin() <<endl;
   
    cout<< "Level guppy sekarang :"<<guppy.getLevel()<<endl;
    
    double fx,fy;

    cout<< "Guppy ingin makan"<< endl;
    cout<< "Masukkan posisi x makanan"<<endl;
    cin>> fx;
    cout<< "Masukkan posisi y makanan"<<endl;
    cin>> fy;

    Posisi feed(fx,fy);
    guppy.makan(feed);

    cout<<"Guppy telah memakan "<< guppy.getJumlahMakanYangDimakan()<<" makanan"<<endl;
    guppy.cekLevel();
    cout<<"Level guppy :"<<guppy.getLevel()<<endl;
    cout<<"Guppy harus makan "<<Guppy::getMakananNaikLevel(1)<<" makanan untuk naik level"<<endl;


    Guppy guppysama = guppy
    void setJumlahMakanYangDimakan(Guppy::getMakananNaikLevel(1));
    guppysama.setLevel(2);
    cout<<"Ada guppy yang sama dengan guppy pertama dengan level 2"<<endl;
    cout<<"Makanan yang guppy tersebut makan yaitu sejumlah "<< guppysama.getJumlahMakanYangDimakan()<<endl;

    guppy.gerak()
    cout <<"Guppy telah bergerak"<<endl;
    cout <<"posisi guppy sekarang ada di poin ("<<guppy.getX()<<","<<guppy.getY()<<")"<<endl;
    
    double x,x1,y,y1;
    cout<<"Siput ingin makan, masukkan 2 absis posisi tujuan makan:"<<endl;
    cin>> x;
    cin>> x1;
    cout<<"Masukkan 2 ordinat posisi tujuan makan: "<<endl;
    cin>>y;
    cin>>y1;

    MakananIkan makananikan(x,y);
    MakananIkan makananikan2(x1,y1);
    List<MakananIkan> listmakananikan(makananikan);
    listmakananikan.add(makananikan2);

    cout<< "Guppy mencari makanan ikan yang terdekat yaitu pada indeks : "<< guppy.cariMakanGuppy(listmakananikan)<<endl;

    return 0;
}
