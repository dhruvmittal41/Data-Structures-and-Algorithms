#include <stdio.h>
#include <iostream>

int InterpolationSearch(int *arr, int low, int high, int Snum)
{

    int pos;

    if (low <= high && arr[high] >= Snum && arr[low] <= Snum)
    {

        pos = low + ((Snum - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == Snum)
        {
            return pos;
        }

        if (arr[pos] < Snum)
        {

            return InterpolationSearch(arr, pos + 1, high, Snum);
        }

        if (arr[pos] > Snum)
        {

            return InterpolationSearch(arr, low, pos - 1, Snum);
        }

        return -1;
    }
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
    std::cout << "\nEnter the element for which you want to perform Interpolation Search ";
    std::cin >> Snum;
    std::cout << "Performing Interpolation Search For " << Snum << " .....";

    int lo = 0;
    int hi = size - 1;
    int result = InterpolationSearch(arr, lo, hi, Snum);

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
