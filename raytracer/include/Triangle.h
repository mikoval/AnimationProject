#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "Object.h"
#include "Vect.h"
#include "Color.h"
using namespace std;
class Triangle: public Object{

    Vect A, B, C;
    Vect* Ap; Vect* Bp; Vect* Cp;
    Vect normalA;
    Vect normalB;
    Vect normalC;
    Vect normal;
    double distance;
    Color color;
    bool setNorm;

    public:

    Triangle();
    Triangle  (Vect, Vect,  Vect, Color);
    Triangle  (Vect*, Vect*,  Vect*, Color);
    Triangle  (Vect*, Vect*,  Vect*, Vect, Vect, Vect, Color);
    //method functions


    Vect getA();
    Vect getB();
    Vect getC();
    virtual Color getColor();
    virtual Vect getNormalAt(Vect point);
    virtual Vect getTriangleNormal();

    double getTriangleDistance();

    virtual void rotate(Matrix r);
    virtual void scale(double x, double y, double z);
    virtual double findIntersection(Ray ray);
    
};

#endif