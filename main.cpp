#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include "Ikan.hpp"
#include "List.hpp"
#include "Player.hpp"
#include "MakananIkan.hpp"

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
    List<Ikan> listofikan;
    Player habibi;
    List<MakananIkan> listofmakananikan;

    // Posisi ikan
    double cy = SCREEN_HEIGHT / 2;
    double cx = SCREEN_WIDTH / 2;

    bool running = true;

    double prevtime = time_since_start();

    int detiknow = 0;

    while (running) {
        if (int(time_since_start()) == detiknow) {
            Ikan newikan(rand()%SCREEN_WIDTH, rand()%SCREEN_HEIGHT, 0, 2000);
            listofikan.add(newikan);
            MakananIkan newmakananikan(rand()%SCREEN_WIDTH);
            listofmakananikan.add(newmakananikan);
            detiknow++;
        }

        for(int i = 0; i < Ikan::getBanyakIkan(); i++) {
            listofikan.getRef(i).gerak();
            listofmakananikan.getRef(i).gerak();
            if (abs(listofmakananikan.get(i).getY() - SCREEN_HEIGHT) < 0.1) {
                listofmakananikan.remove(listofmakananikan.get(i));
            }
        }

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
            case SDLK_r:
                cy = SCREEN_HEIGHT / 2;
                cx = SCREEN_WIDTH / 2;
                break;
            // x untuk keluar
            case SDLK_x:
                running = false;
                break;
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
        draw_image("Aquarium6.jpg", SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
        draw_text("Panah untuk bergerak, r untuk reset, x untuk keluar", 18, 10, 10, 0, 0, 0);
        draw_text(fps_text, 18, 10, 30, 0, 0, 0);
        for(int i = 0; i < Ikan::getBanyakIkan(); i++) {
            draw_image(listofikan.getRef(i).getImage(), listofikan.get(i).getX(), listofikan.get(i).getY());
            draw_image(listofmakananikan.getRef(i).getImage(), listofmakananikan.get(i).getX(), listofmakananikan.get(i).getY());
        }
        draw_text("Koin Player : " +  std::to_string(habibi.getKoin()), 18, 10, 50, 0, 0, 0);
        update_screen();
    }

    close();

    return 0;
}
