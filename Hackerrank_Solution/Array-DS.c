#include <stdio.h>
#include <stdlib.h>

int *reverseArray(int *A, int N)
{
    int *reversedArray = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        reversedArray[i] = A[N-i-1];
    }
    return reversedArray;
}

int main()
{
    int N;
    int *A = (int *)malloc(sizeof(N * sizeof(int)));
    printf("Enter the number of elements you want to see in the array: ");
    scanf("%d", &N);
    printf("Enter the elements: ");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    int *finalarray = reverseArray(A, N);
    printf("Reversed Array: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", finalarray[i]);
    }

    free(A);
    free(finalarray);
}