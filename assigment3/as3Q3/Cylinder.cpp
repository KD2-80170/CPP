#include "./Cylinder.h"
#include<iostream>
using namespace std;
Cylinder::Cylinder()
{
    this->height = 0;
    this->radius = 0;
}
Cylinder::Cylinder(double height, double radius) : height(height) , radius(radius)
{
    
}

// Cylinder::Cylinder(double height = 0, double radius = 0)
// {
//     this->height = height;
//     this->radius = radius;
//}

double Cylinder::getRadius()
{
    return this->radius;
}

double Cylinder::getHeight()
{
    return this->height;
}
void Cylinder::setRadius()
{
    cout << "Enter your Radius : ";
    cin >> this->radius;
}
void Cylinder::setHeight()
{
    cout << "Enter your Height : ";
    cin >> this->height;
}

double Cylinder::getVolume()
{
    this->volume = 3.14 * radius * radius * height;
    return this->volume;
}
void Cylinder::printVolume()
{
    this->volume = 3.14 * radius * radius * height;
    cout << "VOLUME :" << this->volume << endl;
}
