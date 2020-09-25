#include "Node.h"
#include <iostream>
#include <queue>

class Tree
{
private:
    std::queue<node *> Myqueue;
    int count;
    node* root;
    void traverse(node* p, std::ostream &out) const;
    bool traverse1(node* p, node* p1) const;
    bool poisk(int _d, node* p);
    void deletea(node *&p);
public:
    Tree() : count(0), root(nullptr) {}
    void show();

    void kopir(const node* Node);
    Tree(node);
    Tree(const Tree &tree);
    ~Tree();
    void Insert(node Node);
    friend bool operator==(const Tree& other, const Tree& another);
    friend std::ostream& operator<< (std::ostream &out, const Tree &tree);
    void poisk1(int _d);

};
