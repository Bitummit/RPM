#include <bits/stdc++.h>
#include "Triangle.h"


int main()
{
    int M,N;
    std::cout<<"Enter N and M \n";
    std::cin >> M >> N;
    int *a = (int*)(new int[5]) ;
    std::vector<Triangle> v(N);
    for(int i=0;i<N;i++)
    {
        std::cin >> v[i];
    }
    for(int i=0;i<N;i++)
    {
        std::cout << v[i];
    }
    return 0;
}
