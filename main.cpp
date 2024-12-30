#include <iostream>
#include <math.h>
#include <chrono>
#include <thread>

#include "donut.h"

#define WIDTH 60
#define LENGTH 25
#define FOCAL 10

#define CONV (M_PI)/180

using namespace std;

int main(int argc, char* argv[]){
    cout.sync_with_stdio(false);
    // declare variables
    const float inner_R = 7;
    const float outer_R = 18;
    const float y_donut = 0;

    float A = 0;
    float B = 0;

    Point light_vec(1/sqrt(2), -1/sqrt(2), 0);

    char frame[LENGTH][WIDTH];

    while(1) {
        // initialise frame buffer
        for (int i = 0; i < LENGTH; i++){
            for (int j = 0; j < WIDTH; j++){
                frame[i][j] = ' ';
            }
        }  

        // populate frame buffer
        for (float theta = 0; theta < 2 * M_PI; theta += 0.02){
            for (float phi = 0; phi < 2 * M_PI; phi += 0.02){
                float sinT = sin(theta);
                float cosT = cos(theta);
                float sinP = sin(phi);
                float cosP = cos(phi);

                Point p = Donut::get_coordinates(sinT, cosT, sinP, cosP, A, B, inner_R, outer_R, y_donut);

                float lum = Donut::luminance(sinT, cosT, sinP, cosP, light_vec);
                p.convert();
                Donut::project(p, FOCAL);

                frame[(int)round(p.x + LENGTH / 2)][(int)round(p.z + WIDTH / 2)] = Donut::get_char(lum);
            }
        }

        A += 0.1;
        B += 0.07;

        if (A >= 2 * M_PI){
            A = 0;
        }
        if (B >= 2 * M_PI){
            B = 0;
        }

        // print frame

        for (int i = 0; i < LENGTH; i++){
            for (int j = 0; j < WIDTH; j++){
                cout << frame[i][j];
            }
            cout << "\n";
        }

        cout << endl;

        this_thread::sleep_for(chrono::milliseconds(5));
    }
    return 0;
}