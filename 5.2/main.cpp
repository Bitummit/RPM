#include "figures.h"

int main()
{
    std::string ID("sss");
    std::string ID1("ssss");
    Triangle a({1, 2}, {0, 0}, {2, 1}, ID);
    Pentagon b({-10, -10}, {-10, 03}, {10, 10}, {10, -10}, {15, 03}, ID1);
    std::cout << a.IsIntersect(b, a) << std::endl;
    std::vector<Triangle> triangles;
    std::vector<Pentagon> Pentagons;
    int m = 0, n = 0, n1 = 0, now = -1, nowtet = -1;
    while (m != 3)
    {
        std::cout << "Choose the type of figure: Triangle(1) or Pentagon(2). Exit(3) " << std::endl;
        std::cin >> m;
        switch (m)
        {
        case 1:
        {
            while (n != 6)
            {
                std::cout << "Choose the operation for triangle" << std::endl;
                std::cout << "1-Add the triangle, 2-Choose the triangle to change, 3-Show all the triangles, 4-Move triangle\n"
                          << "5-Check is triangle intersect Pentagon, 6-Change the figure or exit, 7-show using triangle" << std::endl;
                std::cin >> n;
                switch (n)
                {
                case 1:
                {
                    Triangle *newt = new Triangle();
                    std::cin >> *newt;
                    triangles.push_back(*newt);
                    delete newt;
                    break;
                }
                case 2:
                {
                    std::cout << "Enter the Triangle's ID you search" << std::endl;
                    std::string Srch;
                    std::cin >> Srch;
                    now = Search(Srch, triangles);
                    if (now != -1)
                    {
                        std::cout << triangles[now] << std::endl;
                    }
                    break;
                }
                case 3:
                {
                    for (int i = 0; i < triangles.size(); i++)
                    {
                        std::cout << triangles[i] << std::endl;
                    }
                    break;
                }
                case 4:
                {
                    if (now == -1)
                    {
                        std::cout << "firstly choose the triangle" << std::endl;
                        break;
                    }
                    else
                    {
                        std::cout << "Enter the coordinates where you want to move triangle" << std::endl;
                        int x, y;
                        std::cin >> x >> y;
                        triangles[now].Move({x, y});
                        break;
                    }
                }
                case 5:
                    if (now == -1 || nowtet == -1)
                    {
                        std::cout << "firstly choose the triangle or the Pentagon" << std::endl;
                        break;
                    }
                    else
                    {
                        if (triangles[now].IsIntersect(Pentagons[nowtet], triangles[now]) == true)
                        {
                            std::cout << "Triangle is intersect Pentagon" << std::endl;
                        }
                        else
                        {
                            std::cout << "Triangle is not intersect Pentagon" << std::endl;
                        }
                        break;
                    }
                case 6:
                    std::cout << "Changing the figure..." << std::endl;
                    break;
                case 7:
                    if (now == -1)
                    {
                        std::cout << "firstly choose the triangle" << std::endl;
                        break;
                    }
                    std::cout << triangles[now];
                    break;
                default:
                    std::cout << "Choose the existing operation" << std::endl;
                }
            }
            n = 0;
            break;
        }
        case 2:
        {
            while (n1 != 6)
            {
                std::cout << "Choose the operation for Pentagon" << std::endl;
                std::cout << "1-Add the Pentagon, 2-Choose the Pentagon to change, 3-Show all the Pentagons, 4-Move Pentagon\n"
                          << "5-Check is Pentagon intersect Triangle, 6-Change the figure or exit, 7-show using Pentagon" << std::endl;
                std::cin >> n1;
                switch (n1)
                {
                case 1:
                {
                    Pentagon *newtet = new Pentagon();
                    std::cin >> *newtet;
                    Pentagons.push_back(*newtet);
                    delete newtet;
                    break;
                }
                case 2:
                {
                    std::cout << "Enter the Pentagon's ID you search" << std::endl;
                    std::string Srchtet;
                    std::cin >> Srchtet;
                    nowtet = Search(Srchtet, Pentagons);
                    if (nowtet != 1)
                    {
                        std::cout << Pentagons[nowtet] << std::endl;
                    }
                    break;
                }
                case 3:
                {
                    for (int i = 0; i < Pentagons.size(); i++)
                    {
                        std::cout << Pentagons[i] << std::endl;
                    }
                    break;
                }
                case 4:
                {
                    if (nowtet == -1)
                    {
                        std::cout << "firstly choose the Pentagon" << std::endl;
                        break;
                    }
                    else
                    {
                        std::cout << "Enter the coordinates where you want to move Pentagon" << std::endl;
                        int x, y;
                        std::cin >> x >> y;
                        Pentagons[nowtet].Move({x, y});
                        break;
                    }
                }
                case 5:
                    if (now == -1 || nowtet == -1)
                    {
                        std::cout << "firstly choose the triangle or the Pentagon" << std::endl;
                        break;
                    }
                    else
                    {
                        if (Pentagons[nowtet].IsIntersect(Pentagons[nowtet], triangles[now]) == true)
                        {
                            std::cout << "Pentagon is intersect triangle" << std::endl;
                        }
                        else
                        {
                            std::cout << "Pentagon is not intersect triangle" << std::endl;
                        }
                        break;
                    }
                    break;
                case 6:
                    std::cout << "Changing the figure..." << std::endl;
                    break;
                case 7:
                    if (nowtet == -1)
                    {
                        std::cout << "firstly choose the Pentagon" << std::endl;
                        break;
                    }
                    std::cout << Pentagons[nowtet];
                    break;
                default:
                    std::cout << "Choose the existing operation" << std::endl;
                }
            }
            n1 = 0;
            break;
        }
        case 3:
        {
            std::cout << "BB" << std::endl;
            break;
        }
        default:
            std::cout << "Choose the existing operation" << std::endl;
            break;
        }
    }
    std::cout << "Welcome to the RPM zone. Only c++ code into enemy pc" << std::endl;

    return 0;
}