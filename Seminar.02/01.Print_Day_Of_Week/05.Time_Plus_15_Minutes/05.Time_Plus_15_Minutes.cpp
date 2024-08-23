#include <iostream>

int main()
{
	unsigned hours, minutes;
	std::cin >> hours >> minutes;

	minutes += 15;

	if (minutes >= 60)
	{
		hours += 1;
	}

	hours %= 24;
	minutes %= 60;

	if (hours < 10)
	{
		std::cout << "0";
	}
	std::cout << hours << ":";
	
	if (minutes < 10)
	{
		std::cout << "0";
	}
	std::cout << minutes;
}