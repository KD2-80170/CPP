#include <iostream>
#include "./Cylinder.h"
#include "./menu.h"

using namespace std;
int main()
{
    Cylinder cylinder(2.0,3.0);
    Emenu flag;
    double radius;
    double height;
    double volume;
    while ((flag = menu()) != EXIT) 
    {
        switch (flag)
        {
        case GET_RADIUS_AND_DISPLAY:
            radius = cylinder.getRadius();
            cout << "RADIUS IN valriable :" << radius << endl;
            break;

        case SET_RADIUS:
            cylinder.setRadius();
            break;

        case GET_HEIGHT_AND_DISPLAY:
            height = cylinder.getHeight();
            cout << "HEIGHT IN valriable : " << height << endl;
            break;

        case SET_HEIGHT:
            cylinder.setHeight();
            break;

        case GET_VOLUME_AND_DISPLAY:
            volume = cylinder.getVolume();
            cout << "VOLUME IN valriable : " << volume << endl;
            break;

        case PRINT_VOLUME:
            cylinder.printVolume();
            break;

        default:
            cout << "PLEASE ENTER A VALID INPUT " << endl;
            break;
        }
    }

    return 0;
}
