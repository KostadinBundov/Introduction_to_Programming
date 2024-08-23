#include <iostream>

bool evalueateTrianglePerimeter(int x1, int y1, int x2, int y2)
{
	int firstDistance = sqrt(x1 * x1 + y1 * y1);
	int secondDistance = sqrt(x2 * x2 + y2 * y2);

	return firstDistance == secondDistance;
}

int main()
{
	int x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;

	std::cout << evalueateTrianglePerimeter(x1, y1, x2, y2);
}