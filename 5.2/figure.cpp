#include "figures.h"

const Figure::Point operator+(const Figure::Point &a, const Figure::Point &b)
{
    return {a.x + b.x, a.y + b.y};
}

const std::ostream &operator<<(std::ostream &out, const Figure::Point &p)
{
    out << "x = " << p.x << " y = " << p.y << "\n";
    return out;
}
int determinant(int x[4])
{
    return (x[0] * x[3] - x[1] * x[2]);
}

int Constant_term(Figure::Point vector[2])
{
    return (vector[0].x * vector[1].y - vector[1].x * vector[0].y);
}

int Y_term(Figure::Point vector[2])
{
    return (vector[1].x - vector[0].x);
}

int X_term(Figure::Point vector[2])
{
    return (vector[0].y - vector[1].y);
}

bool IsVectorIntersect(Figure::Point vector1[2], Figure::Point vector2[2])
{
    int C_t1, C_t2, Y_t1, Y_t2, X_t1, X_t2, smx, bgx, smy, bgy; //C_t - Constant_term; Y_t - Y_term; X_t - X_Term; sm-smaller; bg - bigger
    float Det, Det_x, Det_y, x, y;                              //Det - determinant; x,y - Point of intersection
    X_t1 = X_term(vector1);
    X_t2 = X_term(vector2);
    Y_t1 = Y_term(vector1);
    Y_t2 = Y_term(vector2);
    C_t1 = Constant_term(vector1);
    C_t2 = Constant_term(vector2);
    int Arr[] = {X_t1, Y_t1, X_t2, Y_t2};
    Det = determinant(Arr);
    int Arr1[] = {-C_t1, Y_t1, -C_t2, Y_t2};
    Det_x = determinant(Arr1);
    int Arr2[] = {X_t1, -C_t1, X_t2, -C_t2};
    Det_y = determinant(Arr2);
    x = Det_x / Det;
    y = Det_y / Det;
    smx = std::min(vector1[0].x, vector1[1].x);
    bgx = std::max(vector1[0].x, vector1[1].x);
    smy = std::min(vector1[0].y, vector1[1].y);
    bgy = std::max(vector1[0].y, vector1[1].y);
    if (x >= smx && x <= bgx && y >= smy && y <= smy)
    {
        return true;
    }
    else
    {
        return false;
    }
}
class Triangle;
class Pentagon;

bool Figure::IsIntersect(Pentagon &pent, Triangle &tr)
{
    bool result;
    for (int i = 0; i < 5;i++)
    {
        Point vectPent[2];
        if (i == 4)
        {
            Point vectPent[] = {(Point)(pent.coord[4]), pent.coord[0]};
        }
        else
        {
            Point vectPent[] = {pent.coord[i], pent.coord[i+1]};
        }
        for (int j = 0; j < 3; j++)
        {
            Point vectTr[2];
            if (j == 2)
            {
                Point vectTr[] = {(Point)(tr.coord[2]), tr.coord[0]};
            }
            else
            {
                Point vectTr[] = {tr.coord[j], tr.coord[j+1]};
            }
            result = IsVectorIntersect(vectPent, vectTr);
        }
    }
    return result;
}


