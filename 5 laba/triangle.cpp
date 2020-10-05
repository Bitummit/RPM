#include "triangle.h"
#include <iostream>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
// #pragma once 

triangle::triangle(triangle &Triangle)
{
    for(int i = 0;i < 3;i++)
    {
        coord[i] = Triangle.coord[i];
    }
}

triangle::triangle()
{
    
}


triangle::triangle(Coord vvod, Coord vvod1, Coord vvod2)
{
    if(DoesExist(vvod, vvod1, vvod2)==false)
    {
        std::cout << "triangle doesn't exist" << std::endl;
    }
    else
    {
        coord[0] = vvod;
        coord[1] = vvod1;
        coord[2] = vvod2;
    }

}


std::ostream& operator<< (std::ostream &out, triangle &Trout)
{
    Trout.lensides(out);
    return out;

}
std::istream& operator>> (std::istream &in, triangle &Trin)
{
    while(true)
    {
        for(int i = 0;i < 3;i++)
        {
            std::cout << "Enter the coordinates for " << i+1 << " Angle" << std::endl;
            in >> Trin.coord[i].x;
            in >> Trin.coord[i].y;
        }
        if(Trin.DoesExist(Trin.coord[0], Trin.coord[1], Trin.coord[2])==false)
        {
            std::cout << "triangle doesn't exist" << '\n'
            << "Please, enter normal coordinates" << std::endl;
        }
        else
        {
            break;   
        }
    }
    return in;
}

float triangle::lenvect(Coord &one, Coord &two)
{
    return(sqrt(pow(one.x-two.x,2)+pow(one.y-two.y,2)));
}


bool triangle::DoesExist(Coord vvod, Coord vvod1, Coord vvod2)
{
    return((lenvect(vvod, vvod1)+lenvect(vvod1, vvod2)>lenvect(vvod, vvod2))&&(lenvect(vvod1, vvod2)+lenvect(vvod2, vvod)>lenvect(vvod,vvod1))&&(lenvect(vvod, vvod2)+lenvect(vvod, vvod1)>lenvect(vvod1, vvod2))&&CoordOnStraight());
}

bool triangle::CoordOnStraight()
{
    if((coord[0].x-coord[1].x)*(coord[2].y-coord[1].y)==(coord[2].x-coord[1].x)*(coord[0].y-coord[1].y))
    {
        std::cout << "ssss";
        return false;
    }
    return true;

}
void triangle::lensides(std::ostream &out)
{
    out << "first side=" << std::setprecision(3) << lenvect(coord[0], coord[1]) << ", second side=" << lenvect(coord[1], coord[2]) << ", third side=" << lenvect(coord[0], coord[2]) << "/n";
}

float* triangle::outlensides()
{
    float *temp = new float[3];
    temp[0] = lenvect(coord[0], coord[1]);
    temp[1] = lenvect(coord[1], coord[2]);
    temp[2] = lenvect(coord[0], coord[2]);
    return(temp);
}

void triangle::perimeter()
{
    std::cout << "perimeter is equal " << std::setprecision(5) << (lenvect(coord[0], coord[1]) + lenvect(coord[1], coord[2]) + lenvect(coord[0], coord[2])) << std::endl;
}

float triangle::area()
{
    float p = (lenvect(coord[0], coord[1]) + lenvect(coord[1], coord[2]) + lenvect(coord[0], coord[2]))/2;
    return(sqrt(p*(p-lenvect(coord[0], coord[1]))*(p-lenvect(coord[1], coord[2]))*(p-lenvect(coord[0], coord[2]))));
}

int comp1 (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


bool operator==(triangle& one, triangle& two)
{
    float *first = one.outlensides();
    float *second = two.outlensides();
    qsort(first,3,sizeof(float),comp1);
    qsort(second,3,sizeof(float),comp1);
    for(int i = 0;i<3;i++)
    {
        if(first[i]!=second[i]){
            return(false);
        }
        
    }
    
    return(true);
        
}