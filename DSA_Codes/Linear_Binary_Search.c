#include <stdio.h>
#include <stdlib.h>

int LinearSearch(int arr[], int size, int element)
{
    // LinearSearching starts
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
    // LinearSearching ends
}

int BinarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;

    // BinarySearching starts
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[low] == element)
        {
            // printf("Element was found in if block of low section\n");    
            return low;
        }

        if (arr[high] == element)
        {
            // printf("Element was found in if block of high section\n");
            return high;
        }
        
        if (arr[mid] == element)
        {
            // printf("Element was found in if block of high section\n");
            return mid;
        }

        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
    // BinarySearching ends
}

int main()
{
    // Unsorted array for LinearSearch
    int arr1[] = {1, 200, 3, 238, 2, 4, 100, 25};

    // printf("Size of array 1st including size of int is %d\n", sizeof(arr1));
    // printf("Size of array 1st is %d\n", sizeof(arr1) / sizeof(int));

    int element1 = 1000, searchIndex1, size1;
    size1 = sizeof(arr1) / sizeof(int);
    searchIndex1 = LinearSearch(arr1, size1, element1);
    printf("\nThe element %d was found at index %d\n", element1, searchIndex1);
    printf("\n");

    // Sorted array for BinarySearch
    int arr2[] = {1, 2, 3, 4, 200, 238, 300, 325};

    // printf("Size of array 2nd including size of int is %d\n", sizeof(arr2));
    // printf("Size of array 2nd is %d\n", sizeof(arr2) / sizeof(int));

    int element2 = 2, searchIndex2, size2;
    size2 = sizeof(arr2) / sizeof(int);
    searchIndex2 = BinarySearch(arr2, size2, element2);
    printf("\nThe element %d was found at index %d\n", element2, searchIndex2);
    printf("\n");

    return 0;
}