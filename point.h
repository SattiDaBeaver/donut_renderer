#include <math.h>

class Point{
    public:
        float x, y, z;
        Point() {x = 0; y = 0; z = 0;}
        Point(float x_, float y_, float z_) {x = x_; y = y_; z = z_;}

        void convert(){
            x = x / 2.5;
        }

        void point_round(){
            x = round(x);
            y = round(y);
            z = round(z);
        }
};