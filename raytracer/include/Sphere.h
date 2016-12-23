#ifndef _SPHERE_H
#define _SPHERE_H

#include "Object.h"
#include "Vect.h"
#include "Color.h"
class Sphere: public Object{

    Vect center;
    double radius;
    Color color;

    public:

    Sphere();

    Sphere  (Vect, double,  Color);

    //method functions

    Vect  getCenter();
    double getRadius();
    Color getColor();
    virtual int move(Vect m);
    virtual Vect getNormalAt(Vect point);
    virtual double findIntersection(Ray ray) ;
    

};
#endif