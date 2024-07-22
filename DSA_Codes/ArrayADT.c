#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
}marks;

void createArray(struct myArray *a, int tsize, int usize)
{
    // (*a).total_size = tsize;
    // (*a).used_size = usize;
    // (*a).ptr = (int *)malloc(tsize * sizeof(int));
    
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *)malloc(tsize * sizeof(int));
}

void set(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the %d element of the array\n", i+1);
        scanf("%d", &(a->ptr[i]));
        getchar();
    }
}

void show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d ", a->ptr[i]);
    }
}

int main()
{
    int t, u;
    printf("Enter the value of t so as to set the value for total size\n");
    scanf("%d", &t);
    printf("Enter the value of u less than or equal to t so as to set the value for used size\n");
    scanf("%d", &u);
    createArray(&marks, t, u);
    printf("We are running set now....\n");
    set(&marks);
    printf("We are running show now....\n");
    show(&marks);
    return 0;
}
