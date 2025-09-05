#include <stdio.h>
#include <iostream>
#include <cmath>

int RecursiveBinarySearch(int *arr, int low, int high, int Snum)
{

    if (high >= low)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == Snum)
        {
            return mid;
        }

        if (arr[mid] < Snum)
        {
            return RecursiveBinarySearch(arr, mid + 1, high, Snum);
        }

        else
        {
            return RecursiveBinarySearch(arr, low, mid - 1, Snum);
        }
    }
    return -1;
}

int ExponentialSearch(int *arr, int size, int Snum)
{

    if (arr[0] == Snum)
    {
        return 0;
    }

    int j = 1;
    while (j < size && arr[j] <= Snum)
    {
        j = j * 2;
    }

    return RecursiveBinarySearch(arr, j / 2, std::min(j, size), Snum); // You can call iterative binary search here to implement iterative solution.
}

int main()
{

    int size;
    int Snum;

    std::cout << "Enter the size of array: ";
    std::cin >> size;

    int arr[size];

    std::cout << "Enter " << size << " sorted integer elements of the array : \n";

    for (int i = 0; i < size; i++)
    {
        std::cout << "Element " << i + 1 << " :";
        std::cin >> arr[i];
    }

    std::cout << "\nArray Elements Entered";
    std::cout << "\nEnter the element for which you want to perform Binary Search ";
    std::cin >> Snum;
    std::cout << "Performing Binary Search For " << Snum << " .....";

    int result = ExponentialSearch(arr, Snum, size);

    if (result < 0)
    {
        std::cout << "\n"
                  << Snum << " not found ._.";
    }
    if (result >= 0)
    {
        std::cout << "\n"
                  << Snum << " found at index " << result << " :)";
    }
}
