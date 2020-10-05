#include "figures.h"
#include <math.h>

float Triangle::lenvect(Point &one, Point &two)
{
    return(sqrt(pow(one.x-two.x,2)+pow(one.y-two.y,2)));
}


bool Triangle::CoordOnStraight()
{
    if((coord[0].x-coord[1].x)*(coord[2].y-coord[1].y)==(coord[2].x-coord[1].x)*(coord[0].y-coord[1].y))
    {
        return false;
    }
    else
    {
        return true;    
    }
    

}


bool Triangle::DoesExist(Point vvod, Point vvod1, Point vvod2)
{
    return((lenvect(vvod, vvod1)+lenvect(vvod1, vvod2)>lenvect(vvod, vvod2))&&(lenvect(vvod1, vvod2)+lenvect(vvod2, vvod)>lenvect(vvod,vvod1))&&(lenvect(vvod, vvod2)+lenvect(vvod, vvod1)>lenvect(vvod1, vvod2))&&CoordOnStraight());
}


std::istream& operator>> (std::istream &in, Triangle &Trin)
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
            std::cout << "triangle doesn't exist" << std::endl;
            std::cout << "Please, enter normal coordinates" << std::endl;
        }
        else
        {
            std::cout << "enter the ID" << std::endl;
            in >> Trin.id;
            break;   
        }
    }
    return in;
}

std::ostream& operator<< (std::ostream &out, Triangle &Trout)
{
     out << "ID = " << Trout.id << "\n";
     for(int i = 0;i < 3;i++)
     {
         out << "Coordinate " << i+1 << " : " << Trout.coord[i];
     }
     return out;
}


void Triangle::Move(Point point)
{
    for(int i = 0;i < 3;i++)
    {
        this->coord[i] = this->coord[i] + point;
    }
}

int Search(std::string Sch, std::vector<Triangle>& arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if(Sch == arr[i].id)
        {
            return i;
        }
    }
    std::cout << "There is no object \"Triangle\" whith ID " << Sch <<std::endl;
    return -1;
}


Triangle::Triangle(Point ent1, Point ent2, Point ent3, std::string m_id) : Figure(m_id)
{
    if(DoesExist(ent1, ent2, ent3)==false)
    {
        std::cout << "triangle doesn't exist" << std::endl;

    }
    coord[0] = ent1;
    coord[1] = ent2;
    coord[2] = ent3;

}

Triangle::Triangle()
{

}


// bool Triangle::IsInclude(Tetragon &tet) 
// {
//     bool result = false;
//     for(int i = 0;i < 3; i++)
//     {
//         Point VectorTr[2];
//         if(i==2)
//         {
//             Point VectorTr[] = {coord[2], coord[0]};
//         }
//         else
//         {
//             Point VectorTr[] = {coord[i], coord[i+1]};
//         }
//         if(coord[i].x <= std::min(std::min(tet.coord[0].x, tet.coord[1].x), std::min(tet.coord[2].x, tet.coord[3].x)) || coord[i].y <= std::min(std::min(tet.coord[0].y, tet.coord[1].y), std::min(tet.coord[2].y, tet.coord[3].y)) || coord[i].x >= std::max(std::max(tet.coord[0].x, tet.coord[1].x), std::max(tet.coord[2].x, tet.coord[3].x)) || coord[i].y >= std::max(std::max(tet.coord[0].y, tet.coord[1].y), std::max(tet.coord[2].y, tet.coord[3].y)))
//         {
//             return false;
//         }
//         for(int j = 0;j < 4; j++)
//         {
//             Point VectorTet[2];
//             if(j==3)
//             {
//                 Point VectorTet[] = {tet.coord[3], tet.coord[0]};
//             }
//             else
//             {
//                 Point VectorTet[] = {tet.coord[j], tet.coord[j+1]};
//             }
//             result = !IsVectorIntersect(VectorTr, VectorTet);
//         }
//     }
//     return result;
// }
