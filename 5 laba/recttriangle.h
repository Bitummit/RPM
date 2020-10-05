#include "triangle.h"
// #pragma once 
class recttriangle  : public triangle
{
private:
    bool isOrt(Coord &one, Coord &two, Coord &three);
public:
    recttriangle();
    recttriangle(Coord vvod, Coord vvod1, Coord vvod2);
    bool isRect();
};

