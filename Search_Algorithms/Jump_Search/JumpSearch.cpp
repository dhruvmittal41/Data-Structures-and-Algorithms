#include <stdio.h>
#include <iostream>
#include <cmath>

int JumpSearch(int *arr, int size, int Snum)
{

    for (int j = 0; j <= size; j += sqrt(size))
    {

        if (arr[j] == Snum)
        {
            return j;
        }

        if (arr[j] > Snum)
        {
            for (int i = j - sqrt(size); i <= j; i++)
            {
                if (arr[i] == Snum)
                {
                    return i;
                }
            }
            return -1;
        }
    }
}

int main()
{

    int size;
    int Snum;

    std::cout << "Enter the size of array: ";
    std::cin >> size;

    int arr[size];

    std::cout << "Enter " << size << " integer elements of the array : \n";

    for (int i = 0; i < size; i++)
    {
        std::cout << "Element " << i + 1 << " :";
        std::cin >> arr[i];
    }

    std::cout << "\nArray Elements Entered";
    std::cout << "\nEnter the element for which you want to perform Jump Search ";
    std::cin >> Snum;
    std::cout << "Performing Jump Search For " << Snum << " .....";

    int result = JumpSearch(arr, size, Snum);

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