#include <stdio.h>
#include <stdlib.h>

long arrayManipulation(int n, int m)  //n = size of the array and m = number of operations
{
    long max_value = 0;
    int a, b, k;
    long **arr = (long **)malloc((m + 1) * sizeof(long *));

    for (int i = 0; i < m + 1; i++)
    {
        arr[i] = (long *)malloc(n * sizeof(long));
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    for (int i = 1; i < m + 1; i++)
    {
        printf("Enter the value of a, b and k for operation %d: ", i);
        scanf("%d %d %d", &a, &b, &k);
        while (a > b)
        {
            printf("Error: Invalid input.The value of 'a' cannot be greater than 'b'!!\n");
            printf("Enter the value of a, b and k for operation %d: ", i);
            scanf("%d %d %d", &a, &b, &k);
        }
        for (int j = a - 1; j <= b - 1; j++)
        {
            arr[i][j] = arr[i - 1][j] + k;
        }
    }
    printf("\n");

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < n; j++)        
        {
            printf("%ld ", arr[i][j]);
        }
    }
    printf("\n");

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%ld ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] > max_value)
            {
                max_value = arr[i][j];
            }
        }
    }
    
    // Freeing Dynamically Allocated Memory
    for (int i = 0; i < m + 1; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return max_value;
}

int main()
{
    int n, m, element;
    printf("Enter size of array and the number of operations you want to perform: ");
    scanf("%d %d", &n, &m);
    element = arrayManipulation(n, m);
    printf("The greatest element after the array mainpulation is %ld\n", element);

    return 0;
}