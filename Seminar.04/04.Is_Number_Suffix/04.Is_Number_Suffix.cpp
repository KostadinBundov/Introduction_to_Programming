#include <iostream>

bool isSuffix(int source, int value)
{

	if (source != 0 && value == 0)
	{
		return false;
	}

	while (value != 0)
	{
		if (value % 10 != source % 10)
		{
			return false;
		}

		value /= 10;
		source /= 10;
	}

	return true;
}

int main()
{
	int n, k;
	std::cin >> n >> k;

	std::cout << isSuffix(n, k);
}