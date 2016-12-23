#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "Object.h"
#include "Vect.h"
#include "Color.h"
using namespace std;
class Triangle: public Object{

    Vect A, B, C;
    Vect normal;
    double distance;
    Color color;

    public:

    Triangle();

    Triangle  (Vect, Vect,  Vect, Color);

    //method functions

    Vect getA();
    Vect getB();
    Vect getC();
    virtual Color getColor();
    virtual Vect getNormalAt(Vect point);
    virtual Vect getTriangleNormal();

    double getTriangleDistance();

    virtual void rotate(Matrix r);
    virtual double findIntersection(Ray ray);
    
};

#endif