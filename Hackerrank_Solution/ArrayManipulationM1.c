                                // ******** THIS METHOD WILL FAIL WHEN WE GIVE LARGE INPUTS ********

#include <stdio.h>
#include <stdlib.h>

long arrayManipulation(int soA, int noQ)
{
    long a, b, k;
    long max_value = 0;

    long **arr = (long **)malloc(noQ+1 * sizeof(long *)); // creating a 2-D array according to number of queries given and array formed will be one more than the query
    long **query = (long **)malloc(noQ * sizeof(long *)); // creating a 2-D array according to number of queries given

    for (int i = 0; i <= noQ; i++)
    {
        arr[i] = (long *)calloc(soA, sizeof(long)); // dynamically allocating size of array for each array created according to size of array you had given as input
    }

    for (int i = 0; i < noQ; i++)
    {
        query[i] = (long *)malloc(3 * sizeof(long)); // setting the size for query array to 3 for every query array created by you
    }

    printf("Enter your queries containing three integers which represents a, b and k respectively below\n"); // accepting the input for value of a, b and k
    for (int i = 1; i <= noQ; i++)
    {
        printf("Query%d: ", i);
        scanf("%ld %ld %ld", &a, &b, &k);

        while (a > b) // checking whether the value 'a' is greater than 'b' or not if it is then again asking input for the wrong input query
        {
            printf("Incorrect Input! 'a' cannot be greater than 'b'. Enter your input again for this query\n");
            printf("Query%d: ", i);
            scanf("%ld %ld %ld", &a, &b, &k);
        }

        for (int j = 0; j < soA; j++) // inherit the value of previous row
        {
            arr[i][j] = arr[i-1][j];
        }

        for (int j = a-1; j < b; j++) // update the array with the sum of previous row element and k from position 'a' to 'b' 
        {
            arr[i][j] += k;
            if (arr[i][j] > max_value) // storing the largest element in to the max_value variable
            {
                max_value = arr[i][j];
            }
        }
    }

    // for (int i = 0; i < noQ+1; i++)     // For better debugging of the program
    // {
    //     for (int j = 0; j < soA; j++)
    //     {
    //         printf("%d ", arr[i][j]);
    //     }
    //     printf("\n");
    // }

    // freeing of memory
    for (int i = 0; i < noQ; i++) 
    {
        free(query[i]);
    }
    free(query);
    for (int i = 0; i < noQ+1; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return max_value;
}

int main()
{
    int soA, noQ;
    printf("Enter size of array and number of operation: ");
    scanf("%d %d",  &soA, &noQ);

    if (soA <= 0 || noQ <= 0)  // conditional statement to check the right input for the soA and noQ variable
    {
        printf("Warning: n and m cannot be less than or equal to zero");
        return 1;
    }

    printf("The max value after checking all the arrays comes out to be %ld", arrayManipulation(soA, noQ));
    
    return 0;
}