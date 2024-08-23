#include <iostream>

int lcmOfTwoElements(int firstNumber, int secondNumber)
{
	int greaetrNumber = firstNumber > secondNumber ? firstNumber : secondNumber;
	int lcm = greaetrNumber;

	while ((lcm % firstNumber != 0) || (lcm % secondNumber != 0))
	{
		lcm += greaetrNumber;
	}

	return lcm;
}

int getLcmOfArray(const int* array, size_t size)
{
	if (size == 1)
	{
		return array[0];
	}
	
	int lcm = lcmOfTwoElements(array[0], array[1]);

	for (int i = 2; i < size; i++)
	{
		lcm = lcmOfTwoElements(array[i], lcm);
	}

	return lcm;
}

int main()
{
	constexpr unsigned size = 4;
	int arr[size];

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	std::cout << getLcmOfArray(arr, size);
}