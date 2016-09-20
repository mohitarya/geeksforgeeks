#include <stdio.h>
#include <stdlib.h>

// BST Node Structure 

typedef struct bst_node {
    int data;
    struct bst_node *left;
    struct bst_node *right;
} node;

node *insert(node *, int);
node *create_node(int);
void print(node *);

// Main Starts from here

int main()
{
    node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    return 0;
}

node *create_node(int data)
{
    node *new_node = (node *) malloc(sizeof(node));
    if(!new_node){
        printf("Failed to create a NOde, Memory Failure\n");
        return NULL;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *insert(node *root, int data)
{
    if(root == NULL){
        node *new_node = create_node(data);
        if(!new_node){
            return NULL;
        }
        root = new_node;
    }
    // Adding the smaller value Node to the left of sub-tree
    if(data <= root->data){
        root->left = insert(root->left, data);
    }
    if(data > root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

void print(node *root)
{

}
