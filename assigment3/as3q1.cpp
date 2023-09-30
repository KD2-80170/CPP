#include <iostream>
using namespace std;
class Box
{
private:
    int length;
    int width;
    int height;
    int volume;

public:
    Box() : length(10), width(10), height(10)
    {
        
    }

    Box(int length, int width, int height) : length(length) ,width(width) ,height(height)
    {
        // this->length = length;
        // this->width = width;
        // this->height = height;
    }

    void accept()
    {
        cout << "enter the lenght width and height" << endl;
        cin >> length >> width >> height;
    }

    void print()
    {
        volume = (height * width * length);
        cout << "volume of box is" << volume << endl;
    }
};
int menu()
{
    int choice;
    cout << "0.exit" << endl;
    cout << "1. fortake input" << endl;
    cout << "2. forvolume" << endl;
    cin >> choice;
    return choice;
}

int main()
{
    int choice;
    Box b;

   // Box b2(10,90,10);
    while (choice != 0)
      {
       switch ((choice = menu()))
       {
      case 1:
           b.accept();
           break;
       case 2:
            b.print();
           break;
       default:
           cout << "enter correct choice" << endl;
       }
    }

    return 0;
}