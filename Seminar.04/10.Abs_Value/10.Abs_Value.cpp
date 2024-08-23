#include <iostream>

unsigned absValue(int number)
{
    return number < 0 ? (number * -1) : number;
}

int main()
{
    int number;
    std::cin >> number;

    std::cout << absValue(number);
}