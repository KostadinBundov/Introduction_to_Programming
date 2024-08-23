#include <iostream>

int reverseMostRightBit(int number)
{
	return number & (number - 1);
}

int main()
{
	int number;
	std::cin >> number;

	std::cout << reverseMostRightBit(number);
}