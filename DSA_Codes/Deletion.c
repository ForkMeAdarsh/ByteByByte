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

// Deletion of elements using indDeletion function
void indDeletion(int arr[], int size, int capacity, int index)
{
    if (size >= capacity)
    {
        printf("Deletion failed......!!!\n");
    }
    else
    {
        printf("Executing the deletion of the element.......\n");
        for (int i = index; i < size-1; i++)
        {
            arr[i] = arr[i+1];
        }
    }
}

int main()
{
    int arr[] = {7, 8, 12, 27, 88};
    int size = sizeof(arr)/sizeof(int);
    int capacity = 100, index;
    printf("Here is the array you provided\n");
    display(arr, size, capacity);
    printf("Enter index from where you want element to be deleted: ");
    scanf("%d", &index);
    printf("\n\n");
    indDeletion(arr, size, capacity, index);
    size -= 1;
    display(arr, size, capacity);
    return 0;
}