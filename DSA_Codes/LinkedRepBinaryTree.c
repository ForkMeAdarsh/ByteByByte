#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// function to create node automaticalllr
struct Node* createNode(int data) 
{
    struct Node* n = (struct Node*)malloc(sizeof(struct Node)); // creating node pointer as well as allocating space for the node in heap
    n->data = data; // setting the data for the node
    n->left = NULL; // setting left node to NULL
    n->right = NULL; // setting right node to NULL
    return n; // at the end returning the node
}

int main()
{
    // code to create as well as connect them manuallr

    // struct Node *p, *p1, *p2;
    
    // p = (struct Node*)malloc(sizeof(struct Node));
    // p->data = 2;
    // p->left = p1;
    // p->right = p2;

    // p1 = (struct Node*)malloc(sizeof(struct Node));
    // p1->data = 1;
    // p1->left = NULL;
    // p1->right = NULL;

    // p2 = (struct Node*)malloc(sizeof(struct Node));
    // p2->data = 4;
    // p2->left = NULL;
    // p2->right = NULL;

    // code to create as well as connect them with the help of a function

    struct Node* p = createNode(2);
    struct Node* p1 = createNode(1);
    struct Node* p2 = createNode(4);
    struct Node* p1_l = createNode(11);
    struct Node* p1_r = createNode(12);
    struct Node* p2_r = createNode(3);

    // connecting the node
    p->left = p1;
    p->right = p2;

    p1->left = p1_l;
    p1->right = p1_r;

    p2->right = p2_r;

    return 0;
}