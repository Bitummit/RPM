#include "IsoTriangle.h"

std::istream &operator>>(std::istream &in, IsoTriangle &Trin)
{
    while (true)
    {
        std::cout << "Enter the coordinates for isosceles triangle" << std::endl;
        for (int i = 0; i < 3; i++)
        {
            std::cout << "Enter the coordinates for " << i + 1 << " Angle" << std::endl;
            in >> Trin.coord[i].x;
            in >> Trin.coord[i].y;
        }
        if (Trin.checkexist(Trin.coord[0], Trin.coord[1], Trin.coord[2]) == false)
        {
            std::cout << "triangle doesn't exist" << '\n'
                      << "Please, enter normal coordinates" << std::endl;
        }
        else if (Trin.checkexistiso(Trin.coord[0], Trin.coord[1], Trin.coord[2]) == false)
        {
            std::cout << "triangle doesn't isosceles" << '\n'
                      << "Please, enter isosceles triangle" << std::endl;
        }
        else
        {
            break;
        }
    }
}

bool IsoTriangle::checkexistiso(Coord &point1, Coord &point2, Coord &point3)
{
    if ((lenside(point1, point2) == lenside(point1, point3)) ||
        (lenside(point1, point2) == lenside(point2, point3)) ||
        (lenside(point2, point3) == lenside(point1, point3)))
    {
        return true;
    }
    else
    {
        return false;
    }
}
