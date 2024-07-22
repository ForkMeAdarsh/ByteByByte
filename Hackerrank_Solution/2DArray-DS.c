#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hourglass(int arr[6][6])
{
    int row = 6, col = 6, sum, max_sum = -63;
    for (int i = 0; i < row-2; i++)
    {
        for (int j = 0; j < col-2; j++)
        {
            sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            if (sum > max_sum)
            {
                max_sum = sum;
            }
        }
    }
    return max_sum;
}

int main()
{
    int arr[6][6];
    int row = 6, col = 6;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    
    printf("\nBelow are the elements of the array\n");
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nBelow are all the hourglass created from your given array\n");
    for (int i = 0; i < row-2; i++)
    {
        for (int j = 0; j < col-2; j++)
        {
            printf("%d %d %d\n  %d \n%d %d %d\n", arr[i][j], arr[i][j+1], arr[i][j+2], arr[i+1][j+1], arr[i+2][j], arr[i+2][j+1], arr[i+2][j+2]);
        }
    }
    
    printf("The maximum sum from all the hourglass created from a 6X6 array you provided is %d\n", hourglass(arr));
    
    return 0;
}