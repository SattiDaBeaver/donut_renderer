#include <math.h>
#include "point.h"

class Donut{
    public:
        static Point get_coordinates(float sinT, float cosT, float sinP, float cosP, float A, float B, float r, float R, float Y){
            float sinA = sin(A);
            float cosA = cos(A);
            float sinB = sin(B);
            float cosB = cos(B);

            float L = R + r*cosT;

            float x = L*(cosB*cosP + sinA*sinB*sinP) - r*cosA*sinB*sinT;
            float y = Y + cosA*L*sinP + r*sinA*sinT;
            float z = L*(cosP*sinB - cosB*sinA*sinP) + r*cosA*cosB*sinT;
            
            // float x = (R + r*cosT) * cosP;
            // float y = Y + r * (float)sinT;
            // float z = -(R + r*cosT) * sinP;
            return Point(x, y, z);
        }

        static void project(Point p, float f){
            p.x = (p.x * f) / (f + p.y);
            p.z = (p.z * f) / (f + p.y);
            p.y = 0;
        }

        static float luminance(float sinT, float cosT, float sinP, float cosP, Point light){
            float x = cosT*cosP;
            float z = sinT;
            float y = -sinP*cosT;

            return (x * light.x + y * light.y + z * light.z);
        }

        static char get_char(float lum){
            int x = (int)(-lum*6 + 6);
            return ".,-~:;=!*#$@"[x];
        }
};