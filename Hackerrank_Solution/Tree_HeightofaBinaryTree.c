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

int getHeight(struct Node* root)
{
    if (root == NULL) // base case which will return -1 if node points to NULL
    {
        return -1; 
    }
    else // actual calculation will start here
    {
        int leftHeight = getHeight(root->left); // to calculate the height of left sub-tree
        int rightHeight = getHeight(root->right); // to calculate the height of right sub-tree
        if (leftHeight > rightHeight) // checks wheather the height left sub-tree is greater or of right sub-tree and will return its respective height while adding 1 in it
        {                             // we have added in the left and right height so as identify the position of the current node
            return leftHeight+1; 
        }
        else
        {
            return rightHeight+1; 
        }                            // when left and right heights are equal i.e. our tree is in same level for both left and right sub-tree then when we can return either of these
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

    printf("The height of the binary tree is %d\n", getHeight(p));

    return 0;
}