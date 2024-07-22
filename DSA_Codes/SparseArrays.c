#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **stringList;
    char **queries;
    int sizeOfsL, sizeOfqL;

    printf("Enter the size of the stringList: ");
    scanf("%d", &sizeOfsL);
    getchar();
    stringList = (char **)malloc(sizeOfsL * sizeof(char *));
    printf("Enter the elements in the stringList as characters from which you want the search to happen\n");
    for (int i = 0; i < sizeOfsL; i++)
    {
        stringList[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", stringList[i]);
    }
    printf("---Here is your stringlist---\n");
    printf("{");
    for (int i = 0; i < sizeOfsL - 1; i++)
    {
        printf("%s, ", stringList[i]);
    }
    printf("%s", stringList[sizeOfsL - 1]);
    printf("}");
    printf("\n\n");


    printf("Enter the size of the queries: ");
    scanf("%d", &sizeOfqL);
    getchar();
    queries = (char **)malloc(sizeOfqL * sizeof(char *));
    printf("Enter the elements in the queries as characters which you want to search\n");
    for (int i = 0; i < sizeOfqL; i++)
    {
        queries[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", queries[i]);
    }
    printf("---Here are your queries---\n");
    printf("{");
    for (int i = 0; i < sizeOfqL - 1; i++)
    {
        printf("%s, ", queries[i]);
    }
    printf("%s", queries[sizeOfqL - 1]);
    printf("}");
    printf("\n\n");

    int *countOfqueries = (int *)malloc(sizeOfqL * sizeof(int));
    for (int i = 0; i < sizeOfqL; i++)
    {
        countOfqueries[i] = 0;
    }
    
    
    for (int i = 0; i < sizeOfqL; i++)
    {
        for (int j = 0; j < sizeOfsL; j++)
        {
            if (strcmp(queries[i], stringList[j]) == 0)
            {
                countOfqueries[i]++;
            }
        }
    }
    
    printf("Here is the count of each occurence of queries in the stringList: [");
    for (int i = 0; i < sizeOfqL - 1; i++)
    {
        printf("%d, ", countOfqueries[i]);
    }
    printf("%d]", countOfqueries[sizeOfqL - 1]);

    // Freeing the dynamically allocated meomry
    for (int i = 0; i < sizeOfsL; i++)
    {
        free(stringList[i]);
    }
    free(stringList);
    
    for (int i = 0; i < sizeOfqL; i++)
    {
        free(queries[i]);
    }
    free(queries);
    free(countOfqueries);
    
    return 0;
}