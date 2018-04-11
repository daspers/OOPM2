#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include "Ikan.hpp"
#include "List.hpp"
#include "Player.hpp"
#include "MakananIkan.hpp"
#include "Koin.hpp"
#include "Siput.hpp"
#include "Guppy.hpp"
#include "Piranha.hpp"
#include "Akuarium.hpp"
#include "oop.hpp"

using namespace std;

#define PI 3.14159265
#define ikani arkavkuarium.getListIkan().get(i)
#define mki arkavkuarium.getListMakananIkan().getRef(i)
#define koini arkavkuarium.getListKoin().getRef(i)
#define siputs arkavkuarium.getSiput()

const double speed = 50; // pixels per second

vector<string> split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

int main( int argc, char* args[] )
{
    init();
    
    double a = 30;
    bool sampai = false;
    int asalx = 0;
    int asaly = 0;
    bool kanan = true;

    int banyak = 0;

    // Menghitung FPS
    int frames_passed = 0;
    double fpc_start = time_since_start();
    std::string fps_text = "FPS: 0";

    Player habibi;
    Akuarium arkavkuarium;

    // Posisi ikan
    double cy = SCREEN_HEIGHT / 2;
    double cx = SCREEN_WIDTH / 2;

    bool running = true;
    double prevtime = time_since_start();
    int detiknow = 0;
    int loop = 0;
    
    bool mainmenu = true;
    bool menang= false;
    bool kurangkoin = false;
    bool kalah = false;

    while (running) {
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        handle_input();
        if (quit_pressed()) {
            running = false;
        }

        if (kalah) {
            clear_screen();
                draw_text("Kamu Kalah", 18, 10, 10, 0, 0, 0);
            update_screen();
        } else if (mainmenu) {
            clear_screen();
            for (auto key : get_clicked_mouse()) {
                switch(key) {
                    case 1: {
                        if ((get_clicked_mouseX() <= 770 && get_clicked_mouseX() >= 615) && (get_clicked_mouseY() <= 474 && get_clicked_mouseY() >= 325)) {
                            mainmenu = false;
                        } else if ((get_clicked_mouseX() <= 637 && get_clicked_mouseX() >= 541) && (get_clicked_mouseY() <= 275 && get_clicked_mouseY() >= 188)) {
                            ifstream fileikan;
                            fileikan.open("Ikan.txt");

                            while(!fileikan.eof()) {
                                string line;

                                getline(fileikan, line);
                                if (line == "") {
                                    break;
                                }

                                vector<string> splitline = split(line, ' ');

                                if (splitline[4] == "Guppy") {
                                    Ikan* newguppy = new Guppy(stod(splitline[0]), stod(splitline[1]), 0, 2000);
                                    newguppy->setLapar(stoi(splitline[2]));
                                    newguppy->setWaktuMakan(stoi(splitline[3]));
                                    newguppy->getPointTujuan().setX(stoi(splitline[5]));
                                    newguppy->getPointTujuan().setY(stoi(splitline[6]));
                                    newguppy->setImage(splitline[7]);
                                    newguppy->setWaktuRandom(stod(splitline[8]));
                                    newguppy->setWaktuKoin(stod(splitline[9]));
                                    newguppy->setLevel(stoi(splitline[10]));
                                    newguppy->setJumlahMakanYangDimakan(stoi(splitline[11]));
                                    arkavkuarium.tambahikan(newguppy);
                                } else {
                                    Ikan* newpiranha = new Piranha(stod(splitline[0]), stod(splitline[1]), 0, 4000);
                                    newpiranha->setLapar(stoi(splitline[2]));
                                    newpiranha->setWaktuMakan(stoi(splitline[3]));
                                    newpiranha->getPointTujuan().setX(stoi(splitline[5]));
                                    newpiranha->getPointTujuan().setY(stoi(splitline[6]));
                                    newpiranha->setImage(splitline[7]);
                                    newpiranha->setWaktuRandom(stod(splitline[8]));
                                    arkavkuarium.tambahikan(newpiranha);
                                }
                            }
                            mainmenu = false;

                            ifstream filekoin("Koin.txt");
                            while(!filekoin.eof()) {
                                string line;

                                getline(filekoin, line);
                                if (line == "") {
                                    break;
                                }

                                vector<string> splitline = split(line, ' ');

                                Koin newkoin(stod(splitline[0]), stod(splitline[1]), stod(splitline[2]), stoi(splitline[3]), stoi(splitline[4]));
                                arkavkuarium.tambahkoin(newkoin);
                            }

                            ifstream filemakananikan("MakananIkan.txt");
                            while(!filemakananikan.eof()) {
                                string line;

                                getline(filemakananikan, line);
                                if (line == "") {
                                    break;
                                }

                                vector<string> splitline = split(line, ' ');

                                MakananIkan newmakananikan(stod(splitline[0]), stod(splitline[1]));
                                arkavkuarium.tambahmakananikan(newmakananikan);
                            }

                            ifstream filesiput("Siput.txt");
                            string line;
                            getline(filesiput, line);
                            vector<string> splitline = split(line, ' ');
                            siputs.setX(stod(splitline[0]));
                            siputs.setY(stod(splitline[1]));

                            ifstream fileplayer("Player.txt");
                            getline(fileplayer, line);
                            splitline = split(line, ' ');
                            habibi.setKoin(stoi(splitline[0]));
                            habibi.setBanyakTelur(stoi(splitline[1]));

                            fileplayer.close();
                            filesiput.close();
                            filemakananikan.close();
                            filekoin.close();
                            fileikan.close();
                        }
                        get_clicked_mouse().erase(1);
                    
                        break;
                    }
                }
            }
            draw_image("mainmenu.png",SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
            update_screen(); 
        }else if (menang) {
            for (auto key : get_clicked_mouse()) {
                switch(key) {
                    case 1: {
                        if ((get_clicked_mouseX() <= SCREEN_WIDTH && get_clicked_mouseX() >= 0) && (get_clicked_mouseY() <= SCREEN_HEIGHT && get_clicked_mouseY() >= 0)) {
                            running= false;
                        }
                        get_clicked_mouse().erase(1);
                        break;
                    }
                }
            }    
            draw_image("congratulations.png",SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
            update_screen();
        } else {
            for (auto key : get_clicked_mouse()) {
                switch(key) {
                    case 1: {
                        int ketemu = -1;
                        for(int i = 0; i < arkavkuarium.getListKoin().getSize() && ketemu == -1; i++) {
                            if (abs(arkavkuarium.getListKoin().getRef(i)->getX() - get_clicked_mouseX()) < 40 && abs(arkavkuarium.getListKoin().getRef(i)->getY() - get_clicked_mouseY()-100) < 40) {
                                ketemu = i;
                            }
                        }
                        if (ketemu != -1) {
                            habibi.tambahKoin(arkavkuarium.getListKoin().getRef(ketemu)->getNilai());
                            arkavkuarium.getListKoin().removeIdx(ketemu);
                        } else {
                            if (((get_clicked_mouseX() > 753 || get_clicked_mouseX() < 683)) || ((get_clicked_mouseY() > 135 || get_clicked_mouseY() < 65))){
                                if (habibi.getKoin() < 5) {
                                    kurangkoin = true;
                                } else {
                                    MakananIkan newmakananikan(get_clicked_mouseX(), get_clicked_mouseY()+100);
                                    arkavkuarium.tambahmakananikan(newmakananikan);
                                    habibi.kurangkanKoin(5);   
                                    kurangkoin = false;
                                }
                            }
                        }
                        if (!menang){
                            if ((get_clicked_mouseX() <= 753 && get_clicked_mouseX() >= 683) && (get_clicked_mouseY() <= 135 && get_clicked_mouseY() >= 65)) {
                                if (habibi.getKoin() < 500) {
                                    kurangkoin = true;
                                } else {
                                    habibi.kurangkanKoin(500);
                                    habibi.tambahTelur();
                                    if (habibi.getBanyakTelur()==3){
                                        menang=true;
                                    }
                                    kurangkoin = false;
                                }
                            }
                        }
                        get_clicked_mouse().erase(1);
                        break;
                    }
                }
            }

            // Proses masukan yang bersifat "tombol"
            for (auto key : get_tapped_keys()) {
                switch (key) {
                // r untuk reset
                    case SDLK_r: {
                        cy = SCREEN_HEIGHT / 2;
                        cx = SCREEN_WIDTH / 2;
                        break;
                    }
                    // x untuk keluar
                    case SDLK_x: {
                        running = false;
                        break;
                    }
                    case SDLK_g: {
                        if (habibi.getKoin() < 100) {
                            kurangkoin = true;
                        } else {
                            Ikan* newguppy = new Guppy(rand()%SCREEN_WIDTH, rand()%SCREEN_HEIGHT, 0, 2000);
                            arkavkuarium.tambahikan(newguppy);
                            habibi.kurangkanKoin(100);
                            kurangkoin = false;
                            break; 
                        }
                    }
                    case SDLK_p: {
                        if (habibi.getKoin() < 200) {
                            kurangkoin = true;
                        } else {
                            Ikan* newpiranha = new Piranha(rand()%SCREEN_WIDTH, rand()%SCREEN_HEIGHT, 0, 4000);
                            arkavkuarium.tambahikan(newpiranha);
                            habibi.kurangkanKoin(200);
                            kurangkoin = false;
                            break;    
                        } 
                    }
                    case SDLK_s: {
                        ofstream fileikan;
                        fileikan.open("Ikan.txt");

                        for(int i = 0; i < arkavkuarium.getListIkan().getSize(); i++) {
                            fileikan << ikani->getX() <<  " " << ikani->getY();
                            fileikan << " " << ikani->getLapar() << " " << ikani->getWaktuMakan() - time_since_start() << " " << ikani->getType() << " " << ikani->getPointTujuan().getX() << " " << ikani->getPointTujuan().getY() << " " << ikani->getImage() <<  " " << ikani->getWaktuRandom() - time_since_start();
                            if (ikani->getType() == "Guppy") {
                                fileikan << " " << ikani->getWaktuKoin() - time_since_start() << " " << ikani->getLevel() << " " << ikani->getJumlahMakanYangDimakan() << "\n"; 
                            } else {
                                fileikan << "\n";
                            }
                        }

                        ofstream filemakananikan;
                        filemakananikan.open("MakananIkan.txt");

                        for(int i = 0; i < arkavkuarium.getListMakananIkan().getSize(); i++) {
                            filemakananikan << mki->getX() << " " << mki->getY();
                            filemakananikan << " " << mki->getImage() << "\n";
                        }

                        ofstream filekoin;
                        filekoin.open("Koin.txt");

                        for(int i = 0; i < arkavkuarium.getListKoin().getSize(); i++) {
                            filekoin << koini->getX() << " " << koini->getY() << " " << koini->getKecepatan();
                            filekoin << " " << koini->getNilai() << " " << koini->getLevel() << " " << koini->getImage() << "\n";
                        }

                        ofstream filesiput;
                        filesiput.open("Siput.txt");

                        filesiput << siputs.getX() << " " << siputs.getY() << " " << siputs.getPointTujuan().getX() << " " << siputs.getPointTujuan().getY() << " " << arkavkuarium.getSiput().getImage() << "\n";

                        ofstream fileplayer;
                        fileplayer.open("Player.txt");

                        fileplayer << habibi.getJumlahKoin() << " " << habibi.getBanyakTelur() << "\n";

                        fileplayer.close();
                        filesiput.close();
                        filekoin.close();
                        filemakananikan.close();
                        fileikan.close();
                        break;
                    }
                }
            }

            arkavkuarium.gerak();

            if (arkavkuarium.getListIkan().getSize() == 0) {
                if (habibi.getKoin() < 100) {
                    kalah = true;
                }
            }

            // Update FPS setiap detik
            frames_passed++;
            if (now - fpc_start > 1) {
                std::ostringstream strs;
                strs << "FPS: " ;
                strs << frames_passed/(now - fpc_start);
                fps_text = strs.str();;
                fpc_start = now;
                frames_passed = 0;
            }

            // Gambar ikan di posisi yang tepat.
            clear_screen();
            
            arkavkuarium.gambarAkuarium(habibi, kurangkoin);

            update_screen();            
        }

    }

    close();

    return 0;
}
