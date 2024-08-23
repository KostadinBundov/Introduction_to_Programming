#include <iostream>

double getDistance(int x1, int y1, int x2, int y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double evalueateTrianglePerimeter(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return getDistance(x1, y1, x2, y2) + getDistance(x1, y1, x3, y3) + getDistance(x2, y2, x3, y3);
}

int main()
{
	int x1, y1, x2, y2, x3, y3;
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	std::cout << evalueateTrianglePerimeter(x1, y1, x2, y2, x3, y3);
}