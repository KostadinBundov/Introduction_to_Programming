#include <iostream>

int main()
{
	int max1 = INT32_MIN;
	int max2 = INT32_MIN + 1;

	int n;
	
	do
	{
		std::cin >> n;
	} while (n < 2);

	int number;

	for (int i = 0; i < n; i++)
	{
		std::cin >> number;

		if (number > max1) 
		{
			max2 = max1;
			max1 = number;
		}
		else if (number > max2 && number < max1) 
		{
			max2 = number;
		}
	}

	std::cout << max1 << " " << max2;
}