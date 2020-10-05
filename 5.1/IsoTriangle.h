#include <iostream>
#include "Triangle.h"

class IsoTriangle : public Triangle{

private:

    bool checkexistiso(Coord &point1, Coord &point2, Coord &point3);

public:
    IsoTriangle() =default;

    IsoTriangle(Coord point1, Coord point2, Coord point3)
    {
    }
    ~IsoTriangle()
    {
    }

    friend std::istream& operator>>(std::istream &in, IsoTriangle&);

};