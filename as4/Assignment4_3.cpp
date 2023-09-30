#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;


class Matrix
{

private:
    int length;
    int **array;
public:
   
    Matrix()
    {
        this->length = 3;
        this->array = new int *[this->length];
        for (int i = 0; i < this->length; i++)
            this->array[i] = new int[this->length];
    }

 
    Matrix(int length)
    {
        this->length = length;
        this->array = new int *[this->length];
        for (int i = 0; i < this->length; i++)
            this->array[i] = new int[this->length];
    }

 
    void acceptValues()
    {
        for (int r = 0; r < this->length; r++)
        {
            for (int c = 0; c < this->length; c++)
            {
                cout << "please enter value for row " << r + 1 << " and column " << c + 1 << " : ";
                cin >> this->array[r][c];
            }
        }
    }


    void print()
    {
        for (int r = 0; r < this->length; r++)
        {
            for (int c = 0; c < this->length; c++)
            {
                cout << this->array[r][c];
            }
            cout << "\n";
        }
    }

    
    int getLength()
    {
        return this->length;
    }
    
    int **get_array()
    {
        return this->array;
    }
   
    ~Matrix()
    {
        for (int i = 0; i < this->length; i++)
            delete this->array[i];
        delete this->array;
    }
};
namespace Nmatrix
{
    
    void add(Matrix *m1, Matrix *m2)
    {
        int len = m1->getLength();
        Matrix res(len);

      
        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++)
                res.get_array()[i][j] = m1->get_array()[i][j] + m2->get_array()[i][j];

        // //printing array
        cout << endl
             << "Sum of two matrix is: " << endl;
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
                cout << res.get_array()[i][j] << "  ";
            cout << endl;
        }
    };

   
    void substract(Matrix *m1, Matrix *m2)
    {
        int len = m1->getLength();
        Matrix res(len);

      
        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++)
                res.get_array()[i][j] = m1->get_array()[i][j] - m2->get_array()[i][j];

        
        cout << endl
             << "Substraction of two matrix is: " << endl;
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
                cout << res.get_array()[i][j] << "  ";
            cout << endl;
        }
    };

  
    void multiply(Matrix *m1, Matrix *m2)
    {
        int len = m1->getLength();
        Matrix res(len);

        //
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                res.get_array()[i][j] = 0;

                for (int k = 0; k < len; k++)
                    res.get_array()[i][j] += m1->get_array()[i][k] * m2->get_array()[k][j];
            }
        }

       
        cout << endl
             << "Multiplication of two matrix is: " << endl;
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
                cout << res.get_array()[i][j] << "  ";
            cout << endl;
        }
    }


    
    void transpose(Matrix *m1)
    {
        int len = m1->getLength();
        Matrix res(len);

   
        for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
            res.get_array()[i][j] = m1->get_array()[j][i];

    
        cout << endl
             << "Transpose of the matrix is: " << endl;
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
                cout << res.get_array()[i][j] << "  ";
            cout << endl;
        }
    }

    

    

};
using namespace Nmatrix;
int main()
{
    Matrix m1;
    Matrix m2;
    m1.acceptValues();
    m1.print();
    m2.acceptValues();
    m2.print();
    add(&m1, &m2);
    substract(&m1, &m2);
    multiply(&m1, &m2);
    transpose(&m1);

    return 0;
}
