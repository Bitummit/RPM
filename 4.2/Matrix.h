#ifndef Matrix_H_INCLUDED
#define Matrix_H_INCLUDED
#include <iostream>
class Matrix
{
private:
    int **matrix;
    int n,m;// n quantity of rows; m quantity of columns
public: 
    Matrix(int, int);
    // Matrix(const Matrix &Matrix);



    friend const Matrix operator+(const Matrix& other, const Matrix& another);

    friend const Matrix operator*(const Matrix& other, const Matrix& another);

    friend Matrix operator*=(Matrix& other, int a);

    friend const Matrix operator-(const Matrix& other, const Matrix& another);

    friend std::ostream& operator<< (std::ostream &out, const Matrix&);

    friend std::istream& operator>> (std::istream &in, Matrix&);

};


#endif // Matrix_H_INCLUDED
