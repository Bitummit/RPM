#include <iostream>
#include "Matrix.h"

int main()
{
    int n, m, n2,m2;
    std::cin >> n >> m;
    Matrix ma(n,m);
    std::cin >> ma;
    std::cout << ma;
    std::cin >> n2 >> m2;
    Matrix ma2(n2,m2);
    std::cin >> ma2;
    std::cout << ma2;
    // Matrix ma3(n,m);
    // ma3 = ma+ma2;
    // std::cout << ma3;
    Matrix ma4(n,m);
    ma4 = ma*ma2;
    std::cout << ma4;
    return 0;
}
