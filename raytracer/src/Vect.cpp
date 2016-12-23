#include "Vect.h"
#include "math.h"


    double Vect::getX() { return x; }
    double Vect::getY() { return y; }
    double Vect::getZ() { return z; }
    
    double Vect::magnitude () {
        return sqrt((x*x) + (y*y) + (z*z));
    }
    
    Vect Vect::normalize () {
        double magnitude = sqrt((x*x) + (y*y) + (z*z));
        return Vect (x/magnitude, y/magnitude, z/magnitude);
    }
    
    Vect Vect::negative () {
        return Vect (-x, -y, -z);
    }
    
    double Vect::dotProduct(Vect v) {
        return x*v.getX() + y*v.getY() + z*v.getZ();
    }
    
    Vect Vect::crossProduct(Vect v) {
        return Vect (y*v.getZ() - z*v.getY(), z*v.getX() - x*v.getZ(), x*v.getY() - y*v.getX());
    }
    
    Vect Vect::add (Vect v) {
        return Vect (x + v.getX(), y + v.getY(), z + v.getZ());
    }

    Vect Vect::mult (double scalar) {
        return Vect (x*scalar, y*scalar, z*scalar);
    }


Vect::Vect () {
    x = 0;
    y = 0;
    z = 0;
}

Vect::Vect (double i, double j, double k) {
    x = i;
    y = j;
    z = k;
}

