#include <iostream>
using namespace std;

class employee
{
protected:
    int id;
    float sal;
    string designation;

public:
    employee() : id(0), sal(0) {}
    employee(int id, float sal) : id(id), sal(sal)
    {
    }
    int get_id()
    {
        return this->id;
    }
    float get_sal()
    {
        return this->sal;
    }
    void set_id(int id)
    {
        this->id = id;
    }
    void set_sal(float sal)
    {
        this->sal = sal;
    }
    virtual void accept()
    {
        cout << "Enter the id: ";
        cin >> this->id;
        cout << "Enter the Salary: ";
        cin >> this->sal;
    }
    virtual void display()
    {
        cout << "\nThe details are: " << endl;
        cout << "The id is: " << this->id << endl;
        cout << "The salary is: " << this->sal << endl;
    }
    virtual string getDesignation(){
        return this->designation;
    }
};

class manager : virtual public employee
{
protected:
    float bonus;
    void accept_manager()
    {
        cout << "Enter the bonus: ";
        cin >> this->bonus;
    }
    void dispaly_manager()
    {
        cout << "The bonus is: " << this->bonus << endl;
    }

public:
    manager()
    {
        id = 0;
        sal = 0;
        this->bonus = 0;
        designation = "Manager";
    }
    manager(int id, float sal, float bonus)
    {
        employee::id = id;
        employee::sal = sal;
        this->bonus = bonus;
    }
    float get_bonus()
    {
        return this->bonus;
    }
    void set_bonus(float bonus)
    {
        this->bonus = bonus;
    }
    void accept()
    {
        employee::accept();
        cout << "Enter the bonus: ";
        cin >> this->bonus;
    }
    void display()
    {
        employee::display();
        cout << "The bonus is: " << this->bonus << endl;
    }
    string getDesignation(){
        return this->designation;
    }
};

class salesman : virtual public employee
{
protected:
    float comm;
    void accept_salesman()
    {
        cout << "Enter the commission: ";
        cin >> this->comm;
        cout << endl;
    }
    void display_salesman()
    {
        cout << "The commission is: " << this->comm << endl;
    }

public:
    salesman()
    {
        employee::id = 0;
        employee::sal = 0;
        this->comm = 0;
        designation = "Salesman";
    }
    salesman(int id, float sal, float comm)
    {
        employee::id = 0;
        employee::sal = 0;
        this->comm = 0;
    }
    float get_comm()
    {
        return this->comm;
    }
    void set_comm(float comm)
    {
        this->comm = comm;
    }
    void accept()
    {
        employee::accept();
        cout << "Enter the commission for the salesman: ";
        cin >> this->comm;
        cout << endl;
    }
    void display()
    {
        employee::display();
        cout << "\nThe commission for the salesman is: " << this->comm << endl;
    }
    string getDesignation(){
        return this->designation;
    }
};

class sales_manager : virtual public manager, virtual public salesman
{
public:
    sales_manager()
    {
        employee::id = 0;
        employee::sal = 0;
        manager::bonus = 0;
        salesman::comm = 0;
        designation = "Sales Manager";
    }
    sales_manager(int id, float sal, float bonus, float comm)
    {
        employee::id = id;
        employee::sal = sal;
        manager::bonus = bonus;
        salesman::comm = comm;
    }
    void accept()
    {
        manager::accept();
        salesman::accept_salesman();
    }
    void display()
    {
        manager::display();
        salesman::display_salesman();
    }
    string getDesignation(){
        return this->designation;
    }
};

int menu()
{
    int choice;
    cout << "*******************************************" << endl;
    cout << "0. EXIT" << endl;
    cout << "1. ADD EMPLOYEE" << endl;
    cout << "2. NUMBER OF EMPLOYEES ON EACH DESIGNATION" << endl;
    cout << "3. DISPLAY EMPLOYEES" << endl;
    cout << "********************************************" << endl;
    cout << "Enter your choice" << endl;
    cin >> choice;
    cout << "********************************************" << endl;

    return choice;
}

int main()
{
    int choice, count_salesman = 0, count_manager = 0, count_sales_manager = 0, ch;

    employee *arr[10];

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {

        case 1: 
            for (int i = 0; i < 10; i++)
            {
                cout<<"1. MANAGER"<<endl;
                cout<<"2. SALESMAN"<<endl;
                cout<<"3. SALES_MANAGER"<<endl;
                cout<<"Enter your choice....."<<endl;
                cin>>ch;

                if(ch == 1){
                    arr[i] = new manager;
                    arr[i]->accept();
                    count_manager++;
                }
                else if(ch == 2){
                    arr[i] = new salesman;
                    arr[i]->accept();
                    count_salesman++;
                }
                else if(ch == 3){
                    arr[i] = new sales_manager;
                    arr[i]->accept();
                    count_sales_manager++;
                }
            }
            break;
        case 2:
            cout<<"The number of Managers are: "<<count_manager<<endl;
            cout<<"The number of Salesman are: "<<count_salesman<<endl;
            cout<<"The number of Sales Managers are: "<<count_sales_manager<<endl;
       
            break;
        case 3:
                cout<<"1. DISPLAY MANAGERS"<<endl;
                cout<<"2. DISPLAY SALESMANS"<<endl;
                cout<<"3. DISPLAY SALES_MANAGERS"<<endl;
                cout<<"Enter your choice....."<<endl;
                cin>>ch;

                if(ch == 1){
                    for(int i = 0 ; i < 10 ; i++){
                        if(arr[i]->getDesignation() == "Manager")
                            arr[i]->display();
                    }
                        
                }
                else if(ch == 2){
                    for(int i = 0 ; i < 10 ; i++){
                        if(arr[i]->getDesignation() == "Manager")
                            arr[i]->display();
                    }
                }
                else if(ch == 3){
                    for(int i = 0 ; i < 10 ; i++){
                        if(arr[i]->getDesignation() == "Manager")
                            arr[i]->display();
                    }
                }
            break;
        }
    }
    cout << "Exiting Now..." << endl;
    return 0;
}