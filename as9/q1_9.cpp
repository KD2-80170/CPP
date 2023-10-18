#include <iostream>
using namespace std;

class Factorial
{
private:
    int num;
    int result = 1;

public:
    Factorial()
    {
        this->num = 0;
    }
    Factorial(int num)
    {
        this->num = num;
    }
    void accept()
    {
        cout << "Enter the Number for which you are trying to calculate the factorial: " << endl;
        cin>>this->num;
    }
    void dispaly(){
        cout<<"The Factorial of the number is: "<<this->result<<endl;
    }
    void calFactorial(){
        if(num <= 0)
            throw("Number cannot be negative");
        for(int i = 1 ; i <= num ; i++){
            this->result *= i; 
        }
    }
};


int main(){
    
    Factorial f;
    f.accept();
    try{
    f.calFactorial();
    f.dispaly();
    }
    catch(char const* error){
        cout<<error<<endl;
    }   

    return 0;
}