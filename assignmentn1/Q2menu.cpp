#include <iostream>
using namespace std;
struct Date
{
    int day;
    int month;
    int year;
};

void initDate(struct Date *p)
{
    p->day= 20;
    p->month = 9;
    p->year = 1998;
}
void printDateOnConsole(struct Date *p)
{
    cout <<"value of day is ="<< p->day<<endl;
    cout <<"value of month is ="<< p->month<< endl;
    cout <<"value of year is ="<< p->year<<endl;
}


void acceptDateFromConsole(struct Date *p)
{
    cin >> p->day;
    cin >> p->month;
    cin >> p->year;
}
bool isLeapYear(struct Date *p)
{
    if ((p->year) % 4 == 0)
    {
        cout << "this is leap year" << endl;
    }
    else
    {
       cout << "this is not leap year" << endl;
    }
}

    main()
{
    struct Date p;
    int choice;
    do
    {
        printf("\n 1.Initialize the date \n 2.Add data on console \n 3.print data on console \n 4.leap year");
        printf("\nenter choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            initDate(&p);
            break;
        case 2:
            acceptDateFromConsole(&p);
        case 3:
            printDateOnConsole(&p);
            break;
        case 4:
           isLeapYear(&p);
            break;

        default:
            printf("enter correct choice");
        }
    } while (1);
    
   
}