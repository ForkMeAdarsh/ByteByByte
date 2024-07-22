#include <stdio.h>
#include <stdlib.h>

long arrayManipulation(int soA, int noQ) 
{
    long max_value = 0; // variable to store the largest element
    int a, b, k;
    long *arr = (long *)calloc(soA, sizeof(long)); // 1-D array to store the elements

    printf("Enter the values for a, b and k respectively below\n");
    for (int i = 0; i < noQ; i++) 
    {
        printf("Query%d: ", i+1);
        scanf("%d %d %d", &a, &b, &k);

        if (a < 1 || a > soA || b < 1 || b > soA || k < 0) // validate input
        {
            printf("Invalid input! Please enter valid values.\n");
            i--; // retry current operation
            continue;
        }

        else if (a > b)
        {
            printf("a cannot be greater than b\n");
            i--; // retry current operation
            continue;
        }
        
        arr[a-1] += k; // update the element at position 'a' with sum of previous element and 'k' 

        if (b < soA) 
        {
            arr[b-1] -= k; // optimization to avoid extra loop and make the element at position 'b' the negative of 'a' so that max_value get correct value
        }
    }

    long prefix_sum = 0; // to calculate the sum of the elements and if the sum is greater than the max_value then assign it in max_value variable
    for (int i = 0; i < soA; i++) 
    {
        prefix_sum += arr[i];
        if (prefix_sum > max_value) 
        {
            max_value = prefix_sum; // assigning of the sum value stored in prefix_sum to max_value
        }
    }

    free(arr); // freeing the memory
    return max_value;
}

int main() 
{
    int soA, noQ;
    printf("Enter the size of array and number of operations to perform: ");
    scanf("%d %d", &soA, &noQ);

    if (soA <= 0 || noQ <= 0)  // conditional statement to check the right input for the soA and noQ variable
    {
        printf("Warning: n and m cannot be less than or equal to zero");
        return 1;
    }

    printf("%ld", arrayManipulation(soA, noQ));

    return 0;
}
