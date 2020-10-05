#include <iostream>
#include "Tree.h"
using namespace std;


int main()
{
    int n=1;
    int d;
    node Node;
    cin >> Node;

    Tree tree;
    tree.Insert(Node);

    Tree tree1;
    while(n!=0){
        cout << "1-output, 2-add element,3-find element, 4-comparison, 0-exit\n";
        cin >> n;
        switch(n)
        {

            case 0:
                break;

            case 1:
                cout << tree << endl;
                break;
            case 2:
                cin >> Node;
                tree.Insert(Node);
                break;
            case 3:
                cout << "Enter number " << endl;
                cin >> d;
                tree.poisk1(d);
                break;
            case 4:
                tree1 = Tree(tree);
                if(tree==tree1){
                    std::cout << "Trees are equal \n";
                }
                else{
                    std::cout << "Trees are not equal \n";
                }

        }
    }
    return 0;
}
