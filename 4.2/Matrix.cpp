#include "Matrix.h"
#include <assert.h>

Matrix::Matrix(int a, int b)
{
    n = a;
    m = b;
    matrix = new int*[a];
    for(int i = 0; i<a;i++)
    {
        matrix[i] = new int [b];
    }
}


const Matrix operator+(const Matrix& other, const Matrix& another)
{
    assert(other.n == another.n & other.m==another.m);
    Matrix k(other.n,other.m);
    for(int i = 0; i<other.n; i++){
        for(int j = 0;j<other.m; j++){
            k.matrix[i][j] = other.matrix[i][j]+another.matrix[i][j];
        }
    }
    return k;
}

const Matrix operator-(const Matrix& other, const Matrix& another)
{
    assert(other.n == another.n & other.m==another.m);
    Matrix k(other.n,other.m);
    for(int i = 0; i<other.n; i++){
        for(int j = 0;j<other.m; j++){
            k.matrix[i][j] = other.matrix[i][j]-another.matrix[i][j];
        }
    }
    return k;
}

const Matrix operator*(const Matrix& other, const Matrix& another)
{
    assert(other.m == another.n);
    Matrix k(other.n,another.m);
    int sum = 0;
    for(int i = 0; i<k.n; i++)
    {
        for(int j = 0;j<k.m; j++)
        {
            for(int ki = 0; ki<another.n; ki++)
            {
                k.matrix[i][j] += another.matrix[ki][j] * other.matrix[i][ki];
            }
        }
    }
    return k;
}

// const Matrix operator-(const Matrix& other, const Matrix& another)
// {
//     return Matrix(other.x*another.x,other.y*another.y,other.z*another.z);
// }

// bool operator||(const Matrix& other, const Matrix& another)
// {
//     if((other*another).x==0&&(other*another).y==0&&(other*another).z==0)
//         return true;
//     else
//         return false;
// }

// bool operator==(const Matrix& other, const Matrix& another)
// {
//     return(other.x==another.x && other.y==another.y && other.z==another.z);
// }

// bool operator!=(const Matrix& other, const Matrix& another)
// {
//     return!(other==another);
// }


std::ostream& operator<< (std::ostream &out, const Matrix &Matrixout)
{
    for(int i = 0; i<Matrixout.n; i++){
        for(int j = 0;j<Matrixout.m; j++){
           out << "Matrix[" << i << "][" << j << "]=" << Matrixout.matrix[i][j] << '\t'; 
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    return(out);
}

std::istream& operator>> (std::istream &in, Matrix &Matrixin)
{
    for(int i = 0; i<Matrixin.n; i++){
        for(int j = 0;j<Matrixin.m; j++){
           std::cout << "Enter " << "Matrix[" << i << "][" << j << "]"<< std::endl;
           in >> Matrixin.matrix[i][j];
        }
    }
    return(in);
}
