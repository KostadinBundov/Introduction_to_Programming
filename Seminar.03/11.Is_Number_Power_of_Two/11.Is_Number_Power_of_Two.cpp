#include <iostream>

int main()
{
	int number;
	std::cin >> number;
	
	while (number != 1)
	{
		if (number % 2 != 0)
		{
			std::cout << "False";
			return 0;
		}

		number /= 2;
	}

	std::cout << "True";
}