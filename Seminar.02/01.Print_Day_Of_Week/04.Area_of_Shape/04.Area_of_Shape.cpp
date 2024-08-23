#include <iostream>

int main()
{
    char shape;
    std::cin >> shape;

    double area = 0;

    if (shape == 's')
    {
        double side;
        std::cin >> side;
        area = side * side;
    }
    else if (shape == 't')
    {
        double side, height;
        std::cin >> side >> height;
        area = side * height / 2;
    }
    else if (shape == 'r')
    {
        double firstSide, secondSide;
        std::cin >> firstSide >> secondSide;
        area = firstSide * secondSide;
    }
    else if (shape == 'c')
    {
        double radius;
        std::cin >> radius;
        area = 3.14 * radius * radius;
    }

    std::cout << area;
}