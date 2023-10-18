#include <iostream>
#include <vector>
using namespace std;

enum account_type
{
    SAVING,
    CURRENT,
    DMAT
};

class insufficient_funds
{
private:
    int accid;
    double cur_balance;
    double withdarw_amount;
    insufficient_funds(int accid, double cur_balance, double withdraw_amount)
    {
        this->accid = accid;
        this->cur_balance = cur_balance;
        this->withdarw_amount = withdraw_amount;
    }

public:
    void display()
    {
        cout << "For Account Id: " << accid << " the balance of " << cur_balance << " is too low to withdraw " << withdarw_amount << endl;
    }
    friend class Account;
};

class Account
{
private:
    int id;
    enum account_type type;
    double balance;

public:
    Account()
    {
        this->id = 0;
    }
    Account(int id, account_type type)
    {
        this->id = id;
        this->type = type;
    }
    void accept()
    {
        int ch;
        cout << "Enter the Account id: ";
        cin >> this->id;
        cout << "Choose the Account Type: " << endl;
        cout << "1. SAVING" << endl;
        cout << "2. CURRENT" << endl;
        cout << "3. DMAT" << endl;
        cin >> ch;
        if (ch == 1)
            this->type = SAVING;
        else if (ch == 2)
            this->type = CURRENT;
        else if (ch == 3)
            this->type = DMAT;
    }
    void display()
    {
        cout << "Your Account id: " << this->id << endl;
        if (this->type == 0)
            cout << "Your Account Type is: SAVING" << endl;
        if (this->type == 1)
            cout << "Your Account Type is: CURRENT" << endl;
        if (this->type == 2)
            cout << "Your Account Type is: DMAT" << endl;
    }
    void setId(int id)
    {
        this->id = id;
    }
    void setType(account_type type)
    {
        this->type = type;
    }
    int getId()
    {
        return this->id;
    }
    account_type getType()
    {
        return this->type;
    }
    double getBalance()
    {
        return this->balance;
    }
    void deposit(double amt)
    {
        this->balance += amt;
    }
    void withdraw(double amt)
    {
        double check = this->balance - amt;
        if (check < 200)
            throw insufficient_funds(this->id, this->balance, amt);
        this->balance -= amt;
    }
};

int menu()
{
    int choice;

    cout << "*****************************" << endl;
    cout << "0. EXIT" << endl;
    cout << "1. ADD ACCOUNT" << endl;
    cout << "2. DISPLAY ACCOUNTS" << endl;
    cout << "3. DEPOSIT" << endl;
    cout << "4. WITHDRAW" << endl;
    cout << "5. VIEW BALANCE" << endl;
    cout << "6. VIEW ACCOUNT ID" << endl;
    cout << "7. VIEW ACCOUNT TYPE" << endl;
    cout << "8. CHANGE ACCOUNT ID" << endl;
    cout << "9. CHANGE ACCOUNT TYPE" << endl;
    cout << "10. DISPLAY ACCOUNTS IN REVERSE ORDER" << endl; 
    cout << "11. DISPLAY ACCOUNTS IN FORWARD ORDER" << endl; 
    cout << "*****************************" << endl;
    cout << "Enter your choice....." << endl;
    cin >> choice;
    cout << "*****************************" << endl;

    return choice;
}

int main()
{
    int choice;
    int accid;
    double amt;
    enum account_type Type;
    vector<Account> arr(5);
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {

        case 1:
            for (int i = 0; i < 5; i++)
                arr[i].accept();
            break;
        case 2:
            for (int i = 0; i < arr.size(); i++)
                arr.at(i).display();
            break;
        case 3:
            cout << "Enter the Account id and Amount to Deposit: ";
            cin >> accid >> amt;
            for (int i = 0; i < 5; i++)
            {
                if (accid == arr[i].getId())
                    arr[i].deposit(amt);
            }
            break;
        case 4:
            cout << "Enter the Account id and Amount to Withdraw: ";
            cin >> accid >> amt;
            for (int i = 0; i < 5; i++)
            {
                if (accid == arr[i].getId())
                {
                    try
                    {
                        arr[i].withdraw(amt);
                        cout << "Withdrawal successful. Updated balance: " << arr[i].getBalance() << endl;
                    }
                    catch (insufficient_funds &e)
                    {
                        cout << "Error: " << endl;
                        e.display();
                    }
                }
            }
            break;
        case 5:
            cout << "Enter the Account id: ";
            cin >> accid;
            for (int i = 0; i < 5; i++)
            {
                if (accid == arr[i].getId())
                    amt = arr[i].getBalance();
            }
            cout << "Your Current Balance is: " << amt << endl;
            break;
        case 6:
            int index;
            cout << "Enter the Index: ";
            cin >> index;
            cout << "Your Account Id is: " << arr[index].getId() << endl;
            break;
        case 7:
            cout << "Enter the Account id: ";
            cin >> accid;
            for (int i = 0; i < 5; i++)
            {
                if (accid == arr[i].getId())
                    Type = arr[i].getType();
            }
            if (Type == 0)
                cout << "Your Account Type is: SAVING" << endl;
            if (Type == 1)
                cout << "Your Account Type is: CURRENT" << endl;
            if (Type == 2)
                cout << "Your Account Type is: DMAT" << endl;
            break;
        case 8:
            cout << "Enter the Index and Account Id to change: ";
            cin >> index >> accid;
            arr[index].setId(accid);
            cout << "Your Id has been Successfully changed!!" << endl;

            break;
        case 9:
            int ch;
            cout << "Enter the Account Id for which you wish to change: ";
            cin >> accid;
            cout << "Choose the Account Type to change as: " << endl;
            cout << "1. SAVING" << endl;
            cout << "2. CURRENT" << endl;
            cout << "3. DMAT" << endl;
            cin >> ch;

            for (int i = 0; i < 5; i++)
            {
                if (accid == arr[i].getId())
                {
                    if (ch == 1)
                    {
                        Type = SAVING;
                        arr[i].setType(Type);
                    }
                    else if (ch == 2)
                    {
                        Type = CURRENT;
                        arr[i].setType(Type);
                    }
                }
                else if (ch == 3)
                {
                    Type = DMAT;
                    arr[i].setType(Type);
                }
            }
            break;
        case 10:
            // Display accounts in reverse order using iterators
            for (auto it = arr.rbegin(); it != arr.rend(); it++)
                    it->display();
                break;
            break;
        case 11:
            // Display accounts in forward order using iterators
            for (int i = 0 ; i < arr.size() ; i++)
                arr.at(i).display();
            break;
        default:
            cout << "Wrong choice!! Try Again..." << endl;
            break;
        }
    }
    cout << "Exiting Now..." << endl;

    return 0;
}