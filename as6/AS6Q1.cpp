#include <iostream>
using namespace std;
class date
{
private:
    int day;
    int month;
    int year;

public:
    date()
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void accept()
    {
        cout << "enter day month and year" << endl;
        cin >> day >> month >> year;
    }
    void display()
    {

        cout << day << month << year << endl;
    }
    int getDay()
    { return this->day;}
    int getMonth()
    { return this->day;}
    int getYear()
    { return this->day;}
    void setDay(int day)
    { this->day=day;}
    void setMonth()
    { this->month=month;}
    void setYear()
    {this->year=year;}
};
class employee
{
private:
    int id;
    float salary;
    string dept;
    date job;

public:
    employee()
    {
        this->id = id;
        this->salary = salary;
        this->dept = dept;
    }
    employee(int id, float salary, string dept, int joining,int day,int month,int year):job(day,month,year)
     {// use parameterize custructor when you give output thruhgh cunstructor only
     this->id = id;
     this->salary = salary;
        this->dept = dept;
    }
    void accept()
    {
        cout << "enter id sal dept joining " << endl;
        cin >> id >> salary >> dept; // >> //joining;
        job.accept();
    }
    void display()
    {
        cout << id << salary << dept; //<< joining;
        job.display();
    }
    int getId()
    {
     return this->id;
    }
    float getsalary()
    { return this->salary;
    }
    string getdept()
    { return this->dept;
    }
    void setid(int id)
    {  this->id=id;}
    void setsalary(float salary)
    {     
      this->salary=salary;  
    }
    void setdept(string dept)
    {   this->dept=dept;}

};

class person
{

private:
    string name;
    string address;
    int date_birth;
      date m;
      public:
    person()
    {
        this->name = name;
        this->address = address;
        //this->date_birth = date_birth;
       
    }

    person(int name, string address, int date_birth)
    {
        this->name = name;
        this->address = address;
        this->date_birth = date_birth;
    }

    void accept()
    {
        cout << "enter name  adrres of birth" << endl;
        cin>>name>>address ;
      m.accept();
    }

    void display()
    {
        cout << "name address and date_birth is a below" << endl;
        cout << name <<address<< endl;
        m.display();
    }
    string getname()
    {  return this->name=name;  
    }string getaddress()
    {  return this->address=address;  
    }
    void setname(string name)
    {    
        this->name=name;
    }
    void setaddress(string address)
    { this->address=address;  }

};

int main()
{  
    employee e;
    e.accept();
    e.display();
   person l;
     
   l.accept();
   l.display();

    return 0;
}