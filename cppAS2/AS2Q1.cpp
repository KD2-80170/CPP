#include<iostream>
#include<stdio.h>
#include <string>

using namespace std;
namespace NStudent{
class Student{
    int rollNo;
    string name;
    int marks;
    public:

    void initStudent(){
        this->rollNo = 01;
        this->name = "default";
        this->marks = 100;

    }
    void printStudentOnConsole(){
        cout<<"Student : \n name - "<< this->name <<"\n roll no - "<<this->rollNo<<"\n marks-"<<this->marks<<"\n";
    }
    void acceptStudentFromConsole(){
        printf("enter student roll no - ");
        scanf("%d",&this->rollNo);
        printf("enter student name - ");
        getline(cin >> ws, name);
        printf("enter student marks - ");
        scanf("%d",&this->marks);
    }

};
}
using namespace NStudent;
int main(){
    int k= 1;
    Student student ;
    
    
    do {
    printf("--------------------------------------------------------------------------------\nWelcome to C programming \n");
    printf("To initialize the Student as 01-default-100 press 1 \n");
    printf("To print the Student press 2 \n");
    printf("To enter a Student press 3 \n");
    printf("To exit press 0 \n");
    printf("PLEASE ENTER YOUR NUMBER = ");
    scanf("%d",&k);
    switch (k)
    {
    case 1:
        student.initStudent();
        break;
    
    case 2:
        student.printStudentOnConsole();
        break;
    
    case 3:
            student.acceptStudentFromConsole();
        break;
    default:
        printf("enter correct option \n");

    
    }

    
    
    } while (x!=0);
    





    return 0;
}
