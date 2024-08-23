#include <iostream>

int sumArr(int n, int k)
{
	if (k == 0)
	{
		return 1;
	}

	if (k % 2 == 0)
	{
		return sumArr(n * n, k / 2);
	}
	else
	{
		return n * sumArr(n, k - 1);
	}
}

int main()
{
	int n, k;
	std::cin >> n >> k;

	std::cout << sumArr(n, k);
}