#include <iostream>
using namespace std;
class employee
{
private:
   int id;
   float sal;

public:
   employee()
   {
      this->id = 0;
      this->sal = 0;
   }
   employee(int id, float sal)
   {
      this->id = id;
      this->sal = sal;
   }
   void accept()
   {
      cout << "accetpt employee id and salary" << endl;
      cin>>id>>sal;
   }
   void display()
   {
      cout << "display employee data" << endl;
      cout<<"id is "<<id<<"  "<<"salary is"<<sal;
   }
   int getId()
   {
      return this->id;
   }

   float getSal()
   {
      return this->sal;
   }

   void setId(int id)
   {
      this->id = id;
   }
      void setSal(float sal)
   {
      this->sal = sal;
   }
};

class manager : virtual public employee
{
private:
   float bonus;

public:
   manager()
   { this->bonus=0;
   }
   manager(float bonus)
   {
      this->bonus=bonus;
   }
   void accept()
   {
      employee::accept();
      acceptm();
   }
   void display()
   {
      employee::display();
      displaym();
     
   }
   float getBonus()
   {
     return this->bonus;
   }
   void setBonus(float bonus)
   {
      this->bonus = bonus;
   }
   protected:
   void acceptm()
   {
      cout << "enter manager bonus" << endl;
      cin>>bonus;
   }
   void displaym()
   {
      cout << "manager bonus is =" << endl;
      cout<<bonus;
   }

};
class salesman : virtual public employee
{
private:
   float comm;

public:
    salesman()
    {
this->comm=0;
    }
    salesman(float comm)
    {
     this->comm=comm;
    }

      void accept()
   {
      employee::accept();
      accepts();
   }
   void display()
   {
      employee::display();
          displays();
     
   }
    
  
   void setComm(float comm)
   {
      this->comm = comm;
   }
   float getComm()
   {
      return this->comm;
   }

   protected:
    void accepts()
   {
     
      cout << "enter salespeople commision" << endl;
      cin>>comm;
   }
   void displays()
   {
      
      cout << " salesperson commision =" << endl;
      cout<<comm;
   }
};
class sales_manager : public salesman, public manager
{
    public:
    sales_manager()
    {}
   void accept()
   {
      employee::accept();
      manager::acceptm();
      salesman::accepts();
   
   }
   void display()
   {
      employee::display();
      manager::displaym();
      salesman::displays();
      
   }
};

int main()
{
   sales_manager s;
  s.accept();
  s.display();

   return 0;
}