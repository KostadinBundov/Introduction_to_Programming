#include <iostream>

unsigned getDigitsCount(int number)
{
	if (number == 0)
	{
		return 1;
	}

	unsigned counter = 0;

	while (number != 0)
	{
		counter++;
		number /= 10;
	}

	return counter;
}

void toString(int number, char*& str)
{
	unsigned numberLength = getDigitsCount(number);
	str = new char[numberLength + 1];
	str[numberLength] = '\0';

	for (int i = numberLength - 1; i >= 0; i--)
	{
		str[i] = number % 10 + '0';
		number /= 10;
	}
}

int myStrcmp(const char* first, const char* second)
{
	if (!first || !second)
	{
		return 0;
	}

	while (*first && *second && *first == *second)
	{
		first++;
		second++;
	}

	return *first - *second;
}

void swap(char*& first, char*& second)
{
	char* temp = first;
	first = second;
	second = temp;
}

void sort(char** numbers, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		int minIndex = i;

		for (int j = i + 1; j < size; j++)
		{
			if(myStrcmp(numbers[minIndex], numbers[j]) > 0)
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			swap(numbers[i], numbers[minIndex]);
		}
	}
}

char** convertNumbers(const int* arr, size_t size)
{
	if (!arr)
	{
		return nullptr;
	}

	char** numbers = new char* [size] {nullptr};
	
	for (int i = 0; i < size; i++)
	{
		toString(arr[i], numbers[i]);
	}

	sort(numbers, size);

	return numbers;
}

int main()
{
	int numbersCount;
	std::cin >> numbersCount;

	int* arr = new int[numbersCount];

	for (int i = 0; i < numbersCount; i++)
	{
		std::cin >> arr[i];
	}

	char** numbers = convertNumbers(arr, numbersCount);

	for (int i = 0; i < numbersCount; i++)
	{
		std::cout << numbers[i] << std::endl;
	}

	for (int i = 0; i < numbersCount; i++)
	{
		delete[] numbers[i];
	}

	delete[] numbers;
	delete[] arr;
}