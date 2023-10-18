#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
    int size;
    int top = 0;
    T *ptr;

public:
    Stack()
    {
        size = 5;
        top = 0;
        ptr = new T[size];
    }
    Stack(int size)
    {
        this->size = size;
        top = 0;
        ptr = new T[size];
    }
    void push(T num)
    {
        if (top >= this->size)
            cout << "Stack is Full....Cannot add more element" << endl;
        else
        {
            ptr[top] = num;
            ++top;
        }
    }
    void pop()
    {
        --top;
    }
    T peek()
    {
        return this->top;
    }
    T getIndex(int index)
    {
        if (-1 < index && index < this->top)
            return this->ptr[index];
        return 0;
    }
    void print()
    {
        cout << "STACK is: ";
        for (int i = top; i >= 0; i--)
            cout << ptr[i] << " ";
        cout << endl;
    }
    ~Stack()
    {
        cout << "Inside dtor" << endl;
        delete[] ptr;
    }
    int getLength()
    {
        return this->top;
    }
};

class Box
{
private:
    int length;
    int width;
    int height;

public:
    Box()
    {
        length = 0;
        width = 0;
        height = 0;
    }
    Box(int length, int width, int height)
    {
        this->height = height;
        this->length = length;
        this->width = width;
    }
    void accept()
    {
        cout<<"Enter the Dimensions for the Box: "<<endl;
        cout << "Enter the length: ";
        cin >> this->length;
        cout << "Enter the width: ";
        cin >> this->width;
        cout << "Enter the height: ";
        cin >> this->height;
        cout<<endl;
    }
    int calculateVolume(int length, int width, int height)
    {
        return length * width * height;
    }
    void display()
    {
        int volume;
        volume = this->length * this->width * this->height;
        cout << "Calculated volume is: " << volume << endl;
        cout<<endl;
    }
};

int main()
{
    Stack<int> s1(10);
    for (int i = 0; i < s1.getLength(); i++)
    {
        s1.push(i);
    }
    s1.print();
    cout << endl;
    int ans;
    ans = s1.peek();
    cout << "The top element is: " << ans << endl;
    s1.pop();
    ans = s1.peek();
    cout << "The top element After deletion is: " << ans << endl;
    cout << endl;

    Stack<double> s2(10);
    for (int i = 0; i < s2.getLength(); i++)
    {
        s2.push(i + 2.5);
    }
    s2.print();
    cout << endl;
    double ans_double = s2.peek();
    cout << "The top element is: " << ans_double << endl;
    s2.pop();
    ans_double = s2.peek();
    cout << "The top element After deletion is: " << ans_double << endl;
    cout << endl;

    Stack<Box *> stackBox;

    stackBox.push(new Box);
    stackBox.push(new Box);
    stackBox.push(new Box);

    cout << "The length of the Stack is " << stackBox.getLength() << endl;

    for (int i = 0; i < stackBox.getLength(); i++)
        stackBox.getIndex(i)->accept();

    for (int i = 0; i < stackBox.getLength(); i++)
        stackBox.getIndex(i)->display();

    for (int i = 0; i < stackBox.getLength(); i++)
        delete stackBox.getIndex(i);

    return 0;
}
