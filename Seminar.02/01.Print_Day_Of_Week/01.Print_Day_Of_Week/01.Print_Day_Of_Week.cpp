﻿#include <iostream>

int main()
{
	int number;
	std::cin >> number;

	switch (number)
	{
	case 1:
		std::cout << "Monday";
		break;
	case 2:
		std::cout << "Tuesday";
		break;
	case 3:
		std::cout << "Wednesday";
		break;
	case 4:
		std::cout << "Thursday";
		break;
	case 5:
		std::cout << "Friday";
		break;
	case 6:
		std::cout << "Saturday";
		break;
	case 7:
		std::cout << "Sunday";
		break;
	default:
		std::cout << "Invalid input!";
		break;
	}
}