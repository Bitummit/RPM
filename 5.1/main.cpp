#include <bits/stdc++.h>
#include "IsoTriangle.h"


int main()
{
    int M,N;
    std::cout<<"Enter N and M \n";
    std::cin >> M >> N;
    std::vector<Triangle> v(N);
    std::vector<IsoTriangle> b(M);
    for(int i=0;i<N;i++)
    {
        std::cin >> v[i];
    }
    for(int i=0;i<M;i++)
    {
        std::cin >> b[i];
    }
    for(int i=0;i<N;i++)
    {
        std::cout << v[i];
    }
    for(int i=0;i<M;i++)
    {
        std::cout << b[i];
    }
    return 0;
}
