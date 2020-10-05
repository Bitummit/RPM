#include <iostream>
#include <vector>
#include <string>
#pragma once

class Pentagon; 
class Triangle;

class Figure
{
public:
    Figure()
    {
    }

    Figure(std::string m_id) : id(m_id)
    {

    }
    bool IsIntersect(Pentagon&, Triangle&);
protected:
    struct Point
    {
        int x,y;
    };
    friend const Point operator+(const Figure::Point& a, const Figure::Point& b);
    friend const std::ostream& operator<< (std::ostream &out, const Figure::Point &p);
    friend bool IsVectorIntersect(Point vector1[2], Point vector2[2]);
    std::string id;

private:
    friend int Constant_term(Point vector[2]);
    friend int X_term(Point vector[2]);
    friend int Y_term(Point vector[2]);
    friend int determinant(int x[4]);
};


class Triangle : public Figure 
{
private:
    Point coord[3];
    float lenvect(Point &one, Point &two);
    bool CoordOnStraight();
    bool DoesExist(Point vvod, Point vvod1, Point vvod2);
public:
    Triangle(Point ent1, Point ent2, Point ent3 , std::string m_id);
    Triangle();
    void Move(Point);
    friend int Search(std::string Sch, std::vector<Triangle> &arr);
    friend std::istream& operator>> (std::istream &in, Triangle &Trin);
    friend std::ostream& operator<< (std::ostream &out, Triangle &Trout);
    friend bool Figure::IsIntersect(Pentagon&, Triangle&);
};


class Pentagon : public Figure
{
private:
    Point coord[5];
public:
    Pentagon(Point first, Point second, Point third, Point fourth, Point fifth, std::string m_id);
    Pentagon();
    friend std::istream& operator>> (std::istream &in, Pentagon &Tetin);
    friend std::ostream& operator<< (std::ostream &out, Pentagon &Tetout);
    void Move(Point);
    friend int Search(std::string Sch, std::vector<Pentagon> &arr);
    friend bool Figure::IsIntersect(Pentagon&, Triangle&);
};
