#include <iostream>
#pragma once 
class triangle
{
protected:
    struct Coord
    {
        int x;
        int y;
    } coord[3];
    float lenvect(Coord &one, Coord &two);
    float* outlensides();
    bool CoordOnStraight();
    bool DoesExist(Coord vvod, Coord vvod1, Coord vvod2);
    void lensides(std::ostream &out);
    void perimeter();
    

public:
    triangle();

    triangle(triangle &Triangle);

    triangle(Coord vvod, Coord vvod1, Coord vvod2);

    friend std::istream& operator>> (std::istream &in, triangle &Trin);
    friend std::ostream& operator<< (std::ostream &out, triangle &Trout);
    float area();
    friend bool operator==(triangle& one, triangle& two);

};



