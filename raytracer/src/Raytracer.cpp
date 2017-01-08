#include "Raytracer.h"
int Raytracer::closestObjectIndex(vector<double> intersections){
//return index of smallest value greater than 0
    int index = -1;
    if(intersections.size() ==0 ){
        return -1;
    }
    else if (intersections.size() == 1){
        if(intersections.at(0) > .0000000000001 ){
            return 0;
        }
        else{
            return -1; 
        }
    }
    else {
        double max = 0;
        for (int i = 0; i < intersections.size(); i++){
            if(max < intersections.at(i)){
                max = intersections.at(i);
            }
        }
        if(max > 0){
            for (int i = 0; i < intersections.size(); i ++){
                if(intersections.at(i) > .000000000001 && intersections.at(i) <= max ){
                    max = intersections.at(i);
                    index = i;
                }
            }
            

            return index;
        }
        else{
            return -1;
        }
    }
}

Color Raytracer::getColorAt(Vect intersection_position,Vect intersecting_direction, vector<Object*> scene_objects, int index_closest,vector<Source*> light_sources,double  accuracy,double ambientlight, int n){
    Color winning_object_color = scene_objects.at(index_closest)->getColor();
    Vect winning_object_normal = scene_objects.at(index_closest)->getNormalAt(intersection_position);
    if (winning_object_color.getSpecial() == 2) {
        // checkered/tile floor pattern
        
        int square = (int)floor(intersection_position.getX()) + (int)floor(intersection_position.getZ());
        bool cond = ((int)floor(intersection_position.getX() * 50)) %20 == 0 || ((int)floor(intersection_position.getZ() * 50)) %20 == 0 ;
        if (cond ) {
            // black tile
            winning_object_color.setRed(0);
            winning_object_color.setGreen(0);
            winning_object_color.setBlue(0);
        }
        else {
            // white tile
            winning_object_color.setRed(1);
            winning_object_color.setGreen(1);
            winning_object_color.setBlue(1);
        }
    }
    if (winning_object_color.getSpecial() == 3) {
        // checkered/tile floor pattern
        
        int square = intersection_position.getX() - intersection_position.getY() + 100;
        bool cond = (int)(square * 10) % 4 == 0 ;
        if (cond ) {
            // black tile
            winning_object_color.setRed(0);
            winning_object_color.setGreen(0);
            winning_object_color.setBlue(0);
        }
        else {
            // white tile
            winning_object_color.setRed(1);
            winning_object_color.setGreen(1);
            winning_object_color.setBlue(1);
        }
    }
    Color final_color = winning_object_color.scalar(ambientlight);
    
    if (winning_object_color.getSpecularity() > 0 && winning_object_color.getSpecularity() <= 1) {
        // reflection from objects with specular intensity
        double dot1 = winning_object_normal.dotProduct(intersecting_direction.negative());
        Vect scalar1 = winning_object_normal.mult(dot1);
        Vect add1 = scalar1.add(intersecting_direction);
        Vect scalar2 = add1.mult(2);
        Vect add2 = intersecting_direction.negative().add(scalar2);
        Vect reflection_direction = add2.normalize();
        
        Ray reflection_ray (intersection_position, reflection_direction);
        
        // determine what the ray intersects with first
        vector<double> reflection_intersections;
        
        for (int reflection_index = 0; reflection_index < scene_objects.size(); reflection_index++) {
            reflection_intersections.push_back(scene_objects.at(reflection_index)->findIntersection(reflection_ray));
        }
        
        int index_of_winning_object_with_reflection = closestObjectIndex(reflection_intersections);
        
        if (index_of_winning_object_with_reflection != -1) {
            // reflection ray missed everthing else
            if (reflection_intersections.at(index_of_winning_object_with_reflection) > accuracy) {
                // determine the position and direction at the point of intersection with the reflection ray
                // the ray only affects the color if it reflected off something
                
                Vect reflection_intersection_position = intersection_position.add(reflection_direction.mult(reflection_intersections.at(index_of_winning_object_with_reflection)));
                Vect reflection_intersection_ray_direction = reflection_direction;
                if(n > 0){
                    Color reflection_intersection_color = getColorAt(reflection_intersection_position, reflection_intersection_ray_direction, scene_objects, index_of_winning_object_with_reflection, light_sources, accuracy, ambientlight, n-1);
                       
                    //reflection_intersection_color = Color(1, 1, 1, 0);
                    //cout << reflection_intersection_color.getRed() * 255 << ", " << reflection_intersection_color.getGreen() * 255 << ", " << reflection_intersection_color.getBlue() * 255 << ", " << endl;
                    //cout << final_color.getRed() * 255 << ", " << final_color.getGreen() * 255 << ", " << final_color.getBlue() * 255 << ", " << endl;
                    final_color = final_color.add(reflection_intersection_color.scalar(winning_object_color.getSpecularity()));
                    //cout << final_color.getRed() * 255 << ", " << final_color.getGreen() * 255 << ", " << final_color.getBlue() * 255 << ", " << endl;

                }

                
            }
        }
      

     
         
    }
    if (winning_object_color.getTransparency() > 0 && winning_object_color.getTransparency() <= 1) {
        // refraction from objects with specular intensity
       
        double ind = 1/1.3;
        if(winning_object_normal.dotProduct(intersecting_direction) > 0){
            ind = 1.3/1;
        }
        double c1 = winning_object_normal.dotProduct(intersecting_direction);
        double c2 = sqrt(1-(ind*ind) * (1- c1*c1));


        Vect reflection_direction = intersecting_direction.add(winning_object_normal.mult(c1)).mult(ind).add(winning_object_normal.mult(c2).negative());
       
        Ray reflection_ray (intersection_position, reflection_direction);
        
        // determine what the ray intersects with first
        vector<double> reflection_intersections;
        
        for (int reflection_index = 0; reflection_index < scene_objects.size(); reflection_index++) {
            reflection_intersections.push_back(scene_objects.at(reflection_index)->findIntersection(reflection_ray));
        }
        
        int index_of_winning_object_with_reflection = closestObjectIndex(reflection_intersections);
        
        if (index_of_winning_object_with_reflection != -1) {
            // reflection ray missed everthing else
            if (reflection_intersections.at(index_of_winning_object_with_reflection) > accuracy) {
                // determine the position and direction at the point of intersection with the reflection ray
                // the ray only affects the color if it reflected off something
                
                Vect reflection_intersection_position = intersection_position.add(reflection_direction.mult(reflection_intersections.at(index_of_winning_object_with_reflection)));
                Vect reflection_intersection_ray_direction = reflection_direction;
                if(n > 0){
                    Color reflection_intersection_color = getColorAt(reflection_intersection_position, reflection_intersection_ray_direction, scene_objects, index_of_winning_object_with_reflection, light_sources, accuracy, ambientlight, n-1);
                       
                    //reflection_intersection_color = Color(1, 1, 1, 0);
                    //cout << reflection_intersection_color.getRed() * 255 << ", " << reflection_intersection_color.getGreen() * 255 << ", " << reflection_intersection_color.getBlue() * 255 << ", " << endl;
                    //cout << final_color.getRed() * 255 << ", " << final_color.getGreen() * 255 << ", " << final_color.getBlue() * 255 << ", " << endl;
                    final_color = final_color.add(reflection_intersection_color.scalar(winning_object_color.getTransparency()));
                    //cout << final_color.getRed() * 255 << ", " << final_color.getGreen() * 255 << ", " << final_color.getBlue() * 255 << ", " << endl;

                }

                
            }
        }
      

     
         
    }
    for (int light_index = 0; light_index < light_sources.size(); light_index++){
        Vect light_direction = light_sources.at(light_index) -> getPosition().add(intersection_position.negative()).normalize();
        float cosine_angle = winning_object_normal.dotProduct(light_direction);
        
        if(cosine_angle >0){
            //test for shadows 
            bool shadowed = false;
            
            Vect distance_to_light = light_sources.at(light_index)->getPosition().add(intersection_position.negative());
            float distance_to_light_magnitude = distance_to_light.magnitude();
            
            Ray shadow_ray (intersection_position, light_sources.at(light_index)->getPosition().add(intersection_position.negative()).normalize());
            
            vector<double> secondary_intersections;
            
            for (int object_index = 0; object_index < scene_objects.size() && shadowed == false; object_index++) {
                secondary_intersections.push_back(scene_objects.at(object_index)->findIntersection(shadow_ray));
            }
            
            for (int c = 0; c < secondary_intersections.size(); c++) {
                if (secondary_intersections.at(c) > .1) {
                    if (secondary_intersections.at(c) <= distance_to_light_magnitude) {
                        shadowed = true;
                    }
                    break;
                }
                
            }
            if (shadowed == false) {
                final_color = final_color.add(winning_object_color.multiply(light_sources.at(light_index)->getColor()).scalar(cosine_angle));
                
                if (winning_object_color.getSpecularity() > 0 && winning_object_color.getSpecularity() <= 1) {
                    // special [0-1]
                    double dot1 = winning_object_normal.dotProduct(intersecting_direction.negative());
                    Vect scalar1 = winning_object_normal.mult(dot1);
                    Vect add1 = scalar1.add(intersecting_direction);
                    Vect scalar2 = add1.mult(2);
                    Vect add2 = intersecting_direction.negative().add(scalar2);
                    Vect reflection_direction = add2.normalize();
                    
                    double specular = reflection_direction.dotProduct(light_direction);
                    if (specular > 0) {
                        //cout << "specular" << endl;
                        specular = pow(specular, 10);
                        //cout<< specular << endl;
                        final_color = final_color.add(light_sources.at(light_index)->getColor().scalar(specular*winning_object_color.getSpecularity()));
                    }
                }
                
            }
        }   
    }
    
    return final_color.clip();
}

    
int Raytracer::generate (vector<Object*> objs, vector<Source*>lights, std::string filename, int aa){
    cout << "GENERATING \n";
    aadepth = aa;
    RGBType *pixels = new RGBType[n];
    
    vector<Source*> light_sources;
    vector <Object*> scene_objects;
    light_sources = lights;
    scene_objects = objs;
    double xamnt, yamnt;
    int thisone, aa_index;
    for (int x = 0; x < width; x++) {
       // cout << x << " of " << width << endl;
        for (int y = 0; y < height; y++) {
            thisone = y*width + x;
            
            // start with a blank pixel
            double tempRed[aadepth*aadepth];
            double tempGreen[aadepth*aadepth];
            double tempBlue[aadepth*aadepth];
            
            for (int aax = 0; aax < aadepth; aax++) {
                for (int aay = 0; aay < aadepth; aay++) {
            
                    aa_index = aay*aadepth + aax;
                    
                    srand(time(0));
                    
                    // create the ray from the camera to this pixel
                    if (aadepth == 1) {
                    
                        // start with no anti-aliasing
                        if (width > height) {
                            // the image is wider than it is tall
                            xamnt = ((x+0.5)/width)*aspectratio - (((width-height)/(double)height)/2);
                            yamnt = ((height - y) + 0.5)/height;
                        }
                        else if (height > width) {
                            // the imager is taller than it is wide
                            xamnt = (x + 0.5)/ width;
                            yamnt = (((height - y) + 0.5)/height)/aspectratio - (((height - width)/(double)width)/2);
                        }
                        else {
                            // the image is square
                            xamnt = (x + 0.5)/width;
                            yamnt = ((height - y) + 0.5)/height;
                        }
                    }
                    else {
                        // anti-aliasing
                        if (width > height) {
                            // the image is wider than it is tall
                            xamnt = ((x + (double)aax/((double)aadepth - 1))/width)*aspectratio - (((width-height)/(double)height)/2);
                            yamnt = ((height - y) + (double)aax/((double)aadepth - 1))/height;
                        }
                        else if (height > width) {
                            // the imager is taller than it is wide
                            xamnt = (x + (double)aax/((double)aadepth - 1))/ width;
                            yamnt = (((height - y) + (double)aax/((double)aadepth - 1))/height)/aspectratio - (((height - width)/(double)width)/2);
                        }
                        else {
                            // the image is square
                            xamnt = (x + (double)aax/((double)aadepth - 1))/width;
                            yamnt = ((height - y) + (double)aax/((double)aadepth - 1))/height;
                        }
                    }
                    
                    Vect cam_ray_origin = scene_cam.getPosition();
                    Vect cam_ray_direction = camdir.add(camright.mult(xamnt - 0.5).add(camdown.mult(yamnt - 0.5))).normalize();
                    
                    Ray cam_ray (cam_ray_origin, cam_ray_direction);
                    
                    vector<double> intersections;
                    
                    for (int index = 0; index < scene_objects.size(); index++) {
                        intersections.push_back(scene_objects.at(index)->findIntersection(cam_ray));
                    }
                    
                    int index_of_winning_object = closestObjectIndex(intersections);
                    if (index_of_winning_object == 2){
                        //cout << "Origin: (" << cam_ray.getRayOrigin().getVectX() << ", " << cam_ray.getRayOrigin().getVectY() << ", " << cam_ray.getRayOrigin().getVectZ() << ") ";
                        //cout << "Direction: (" << cam_ray.getRayDirection().getVectX() << ", " << cam_ray.getRayDirection().getVectY() << ", " << cam_ray.getRayDirection().getVectZ() << ") \n";
                    }
                    if (index_of_winning_object == -1) {
                        // set the backgroung black
                        tempRed[aa_index] = 0;
                        tempGreen[aa_index] = 0;
                        tempBlue[aa_index] = 0;
                    }
                    else{
                        // index coresponds to an object in our scene
                        if (intersections.at(index_of_winning_object) > accuracy) {
                            // determine the position and direction vectors at the point of intersection
                            
                            Vect intersection_position = cam_ray_origin.add(cam_ray_direction.mult(intersections.at(index_of_winning_object)));
                            Vect intersecting_ray_direction = cam_ray_direction;
        
                            Color intersection_color = getColorAt(intersection_position, intersecting_ray_direction, scene_objects, index_of_winning_object, light_sources, accuracy, ambientlight, 10);
                            
                            tempRed[aa_index] = intersection_color.getRed();
                            tempGreen[aa_index] = intersection_color.getGreen();
                            tempBlue[aa_index] = intersection_color.getBlue();
                        }
                    }
                }
            }
            
            // average the pixel color
            double totalRed = 0;
            double totalGreen = 0;
            double totalBlue = 0;
            
            for (int iRed = 0; iRed < aadepth*aadepth; iRed++) {
                totalRed = totalRed + tempRed[iRed];
            }
            for (int iGreen = 0; iGreen < aadepth*aadepth; iGreen++) {
                totalGreen = totalGreen + tempGreen[iGreen];
            }
            for (int iBlue = 0; iBlue < aadepth*aadepth; iBlue++) {
                totalBlue = totalBlue + tempBlue[iBlue];
            }
            
            double avgRed = totalRed/(aadepth*aadepth);
            double avgGreen = totalGreen/(aadepth*aadepth);
            double avgBlue = totalBlue/(aadepth*aadepth);
            
            pixels[thisone].r = avgRed;
            pixels[thisone].g = avgGreen;
            pixels[thisone].b = avgBlue;
        }
    }
    savebmp(filename.c_str(), width, height, dpi, pixels, n);

    delete pixels;
    t2 = clock();
    float diff = ((float)t2 - (float )t1)/CLOCKS_PER_SEC;
    cout << diff << " seconds " << endl;
    return 0; 
}
void Raytracer::savebmp (const char *filename, int w, int h, int dpi, RGBType *data, int size){
    cout << "SAVING \n";
    RGBType *pixels = new RGBType[size];
    FILE *f;
    int k = w*h;
    int s = 4*k;
    int filesize = 54 + s;

    double factor = 39.375;
    int m = static_cast<int>(factor);

    int ppm = dpi*m;

    unsigned char bmpfileheader[14] = {'B', 'M', 0,0,0,0, 0,0,0,0, 54, 0,0,0};
    unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0};

    bmpfileheader[2] = (unsigned char) (filesize);
    bmpfileheader[3] = (unsigned char) (filesize >> 8);
    bmpfileheader[4] = (unsigned char) (filesize >> 16);
    bmpfileheader[5] = (unsigned char) (filesize >> 24);

    bmpinfoheader[4] = (unsigned char) (w);
    bmpinfoheader[5] = (unsigned char) (w>>8);
    bmpinfoheader[6] = (unsigned char) (w>>16);
    bmpinfoheader[7] = (unsigned char) (w>>24);

    bmpinfoheader[8] = (unsigned char) (h);
    bmpinfoheader[9] = (unsigned char) (h>>8);
    bmpinfoheader[10] = (unsigned char) (h>>16);
    bmpinfoheader[11] = (unsigned char) (h>>24);

    bmpinfoheader[21] = (unsigned char) (s);
    bmpinfoheader[22] = (unsigned char) (s>>8);
    bmpinfoheader[23] = (unsigned char) (s>>16);
    bmpinfoheader[24] = (unsigned char) (s>>24);

    bmpinfoheader[25] = (unsigned char) (ppm);
    bmpinfoheader[26] = (unsigned char) (ppm>>8);
    bmpinfoheader[27] = (unsigned char) (ppm>>16);
    bmpinfoheader[28] = (unsigned char) (ppm>>24);

    bmpinfoheader[29] = (unsigned char) (ppm);
    bmpinfoheader[30] = (unsigned char) (ppm>>8);
    bmpinfoheader[31] = (unsigned char) (ppm>>16);
    bmpinfoheader[32] = (unsigned char) (ppm>>24);

    f = fopen(filename, "wb");

    fwrite(bmpfileheader, 1, 14, f);
    fwrite(bmpinfoheader, 1, 40, f); 

    for (int i = 0; i < k; i ++){
        RGBType rgb = data[i];

        double red = (data[i].r) * 255;
        double green = (data[i].g) * 255;
        double blue = (data[i].b) * 255;

        unsigned char color[3] = {(int) floor(blue), (int) floor(green), (int) floor(red)};

        fwrite(color, 1, 3, f);
    }

    fclose(f);

}




Raytracer::Raytracer(){
    
    t1 = clock();

    dpi = 72;
    width = 640;
    height = 480;

    n = width*height;
   

    aadepth = 2;
    aathreshold = 0.1;
    aspectratio = (double)width/ (double)height;
    ambientlight = 0.2;
    accuracy = 0.0000001;
    O = Vect(0,0,0);
    X = Vect(1,0,0);
    Y = Vect(0,1,0);
    Z = Vect(0,0,1);

    campos = Vect(-3,6, -10);
    look_at = Vect(0,0,0);
    diff_btw = Vect(campos.getX() - look_at.getX(), campos.getY() - look_at.getY(), campos.getZ() - look_at.getZ());
    
    camdir = diff_btw.negative().normalize();
    camright = Y.crossProduct(camdir).normalize();
    camdown = camright.crossProduct(camdir);
    scene_cam = Camera(campos, camdir, camright, camdown);

    
}
