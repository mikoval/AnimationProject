#include "Rectangle.h"

bool Rectangle::pointInTriangle(Triangle t, Vect p){
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
void Rectangle::createRectangle(){
    double cx = center.getX();
    double cy = center.getY();
    double cz = center.getZ();
    double w = width/2;
    double h = height/2;
    double l = length/2;
    Vect c1 = Vect(cx-w, cy+h, cz+l);
    Vect c2 = Vect(cx+w, cy+h, cz+l);
    Vect c3 = Vect(cx-w, cy-h, cz+l);
    Vect c4 = Vect(cx+w, cy-h, cz+l);

   

    Vect c5 = Vect(cx-w, cy+h, cz-l);
    Vect c6 = Vect(cx+w, cy+h, cz-l);
    Vect c7 = Vect(cx-w, cy-h, cz-l);
    Vect c8 = Vect(cx+w, cy-h, cz-l);
    //front 
     t1 = Triangle(c1, c2, c3, color);
     t2 = Triangle(c2, c4, c3, color);
    //back
     t3 = Triangle(c5, c7, c6, color);
     t4 = Triangle (c6, c7, c8, color);
    //left
     t5 = Triangle(c1, c3, c5, color);
     t6 = Triangle(c5, c3, c7, color);
    //right
     t7 = Triangle(c6, c8, c2, color);
     t8 = Triangle(c2, c8, c4, color);
    //top
     t9 = Triangle(c1, c5, c2, color);
     t10 = Triangle(c5, c6, c2, color);
    //bottom
     t11 = Triangle(c3, c4, c7, color);
     t12 = Triangle(c4, c8, c7, color);
    


    triangles.push_back(dynamic_cast<Triangle*>(&t1));
    triangles.push_back(dynamic_cast<Triangle*>(&t2));
    triangles.push_back(dynamic_cast<Triangle*>(&t3));
    triangles.push_back(dynamic_cast<Triangle*>(&t4));
    triangles.push_back(dynamic_cast<Triangle*>(&t5));
    triangles.push_back(dynamic_cast<Triangle*>(&t6));
    triangles.push_back(dynamic_cast<Triangle*>(&t7));
    triangles.push_back(dynamic_cast<Triangle*>(&t8));
    triangles.push_back(dynamic_cast<Triangle*>(&t9));
    triangles.push_back(dynamic_cast<Triangle*>(&t10));
    triangles.push_back(dynamic_cast<Triangle*>(&t11));
    triangles.push_back(dynamic_cast<Triangle*>(&t12));
    
    
}
Color Rectangle::getColor(){return color;}

int Rectangle::move(Vect m){
    center = m;
    return 1;

}
Vect Rectangle::getNormalAt(Vect point){
    for (int index = 0; index < triangles.size(); index++) {
        Triangle* op  =  triangles.at(index);
        Triangle o = *op;
        if(pointInTriangle(o, point)){
            return o.getNormalAt(point);
        }
    }
    return Vect(0,0,0);
}
double Rectangle::findIntersection(Ray ray) {
    vector<double> intersections;      
    
    for (int index = 0; index < triangles.size(); index++) {
        Triangle* op  =  triangles.at(index);
        Triangle o = *op;
        intersections.push_back(o.findIntersection(ray));   
    }

    int index_of_winning_object = Raytracer::closestObjectIndex(intersections);

    if(index_of_winning_object >= 0){
        //cout << index_of_winning_object << endl;
        return intersections.at(index_of_winning_object);
    } 
    return -1;
}
void Rectangle::rotate(Matrix r){
    for (int index = 0; index < triangles.size(); index++) {
        triangles.at(index)->rotate(r);
    
    }
}
    



Rectangle::Rectangle(){
    center = Vect(0,0,0);
    color = Color(1,1,1,0);
    length = 1;
    width = 1;
    height = 1;
    createRectangle();
}

Rectangle::Rectangle(Vect position, double l , double w, double h, Color col){
    center = position;
    length = l;
    width = w;
    height = h;
    color = col;
    createRectangle();
}
