#include "Node.h"
#include <iostream>

bool operator==(const node& Other, const node& another)
{
    return(Other.d==another.d && Other.time==another.time);
}

bool operator!=(const node& Other, const node& another)
{
    return!(Other==another);
}

std::istream& operator>> (std::istream &in, node &Node)
{
    std::cout << "Enter number and time" << std::endl;
    in >> Node.d;
    in >> Node.time;
    return in;
}
