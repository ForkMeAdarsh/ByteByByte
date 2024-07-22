#include <stdio.h>
#include <stdlib.h>

void printArray(int Array[6], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", Array[i]);
    }
}

void BubbleSort(int Array[6], int size)
{
    int temp;
    int isSorted;
    for (int i = 0; i < size - 1; i++)
    {
        printf("Working on pass no %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (Array[j] > Array[j + 1])
            {
                temp = Array[j + 1];
                Array[j + 1] = Array[j];
                Array[j] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        return;
    }
}

int main()
{
    int A[6] = {7, 11, 9, 2, 17, 4};
    // int A[6] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    printf("Array before Sorting:\n");
    printArray(A, n);
    printf("\n\n");
    BubbleSort(A, n);
    printf("Array after Sorting:\n");
    printArray(A, n);
    return 0;
}