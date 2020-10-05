#include <iostream>
#include "recttriangle.h"
#include "triangle.h"
#include <conio.h>
#include <set>
#include <iterator>



int main(){



    int N,M ,count = 0;
    float areamax=0,areamin;
    triangle Triangle({1,3},{2,4},{5,6});
    // triangle Triangle1({1,3},{1,3},{1,3});
    // recttriangle rect({1,2},{2,4},{4,3});
    std::cout << "Enter quantity of triangles and rectangular triangles" << std::endl;
    std::cin >> N >> M;
    triangle *Triangles = static_cast<triangle*>(operator new[] (N*sizeof(triangle)));
    recttriangle *Recttriangles = static_cast<recttriangle*>(operator new[] (M*sizeof(recttriangle)));
    for(int i = 0;i < N;i++)
    {
        std::cin >> Triangles[i];
    }
    for(int i = 0;i < M;i++)
    {
        std::cin >> Recttriangles[i];
    }
    std::set<int> RectSet;
    for(int i = 0;i < N;i++)
    {
        if(i==0){
            areamin = Triangles[0].area();
        }
        if(Triangles[i].area()>areamax)
            areamax = Triangles[i].area();
        else if(Triangles[i].area()<areamin)
            areamin = Triangles[i].area();
    }
    for(int i = 0;i < M;i++)
    {
        if(N==0){
            areamin = Recttriangles[0].area();
        }
        for(int j = 0;j < M;j++)
        {
            if(i==j)
            {
            }
            else if(Recttriangles[i]==Recttriangles[j])
            {
                RectSet.insert({i});
                count++;
            }
        }
        if(Recttriangles[i].area()>areamax)
            areamax = Recttriangles[i].area();
        else if(Recttriangles[i].area()<areamin)
            areamin = Recttriangles[i].area();
    }
    std:: cout<< "max area is equal " << areamax << std::endl;
    std:: cout<< "min area is equal " << areamin << std::endl;
    std:: cout<< "list of equal triangles" << std::endl;
    std::set <int> :: iterator it = RectSet.begin();
    for(int i=0;i<count;i++)
    {
        std::cout << *it;
        if(i<count-1){
            std::cout << ",";
            it++;
        }
        else
        {
            std::cout << "\n";
        }
    }

    operator delete[] (Triangles);
    operator delete[] (Recttriangles);
    getch();
    return 0;
}