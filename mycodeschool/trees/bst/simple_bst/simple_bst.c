#include <stdio.h>
#include <stdlib.h>

// BST Node Structure 

typedef struct bst_node {
    int data;
    struct bst_node *left;
    struct bst_node *right;
} node;

typedef struct queue_node{
    node *pnode;
    struct queue_node *next;
} queue;

node *insert(node *, int);
node *create_node(int);
void search_data(node *, int);
int find_min(node *);
int find_max(node *);
int find_height(node *);
void print_tree_level_order(node *);
void push_queue(queue **, queue **, node *);
queue *create_q_new_node(node *);
// Main Starts from here

int main()
{
    int min_val, max_val, height = 0;
    node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 18);
    root = insert(root, 50);
    //search_data(root, 20);
    //search_data(root, 50);
    //min_val = find_min(root);
    //max_val = find_max(root);
    //printf("Min Value in tree is %d\n", min_val);
    //printf("Max value in tree is %d\n", max_val);
    //height = find_height(root);
    //printf("Height of tree is %d\n", height);
    return 0;
}

void print_tree_level_order(node *root)
{
    queue *front_queue, *rear_queue;
    front_queue = rear_queue = NULL;
    push_queue(&front_queue, &rear_queue, root);
}

queue *create_q_new_node(node *p)
{
    queue *new_node = NULL;
    new_node = (queue *) malloc(sizeof(queue));
    if(new_node == NULL){
        printf("Unable to allocate memory for queue node\n");
        return NULL;
    }
    new_node->pnode = p;
    new_node->next = NULL;
    return new_node;
}

void push_queue(queue **front_queue, queue **rear_queue, node *pnode)
{
    queue *new_node = NULL;
    // Create a New Node
    new_node = create_q_new_node(pnode);
    if(*front_queue == NULL && *rear_queue == NULL){
        *front_queue = new_node;
        *rear_queue = new_node;
    }else{
        *rear_queue->next = new_node;
        *rear_queue = new_node;
    }
}

int find_height(node *root)
{
    int height_left, height_right;
    if(root == NULL){
        return -1;
    }
    height_left = find_height(root->left);
    height_right = find_height(root->right);
    if(height_left <= height_right){
        return height_right + 1;
    }else{
        return height_left + 1;
    }
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
