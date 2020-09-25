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
    Matrix ma_plus=ma+ma2;
    Matrix ma_mult = ma*ma2;
    ma_plus *= 2;
    Matrix ma_plus_mult = ma_plus*ma;
    ma_mult *= 3;
    Matrix ma7=ma_plus_mult-ma_mult;
    Matrix ma3 = ma*(ma+ma2)*2-ma*ma2*3;
    std :: cout << ma3;
    ma3.Simmetric();
    
    return 0;
}
