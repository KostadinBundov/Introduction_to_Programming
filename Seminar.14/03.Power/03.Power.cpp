#include <iostream>

int sumArr(int n, int k)
{
	if (k == 0)
	{
		return 1;
	}

	return n * sumArr(n, k - 1);
}

int main()
{
	int n, k;
	std::cin >> n >> k;

	std::cout << sumArr(n, k);
}