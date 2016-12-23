#include "Pyramid.h"
#include "Raytracer.h"
bool Pyramid::pointInTriangle(Triangle t, Vect p){
    Vect normal = t.getNormalAt(p);
    Vect A = t.getA();
    Vect B = t.getB();
    Vect C = t.getC();
    Vect Q = p;
    Vect CA (C.getX()- A.getX(),C.getY()- A.getY(), C.getZ()- A.getZ()); 
    Vect QA (Q.getX()- A.getX(),Q.getY()- A.getY(), Q.getZ()- A.getZ()); 
    double test1 = (CA.crossProduct(QA)).dotProduct(normal);

    Vect BC (B.getX()- C.getX(),B.getY()- C.getY(), B.getZ()- C.getZ()); 
    Vect QC (Q.getX()- C.getX(),Q.getY()- C.getY(), Q.getZ()- C.getZ()); 
    double test2 = (BC.crossProduct(QC)).dotProduct(normal);

    Vect AB (A.getX()- B.getX(), A.getY()- B.getY(), A.getZ()- B.getZ()); 
    Vect QB (Q.getX()- B.getX(),Q.getY()- B.getY(), Q.getZ()- B.getZ()); 
    double test3 = (AB.crossProduct(QB)).dotProduct(normal);

    double test4 = QA.dotProduct(t.getNormalAt(p));
  

    if(test1 >= 0 && test2 >= 0 && test3 >= 0 && test4 < .00001 && test4 > -.00001){

        return true;
    }
    else{
        return false;
    }
}
void Pyramid::createPyramid(){
    double cx = center.getX();
    double cy = center.getY();
    double cz = center.getZ();
    Vect base_center = Vect(cx, cy, cz); 
    Vect top = Vect(cx, cy+height, cz);
    
    vector<Vect> base_corners;
    /*Vect c1 = Vect(cx+ radius, cy, cz);
    Vect c2 = Vect(cx - radius, cy, cz);
    Vect c3 = Vect(cx, cy, cz+radius);

    base_corners.push_back(c1);
    base_corners.push_back(c2);
    base_corners.push_back(c3);*/
    double amnt = 6.28318 / sides;
    for (int i = 0; i < sides; i++){
        Vect c = Vect(cx+ radius*cos(amnt*i), cy, cz+ radius*sin(amnt*i));
        base_corners.push_back(c);
    }
     //base 
    for(int i = 0; i < base_corners.size(); i++){
        int i1 = i;
        int i2 = i+1;
        if(i2 == base_corners.size()){
            i2 = 0;
        }
        Vect corner1 = base_corners.at(i1);
        Vect corner2 = base_corners.at(i2);
        Triangle t1 = Triangle(base_center, corner1, corner2, color);
        Triangle t2 = Triangle(top, corner1, corner2, color);

        triangleOs.push_back(t1);

        triangleOs.push_back(t2);
        
    }
    for(int i = 0; i< triangleOs.size(); i++){
        triangles.push_back(&triangleOs[i]);
    }

    
}
Color Pyramid::getColor(){return color;}
Vect Pyramid::getNormalAt(Vect point){
    for (int index = 0; index < triangles.size(); index++) {
        Triangle* op  =  triangles.at(index);
        Triangle o = *op;
        if(pointInTriangle(o, point)){
            return o.getNormalAt(point);
        }
    }
    return Vect(0,0,0);
}
double Pyramid::findIntersection(Ray ray) {
    vector<double> intersections;      
    
    for (int index = 0; index < triangles.size(); index++) {
        Triangle* op  =  triangles.at(index);
        Triangle o = *op;
        intersections.push_back(o.findIntersection(ray));   
    }

    int index_of_winning_object = Raytracer::closestObjectIndex(intersections);

    if(index_of_winning_object >= 0){
   
        return intersections.at(index_of_winning_object);
    } 
    return -1;
}
void Pyramid::rotate(Matrix r){
    for (int index = 0; index < triangles.size(); index++) {
        Vect A = triangles.at(index)->getA();
        Vect B = triangleOs.at(index).getA();

        triangles.at(index)->rotate(r);
    
    }
}




Pyramid::Pyramid(){
    center = Vect(0,0,0);
    color = Color(1,1,1,0);
    sides = 3;
    radius = 1;
    height = 1;
    createPyramid();
}

Pyramid::Pyramid(Vect position, double s , double r, double h, Color col){
    center = position;
    sides = s;
    radius = r;
    height = h;
    color = col;
    createPyramid();
}