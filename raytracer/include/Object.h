#ifndef _OBJECT_H
#define _OBJECT_H

#include "Ray.h"
#include "Vect.h"
#include "Color.h"
#include "Matrix.h"
#include "Matrix4x4.h"
class Object {
    
    public:
    Matrix4x4 rotation;
    Vect position;
    Object();

    //method functions

    virtual Color getColor();
    virtual int move(Vect);
    virtual double findIntersection(Ray ray);
    virtual Vect getNormalAt(Vect intersection_position);
    virtual void rotate(Matrix r);
    virtual void rotateY(double s);
    virtual void rotateX(double s);
    virtual void rotateZ(double s);
    virtual void translate(Vect v);
    virtual void scale(double x, double y, double z);
};



#endif