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

/* here height is number of edges between tree's root and its furthest leaf. the longest root-to-leaf path is to the 
extreme right and since there 4 nodes in this path and 3 edges therefore height is 3 */
int getHeight(struct Node* root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if (leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }
        else
        {
            return rightHeight + 1;
        }
    }
}

int main()
{
    struct Node* p = createNode(3);
    struct Node* p1 = createNode(2);
    struct Node* p2 = createNode(5);
    struct Node* p3 = createNode(1);
    struct Node* p4 = createNode(4);
    struct Node* p5 = createNode(6);
    struct Node* p6 = createNode(7);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p2->left = p4;
    p2->right = p5;
    p5->right = p6;

    printf("\n\n\t\t***** The height of the tree is %d *****\n\n", getHeight(p));

    return 0;
}
