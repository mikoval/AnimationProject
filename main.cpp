
#include "Raytracer.h"
#include <iostream>
#include "Plane.h"
#include "Pyramid.h"
#include "Cylinder.h"
#include "Light.h"
#include "Matrix4x4.h"
#include "Rectangle.h"
#include "Sphere.h"
#include "Cone.h"
#include "TriangleMesh.h"
#include "Matrix.h"
using namespace std;

void animateY(vector <Object*> scene_objects){
    Matrix m = Matrix(Vect(0,1,0), 3.1415926/50);
     
    scene_objects[0] -> rotate(m);
   
    
    
}
void animateX(vector <Object*> scene_objects){
    for (int i = 1; i<scene_objects.size(); i++){
        scene_objects[i] -> rotateX(3.14/50);
   
    }
    
}

int main (int argc, char *argv[]){
    Vect O (0,0,0);
    Color white_light (0.9, 0.9, 0.9, 0);
    Color green_light (.5, 1.0, .5, 0);
    Color gray_light (.5, .5, .5, 0);
    Color black_light (0, 0, 0, 0);
    Color maroon_light (0.5, 0.25, 0.25, 0);
    Color black ( 0.1,0.1,0.1,0.0);
    Color shiny_black ( 0.4,0.4,0.4,0.2);
    Color shiny_white ( .9,0.9,0.9,.3);
    Color shiny_grey ( 0.3,0.3,0.3,0);
    Color white ( 0.9,0.9,0.9,1.0);
    Color shiny_green ( 0.2,0.9,0.2,0.3);
    Color shiny_blue ( 0.2,0.2,0.6,0.1);
    Color blue (0, 0, 1, 0);
    Color reflective (0,0,0,1);
    Color tiles (0,0,0,0,0,2);
    Color back_lines (0,0,0,0,0,3);
    Color trans (.2,.2,.2,0,0.4,0);
    Vect light_pos (-7, 10, -10);
    
    vector<Source*> light_sources;
    vector <Object*> scene_objects;
    //scene lights 
    Light scene_light (light_pos, white_light);
    light_sources.push_back(dynamic_cast<Source*>(&scene_light));
    //scene objects 

    TriangleMesh r = TriangleMesh("teapot.obj", shiny_blue);
    scene_objects.push_back(dynamic_cast<Object*>(&r));  

    r.scale(3,3,3 );
    //r.translate(Vect(0,4,0));
    
    Sphere s1 = Sphere(Vect(0, 0, 0), 1, shiny_white);
    //scene_objects.push_back(dynamic_cast<Object*>(&s1));
    Matrix m = Matrix(Vect(0,1,0), 3.1415926);
    r.rotate(m);

    Plane scene_plane (Vect(0,1,0), -100, maroon_light);
    scene_objects.push_back(dynamic_cast<Object*>(&scene_plane));
    /*
    Plane scene_plane (Vect(0,1,0), -3, maroon_light);
    scene_objects.push_back(dynamic_cast<Object*>(&scene_plane));

    Plane scene_back (Vect(0,0,-1), -12, back_lines);
    scene_objects.push_back(dynamic_cast<Object*>(&scene_back));

    Cone cone = Cone(trans);
    scene_objects.push_back(dynamic_cast<Object*>(&cone));  
    Cylinder cyl = Cylinder(green_light);
    scene_objects.push_back(dynamic_cast<Object*>(&cyl)); 

    scene_objects.push_back(dynamic_cast<Object*>(&cone));
    cone.rotateX(3.14159/2);
    cone.scale(2,39,2);  
    cone.translate(Vect(0,-37,-0));
    cyl.scale(.2,.2,3);
    cyl.rotateY(-.3);
    cyl.rotateX(3.14159/2);
    cyl.translate(Vect(0,1,0));
    
      
    cyl.translate(Vect(0,0,-1));
    */
    /*
    Cylinder c1 = Cylinder(-3,3,0.05,shiny_white);
    scene_objects.push_back(dynamic_cast<Object*>(&c1));
    
    Cylinder c2 = Cylinder(-3,3,0.05,shiny_white);
    scene_objects.push_back(dynamic_cast<Object*>(&c2));

    Cylinder c3 = Cylinder(-3,3,0.05,shiny_white);
    scene_objects.push_back(dynamic_cast<Object*>(&c3));

    Rectangle r1 = Rectangle(Vect(0,0,0),1,1,1,black);
    scene_objects.push_back(dynamic_cast<Object*>(&r1));

    c2.rotateY(3.14159/2);
    c3.rotateX(3.14159/2);

    Sphere s1 = Sphere(Vect(-3, 0, 0), 1, shiny_black);
    Sphere s2 = Sphere(Vect(3, 0, 0), 1, shiny_black);
    Sphere s3 = Sphere(Vect(0, -3, 0), 1, shiny_black);
    Sphere s4 = Sphere(Vect(0, 3, 0), 1, shiny_black);
    Sphere s5 = Sphere(Vect(0, 0, -3), 1, shiny_black);
    Sphere s6 = Sphere(Vect(0, 0, 3), 1, shiny_black);
    scene_objects.push_back(dynamic_cast<Object*>(&s1));
    scene_objects.push_back(dynamic_cast<Object*>(&s2));
    scene_objects.push_back(dynamic_cast<Object*>(&s3));
    scene_objects.push_back(dynamic_cast<Object*>(&s4));
    scene_objects.push_back(dynamic_cast<Object*>(&s5));
    scene_objects.push_back(dynamic_cast<Object*>(&s6));
    */
    //c2.translate(Vect(2,1,0))
    
    //create scene
    Raytracer tracer = Raytracer();
    std::string name;

    for (double i = 50; i < 100; i++){
        name = "pictures/scene" + std::to_string((int)(i)) + ".bmp";
        cout << name << endl;
        cout << "CALLING GENERATE \n";
        animateY(scene_objects);
        tracer.generate(scene_objects, light_sources, name, 1);
       
    }
}
