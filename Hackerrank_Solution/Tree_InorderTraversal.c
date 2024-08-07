#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
{
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inOrderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main()
{
    struct Node* p = createNode(1);
    struct Node* p1 = createNode(2);
    struct Node* p2 = createNode(5);
    struct Node* p3 = createNode(3);   
    struct Node* p4 = createNode(6);   
    struct Node* p5 = createNode(4);

    p->right = p1;
    p1->right = p2;
    p2->left = p3;
    p2->right = p4;
    p3->right = p5;

    inOrderTraversal(p);

    return 0;
}