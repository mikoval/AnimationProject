#ifndef _PYRAMID_H
#define _PYRAMID_H

#include "Object.h"
#include "Vect.h"
#include "Color.h"
#include "Triangle.h"
#include "Ray.h"
#include "Matrix.h"
#include <vector>

class Pyramid: public Object{
    Vect center;
    double sides;
    double radius;
    double height;
    Color color;
    vector<Triangle*> triangles;
    vector<Triangle> triangleOs;
    Triangle t1;
    Triangle t2;
    Triangle t3;
    Triangle t4;
    Triangle t5;
    Triangle t6;
    Triangle t7;
    Triangle t8;
    Triangle t9;
    Triangle t10;
    Triangle t11;
    Triangle t12;
    public:

    Pyramid();

    Pyramid  (Vect, double, double, double, Color);

    //method functions
    bool pointInTriangle(Triangle t, Vect p);
    
    void createPyramid();
    Color getColor();

    virtual Vect getNormalAt(Vect point);
    virtual double findIntersection(Ray ray) ;
    virtual void rotate(Matrix r);
    

};

#endif