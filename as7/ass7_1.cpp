#include<iostream>
using namespace std;
class Date
{
 private :
 int day;
 int month;
 int year;

 public:

 Date()
 {
this->day = 0;
this->month = 0;
this-> year= 0;
}
Date(int day, int month, int year)
{
 this-> day = day;
 this->month= month;
 this->year = year;
}
int get_day()
{
  return this->day;

}
void set_day(int day)
{

    this->day = day;
}
int get_month()
{
  return this->month;

}
void set_month(int month)
{

    this->month = month;
}
int get_year()
{

   return this->year;
}
void set_year(int year)
{
  this->year = year;

}
void accept()
{
   cout<<"Enter day :";
  cin>>day;
  cout<<"Enter month :";
  cin>>month;
  cout<<"Enter year :";
  cin>>year;




}
void display()
{
  
  cout<<day<<"/"<<month<<"/"<<year;
 

}
bool is_leap_year()
{
if((year%4==0 && year%100!=0) || (year % 400 == 0))
  
    return true;
  
  
  else
  return false;
  
  
}



};
class Person
{
private :
string name;
string addre;
Date dob;

public:

Person()
{
  this->name = "X";
  this->addre = "X";
 

}
Person(string name, string addre, int day, int month, int year): dob(day,month,year)
{
 this->name = name;
 this->addre = addre;
}
string get_name()
{
 return  this-> name;
  
}
void set_name(string name)
{

    this->name = name;
}
string get_addre()
{
 return this->addre;

}
void set_addre(string addre)
{
    this->addre= addre;
}
Date get_dob()
{

    return this->dob;
} 
void set_dob(Date dob )
{
    this-> dob = dob;
}
void accept_per()
{
cout<<"Enter the name";
cin>>name;
cout<<"Enter  the address";
cin>>addre;
cout<<"Enter the date of birth";
dob.accept();

}
 void display_per()
{
cout<<"Name is...person"<<name<<endl;
cout<<"Address is...person"<<addre<<endl;
cout<<"DATE OF BIRTH is...person"<<endl;
dob.display();

}


};
class Employee : public Person
{
 private :
 int id;
 float sal;
 string dept;
 Date join;

 public:
 
 Employee()
 {
  this->id = 0;
  this-> sal = 0;
  this-> dept = "XX";
  
 }
 Employee(int id, float sal, string dept, int day, int month, int year):join(day, month, year)
 {
  this->id = id;
  this->sal = sal;
  this->dept = dept;

 }
int get_id()
{
 return this->id = id;

}
void set_id(int id)
{
  this->id = id;

}
float get_sal()
{

    return this->sal;
}
void set_sal(float sal)
{
  this->sal=sal;

}
string get_dept()
{

    return this->dept = dept;
}
void set_dept(string dept)
{
   this->dept = dept;

}
Date get_join()
{

    return this->join ;
}
void set_join(Date join)
{
   this->join = join;

}
void accept()
{
  cout<<"Enter the id";
  cin>>id;
  cout<<"Enter the sal";
  cin>>sal;
  cout<<"Enter the dept";
  cin>>dept;
  cout<<"Enter date of joining";
  join.accept();
  this->accept_per();
 

}
void display()
{
cout<<"The id is..."<<id<<endl;
cout<<"The salary is.."<<sal<<endl;
cout<<"The department is"<<dept<<endl;
cout<<"The Date Of Joining ....";
join.display();
 this->display_per();

}

};
/*class Employee :  Person
{



};*/
int main()
{
   Employee e;
  
   e.accept();
   e.display();
    
   //Person p;
   //p.accept();
   //p.display();


    return 0;
}