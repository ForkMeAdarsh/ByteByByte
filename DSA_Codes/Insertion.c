#include <stdio.h>
#include <stdlib.h>

// Traversal of elements using display function
void display(int array[], int size, int capacity)
{
    if (size > capacity)
    {
        printf("Cannot function properly!\n");
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
}

// Insertion of elements using indInsertion function
void indInsertion(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        printf("Insertion failed......!!!\n");
    }
    else
    {
        printf("Executing the insertion of the element.......\n");
        for (int i = size-1; i >= index; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[index] = element;
    }
}

int main()
{
    int arr[] = {7, 8, 12, 27, 88};
    int size = sizeof(arr)/sizeof(int);
    int capacity = 100, element, index;
    printf("Here is the array you provided\n");
    display(arr, size, capacity);
    printf("Enter element you want to insert: ");
    scanf("%d", &element);
    printf("Enter the index where you want element to get positioned: ");
    scanf("%d", &index);
    printf("\n\n");
    indInsertion(arr, size, element, capacity, index);
    size += 1;
    display(arr, size, capacity);
    return 0;
}