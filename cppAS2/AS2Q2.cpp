#include<iostream>
using namespace std;
#include<string>
class Address
{
private :
string building;
string city;
string street;
int pin;
public :
 Address()
 { this->city="banglore";this->building="chvahan hostel";  this->street="magistic"; this->pin=410856;}            
 Address(string building ,string city,string street,int pin)
  {
       this->building=building; this->city=city; this->street=street; this->pin=pin;
  }

void accept()
{
cin>>building>>city>>street>>pin;
}
void Printdata()
{
cout<<this->building<<" "<<this->city<<" "<<this->street<<" "<<this->pin<<endl;
}
 string get_Buliding()
{
  return this->building;
}
string get_City()
{
  return this->city;  
}
 string get_Street()
{
   return this->street; 
}
int get_Pin()
{
   return this->pin; 
}
void set_building( string building)
{
    this->building=building;
}
void set_street(string street)
{   this-> street=street;   
}
void set_city(string city)
{
this->city =city;
}
void set_pin(int pin)
{this->pin=pin;
}
};
int main(){
Address a;
string building =a.get_Buliding();  cout<<building<<endl;
string street = a.get_Street();  cout<<street<<endl;  
int pin=a.get_Pin();   cout<<pin<<endl;
string city =a.get_City(); cout<<city<<endl;

a.Printdata();

a.set_building("taj mahal");
a.set_city("washington dc ");
a.set_street(" church get");
a.set_pin(454545);

a.Printdata();  
                     //a.set_building("tajamahal"); you can set manualy like this
a.accept();
a.Printdata();

return 0;
}

