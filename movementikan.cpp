#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>

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

    // Menghitung FPS
    int frames_passed = 0;
    double fpc_start = time_since_start();
    std::string fps_text = "FPS: 0";

    // Posisi ikan
    double cy = SCREEN_HEIGHT / 2;
    double cx = SCREEN_WIDTH / 2;

    bool running = true;

    double prevtime = time_since_start();

    while (running) {
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        handle_input();
        if (quit_pressed()) {
            running = false;
        }

        if (sampai) {
            asalx = rand()%SCREEN_WIDTH;
            asaly = rand()%SCREEN_HEIGHT;
            sampai = false;
        } else {
            a = atan2(asaly - cy, asalx- cx);
            if (a*180/PI > -90 && a*180/PI < 90) {
                kanan = true;
            } else {
                kanan = false;
            }
            cx += speed*cos(a)*sec_since_last;
            cy += speed*sin(a)*sec_since_last;
            if (abs(cx - asalx) < 0.001 && abs(cy - asaly) < 0.001) {
                sampai = true;
            }
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
        draw_text("Panah untuk bergerak, r untuk reset, x untuk keluar", 18, 10, 10, 0, 0, 0);
        draw_text(fps_text, 18, 10, 30, 0, 0, 0);
        if (kanan) {
            draw_image("kanan.jpg", cx, cy);
        } else {
            draw_image("kiri.jpg", cx, cy);
        }
        if (sampai) {
            draw_text("HAI", 18, 10, 10, 0, 0, 0);
        } else {
            draw_text("HEHE", 18, 10, 50, 0, 0, 0);
        }
        if (kanan) {
            draw_text("HUUHU", 18, 10, 70, 0, 0, 0);
        }
        draw_text(std::to_string(a*180/PI), 18, 10, 100, 0, 0, 0);
        update_screen();
    }

    close();

    return 0;
}
