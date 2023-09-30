#include <iostream>
using namespace std;
class student {
    private:
    int rollno;
    string name;
    int mark;

public: 
student()
{this->rollno=rollno;
this->name=name;
this->mark=mark;}
 void initStudent()
{
 this->rollno=10;
 this->name="hrishikesh";
 this->mark=34;
}
void printStudentOnConsole()
{
cout<<"student roll no is="<<rollno<<endl;
cout<<"student name is="<<name<<endl;
cout<<"student markis ="<<mark<<endl;
}
void acceptStudentFromConsole(){
  cout<<"enter the rollno name mark"<<endl;
    cin>>rollno;
    getchar();
    getline(cin,name);
    cin>>mark;

}
};
int main()
{
  class  student t;
int choice;
 do{
cout<<"enter choice 1.initialization 2.printstudent on console 3.accept data from  user"<<endl;
cin>>choice;
   switch(choice)                      {
    case 1:
      t.initStudent();
      break;
      case 2:
t.printStudentOnConsole();
    break ;
    case 3:
t.acceptStudentFromConsole();
      break;
      default :
      cout<<"enter valid choice"<<endl;}
      } while(1) ; 
}


