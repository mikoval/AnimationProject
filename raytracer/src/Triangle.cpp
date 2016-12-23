#include "Triangle.h"
Vect Triangle::getA(){return A;}
Vect Triangle::getB(){return B;}
Vect Triangle::getC(){return C;}
Color Triangle::getColor(){return color;}
Vect Triangle::getNormalAt(Vect point){
    return getTriangleNormal();
}
Vect Triangle::getTriangleNormal(){
    Vect CA (C.getX()- A.getX(),C.getY()- A.getY(), C.getZ()- A.getZ()); 
    Vect BA (B.getX()- A.getX(),B.getY()- A.getY(), B.getZ()- A.getZ()); 
    Vect normal = CA.crossProduct(BA).normalize();
    return normal;
}
double Triangle::getTriangleDistance(){
    normal = getTriangleNormal();
    distance = normal.dotProduct(A);
    return distance;
}
void Triangle::rotate(Matrix r){
    A = r.vectMult(A);
    B = r.vectMult(B);
    C = r.vectMult(C);


}
double Triangle::findIntersection(Ray ray) {

    Vect ray_direction = ray.getDirection();
    Vect ray_origin = ray.getOrigin();
    normal = getTriangleNormal();

    distance = getTriangleDistance();
    double a = ray_direction.dotProduct(normal);
    
    if (a == 0) {
        // ray is parallel to the plane
        return -1;
    }
    else {
        //get distance
        double b = normal.dotProduct(ray.getOrigin().add(normal.mult(distance).negative()));
        double distance_to_plane = -1*b/a;
        //get point of intersection
        double Qx = ray_direction.mult(distance_to_plane).getX() + ray_origin.getX();
        double Qy = ray_direction.mult(distance_to_plane).getY() + ray_origin.getY();
        double Qz = ray_direction.mult(distance_to_plane).getZ() + ray_origin.getZ();
        Vect Q (Qx, Qy, Qz);
        //do tests
        Vect CA (C.getX()- A.getX(),C.getY()- A.getY(), C.getZ()- A.getZ()); 
        Vect QA (Q.getX()- A.getX(),Q.getY()- A.getY(), Q.getZ()- A.getZ()); 
        double test1 = (CA.crossProduct(QA)).dotProduct(normal);

        Vect BC (B.getX()- C.getX(),B.getY()- C.getY(), B.getZ()- C.getZ()); 
        Vect QC (Q.getX()- C.getX(),Q.getY()- C.getY(), Q.getZ()- C.getZ()); 
        double test2 = (BC.crossProduct(QC)).dotProduct(normal);

        Vect AB (A.getX()- B.getX(), A.getY()- B.getY(), A.getZ()- B.getZ()); 
        Vect QB (Q.getX()- B.getX(),Q.getY()- B.getY(), Q.getZ()- B.getZ()); 
        double test3 = (AB.crossProduct(QB)).dotProduct(normal);
      

        if(test1 >= 0 && test2 >= 0 && test3 >= 0){

            return distance_to_plane;
        }
        else{
            return -1;
        }
    }
}


Triangle::Triangle(){
    A = Vect(1,0,0);
    B = Vect(0,1,0);
    C = Vect(0,0,1);
    
    normal = Vect(1,0,0);
    distance  = 1;
    color = Color(.5,.5,.5,0);
   
}

Triangle::Triangle(Vect a, Vect b, Vect c, Color col){
    A = a;
    B = b; 
    C = c;
    color = col;
}
