#include <iostream>
using namespace std;

class Distance
{
private:
    float feet;
    float inches;

public:
    Distance()
    {
        this->feet = 0;
        this->inches = 0;
    }
    Distance(float feet, float inches)
    {
        this->feet = feet;
        this->inches = inches;
    }
    friend Distance operator+(Distance d1, Distance d2)
    {
        Distance d;
        d.feet = d1.feet + d2.feet;
        d.inches = d1.inches + d2.inches;
        return d;
    }
    Distance operator++()
    {
        ++this->inches;
        return *this;
    }
    float getFeet()
    {
        return this->feet;
    }
    float getInches()
    {
        return this->inches;
    }

    friend bool operator==(Distance &, Distance &);
    friend Distance operator--(Distance &);
    friend void operator>>(istream &, Distance &);
};

bool operator==(Distance &d, Distance &d1)
{
    if (d.feet == d1.feet && d.inches == d1.inches)
        return true;
    else
        return false;
    return true;
}
Distance operator--(Distance &d)
{
    --d.inches;
    return d;
}

void operator<<(ostream &out, Distance &d)
{
    out << "The Distance is: " << d.getFeet() << " feet and " << d.getInches() << " inches." << endl;
}
void operator>>(istream &in, Distance &d)
{
    cout << "Enter the Feet: ";
    in >> d.feet;
    cout << "Enter the Inches: ";
    in >> d.inches;
}

int main()
{
    Distance d;

    cout << "Enter the Distance: " << endl;
    cin >> d;

    // cout << d;

    Distance d1(4, 5);

    Distance d2 = d1;

    cout << d2;

    Distance d3 = d + d1;
    cout << "After the sum of two objects" << endl;
    cout << d3;

    ++d3;
    cout<<"After increment"<<endl;
    cout<<d3;

    --d3;
    cout<<"After decrement"<<endl;
    cout<<d3;


    return 0;
}