#include <iostream>
#include "Matrix.h"

int main()
{
    int n, m, n2,m2,a;
    std::cout << "Enter first matrix's dimension\n";
    std::cin >> n >> m;
    Matrix ma(n,m);
    std::cin >> ma;  
    std::cout << ma;
    std::cout << "Enter second matrix's dimension\n";
    std::cin >> n2 >> m2;
    Matrix ma2(n2,m2);
    std::cin >> ma2;
    std::cout << "ma2:\n";
    std::cout << ma2;
    std::cout << "ma_plus:\n";
    Matrix ma_plus=ma+ma2;
    std::cout << ma_plus;
    std::cout << "ma_mult:\n";
    Matrix ma_mult = ma*ma2;
    std::cout << ma_mult;
    std::cout << "ma_plus*2:\n";
    ma_plus *= 2;
    std::cout << ma_plus;
    std::cout << "ma_plus_mult*3:\n";
    Matrix ma_plus_mult = ma_plus*ma;
    std::cout << ma_plus_mult;
    std::cout << "ma_mult*3:\n";
    ma_mult *= 3;
    std::cout << ma_mult;
    Matrix ma7=ma_plus_mult-ma_mult;
    std :: cout << ma7;
    ma7.Simmetric();
    
    return 0;
}
