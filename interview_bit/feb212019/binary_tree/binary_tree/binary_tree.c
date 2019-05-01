#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QUEUE_LEN 15
#define TRUE 1
#define FALSE 0

typedef struct tree_node{
    int data;
    struct tree_node *left;
    struct tree_node *right;
}node;

node *queue[QUEUE_LEN];
int front = -1, rear = -1;

/*************************************************/
/*****************Queue Implementation************/
/*****************Start***************************/

int isFull()
{
    if(((rear + 1) % (QUEUE_LEN - 1)) == front)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int isEmpty()
{
    if((front == -1) && (rear == -1))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void enQueue(node *data)
{
    int index;
    if(isFull())
    {
        printf("Queue is Full\n");
        return;
    }
    else if(isEmpty())
    {
        front = rear = index = 0;
    }
    else
    {
        index = (rear + 1) % (QUEUE_LEN - 1);
        rear = index;
    }
    queue[index] = data;
}

node *deQueue()
{
    node *temp = NULL;
    if(isEmpty())
    {
        printf("Queue is Empty\n");
        return NULL;
    }
    else if(front == rear)
    {
        temp = queue[rear];
        front = rear = -1;
    }
    else
    {
        temp = queue[front];
        front = (front + 1) % (QUEUE_LEN - 1);
    }
    return temp;
}

/*****************End***************************/

node *create_node(int data)
{
    node *new_node;

    new_node = (node *) malloc(sizeof(node));

    new_node->data = data;

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
            temp = NULL;
            return;
        }
        temp = new_node;
        *root = temp;
    }
    else if (data <= temp->data)
    {
        insert(&(temp->left), data);
    }
    else if(data > temp->data)
    {
        insert(&(temp->right), data);
    }
}

void min_binary_tree(node *root)
{
    if(root == NULL)
    {
        printf("Binary Tree is empty\n");
        return;
    }

    if(root->left == NULL)
    {
        printf("Min = %d\n", root->data);
        return;
    }
    min_binary_tree(root->left);
}

void max_binary_tree(node *root)
{
    if(root == NULL)
    {
        printf("Binary Tree is empty\n");
        return;
    }

    if(root->right == NULL)
    {
        printf("Max = %d\n", root->data);
        return;
    }
    max_binary_tree(root->right);
}

int height_tree(node *root)
{
    int height_left = 0, height_right = 0;

    if(root == NULL)
    {
        return -1;
    }
    height_left = height_tree(root->left);
    height_right = height_tree(root->right);
    if(height_left >= height_right)
    {
       return (height_left + 1);
    }
    else
    {
       return (height_right + 1);
    }
}

void level_order_traversal(node *root)
{
    node *temp;

    if(root == NULL)
    {
        printf("Tree is Empty\n");
        return;
    }
    enQueue(root);
    while(!(isEmpty()))
    {
        temp = deQueue();
        if(temp == NULL)
        {
            return;
        }
        else
        {
            printf("%d\t", temp->data);
            if(temp->left != NULL)
            {
                enQueue(temp->left);
            }

            if(temp->right != NULL)
            {
                enQueue(temp->right);
            }
        }
    }
    printf("\n");
}

int main()
{
    node *root = NULL;
    memset(queue, 0x0, sizeof(node) * QUEUE_LEN);
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
    min_binary_tree(root);
    max_binary_tree(root);
    printf("Height = %d\n", height_tree(root));
    level_order_traversal(root);
}
