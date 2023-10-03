#include <iostream>
#include <string>
using namespace std;

class Student
{
    string name;
    char gender;
    int roll;
    float marks_1, marks_2, marks_3;

public:
    Student()
    {
        name = "";
        gender = ' ';
        roll = 0;
        marks_1 = 0;
        marks_2 = 0;
        marks_3 = 0;
    }

    void acceptStudent()
    {
        cin.ignore(); // Ignore any previous newline character
        cout << "ENTER NAME: ";
        getline(cin, name);
        cout << "ENTER GENDER (M/F): ";
        cin >> gender;
        cout << "ENTER ROLL NUMBER: ";
        cin >> roll;
        cout << "ENTER MARKS_1: ";
        cin >> marks_1;
        cout << "ENTER MARKS_2: ";
        cin >> marks_2;
        cout << "ENTER MARKS_3: ";
        cin >> marks_3;
    }

    void print()
    {
        cout << "NAME: " << name << endl;
        cout << "GENDER: " << gender << endl;
        cout << "ROLL NUMBER: " << roll << endl;
        cout << "MARKS_1: " << marks_1 << endl;
        cout << "MARKS_2: " << marks_2 << endl;
        cout << "MARKS_3: " << marks_3 << endl;
    }

    const string& getName() const
    {
        return name;
    }

    int getRoll() const
    {
        return roll;
    }
};

void sortRecords(Student arr[], int size)
{
    // Bubble sort implementation to sort students based on roll number
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j].getRoll() > arr[j + 1].getRoll())
            {
                // Swap the elements if they are in the wrong order
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int searchRecords(Student arr[], int size, int roll)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].getRoll() == roll)
        {
            return i; // Return the index of the found student
        }
    }
    return -1; // Return -1 if student is not found
}

int main()
{
    const int maxSize = 10;
    Student students[maxSize];
    int size = 0;

    while (true)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Student" << endl;
        cout << "3. Sort Students by Roll Number" << endl;
        cout << "4. Search Student by Roll Number" << endl;
        cout << "0. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (size < maxSize)
            {
                students[size].acceptStudent();
                size++;
                cout << "Student added successfully!" << endl;
            }
            else
            {
                cout << "Maximum number of students reached!" << endl;
            }
            break;
        case 2:
            for (int i = 0; i < size; i++)
            {
                students[i].print();
                cout << "--------------------" << endl;
            }
            break;
        case 3:
            sortRecords(students, size);
            cout << "Students sorted by Roll Number." << endl;
            break;
        case 4:
            int rollToSearch;
            cout << "Enter Roll Number to search: ";
            cin >> rollToSearch;
            int result = searchRecords(students, size, rollToSearch);
            if (result != -1)
            {
                cout << "Student found at index " << result << ":" << endl;
                students[result].print();
            }
            else
            {
                cout << "Student not found!" << endl;
            }
            break;
        case 0:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
