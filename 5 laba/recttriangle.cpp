#include"recttriangle.h"

recttriangle::recttriangle(Coord vvod, Coord vvod1, Coord vvod2) : triangle(vvod, vvod1, vvod2)
{
    if(this->isRect()==false)
        std::cout << "Triangle is not rectangular" << std::endl;
}
recttriangle::recttriangle()
{
}

bool recttriangle::isOrt(Coord &one, Coord &two, Coord &three)
{
    int vecx = (two.x-one.x)*(three.x-two.x);
    int vecy = (two.y-one.y)*(three.y-two.y);
    return((vecx + vecy)==0);
}

bool recttriangle::isRect()
    {
        return(isOrt(coord[0],coord[1],coord[2])||isOrt(coord[1],coord[2],coord[0])||isOrt(coord[2],coord[0],coord[1])||isOrt(coord[2],coord[1],coord[0])||isOrt(coord[1],coord[0],coord[2])||isOrt(coord[0],coord[2],coord[1]));
    }