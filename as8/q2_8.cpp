#include <iostream>
using namespace std;
class Stack
{
private:
    int *ptr;
    int top;

public:
    int size;

    Stack()
    {
        size = 5;
        top = -1;
        ptr = new int[size];
    }
    Stack(int size)
    {
        this->size = size;
        top = -1;
        ptr = new int[size];
    }
    Stack(Stack& stk) : size(stk.size), top(stk.top), ptr(new int[size]) {
        for (int i = 0; i <= top; i++) {
            ptr[i] = stk.ptr[i];
        }
    }
    int pop()
    {
        int temp;
        if (isEmpty())
            return 0;
        temp = ptr[top];
        --top;
        return temp;
    }
    int push(int num)
    {
        if (isFull())
            return 0;
        ++top;
        ptr[top] = num;
        return num;
    }
    int peek()
    {
        return ptr[top];
    }
    int isEmpty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }
    int isFull()
    {
        if (top == (size - 1))
            return 1;
        else
            return 0;
    }
    void print()
    {
        cout << "STACK is: ";
        for (int i = top; i >= 0; i--)
            cout << ptr[i] << " ";
        cout << endl;
    }
    void increaseSize(int size){
        int *iptr = new int[size];
        for(int i = 0 ; i < this->size ; i++){
            iptr[i] = ptr[i];
        }
        delete[] ptr;
        ptr = iptr;
        iptr = NULL;
        this->size = size;
    }
    Stack operator=(Stack &stk){
        size = stk.size;
        top = stk.top;
        ptr = new int[size];

        for (int i = 0; i <= top; i++) {
            ptr[i] = stk.ptr[i];
        }

        return *this;
    }
    ~Stack(){
        cout<<"Inside dtor"<<endl;
        delete[] ptr;
    }
};

int main()
{
    Stack s1(10);
    for (int i = 0; i < s1.size; i++)
    {
        s1.push(i);
    }
    s1.print(); 
    cout<<endl;
    int ans;
    ans = s1.peek();
    cout<<"The top element is: "<<ans<<endl;
    s1.pop();
    cout<<endl;
    ans = s1.peek();
    cout<<"After pop the top element is: "<<ans<<endl;
    cout<<endl;
    cout<<"Making a copy of the current stack..."<<endl;
    
    Stack s2;
    s2 = s1;

    cout<<"The Copied Stack is: "<<endl;
    s2.print();

    return 0;
}