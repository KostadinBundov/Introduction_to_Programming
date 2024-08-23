#include <iostream>

int main()
{
	char symbol;
	std::cin >> symbol;

	bool check = ('a' <= symbol && symbol <= 'z') || ('A' <= symbol && symbol <= 'Z');

	std::cout << check;
}