#include <iostream>

class Triangle{
    protected:
    struct Coord
    {
        int x;
        int y;
    }coord[3];

    float lenside(const Coord &one, const Coord &two) const;
    void perimeter() const;
    void area() const;
    bool CoordOnStraight();

    public:
    Triangle() =default;

    Triangle(Coord point1, Coord point2, Coord point3)
    {

    }
    ~Triangle()
    {

    }

    friend std::ostream& operator<<(std::ostream &out, const Triangle&);

    friend std::istream& operator>>(std::istream &in, Triangle&);

    bool checkexist(Coord point1, Coord point2, Coord point3);

    void lensides(std::ostream &out) const;

};