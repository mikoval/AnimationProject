#include "Object.h"

Color Object::getColor(){return Color(0,0,0,0);}
int Object::move(Vect){return 0;}
double Object::findIntersection(Ray ray){return 0;}

Vect Object::getNormalAt(Vect intersection_position){
    return Vect(0,0,0);
}
 void Object::rotate(Matrix r){}


Object::Object(){
   
}

