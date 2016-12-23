#ifndef _OBJECT_H
#define _OBJECT_H

#include "Ray.h"
#include "Vect.h"
#include "Color.h"
#include "Matrix.h"
class Object {

    public:

    Object();

    //method functions

    virtual Color getColor();
    virtual int move(Vect);
    virtual double findIntersection(Ray ray);
    virtual Vect getNormalAt(Vect intersection_position);
    virtual void rotate(Matrix r);
};



#endif