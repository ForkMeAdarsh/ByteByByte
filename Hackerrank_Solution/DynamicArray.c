#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
    int noA, noQ, queryNum, x, y, lastAnswer = 0, idx;
    printf("Enter the number of arrays and number of queries respectively you want in this problem: "); 
    scanf("%d %d", &noA, &noQ);

    int **arr = (int **)malloc(noA * sizeof(int *)); // Pointer to Pointer which stores the addresses of the rows present in your array
    int *s = (int *)malloc(noA * sizeof(int)); // Dynamically sets the space for elements/columns
    int *a = (int *)malloc(noA * sizeof(int)); // Works as second parameter for the accessing of the elements when element are entered dynamically

    for (int i = 0; i < noA; i++)
    {
        s[i] = 1; // This will make space for elements/columns in the array and will be dynamically altered in the later stage
        arr[i] = (int *)malloc(s[i] * sizeof(int)); // This will set space for first,second,and third row...son on.....according to space filled till now
        a[i] = 0; // This will be used as second parameter for the accessing the array according to space filled and will dynamically changed egs:- like arr[idx][a[idx]]
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

// For better understanding of this solution please check the Dynamic Array Explanation file.
