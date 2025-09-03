#include <stdio.h>
#include <iostream>

int LinearSearch(int *arr, int Snum)
{
    for (int j = 0; j <= (sizeof(arr)); j++)
    {

        if (arr[j] == Snum)
        {
            return j;
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

    std::cout << "Enter " << size << " integer elements of the array : \n";

    for (int i = 0; i < size; i++)
    {
        std::cout << "Element " << i + 1 << " :";
        std::cin >> arr[i];
    }

    std::cout << "\nArray Elements Entered";
    std::cout << "\nEnter the element for which you want to perform Linear Search ";
    std::cin >> Snum;
    std::cout << "Performing Linear Search For " << Snum << " .....";

    int result = LinearSearch(arr, Snum);

    if (result >= 0)
    {
        std::cout << "\n"
                  << Snum << " found at index : " << result << " :)";
    }
    else
    {
        std::cout << "\n"
                  << Snum << " not found ._.";
    }
}