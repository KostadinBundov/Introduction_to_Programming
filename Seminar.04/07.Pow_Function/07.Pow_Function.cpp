#include <iostream>

int powFunction(int n, int k)
{
	int result = 1;

	for (int i = 0; i < k; i++)
	{
		result *= n;
	}

	return result;
}

int main()
{
	int n, k;
	std::cin >> n >> k;

	std::cout << powFunction(n, k);
}