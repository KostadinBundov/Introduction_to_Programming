#include <iostream>

int findEncodedNumber(int number, int bitsCount)
{
	int mask = (1 << bitsCount) - 1;

	return mask & number;
}

int main()
{
	int number, bitsCount;
	std::cin >> number >> bitsCount;

	std::cout << findEncodedNumber(number, bitsCount);
}