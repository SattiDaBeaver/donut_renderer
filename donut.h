#include <math.h>
#include "point.h"


class Donut{
    public:
        static Point get_coordinates(float sinT, float cosT, float sinP, float cosP, float r, float R, float Y){
            float x = (R + r*cosT) * cosP;
            float y = Y + r * (float)sinT;
            float z = -(R + r*cosT) * sinP;
            return Point(x, y, z);
        }

        static void project(Point p, float f){
            p.x = (p.x * f) / (f + p.y);
            p.z = (p.z * f) / (f + p.y);
            p.y = 0;
        }

        static float luminance(float sinT, float cosT, float sinP, float cosP, Point light){
            Point norm;

        }


};