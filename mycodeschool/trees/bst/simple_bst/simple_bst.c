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
void search_data(node *, int);
int find_min(node *);
// Main Starts from here

int main()
{
    int min_val, max_val;
    node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    //search_data(root, 20);
    //search_data(root, 50);
    min_val = find_min(root);
    max_val = find_max(root);
    printf("Min Value in tree is %d\n", min_val);
    printf("Max value in tree is %d\n", max_val);
    return 0;
}

int find_max(node *root)
{
    if(root->right == NULL){
        return root->data;
    }
    int val;
    val = find_min(root->right);
    if(val > root->data){
        return val;
    }else{
        return root->data;
    }
}
int find_min(node *root)
{
    if(root->left == NULL){
        return root->data;
    }
    int val;
    val = find_min(root->left);
    if(val < root->data){
        return val;
    }else{
        return root->data;
    }
}
void search_data(node *root, int data)
{
    if(root == NULL){
        printf("Data not found in the tree\n");
    }
    else if(root->data == data){
        printf("Data matched in the tree\n");
    }
    else if(data < root->data){
        search_data(root->left, data);
    }
    else{
        search_data(root->right, data);
    }
    return;
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
    else if(data <= root->data){
        root->left = insert(root->left, data);
    }
    else if (data > root->data){
        root->right = insert(root->right, data);
    }
    return root;
}
