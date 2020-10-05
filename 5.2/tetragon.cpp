#include "figures.h"

Pentagon::Pentagon(Figure::Point first, Figure::Point second, Figure::Point third, Figure::Point fourth, Figure::Point fifth, std::string m_id) : Figure(m_id)
{
    coord[0] = first;
    coord[1] = second;
    coord[2] = third;
    coord[3] = fourth;
    coord[4] = fifth;
}

std::istream &operator>>(std::istream &in, Pentagon &Tetin)
{

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Enter the coordinates for " << i + 1 << " Angle" << std::endl;
        in >> Tetin.coord[i].x;
        in >> Tetin.coord[i].y;
    }
    std::cout << "enter the ID" << std::endl;
    in >> Tetin.id;
    return in;
}

std::ostream &operator<<(std::ostream &out, Pentagon &Tetout)
{
    out << "ID = " << Tetout.id << "\n";
    for (int i = 0; i < 5; i++)
    {
        out << "Coordinate " << i + 1 << " : " << Tetout.coord[i];
    }
    return out;
}

void Pentagon::Move(Point point)
{
    for (int i = 0; i < 5; i++)
    {
        this->coord[i] = this->coord[i] + point;
    }
}

int Search(std::string Sch, std::vector<Pentagon> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (Sch == arr[i].id)
        {
            return i;
        }
    }
    std::cout << "There is no object \"Pentagon\" whith this ID " << Sch << std::endl;
    return -1;
}

Pentagon::Pentagon()
{
}

