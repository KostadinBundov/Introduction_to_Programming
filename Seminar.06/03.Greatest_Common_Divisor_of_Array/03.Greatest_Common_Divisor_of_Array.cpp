#include <iostream>

void swap(int& firstNumber, int& secondNumber)
{
	int temp = firstNumber;
	firstNumber = secondNumber;
	secondNumber = temp;
}

int gcdOfTwoNumbers(int firstNumber, int secondNumber)
{
	if (firstNumber > secondNumber)
	{
		swap(firstNumber, secondNumber);
	}
	
	while (true)
	{
		int temp = firstNumber % secondNumber;

		if (temp == 0)
		{
			break;
		}

		firstNumber = secondNumber;
		secondNumber = temp;
	}

	return secondNumber;
}

int getGcdOfArray(const int* array, size_t size)
{
	if (size == 1)
	{
		return array[0];
	}

	int gcd = gcdOfTwoNumbers(array[0], array[1]);

	for (int i = 2; i < size; i++)
	{
		gcd = gcdOfTwoNumbers(gcd, array[i]);
	}

	return gcd;
}

int main()
{
	constexpr unsigned size = 4;
	int arr[size];

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	std::cout << getGcdOfArray(arr, size);
}