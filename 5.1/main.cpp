#include <bits/stdc++.h>
<<<<<<< HEAD
#include "IsoTriangle.h"
=======
#include "Triangle.h"
>>>>>>> 1aa6f57ab1ac0e26088710872cd2af715201cce0


int main()
{
    int M,N;
    std::cout<<"Enter N and M \n";
    std::cin >> M >> N;
<<<<<<< HEAD
    std::vector<Triangle> v(N);
    std::vector<IsoTriangle> b(M);
=======
    int *a = (int*)(new int[5]) ;
    std::vector<Triangle> v(N);
>>>>>>> 1aa6f57ab1ac0e26088710872cd2af715201cce0
    for(int i=0;i<N;i++)
    {
        std::cin >> v[i];
    }
<<<<<<< HEAD
    for(int i=0;i<M;i++)
    {
        std::cin >> b[i];
    }
=======
>>>>>>> 1aa6f57ab1ac0e26088710872cd2af715201cce0
    for(int i=0;i<N;i++)
    {
        std::cout << v[i];
    }
<<<<<<< HEAD
    for(int i=0;i<M;i++)
    {
        std::cout << b[i];
    }
=======
>>>>>>> 1aa6f57ab1ac0e26088710872cd2af715201cce0
    return 0;
}
