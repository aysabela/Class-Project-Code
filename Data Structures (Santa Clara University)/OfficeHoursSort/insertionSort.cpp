#include <iostream>
using namespace std;

void insertionSort(size_t list[], int listSize)
{
    for (int i = 1; i < listSize; i++)
    {
        size_t current = list[i];
        int j;

        for (j = i - 1; j >= 0 && list[j] > current; j--)
        {
            list[j + 1] = list[j];
        }

        list[j + 1] = current;
    }
}