#include <iostream>

int fibbRec(int n, int* cache)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}

	if (cache[n] != 0)
	{
		return cache[n];
	}
	else
	{
		cache[n] = fibbRec(n - 1, cache) + fibbRec(n - 2, cache);
		return cache[n];
	}
}

int fibb(int n)
{
	int* cache = new int[n + 1] { 0 };
	int result = fibbRec(n, cache);
	delete[] cache;
	return result;
}

int main()
{
	int n;
	std::cin >> n;
	std::cout << fibb(n);
}