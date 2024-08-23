#include <iostream>

int getValue(char symbol)
{
	if ('0' <= symbol && symbol <= '9')
	{
		return symbol - '0';
	}
	else if ('A' <= symbol && symbol <= 'Z')
	{
		return symbol - 'A' + 10;
	}
	else
	{
		return -1;
	}
}

char getSymbol(int value)
{
	if (0 <= value && value <= 9)
	{
		return '0' + value;
	}
	else if (value >= 10)
	{
		return 'A' + (value - 10);
	}
	else
	{
		return '0';
	}
}

int myPow(int n, int k)
{
	int result = 1;

	for (int i = 0; i < k; i++)
	{
		result *= n;
	}

	return result;
}

int convertFromRandomToDecimal(const char* from, size_t size, unsigned base)
{
	int result = 0;

	for (int i = size - 1, multiple = 0; i >= 0; i--, multiple++)
	{
		result += getValue(from[i]) * myPow(base, multiple);
	}

	return result;
}

void convertFromDecimalToRandom(int number, char* to, size_t size, unsigned base)
{
	int iter = size - 1;

	while (number != 0 && iter > 0)
	{
		to[iter] = getSymbol(number % base);
		number /= base;
		iter--;
	}
}

void convertFromRandomToRandom(const char* from, size_t fromSize, unsigned fromBase, char* to, size_t  toSize, unsigned toBase)
{
	int decimalNumber = convertFromRandomToDecimal(from, fromSize, fromBase);
	convertFromDecimalToRandom(decimalNumber, to, toSize, toBase);
}

void print(const char arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == ' ')
		{
			continue;
		}

		std::cout << arr[i];
	}

	std::cout << std::endl;
}

int main()
{
	constexpr int SIZE = 5;
	{
		char from[] = { '0', 'A', 'A','B', '3' };
		unsigned n = convertFromRandomToDecimal(from, SIZE, 16); //AAB3 in hex to decimal;
		std::cout << n << std::endl;;
	}

	{
		char to[SIZE] = {' '};
		convertFromDecimalToRandom(1234, to, SIZE, 16); //124 in decimal to hex;
		print(to, SIZE);
	}

	{
		char from[SIZE] = { '0', '0', 'A','B', '3' };

		char to[SIZE] {' '};

		convertFromRandomToRandom(from, SIZE, 16, to, SIZE, 10);

		print(to, SIZE);
	}
}