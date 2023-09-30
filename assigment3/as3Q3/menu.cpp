#include "./menu.h"
#include<iostream>
using namespace std;

Emenu menu()
{
    int flag;
    cout << "****************************************" << endl;
    cout << "WELCOME TO CPP  - Cylinder " << endl;
    cout << "0. Exit" << endl;
    cout << "1. Get radius and Display " << endl;
    cout << "2. Set radius " << endl;
    cout << "3. Get height and Display " << endl;
    cout << "4. Set height " << endl;
    cout << "5. Get Volume and Display " << endl;
    cout << "6. print volume " << endl;
    cout << "Please enter your choice : ";
    cin >> flag;
    cout << "****************************************" << endl;
    return Emenu(flag);
}
