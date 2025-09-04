#include <stdio.h>
#include <iostream>

int IterativeBinarySearch(int *arr, int Snum, int size)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        if (arr[mid] == Snum)
        {
            return mid;
        }

        if (arr[mid] < Snum)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }

    return -1;
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

    int result = IterativeBinarySearch(arr, Snum, size);

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

// Recursive Solution
// Usage : Call RecursiveBinarySearch(arr,0,size-1,Snum);

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
