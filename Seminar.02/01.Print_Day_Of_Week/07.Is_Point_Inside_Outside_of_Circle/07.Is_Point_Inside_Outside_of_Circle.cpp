#include <iostream>

int main()
{
	int radius, x, y;

	std::cin >> radius >> x >> y;

	double length = sqrt(x * x + y * y);

	if (length < radius)
	{
		std::cout << "In the circle";
	}
	else if (length > radius)
	{
		std::cout << "Out of the circle";
	}
	else
	{
		std::cout << "On the circle";
	}
}