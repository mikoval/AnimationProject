#ifndef _TRIANGLEMESH_H
#define _TRIANGLEMESH_H

#include "Object.h"
#include "Vect.h"
#include "Color.h"
#include "Triangle.h"
#include "Ray.h"
#include "Matrix.h"
#include <vector>
#include "Sphere.h"

class TriangleMesh: public Object{
    Vect center;
    Color color;

    vector<Vect> corners;
    vector<Vect> normals;
    vector<Triangle*> triangles;
    vector<Triangle> triangleOs;
    Sphere boundingSphere;

    public:

    TriangleMesh();
    TriangleMesh(string, Color);



    //method functions
    bool pointInTriangle(Triangle t, Vect p);
    
    void createMesh(string c);
    Color getColor();

    virtual Vect getNormalAt(Vect point);
    virtual double findIntersection(Ray ray) ;
    virtual void rotate(Matrix r);
    virtual void scale(double x, double y, double z);

};

#endif