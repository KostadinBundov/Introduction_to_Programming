#include <iostream>

int main()
{
	constexpr int lowerBound = -100;
	constexpr int upperBound = 100;

	int a, b, c, d, e;
	std::cin >> a >> b >> c >> d >> e;

	for(int x = lowerBound; x <= upperBound; x++)
	{
		int result = (a * x * x * x * x) + (b * x * x * x) + (c * x * x) + (d * x) + e;

		if (result >= 0)
		{
			std::cout << x << " ";
		}
	}
}