#include <iostream>

int sumRec(const int* arr, size_t size, int sum = 0)
{
    if (size == 0)
    {
        return sum;
    }

    return sumRec(arr + 1, size - 1, sum + *arr);
}

int main()
{
    int size;
    std::cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }

    std::cout << sumRec(arr, size);
}