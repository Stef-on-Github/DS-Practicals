/*9. Write a program for creating a Binary tree and traversal of Binary tree*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create();
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);

int main()
{
    struct node *root = NULL;  // Initialize root to NULL
    int ch;
    while (1)
    {
        printf("\n 1. create node");
        printf("\n 2. inorder traversal");
        printf("\n 3. preorder traversal");
        printf("\n 4. postorder traversal");
        printf("\n 5. exit");
        printf("\n Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            root = create();
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            exit(0);
        default:
            printf(" WRONG CHOICE");
        }
    }
}

struct node *create()
{
    struct node *temp;
    int num;
    temp = (struct node *)malloc(sizeof(struct node));
    printf(" Enter data (press 0 for no node) : ");
    scanf("%d", &num);
    if (num == 0)
    {
        return NULL;  // Return NULL for no node
    }
    temp->data = num;
    printf(" Enter left child of %d = ", num);
    temp->left = create();
    printf(" Enter right child of %d = ", num);
    temp->right = create();
    return temp;
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
