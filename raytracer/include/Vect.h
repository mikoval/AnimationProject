#ifndef _VECT_H
#define _VECT_H

#include "math.h"

class Vect {
    double x, y, z;
    
    public:
    
    Vect ();
    
    Vect (double, double, double);
    
    // method functions
    double getX();
    double getY();
    double getZ();
    
    double magnitude ();
        
    
    Vect normalize ();
    Vect negative ();
    
    double dotProduct(Vect v);
    
    Vect crossProduct(Vect v);
    
    Vect add (Vect v);

    Vect mult (double scalar);
};


#endif
