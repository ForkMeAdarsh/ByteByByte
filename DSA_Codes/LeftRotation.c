#include <stdio.h>
#include <stdlib.h>

int *rotateArray(int *arr, int stepsRotate, int size)
{
    int *temp = (int *)malloc(stepsRotate * sizeof(int));
    
    for (int i = 0; i < stepsRotate; i++)
    {
        temp[i] = arr[i];
    }
    
    for (int i = 0; i < size - stepsRotate; i++)
    {
        arr[i] = arr[i + stepsRotate];
    }
    
    for (int i = 0; i < stepsRotate; i++)
    {
        arr[size - stepsRotate + i] = temp[i];
    }
    free(temp);
    return arr;
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 6};
    int size, unitRotate;
    
    printf("Enter the size of the array and number of units you want to rotate respectively below\n");
    scanf("%d %d", &size, &unitRotate);

    // Dynamically allocating the memory for the array as per the size given as input by the user
    int *arr = (int *)malloc(size * sizeof(int));

    // Taking the inputs as elements of the array
    printf("Enter the elements in the array below\n"); 
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    // Executing the rotation with the help of rotateArray function
    int *array = rotateArray(arr, unitRotate, size);

    // Printing the elements with the help of printArray function
    printf("Here is the array after rotation\n");
    printArray(array, size);

    free(arr);
    free(array);
    return 0;
}
