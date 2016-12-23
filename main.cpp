
#include "Raytracer.h"
#include <iostream>
#include "Plane.h"
#include "Pyramid.h"
#include "Light.h"
using namespace std;



int main (int argc, char *argv[]){
    Vect O (0,0,0);
    Color white_light (0.9, 0.9, 0.9, 0);
    Color green_light (.5, 1.0, .5, 0);
    Color gray_light (.5, .5, .5, 0);
    Color black_light (0, 0, 0, 0);
    Color maroon_light (0.5, 0.25, 0.25, 0 );
    Color shiny_black ( 0.1,0.1,0.1,0.3);
    Color shiny_white ( 0.9,0.9,0.9,0.2);
    Color reflective (0,0,0,1);
    Color tiles (0,0,0,2);
    Vect light_pos (-7, 10, -10);
    
    vector<Source*> light_sources;
    vector <Object*> scene_objects;
    //scene lights 
    Light scene_light (light_pos, white_light);
    light_sources.push_back(dynamic_cast<Source*>(&scene_light));
    //scene objects 
    
    Plane scene_plane (Vect(0,1,0), -1,tiles);
    scene_objects.push_back(dynamic_cast<Object*>(&scene_plane));
    
    Pyramid p = Pyramid(Vect(0,-1,0), 3, 2, 3, shiny_black);
    scene_objects.push_back(dynamic_cast<Object*>(&p));
   

    //create scene
    Raytracer tracer = Raytracer();
    std::string name;
    for (double i = 0; i < 100; i++){
        name = "pictures/scene" + std::to_string((int)(i)) + ".bmp";
        cout << name << endl;
        cout << "CALLING GENERATE \n";
        tracer.generate(scene_objects, light_sources, name, 1);
        //animate(scene_objects);
    }
}