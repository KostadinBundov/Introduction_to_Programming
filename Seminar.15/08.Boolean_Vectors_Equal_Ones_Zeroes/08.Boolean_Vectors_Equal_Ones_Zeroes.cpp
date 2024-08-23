#include <iostream>

bool areZeroesAndOnesEqual(const bool* arr, size_t size)
{
	size_t onesCount = 0;
	size_t zeroesCount = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i])
		{
			onesCount++;
		}
		else
		{
			zeroesCount++;
		}
	}

	return onesCount == zeroesCount;
}

void generatePermutationsRec(bool* arr, size_t size, bool(*pred)(const bool*, size_t), unsigned index = 0)
{
	if (index == size)
	{
		if (pred(arr, size))
		{
			for (int i = 0; i < size; i++)
			{
				std::cout << arr[i];
			}

			std::cout << std::endl;
		}
	}
	else
	{
		arr[index] = 0;
		generatePermutationsRec(arr, size, pred, index + 1);

		arr[index] = 1;
		generatePermutationsRec(arr, size, pred, index + 1);
	}
}

void generatePermutations(bool* arr, size_t size)
{
	generatePermutationsRec(arr, size, areZeroesAndOnesEqual);
}

int main()
{
	size_t size;
	std::cin >> size;

	bool* arr = new bool[size] {false};

	generatePermutations(arr, size);

	delete[] arr;
}