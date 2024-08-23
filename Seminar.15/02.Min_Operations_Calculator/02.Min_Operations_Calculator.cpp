#include <iostream>

int myMin(unsigned a, unsigned b)
{
	return a < b ? a : b;
}

int myMin(unsigned a, unsigned b, unsigned c)
{
	return myMin(myMin(a, b), c);
}

unsigned recCalc(unsigned n, unsigned* cache)
{
	if (n == 1)
	{
		return 0;
	}

	if (cache[n] != 0)
	{
		return n;
	}

	unsigned div3 = INT32_MAX, div2 = INT32_MAX, min1 = INT32_MAX;

	if (n % 3 == 0)
	{
		div3 = recCalc(n / 3, cache);
	}

	if (n % 2 == 0)
	{
		div2 = recCalc(n / 2, cache);
	}

	min1 = recCalc(n - 1, cache);

	cache[n] = myMin(div3, div2, min1) + 1;
	return cache[n];
}

unsigned calculate(unsigned n)
{
	unsigned* cache = new unsigned[n + 1] { 0 };
	unsigned result = recCalc(n, cache);
	delete[] cache;
	return result;
}

int main()
{
	unsigned number;
	std::cin >> number;
	std::cout << calculate(number);
}