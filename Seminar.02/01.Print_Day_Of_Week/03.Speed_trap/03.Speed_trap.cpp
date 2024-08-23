#include <iostream>

int main()
{
	double speed;
	std::cin >> speed;

	if (speed < 0)
	{
		std::cout << "Invalid speed!";
	}
	if (speed <= 10)
	{
		std::cout << "Slow";
	}
	else if (speed <= 50)
	{
		std::cout << "Average";
	}
	else if (speed <= 150)
	{
		std::cout << "Fast";
	}
	else if (speed <= 1000)
	{
		std::cout << "Ultra fast";
	}
	else
	{
		std::cout << "Extremely fast";
	}
}