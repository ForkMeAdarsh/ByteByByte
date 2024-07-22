#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
    int noA, noQ, queryNum, x, y, lastAnswer = 0, idx;
    printf("Enter the number of arrays and number of queries respectively you want in this problem: "); 
    scanf("%d %d", &noA, &noQ);

    int **arr = (int **)malloc(noA * sizeof(int *)); //Pointer to Pointer which stores the addresses of the rows present in your array
    int *s = (int *)malloc(noA * sizeof(int));
    int *a = (int *)malloc(noA * sizeof(int));

    for (int i = 0; i < noA; i++)
    {
        s[i] = 1;
        arr[i] = (int *)malloc(s[i] * sizeof(int));
        a[i] = 0;
    }
    
    for (int i = 0; i < noQ; i++)
    { 
        printf("Enter the query number, value of x and value of y respectively: ");
        scanf("%d %d %d", &queryNum, &x, &y);

        idx = (x ^ lastAnswer) % noA;

        if (queryNum == 1)
        {
            arr[idx][a[idx]] = y;
            a[idx]++;
            if (a[idx] == s[idx] + 1)
            {
                s[idx]++;
                arr[idx] = realloc(arr[idx], s[idx] * sizeof(int));
                s[idx]++;
            }
        }
        else
        {
            int pdx = y % a[idx];
            printf("%d\n", arr[idx][pdx]);
            lastAnswer = arr[idx][pdx];
        }
    }
    
    // Freeing the dynamic allocated memory

    for (int i = 0; i < noA; i++) 
    { 
        free(arr[i]); 
    } 
    free(arr);
    free(s);
    free(a);
 
    return 0; 
} 
