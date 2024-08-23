#include <iostream>

int main()
{
	int a, b;
	std::cin >> a >> b;

	int smallerNumber = a < b ? a : b;

	for (int i = smallerNumber; i > 0; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			std::cout << i << " ";
		}
	}
}