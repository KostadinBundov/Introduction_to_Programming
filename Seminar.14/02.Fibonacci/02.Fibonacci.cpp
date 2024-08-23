#include <iostream>

int power(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}

	return power(n - 1) + power(n - 2);
}

int main()
{
	int n;
	std::cin >> n;

	std::cout << power(n);
}