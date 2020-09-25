#include "Triangle.h"
#include <iostream>
#include <math.h>

float Triangle::lenside(const Coord &one, const Coord &two) const
{
    return(sqrt(pow(one.x-two.x,2)+pow(one.y-two.y,2)));
}


bool Triangle::checkexist(Coord point1, Coord point2, Coord point3)
{
    return((lenside(point1, point2)+lenside(point2, point3)>=lenside(point1, point3))&&(lenside(point2, point3)+lenside(point3, point1)>=lenside(point1,point2))&&(lenside(point1, point3)+lenside(point1, point2)>=lenside(point2, point3))&&CoordOnStraight());
}



std::istream& operator>>(std::istream &in, Triangle &Trin)
{
    while(true)
    {
        for(int i = 0;i < 3;i++)
        {
            std::cout << "Enter the coordinates for " << i+1 << " Angle" << std::endl;
            in >> Trin.coord[i].x;
            in >> Trin.coord[i].y;
        }
        if(Trin.checkexist(Trin.coord[0], Trin.coord[1], Trin.coord[2])==false)
        {
            // std::cout << Trin.lenside(Trin.coord[0], Trin.coord[1])<< std::endl;
            // std::cout <<Trin.lenside(Trin.coord[1], Trin.coord[2]) << std::endl;;
            // std::cout << Trin.lenside(Trin.coord[0], Trin.coord[2]);
            std::cout << "triangle doesn't exist" << '\n'
            << "Please, enter normal coordinates" << std::endl;
        }
        else
        {
            break;   
        }
    }
}

bool Triangle::CoordOnStraight()
{
    if((coord[0].x-coord[1].x)*(coord[2].y-coord[1].y)==(coord[2].x-coord[1].x)*(coord[0].y-coord[1].y))
    {
        return false;
    }
    return true;

}

void Triangle::lensides(std::ostream &out) const
{
    out << "first side=" << lenside(coord[0], coord[1]) << ", second side=" << lenside(coord[1], coord[2]) << ", third side=" << lenside(coord[0], coord[2])  << "\n"; 
    perimeter();
    std::cout << std::endl;
    area();
}

std::ostream& operator<< (std::ostream &out, const Triangle &Trout)
{
    Trout.lensides(out);
    return out;

}


void Triangle::perimeter() const
{
    std::cout << "perimeter is equal "<< (lenside(coord[0], coord[1]) + lenside(coord[1], coord[2]) + lenside(coord[0], coord[2]));
}

void Triangle::area() const
{
    float p = (lenside(coord[0], coord[1]) + lenside(coord[1], coord[2]) + lenside(coord[0], coord[2]))/2;
    std::cout << "Area is equal " << (sqrt(p*(p-lenside(coord[0], coord[1]))*(p-lenside(coord[1], coord[2]))*(p-lenside(coord[0], coord[2]))))<< std::endl << std::endl;
}