#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include "Ikan.hpp"
#include "List.hpp"
#include "Player.hpp"
#include "MakananIkan.hpp"
#include "Koin.hpp";
#include "Siput.hpp";
#include "Guppy.hpp";
#include "Piranha.hpp";

// using namespace std;
#define PI 3.14159265

const double speed = 50; // pixels per second

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

    //Kebutuhan
    List<Ikan*> listofikan;
    Player habibi;
    List<MakananIkan> listofmakananikan;
    List<Koin> listofkoin;
    Siput siput(rand()%SCREEN_WIDTH, SCREEN_HEIGHT, 0,500);

    // Posisi ikan
    double cy = SCREEN_HEIGHT / 2;
    double cx = SCREEN_WIDTH / 2;

    bool running = true;
    double prevtime = time_since_start();
    int detiknow = 0;
    int loop = 0;
    
    bool mainmenu = true;
    bool menang= false;

    while (running) {
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        handle_input();
        if (quit_pressed()) {
            running = false;
        }

        // Gerakkan ikan selama tombol panah ditekan
        // Kecepatan dikalikan dengan perbedaan waktu supaya kecepatan ikan
        // konstan pada komputer yang berbeda.

        // for (auto key : get_pressed_keys()) {
        //     switch (key) {
        //     case SDLK_UP:
        //         cy -= speed * sec_since_last;
        //         break;
        //     case SDLK_DOWN:
        //         cy += speed * sec_since_last;
        //         break;
        //     case SDLK_LEFT:
        //         cx -= speed * sec_since_last;
        //         break;
        //     case SDLK_RIGHT:
        //         cx += speed * sec_since_last;
        //         break;
        //     }
        // }

        if (mainmenu) {
            clear_screen();
            for (auto key : get_clicked_mouse()) {
                switch(key) {
                    case 1: {
                        cout << get_clicked_mouseX() << " " << get_clicked_mouseY() << "\n";
                        if ((get_clicked_mouseX() <= 736 && get_clicked_mouseX() >= 498) && (get_clicked_mouseY() <= 145 && get_clicked_mouseY() >= 64)) {
                            mainmenu = false;
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
                        cout << get_clicked_mouseX() << " " << get_clicked_mouseY() << "\n";
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
                        for(int i = 0; i < listofkoin.getSize() && ketemu == -1; i++) {
                            if (abs(listofkoin.getRef(i)->getX() - get_clicked_mouseX()) < 40 && abs(listofkoin.getRef(i)->getY() - get_clicked_mouseY()-24) < 40) {
                                ketemu = i;
                            }
                        }
                        if (ketemu != -1) {
                            habibi.tambahKoin(listofkoin.getRef(ketemu)->getNilai());
                            listofkoin.removeIdx(ketemu);
                        } else {
                            if (((get_clicked_mouseX() > 753 || get_clicked_mouseX() < 683)) && ((get_clicked_mouseY() > 135 || get_clicked_mouseY() < 65))){
                                MakananIkan newmakananikan(get_clicked_mouseX(), get_clicked_mouseY());
                                listofmakananikan.add(newmakananikan);
                                habibi.setKoin(habibi.getKoin() - 5);
                            }
                        }
                        if (!menang){
                            if ((get_clicked_mouseX() <= 753 && get_clicked_mouseX() >= 683) && (get_clicked_mouseY() <= 135 && get_clicked_mouseY() >= 65)) {
                                habibi.tambahTelur();
                                if (habibi.getBanyakTelur()==3){
                                menang=true;
                            }
                        }
                        get_clicked_mouse().erase(1);
                        break;
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
                    case SDLK_m: {
                        MakananIkan newmakananikan(rand()%SCREEN_WIDTH, 0);
                        listofmakananikan.add(newmakananikan);
                        habibi.kurangkanKoin(5);
                        break;
                    }
                    case SDLK_g: {
                        Ikan* newguppy = new Guppy(rand()%SCREEN_WIDTH, rand()%SCREEN_HEIGHT, 0, 2000);
                        listofikan.add(newguppy);
                        habibi.kurangkanKoin(100);
                        break;
                    }
                    case SDLK_p: {
                        Ikan* newpiranha = new Piranha(rand()%SCREEN_WIDTH, rand()%SCREEN_HEIGHT, 0, 4000);
                        listofikan.add(newpiranha);
                        habibi.kurangkanKoin(200);
                        break;
                    }
                    case SDLK_t: {
                        habibi.kurangkanKoin(100);
                        habibi.tambahTelur();
                        if (habibi.getBanyakTelur()==3){
                            menang=true;
                        }
                        break;
                    }
                }
            }


            int dapatkoin = siput.cariKoin(listofkoin);
            
            if (dapatkoin != -1) {
                listofkoin.removeIdx(dapatkoin);
            }


            loop = 0;
            while(loop < listofikan.getSize()) {
                if (listofikan.get(loop)->getType() == "Guppy") {
                    if (listofikan.get(loop)->mati()) {
                        listofikan.removeIdx(loop);
                        continue;
                    }  
                    if (listofikan.get(loop)->getLapar()) {
                        int makanandimakan = listofikan.get(loop)->cariMakanGuppy(listofmakananikan);
                        if (makanandimakan != -1) {
                            listofmakananikan.removeIdx(makanandimakan);
                        }
                    } else {
                        listofikan.get(loop)->gerak();
                    }
                    if (listofikan.get(loop)->keluarkanKoinGuppy()) {
                        if (listofikan.get(loop)->getLevel() == 1) {
                            Koin newkoin(listofikan.get(loop)->getX(), listofikan.get(loop)->getY(), 10, 10, 1);
                            listofkoin.add(newkoin);
                        } else if (listofikan.get(loop)->getLevel() == 2) {
                            Koin newkoin(listofikan.get(loop)->getX(), listofikan.get(loop)->getY(), 10, 20, 2);
                            listofkoin.add(newkoin);
                        } else {
                            Koin newkoin(listofikan.get(loop)->getX(), listofikan.get(loop)->getY(), 10, 50, 3);
                            listofkoin.add(newkoin);
                        }
                    }              
                } else {
                    if (listofikan.get(loop)->mati()) {
                        listofikan.removeIdx(loop);
                        continue;
                    }
                    if (listofikan.get(loop)->getLapar()) {
                        int ikandimakan = listofikan.get(loop)->cariIkanTerdekat(listofikan);
                        if (ikandimakan != -1) {
                            Koin newkoin(listofikan.get(loop)->getX(), listofikan.get(loop)->getY(), 10, 100*(listofikan.get(ikandimakan)->getLevel()+1), 4);
                            listofkoin.add(newkoin);
                            listofikan.removeIdx(ikandimakan);
                        }
                    } else {
                        listofikan.get(loop)->gerak();
                    }
                }
                loop++;
            }

            for(int i = 0; i < listofmakananikan.getSize(); i++) {
                listofmakananikan.getRef(i)->gerak();
                if (abs(listofmakananikan.get(i).getY() - SCREEN_HEIGHT) < 0.1) {
                    listofmakananikan.removeIdx(i);
                }
            }

            for(int i = 0; i < listofkoin.getSize(); i++) {
                listofkoin.getRef(i)->gerak();
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
            draw_image("Aquarium6.jpg", SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
            draw_text("Panah untuk bergerak, r untuk reset, x untuk keluar", 18, 10, 10, 0, 0, 0);
            draw_text(fps_text, 18, 10, 30, 0, 0, 0);

            for(int i = 0; i < listofikan.getSize(); i++) {
                draw_image(listofikan.get(i)->getImage(), listofikan.get(i)->getX(), listofikan.get(i)->getY()-24);
            }

            for(int i = 0; i < listofmakananikan.getSize(); i++) {
                draw_image(listofmakananikan.getRef(i)->getImage(), listofmakananikan.get(i).getX(), listofmakananikan.get(i).getY()-24);
            }

            for(int i = 0; i < listofkoin.getSize(); i++) {
                draw_image(listofkoin.getRef(i)->getImage(), listofkoin.get(i).getX(), listofkoin.get(i).getY()-24);
            }
            if (habibi.getBanyakTelur()==0){
                draw_image("telor1.png",718,100);
            }else if (habibi.getBanyakTelur()==1){
                draw_image("telor2.png",718,100);
            }else{
                draw_image("telor3.png",718,100);
            }

            draw_image(siput.getImage(), siput.getX(), siput.getY()-24);

            draw_text("Koin Player : " +  std::to_string(habibi.getKoin()), 18, 10, 50, 0, 0, 0);
            draw_text("Banyak telur: " + std::to_string(habibi.getBanyakTelur()),18,10,100,0,0,0);
            update_screen();            
        }

    }

    close();

    return 0;
}
