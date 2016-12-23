#ifndef _COLOR_H
#define _COLOR_H

class Color {

    double red, green, blue, special;
    public:

    Color();

    Color (double, double, double, double);

    //method functions

    double getRed();
    double getGreen();
    double getBlue();
    double getSpecial();

    void setRed(double r);
    void setGreen(double g);
    void setBlue(double b);
    void setSpecial(double s);

    double brightness();

    Color scalar(double scalar);
    Color add(Color color);
    Color multiply(Color color);
    Color average(Color color);
    Color clip();
};

#endif