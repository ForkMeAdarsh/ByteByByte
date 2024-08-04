#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinglyLinkedListNode
{
    int data;
    struct SinglyLinkedListNode* next;
};

typedef struct SinglyLinkedListNode SinglyLinkedListNode;

SinglyLinkedListNode* createLinkedList(int arr[], int noNode) 
{
    SinglyLinkedListNode* head = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));

    if (head == NULL || noNode <= 0)
    {
        printf("Memory Allocation Failed\n");
        return NULL;
    }

    head->data = arr[0]; 
    head->next = NULL; 

    SinglyLinkedListNode* currentNode = head; 
    for (int i = 1; i < noNode; i++)
    {
        SinglyLinkedListNode* newNode = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode)); 
        if (newNode == NULL)
        {
            printf("Memory Allocation Failed\n");
            return NULL;
        }
        newNode->data = arr[i];
        newNode->next = NULL;
        currentNode->next = newNode; 
        currentNode = newNode;
    }
    return head; 
}

bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) 
{
    int nodeCountL1 = 0, nodeCountL2 = 0;
    SinglyLinkedListNode* temp1 = head1;
    SinglyLinkedListNode* temp2 = head2;
    while (temp1 != NULL) 
    {
        nodeCountL1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) 
    {
        nodeCountL2++;
        temp2 = temp2->next;
    }
    if (nodeCountL1 != nodeCountL2) 
    {
        return false;
    }
    else 
    {
        while (head1 != NULL && head2 != NULL) 
        {
            if (head1->data != head2->data) 
            {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;    
        }
        return true;
    }
}

int main()
{
    int test_cases;
    SinglyLinkedListNode** LinkedList1head = (SinglyLinkedListNode**)malloc(test_cases * sizeof(SinglyLinkedListNode*)); 
    SinglyLinkedListNode** LinkedList2head = (SinglyLinkedListNode**)malloc(test_cases * sizeof(SinglyLinkedListNode*)); 

    printf("Enter the number of test cases: ");
    scanf("%d", &test_cases);
    
    for (int i = 0; i < test_cases; i++)
    {
        if (test_cases == 1)
        {
            printf("\n\t\t\t\t\t\t******ENTER THE DATA AS REQUESTED******\n");
        }
        else if (test_cases == 2)
        {
            if (i == 0)
            {
                printf("\n\t\t\t\t\t\t******FIRST TEST CASE******\n");
            }
            else
            {
                printf("\n\t\t\t\t\t\t******SECOND TEST CASE******\n");
            }
        }
        else if (test_cases == 3)
        {
            if (i == 0)
            {
                printf("\n\t\t\t\t\t\t******FIRST TEST CASE******\n");
            }
            else if (i == 1)
            {
                printf("\n\t\t\t\t\t\t******SECOND TEST CASE******\n");
            }
            else
            {
                printf("\n\t\t\t\t\t\t******THIRD TEST CASE******\n");
            }
        }
        else if (test_cases == 4)
        {
            if (i == 0)
            {
                printf("\n\t\t\t\t\t\t******FIRST TEST CASE******\n");
            }
            else if (i == 1)
            {
                printf("\n\t\t\t\t\t\t******SECOND TEST CASE******\n");
            }
            else if (i == 2)
            {
                printf("\n\t\t\t\t\t\t******THIRD TEST CASE******\n");
            }
            else
            {
                printf("\n\t\t\t\t\t\t******FOURTH TEST CASE******\n");
            }
        }
        else
        {
            printf("\n\t\t\t\t\t\t******TEST CASE %d******\n", i+1);
        }
        
        int noNode1, noNode2;

        printf("Enter total number of nodes for first linkedlist: ");
        scanf("%d", &noNode1);
        int* arr1 = (int*)malloc(noNode1 * sizeof(int));
        printf("Enter elements for first linkedlist\n");
        for (int j = 0; j < noNode1; j++)
        {
            scanf("%d", &arr1[j]);
        }
        LinkedList1head[i] = createLinkedList(arr1, noNode1);

        printf("Enter total number of nodes for second linkedlist: ");
        scanf("%d", &noNode2);
        int* arr2 = (int*)malloc(noNode2 * sizeof(int));
        printf("Enter elements for second linkedlist\n");
        for (int k = 0; k < noNode2; k++)
        {
            scanf("%d", &arr2[k]);
        }
        LinkedList2head[i] = createLinkedList(arr2, noNode2);
    }

    printf("\nDisclaimer:-If the lists are equal then the result will be true/1 otherwise false/0\n");
    for (int j = 0; j < test_cases; j++)
    {
        printf("The result of comparison of test case %d is %s\n", j+1, compare_lists(LinkedList1head[j], LinkedList2head[j]) ? "true" : "false"); // we have done compare_list(LinkedList1head[j], LinkedList2head[j]) ? "true" : "false" because we want to print the result of compare_list function in true or false form in place of 1 or 0
    }
    
    return 0;
}