#include "Akuarium.hpp"

//ctor tanpa parameter dengan default size yang akan dideskripsikan dikemudian hari
Akuarium::Akuarium() : tinggi(0), lebar(0) {
}

//ctor dengan parameter panjang dan lebar
Akuarium::Akuarium(int x,int y) : lebar(x), tinggi(y) {
}

//cctor
Akuarium::Akuarium(const Akuarium& other) : lebar(other.getLebar()), tinggi(other.getTinggi()) {

}

//dtor
Akuarium::~Akuarium() {}

//operator overloading untuk assignment
Akuarium& Akuarium::operator=(const Akuarium&) {}

//Mengembalikan panjang akuarium
int Akuarium::getTinggi() const {
	return tinggi;
}

//Mengembalikan lebar akuarium
int Akuarium::getLebar() const {
	return lebar;
}

//Mengembalikan list ikan
List<Ikan*>& Akuarium::getListIkan(){
	return ikan;
}

List<MakananIkan>& Akuarium::getListMakananIkan(){
	return makananikan;
}

//Mengembalikan list koin
List<Koin>& Akuarium::getListKoin(){
	return koin;
}

Siput& Akuarium::getSiput(){
	return siput;
}

void Akuarium::tambahikan(Ikan* newikan) {
	ikan.add(newikan);
}

void Akuarium::tambahmakananikan(MakananIkan newmakananikan) {
	makananikan.add(newmakananikan);
} 

void Akuarium::tambahkoin(Koin newkoin) {
	koin.add(newkoin);
}

void Akuarium::gerak() {
	int loop = 0;
	
	int dapatkoin = siput.cariKoin(koin);
            
    if (dapatkoin != -1) {
        koin.removeIdx(dapatkoin);
    }
	
	while(loop < ikan.getSize()) {
        if (ikan.get(loop)->getType() == "Guppy") {
            if (ikan.get(loop)->mati()) {
                ikan.removeIdx(loop);
                continue;
            }  
            if (ikan.get(loop)->getLapar()) {
                int makanandimakan = ikan.get(loop)->cariMakanGuppy(makananikan);
                if (makanandimakan != -1) {
                    makananikan.removeIdx(makanandimakan);
                }
            } else {
                ikan.get(loop)->gerak();
            }
            if (ikan.get(loop)->keluarkanKoinGuppy()) {
                if (ikan.get(loop)->getLevel() == 1) {
                    Koin newkoin(ikan.get(loop)->getX(), ikan.get(loop)->getY(), 10, 10, 1);
                    koin.add(newkoin);
                } else if (ikan.get(loop)->getLevel() == 2) {
                    Koin newkoin(ikan.get(loop)->getX(), ikan.get(loop)->getY(), 10, 20, 2);
                    koin.add(newkoin);
                } else {
                    Koin newkoin(ikan.get(loop)->getX(), ikan.get(loop)->getY(), 10, 50, 3);
                    koin.add(newkoin);
                }
            }              
        } else {
            if (ikan.get(loop)->mati()) {
                ikan.removeIdx(loop);
                continue;
            }
            if (ikan.get(loop)->getLapar()) {
                int ikandimakan = ikan.get(loop)->cariIkanTerdekat(ikan);
                if (ikandimakan != -1) {
                    Koin newkoin(ikan.get(loop)->getX(), ikan.get(loop)->getY(), 10, 100*(ikan.get(ikandimakan)->getLevel()+1), 4);
                    koin.add(newkoin);
                    ikan.removeIdx(ikandimakan);
                }
            } else {
                ikan.get(loop)->gerak();
            }
        }
        loop++;
    }

    for(int i = 0; i < makananikan.getSize(); i++) {
        makananikan.getRef(i)->gerak();
        if (abs(makananikan.get(i).getY() - SCREEN_HEIGHT - 70) < 0.1) {
            makananikan.removeIdx(i);
        }
    }

    for(int i = 0; i < koin.getSize(); i++) {
        koin.getRef(i)->gerak();
    }

    
}

void Akuarium::gambarAkuarium(Player habibi, bool kurangkoin) {
	draw_image("Aquarium6.jpg", SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
            draw_text("Panah untuk bergerak, r untuk reset, x untuk keluar", 18, 10, 10, 0, 0, 0);
	for(int i = 0; i < ikan.getSize(); i++) {
        draw_image(ikan.get(i)->getImage(), ikan.get(i)->getX(), ikan.get(i)->getY()-100);
    }

    for(int i = 0; i < makananikan.getSize(); i++) {
        draw_image(makananikan.getRef(i)->getImage(), makananikan.get(i).getX(), makananikan.get(i).getY()-100);
    }

    for(int i = 0; i < koin.getSize(); i++) {
        draw_image(koin.getRef(i)->getImage(), koin.get(i).getX(), koin.get(i).getY()-100);
    }

    if (habibi.getBanyakTelur()==0){
        draw_image("telor1.png",718,100);
    }else if (habibi.getBanyakTelur()==1){
        draw_image("telor2.png",718,100);
    }else{
        draw_image("telor3.png",718,100);
    }
    draw_image(siput.getImage(), siput.getX(), siput.getY()-100);
	if (kurangkoin) {
        draw_text("Koin Player : " +  std::to_string(habibi.getKoin()), 18, 10, 50, 255, 0, 0);
    } else {
        draw_text("Koin Player : " +  std::to_string(habibi.getKoin()), 18, 10, 50, 0, 0, 0);
    }
    draw_text("Banyak telur: " + std::to_string(habibi.getBanyakTelur()),18,10,100,0,0,0);
}
// //prosedur untuk mengupdate isi dari aquarium
// void Akuarium::updateIsi();
// //prosedur untuk menggambarkan petak akuarium
// void Akuarium::gambarAkuarium();
// //prosedur untuk memunculkan benda akuarium secara random
// void Akuarium::spawnItem();