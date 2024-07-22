#include <stdio.h>
#include <stdlib.h>

int *rotateArrayLeft(int *arr, int unitsRotate, int size)
{
    int *array = (int *)malloc(size * sizeof(int)); // Making dynamic array upto to the size of original array
    for (int i = 0; i < size; i++)
    {
        array[i] = arr[(i+unitsRotate)%(size)]; // Logic to rotate the array by a given amount 
    }
    return array;
}

void printArray(int *arr, int size) // Function to print the array
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

int main()
{
    int size, unitsRotate;
    printf("Enter the size and units to rotate the array by: ");
    scanf("%d %d", &size, &unitsRotate);
    int *arr = (int *)malloc(size * sizeof(int));

    printf("Enter the elements upto size you entered in the array below\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n");

    printf("The elements you provided in the array are\n");
    printArray(arr, size);

    printf("The array rotated to left by %d is\n", unitsRotate);
    int *rotatedArray = rotateArrayLeft(arr, unitsRotate, size); // Storing the array in variable pointer which will be used in traversing the array
    printArray(rotatedArray, size);
    
    return 0;
}

//                                      ****** Second method for this problem ******

// #include <stdio.h>
// #include <stdlib.h>

// int *rotateArrayLeft(int *arr, int unitsRotate, int size)
// {
//     int *temp = (int *)malloc(unitsRotate * sizeof(int));
//     for (int i = 0; i < unitsRotate; i++)
//     {
//         temp[i] = arr[i];
//     }
    
//     for (int i = 0; i < size-unitsRotate; i++)
//     {
//         arr[i] = arr[i+unitsRotate];
//     }
    
//     for (int i = 0; i < unitsRotate; i++)
//     {
//         arr[i+size-unitsRotate] = temp[i];
//     }
//     return arr;
// }

// void printArray(int *arr, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// int main()
// {
//     int size, unitsRotate;
//     printf("Enter the value for size of array and the amount by which you want the array to be rotated: ");
//     scanf("%d %d", &size, &unitsRotate);

//     int *arr = (int *)malloc(size * sizeof(int));
//     printf("Enter the elements in the array below\n");
//     for (int i = 0; i < size; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     printf("\n");

//     printf("Here are the elements in the array you entered\n");
//     printArray(arr, size); 

//     int *Rotatedarray = rotateArrayLeft(arr, unitsRotate, size);
//     printf("Here is the array after %d rotation\n", unitsRotate);
//     printArray(Rotatedarray, size);

//     return 0;
// }