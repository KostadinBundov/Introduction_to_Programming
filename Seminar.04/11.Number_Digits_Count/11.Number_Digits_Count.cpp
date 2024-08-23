#include <iostream>

unsigned getDigitsCount(int number)
{
    unsigned result = 0;

    if (number == 0)
    {
        return 1;
    }

    while (number != 0)
    {
        result++;
        number /= 10;
    }

    return result;
}

int main()
{
    int number;
    std::cin >> number;

    std::cout << getDigitsCount(number);
}