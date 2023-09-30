#include<iostream>
using namespace std;
class Date
{  
private:
     int day;
    int month; 
   int year;

 public :  
Date() {
this->day=day;
this->month=month;
this->year=year;
       }    
void initDate()
{
 this->day=24;
 this->month=8;
 this->year=1998;
}
void printDateOnConsole()
{
cout<<"date is"<<endl;
cout<<day<<"/"<<month<<"/"<<year<<endl;
}
void acceptDateFromConsole()
{
 cout<<"enter day"<<endl;
 cin>>day;
 cout<<"enter month"<<endl;
 cin>>month;
 cout<<"enter year"<<endl;
 cin>>year;
}
bool isLeapYear()
{
    if ((year%4)==0)
    {
        cout<<year<<" "<<"year is leap year"<<endl;
    }
    else
    {
        cout<<year<<" "<<"this is not leap year"<<endl;
    }
}

};
     main()
{class Date t;
int choice;
do{
cout<<"enter choice \n1.inti the date  \n2.print date \n3.enter day month year"<<endl;
  cin>>choice;
    switch(choice){
    case 1:t.initDate();
    break;
    case 2:t.printDateOnConsole();
    break;
    case 3:t.acceptDateFromConsole();
    break;
    case 4:t.isLeapYear();
    break;
    default : cout<<"enter correct choice"<<endl;
 }
 }while(1);
}