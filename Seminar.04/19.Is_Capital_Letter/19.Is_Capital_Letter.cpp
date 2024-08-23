#include <iostream>

bool checkIsCapitalLetter(char symbol)
{
	return 'A' <= symbol && symbol <= 'Z';
}

int main()
{
	char symbol;
	std::cin >> symbol;

	std::cout << checkIsCapitalLetter(symbol);
}