#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *matchingStrings(char **stringList, char **queryList, int sizeOfsL, int sizeOfqL) // we will pass the pointer to pointer character array itself
{
    int *result = (int *)malloc(sizeOfqL * sizeof(int));
    for (int i = 0; i < sizeOfqL; i++)
    {
        result[i] = 0; // intialize the the elements of the result array to 0
    }

    for (int i = 0; i < sizeOfqL; i++)
    {
        for (int j = 0; j < sizeOfsL; j++)
        {
            if (strcmp(queryList[i], stringList[j]) == 0) // will compare the elements in the queryList to the elements in stringList one by one and then update the result array counter
            {
                result[i] = result[i]+1;
            }
        }
    }
    return result;
}

int main()
{
    int sizeOfsL, sizeOfqL;

    printf("Enter the size of stringList: ");
    scanf("%d", &sizeOfsL);

    char **stringList = (char **)malloc(sizeOfsL * sizeof(char *)); // this added pointer to pointer because the strings we are going to add as a element will be considered as strings of strings
    printf("Enter the elements as charaters in the array of strings\n");
    for (int i = 0; i < sizeOfsL; i++)
    {
        stringList[i] = (char *)malloc(100 * sizeof(char)); // dynamically allocate memory to the stringList[i] for the size 100
        scanf("%s", stringList[i]);
    }
    printf("---Here is your stringlist---\n");
    printf("{");
    for (int i = 0; i < sizeOfsL-1; i++)
    {
        printf("%s, ", stringList[i]);
    }
    printf("%s", stringList[sizeOfsL-1]);
    printf("}");
    printf("\n\n");

    printf("Enter the size of queryList: ");
    scanf("%d", &sizeOfqL);

    char **queryList = (char **)malloc(sizeOfqL * sizeof(char *)); // this added pointer to pointer because the strings we are going to add as a element will be considered as strings of strings
    printf("Enter the elements as characters in the array of queries\n");
    for (int i = 0; i < sizeOfqL; i++)
    {
        queryList[i] = (char *)malloc(100 * sizeof(char)); // dynamically allocate memory to the queryList[i] for the size 100
        scanf("%s", queryList[i]);
    }
    printf("---Here is your querylist---\n");
    printf("{");
    for (int i = 0; i < sizeOfqL-1; i++)
    {
        printf("%s, ", queryList[i]);
    }
    printf("%s", queryList[sizeOfqL-1]);
    printf("}");
    printf("\n\n");

    int *resultant = matchingStrings(stringList, queryList, sizeOfsL, sizeOfqL); // resultant array pointer will store the count in form of elements of an array
    for (int i = 0; i < sizeOfqL; i++)
    {
        printf("%d ", resultant[i]);
    }

    // freeing the dynamically allocated memory
    for (int i = 0; i < sizeOfsL; i++)
    {
        free(stringList[i]);
    }
    free(stringList);

    for (int i = 0; i < sizeOfqL; i++)
    {
        free(queryList[i]);
    }
    free(queryList);

    free(resultant);
    
    return 0;
}

