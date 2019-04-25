#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree_node{
    int data;
    struct tree_node *left;
    struct tree_node *right;
}node;

node *create_node(int data)
{
    node *new_node;

    new_node = (node *) malloc(sizeof(node));

    return new_node;
}

void insert(node **root, int data)
{
    node *temp = (*root);
    node *new_node = NULL;

    if(temp == NULL)
    {
        new_node = create_node(data);
        if(new_node == NULL)
        {
            printf("Failed to allocate the node\n");
            return;
        }
        temp = new_node;
    }
}

int main()
{
    node *root = NULL;

    // Insert data in the tree
    insert(&root, 20);
    insert(&root, 10);
    insert(&root, 8);
    insert(&root, 35);
    insert(&root, 25);
    insert(&root, 15);
    insert(&root, 50);
    insert(&root, 2);
    insert(&root, 42);
    insert(&root, 14);
}
