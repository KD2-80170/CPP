#include <iostream>
using namespace std;

class Product
{
protected:
    int id;
    string tittle;
    float price;
    string type;

public:
    virtual void accept() = 0;
    virtual void display() = 0;
    virtual string getType() = 0;
    virtual float getPrice() = 0;

};

class Book : public Product
{
protected:
    string author;

public:
    Book()
    {
        this->type = "B";
    }
    void accept()
    {
        cout << "\nEnter the Book id: ";
        cin >> this->id;
        cout << "Enter the Book Tittle: ";
        cin >> this->tittle;
        cout << "Enter the Book Author: ";
        cin >> this->author;
        cout << "Enter the Book Price: ";
        cin >> this->price;
    }
    void display()
    {
        cout << "The Book id: " << this->id << endl;
        cout << "The Book Tittle: " << this->tittle << endl;
        cout << "The Book Author: " << this->author << endl;
        cout << "The Book Price: " << this->price << endl;
        cout << endl;
    }
    string getType()
    {
        return this->type;
    }
    float getPrice(){
        return this->price;
    }
};

class Tapes : public Product
{
protected:
    string artist;

public:
    Tapes()
    {
        this->type = "T";
    }
    void accept()
    {
        cout << "\nEnter the Tape id: ";
        cin >> this->id;
        cout << "Enter the Tape Tittle: ";
        cin >> this->tittle;
        cout << "Enter the Tape Artist: ";
        cin >> this->artist;
        cout << "Enter the Tape Price: ";
        cin >> this->price;
    }
    void display()
    {
        cout << "The id is : " << this->id << endl;
        cout << "The Tape Tittle is : " << this->tittle << endl;
        cout << "The Tape Artist is : " << this->artist << endl;
        cout << "The Tape Price is : " << this->price << endl;
        cout << endl;
    }
    string getType()
    {
        return this->type;
    }
    float getPrice(){
        return this->price;
    }
};

int menu()
{
    int choice;
    cout << "*******************************************" << endl;
    cout << "0. EXIT" << endl;
    cout << "1. ADD A PRODUCT" << endl;
    cout << "2. DISPLAY ALL PRODUCTS" << endl;
    cout << "3. CALCULATE THE BILL" << endl;
    cout << "********************************************" << endl;
    cout << "Enter your choice" << endl;
    cin >> choice;
    cout << "********************************************" << endl;

    return choice;
}

float calculateFinalBill(Product *p[])
{
    float price;    
    for (int i = 0; i < 3; i++)
    {   
        if(p[i]->getType() == "B")
            price += p[i]->getPrice() - (p[i]->getPrice() * 0.10);
        else
            price += p[i]->getPrice() - (p[i]->getPrice() * 0.05);
    }
    return price;
}

int main()
{
    int choice;
    Product *arr[3];

    while ((choice = menu()) != 0)
    {

        switch (choice)
        {
        case 1:
            int ch;
            for (int i = 0; i < 3; i++)
            {
                cout << "What do you want to buy ? " << endl;
                cout << "1. BOOK" << endl;
                cout << "2. TAPES" << endl;
                cout << "Enter your choice ";
                cin >> ch;

                if (ch == 1)
                {
                    arr[i] = new Book();
                    arr[i]->accept();
                }
                if (ch == 2)
                {
                    arr[i] = new Tapes();
                    arr[i]->accept();
                }
            }

            break;

        case 2:
            cout<<"The products in the carts are: "<<endl;
            for (int i = 0; i < 3; i++)
            {
                if (arr[i]->getType() == "B")
                    arr[i]->display();
                if (arr[i]->getType() == "T")
                    arr[i]->display();
            }
            break;

        case 3:     float totalPrice;
                    totalPrice = calculateFinalBill(arr);
                    cout<<"\nThe Total bill is: "<<totalPrice;

            break;

        default:
            cout << "Wrong choice!! Try again..." << endl;
            break;
        }
    }
    for(int  i = 0 ; i < 3 ; i++){
        delete arr[i];
        arr[i] = NULL;
    }
    
    cout << "Exiting Now..." << endl;

    return 0;
}