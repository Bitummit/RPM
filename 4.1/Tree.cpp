#include "Tree.h"
#include <iostream>
#include <queue>

Tree::Tree(node Node)
{
    root = new node;
    root->d = Node.d;
    root->time = Node.time;
    count = 1;
}

Tree::Tree(const Tree &tree)
{
    std::queue<node*> Myqueue1 = tree.Myqueue;
    count = tree.count;
//    std::cout << count << std::endl;
    root = Myqueue1.front();
//    std::cout << root->d;
    Myqueue1.pop();
    while(!Myqueue.empty())
    {
        node *Node = Myqueue1.front();
        Myqueue1.pop();
        do {
        if(Node->d<root->d){
            if(root->left==nullptr)
            {
                node *rootn = new node;
                rootn->d=Node->d;
                rootn->time=Node->time;
                rootn->right=rootn->left=nullptr;
                root->left = rootn;
                break;
            }
            else
                root = root->left;
        }
        else if(Node->d==root->d)
        {
            return;
        }
        else{
            if(root->right==nullptr){
                node *rootn = new node;
                rootn->d=Node->d;
                rootn->time=Node->time;
                rootn->right=rootn->left=nullptr;
                root->right = rootn;
                break;
            }
            else
                root = root->right;
        }
    } while (1);


    }


}

Tree::~Tree()
{
    deletea(root);
}


void Tree::show()
{
    std::cout<<count;
}


void Tree::deletea(node*& p)
{
    if(!p)
        return;
    node *p1 = p;
    deletea(p->left);
    delete p;
    p = nullptr;
    deletea(p1->right);
}

void Tree::Insert(const node Node)
{
    if(!root)
    {
        root = new node;
        root->d = Node.d;
        root->time = Node.time;
        Myqueue.push(root);
        count = 1;
        return;
    }
    node* save = root;
    do {
        if(Node.d<root->d)
        {
            if(root->left==nullptr)
            {
                node *rootn = new node;
                rootn->d=Node.d;
                rootn->time=Node.time;
                root->left = rootn;
                Myqueue.push(rootn);
                break;
            }
            else
                root = root->left;
        }
        else if(Node.d==root->d)
        {
            return;
        }
        else{
            if(root->right==nullptr){
                node *rootn = new node;
                rootn->d=Node.d;
                rootn->time=Node.time;
                root->right = rootn;
                Myqueue.push(rootn);
                break;
            }
            else
                root = root->right;
        }
    } while (1);
    count++;
    root = save;
}

bool Tree::traverse1(node* p, node* p1) const
{
    if(!p && p1 || p && !p1)
    {
        return false;
    }
    else if(!p && !p1)
    {
        return true;
    }
    if(traverse1(p->left,p1->left)==false)
    {
        return false;
    }
    if(p->d!=p1->d || p->time!=p1->time)
    {
        return false;
    }
    if(traverse1(p->right,p1->right)==false)
    {
        return false;
    }
    return true;
}

bool Tree::poisk(int _d, node* p)
{
    if(!p)
    {
        return(false);
    }
    poisk(_d,p->left);
    if(_d==p->d)
    {
        std::cout << "time=" << p->time << std::endl;
        return(true);
    }
    poisk(_d,p->right);
}

bool operator==(const Tree& other, const Tree& another)
{
    if(another.count!=other.count){
        return(false);
    }
    else
    {
        return other.traverse1(another.root,other.root);
    }
}


void Tree::traverse(node* p, std::ostream &out) const
{
    if(!p)
        return;
    traverse(p->left, out);
    out << p->d << ' ' << p->time << " "  << "\n";
    traverse(p->right, out);
}

std::ostream& operator<< (std::ostream &out, const Tree &tree)
{
    tree.traverse(tree.root, out);
    return out;
}


void Tree::poisk1(int _d)
{
    this->poisk(_d,this->root);
}
