#ifndef CYLINDER_H
#define CYLINDER_H
#include<iostream>
using namespace std;

class Cylinder
{
private:
    double volume;
    double radius;
    double height;

public:
    Cylinder();
    Cylinder(double height , double radius );
    //Cylinder(double height = 0, double radius = 0);
    double getRadius();
    double getHeight();
    void setRadius();
    void setHeight();
    double getVolume();
    void printVolume();
};


#endif