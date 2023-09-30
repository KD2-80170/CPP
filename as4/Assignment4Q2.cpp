#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
class Stack
{
    
private:
    int top = -1;
    int length;
    int *array;

    
public:
    
    Stack()
    {
        this->length = 5;
        this->array = new int[this->length];
    }
   
    Stack(int length)
    {
        this->length = length;
        this->array = new int[this->length];
    }

   
    void push(int value)
    {
        if (top < this->length)
        {
            top++;
            this->array[top] = value;
            cout << this->array[top] << " Succesfully Pushed" << endl;
        }
        else
        {
            cout << "STACK IS FULL , Dont push more or make a bigger one " << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {

            cout << this->array[top] << " Succesfully Poped" << endl;
            this->array[top] = -999;
            top--;
        }
        else
        {
            cout << "Stack is empty. push something" << endl;
        }
    }

   

    void peek()
    {

        cout << "peekaboo : " << this->array[top] << endl;
    }

 

    bool isEmpty()
    {
        if (top == -1)
        {
            cout << "Yes EMPTY" << endl;
            return true;
        }
        else
        {
            cout << "Not Empty , elements present : " << top+1 << endl;
            return false;
        }
    }

   

    void print()
    {
        if (this->top < 0)
        {
            cout << "empty" << endl;
        }
        else
        {
            cout << "The stack is having  -: " << endl;
            for (int i = 0; i <=top ; i++)
            {
                cout << this->array[i] << endl;
            }
            cout << "--------------" << endl;
        }
    }

   
    ~Stack()
    {
        delete[] array;
    }
};

int main()
{
    Stack stack1(15);
    Stack stack2(20);

    stack1.push(1);
    stack1.push(2);
    stack1.push(6);
    stack1.push(7);
    stack1.peek();
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.pop();
    stack1.print();

    return 0;
}
