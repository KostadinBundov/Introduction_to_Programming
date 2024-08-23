#include <iostream>

int logFunction(int n, int k)
{
	int result = 1;
	int power = k;

	while (power <= n)
	{
		power*= k;
		result++;
	}

	return result - 1;
}

int main()
{
	int n, k;
	std::cin >> n >> k;

	std::cout << logFunction(n, k);
}