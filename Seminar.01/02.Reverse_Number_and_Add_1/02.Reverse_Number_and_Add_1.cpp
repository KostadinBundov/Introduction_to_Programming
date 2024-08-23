#include <iostream>

int main()
{
	unsigned number;
	std::cin >> number;

	unsigned reversedNumber = number % 10;
	number /= 10;

	reversedNumber = 10 * reversedNumber + number % 10;
	number /= 10;
	
	reversedNumber = 10 * reversedNumber + number + 1;

	std::cout << reversedNumber;
}