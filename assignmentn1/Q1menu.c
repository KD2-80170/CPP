#include<stdio.h>
struct date 
{
int day;
int month;
int year;
};

void initdate(struct date *p)
{
    p->day=23;
    p->month=8;
    p->year=1997;
}

void acceptDataonConsole(struct date *p)
 {
  printf("enter date");
  scanf("%d",&p->day);  
  printf("enter month");
  scanf("%d",&p->month);  
  printf("enter year");
  scanf("%d",&p->year);  
 }
 void PrintDateonconsole(struct date *p)
 {
   printf("day is=%d\n",p->day);
   printf("month is=%d\n",p->month);
   printf("year is =%d",p->year);
   }

void main()
{
    struct date p; 
    int choice;
    do {
    printf("\n 1.Initialize the date \n 2.Add data on console \n 3.print data on console ");
    printf("\nenter choice");
    scanf("%d",&choice);
    switch(choice)
        {
        case 1:
        initdate(&p);
       break;
       case 2:
       acceptDataonConsole(&p);
        case 3:
        PrintDateonconsole(&p);
        break;

        default:
        printf("enter correct choice");
        }}while(1);
}


 
 












































































