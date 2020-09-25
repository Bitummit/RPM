
#include <iostream>
class node {
public:

    node(int _d = 0, int _time = 0) : d(_d), time(_time) {}

    int d;
    int time;
    node* right = nullptr;
    node* left = nullptr;
    friend std::istream& operator>> (std::istream &in, node &Node);
    friend bool operator==(const node& Other, const node& another);
    friend bool operator!=(const node& Other, const node& another);
};
