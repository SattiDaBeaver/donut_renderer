#include <iostream>
#include <math.h>
#include <chrono>
#include <thread>

#include "donut.h"

#define WIDTH 70
#define LENGTH 30
#define FOCAL 10

#define X_ROTATION 0.08
#define Y_ROTATION 0.03

#define INC_THETA 0.08
#define INC_PHI 0.08

#define TIME_PER_FRAME 25

using namespace std;

int main(int argc, char* argv[]){
    cout.sync_with_stdio(false);
    // declare variables
    const float inner_R = 10;
    const float outer_R = 22;
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
        for (float theta = 0; theta < 2 * M_PI; theta += INC_THETA){
            for (float phi = 0; phi < 2 * M_PI; phi += INC_PHI){
                float sinT = sin(theta);
                float cosT = cos(theta);
                float sinP = sin(phi);
                float cosP = cos(phi);

                Point p = Donut::get_coordinates(sinT, cosT, sinP, cosP, A, B, inner_R, outer_R, y_donut);

                float lum = Donut::luminance(sinT, cosT, sinP, cosP, light_vec);
                p.convert();
                Donut::project(p, FOCAL);
                int x = round(p.x + LENGTH / 2);
                int y = round(p.z + WIDTH / 2);
                if (frame[x][y] == ' ')
                    frame[x][y] = Donut::get_char(lum);
            }
        }

        A += X_ROTATION;
        B += Y_ROTATION;

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

        this_thread::sleep_for(chrono::milliseconds(TIME_PER_FRAME));
    }
    return 0;
}