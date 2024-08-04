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

int calNodeofLinkedList(SinglyLinkedListNode* head) // function to calculate number of nodes of a linkedlist
{
    int nodeCount = 0;
    while (head != NULL)
    {
        nodeCount++;
        head = head->next;
    }
    return nodeCount;
}

SinglyLinkedListNode* createLinkedList(int arr[], int noNode) // function to create as many number of nodes as the data given in the array and then link all the nodes together
{
    SinglyLinkedListNode* head = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));

    if (head == NULL || noNode <= 0)
    {
        printf("Memory Allocation Failed\n");
        return NULL;
    }

    head->data = arr[0]; // to create a node with its name as head node and put the first element of array and make it the data part of the head node
    head->next = NULL; // to make head point to NULL

    SinglyLinkedListNode* currentNode = head; // to keep check of the current node

    for (int i = 1; i < noNode; i++)
    {
        SinglyLinkedListNode* newNode = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode)); // allocating space for newnode variable so as introduce new node where the data part of that node will be rest of the elements in the array and it will be stored iteratively
        if (newNode == NULL)
        {
            printf("Memory Allocation Failed\n");
            return NULL;
        }
        newNode->data = arr[i];
        newNode->next = NULL;
        currentNode->next = newNode; // making the connection of nodes via this statement
        currentNode = newNode; // moving the current node pointer point to new node
    }
    return head; // function will return the pointer to head
}

bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) // function to compare the two lists given
{
    int countL1 = calNodeofLinkedList(head1);
    int countL2 = calNodeofLinkedList(head2);
    if (countL1 != countL2)
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
        // return head1 == NULL && head2 == NULL; // conditional statement to return true value
    }
}

int main()
{
    int test_cases;
    // SinglyLinkedListNode* LinkedList1head, LinkedList2head; // this will make LinkedList1head a pointer but not LinkedList2head a pointer instead it wil simply be a struct Node variable not a pointer
    SinglyLinkedListNode** LinkedList1head = (SinglyLinkedListNode**)malloc(test_cases * sizeof(SinglyLinkedListNode*)); // making this variable pointer to pointer so as to store the address of head node of first linkedlist for each test case
    SinglyLinkedListNode** LinkedList2head = (SinglyLinkedListNode**)malloc(test_cases * sizeof(SinglyLinkedListNode*)); // making this variable pointer to pointer so as to store the address of head node of second linkedlist for each test case

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
        printf("The result of comparison of test case %d is %d\n", j+1, compare_lists(LinkedList1head[j], LinkedList2head[j]));
    }
    
    return 0;
}