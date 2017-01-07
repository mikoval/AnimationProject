#include "Sphere.h"
#include <iostream>
using namespace std;
Vect Sphere::getCenter(){return center;}
double Sphere::getRadius(){return radius;}
Color Sphere::getColor(){return color;}
int Sphere::move(Vect m){
    center = m;
    return 1;

}
Vect Sphere::getNormalAt(Vect point){
    Vect normal_vect = point.add(center.negative()).normalize();
    return normal_vect;
}
double Sphere::findIntersection(Ray ray) {
    Vect ray_origin = ray.getOrigin();
    double ray_origin_x = ray_origin.getX();
    double ray_origin_y = ray_origin.getY();
    double ray_origin_z = ray_origin.getZ();
    
    Vect ray_direction = ray.getDirection();
    double ray_direction_x = ray_direction.getX();
    double ray_direction_y = ray_direction.getY();
    double ray_direction_z = ray_direction.getZ();
    
    Vect sphere_center = center;
    double sphere_center_x = sphere_center.getX();
    double sphere_center_y = sphere_center.getY();
    double sphere_center_z = sphere_center.getZ();
    
    double a = 1; // normalized
    double b = (2*(ray_origin_x - sphere_center_x)*ray_direction_x) + (2*(ray_origin_y - sphere_center_y)*ray_direction_y) + (2*(ray_origin_z - sphere_center_z)*ray_direction_z);
    double c = pow(ray_origin_x - sphere_center_x, 2) + pow(ray_origin_y - sphere_center_y, 2) + pow(ray_origin_z - sphere_center_z, 2) - (radius*radius);
    
    double discriminant = b*b - 4*c;
    
    if (discriminant > 0) {
        /// the ray intersects the sphere
        
        // the first root
        double root_1 = ((-1*b - sqrt(discriminant))/2) - 0.000001;
        
        if (root_1 > 0) {
            // the first root is the smallest positive root
            return root_1;
        }
        else {
            // the second root is the smallest positive root
            double root_2 = ((sqrt(discriminant) - b)/2) - 0.000001;
            return root_2;
        }
    }
    else {
        // the ray missed the sphere
        return -1;
    }
}


void Sphere::rotate(Matrix r){
    center = r.vectMult(center);
}
void Sphere::rotateY(double s){
    Vect r (0,1,0);
    Matrix m (r, s);
    rotate(m);
}
void Sphere::rotateX(double s){
    Vect r (1,0,0);
    Matrix m (r, s);
    rotate(m);
}
void Sphere::scale(double s){
    radius = radius * s;
}

Sphere::Sphere(){
    center = Vect(0,0,0);
    radius  = 1;
    color = Color(.5,.5,.5,0);
   
}

Sphere::Sphere(Vect c, double  r, Color col){
    center = c;
    radius = r; 
    color = col;
}
