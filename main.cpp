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

    Ikan* ikan1 = new Ikan(rand()%SCREEN_WIDTH, rand()%SCREEN_HEIGHT, 0, 2000);
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

        for (auto key : get_pressed_keys()) {
            switch (key) {
            case SDLK_UP:
                cy -= speed * sec_since_last;
                break;
            case SDLK_DOWN:
                cy += speed * sec_since_last;
                break;
            case SDLK_LEFT:
                cx -= speed * sec_since_last;
                break;
            case SDLK_RIGHT:
                cx += speed * sec_since_last;
                break;
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
                case SDLK_i: {
                    Ikan* newikan = new Ikan(rand()%SCREEN_WIDTH, rand()%SCREEN_HEIGHT, 0, 2000);
                    listofikan.add(newikan);
                    break;
                }             
                case SDLK_m: {
                    MakananIkan newmakananikan(rand()%SCREEN_WIDTH);
                    listofmakananikan.add(newmakananikan);
                    habibi.setKoin(habibi.getKoin() - 5);
                    break;
                }
                case SDLK_g: {
                    Ikan* newguppy = new Guppy(rand()%SCREEN_WIDTH, rand()%SCREEN_HEIGHT, 0, 2000);
                    listofikan.add(newguppy);
                    break;
                }
            }
        }

        if (listofkoin.getSize() <= 0) {
            siput.gerak();
        } else {
            int dapatkoin = siput.cariKoin(listofkoin);
            if (dapatkoin != -1) {
                listofkoin.removeIdx(dapatkoin);
            }
        }

        for(int i = 0; i < listofikan.getSize(); i++) {
            if (listofikan.get(i)->getLapar()) {
                int makanandimakan = listofikan.get(i)->cariMakanGuppy(listofmakananikan);
                if (makanandimakan != -1) {
                    listofmakananikan.removeIdx(makanandimakan);
                }
                if (listofikan.get(i)->mati()) {
                    listofikan.removeIdx(i);
                }
            } else {
                listofikan.get(i)->gerak();
            }
            if (listofikan.get(i)->keluarkanKoinGuppy()) {
                Koin newkoin(listofikan.get(i)->getX(), listofikan.get(i)->getY(), 10, 50);
                listofkoin.add(newkoin);
            }
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

        draw_image(siput.getImage(), siput.getX(), siput.getY()-24);

        draw_text("Koin Player : " +  std::to_string(habibi.getKoin()), 18, 10, 50, 0, 0, 0);
        update_screen();
    }

    close();

    return 0;
}
