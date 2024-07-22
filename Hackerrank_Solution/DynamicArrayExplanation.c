#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Allocate memory for the array of pointers (rows)
    // Basically pointer to pointer i.e **arr below is an array of an array
    int **arr = (int **)malloc(rows * sizeof(int *));

    // Allocate memory for each row (array of columns)
    for (int i = 0; i < rows; i++)
    {
        arr[i] = (int *)malloc(cols *sizeof(int));
    }

    printf("Enter the elements for %dX%d array below\n", rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");

    printf("%d\n", *arr[0]); // This will print only the first elements in each row for all the three i.e one on this line and two below
    printf("%d\n", *arr[1]);
    printf("%d\n", *arr[2]);
    printf("\n");

    for (int i = 0; i < cols; i++)
    {
        printf("%d\n", arr[0][i]); // To print only the elements in the first row
    }
    
    printf("Here is the array you provided dynamically\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]); 
        }
        printf("\n");
    }
    
}