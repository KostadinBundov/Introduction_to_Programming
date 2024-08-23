#include <iostream>

int main()
{
	int a, b;
	std::cin >> a >> b;

	int sum = a + b;
	int diff = a - b;
	int result = sum * sum * sum * sum - diff * diff;

	std::cout << result;
}