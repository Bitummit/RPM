#include <iostream>
#include "Matrix.h"

int main()
{
    int n, m, n2,m2,a;
    std::cout << "Enter first matrix's dimension\n";
    std::cin >> n >> m;
    Matrix ma(n,m);
    Matrix ma4(n,m);
    std::cin >> ma;  
    std::cout << ma;
    // std::cout << "Enter second matrix's dimension\n";
    // std::cin >> n2 >> m2;
    Matrix ma2(n,m);
    ma4 = ma2+ma;
    std::cout << ma4;
    std::cin >> ma2;
    std::cout << ma2;
    Matrix ma3 = ma+ma2;
    std::cout << ma3;
    ma3 = ma * ma3;
    std::cout << ma3;
    ma3*=2;
    std::cout << ma3;
    ma4=ma*ma2;
    std::cout << ma4;
    ma4*=3;
    std::cout << ma4;
    ma3 = ma3-ma4;
    std::cout << ma3;
    ma3.Simmetric();
    
    return 0;
}
